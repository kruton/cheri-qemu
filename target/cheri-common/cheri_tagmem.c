 *
#include "cheri_tagmem.h"
#include "cheri-helper-utils.h"
// XXX: use hbitmap? Or a different data structure?
#include "qemu/bitmap.h"
#endif
#endif
 * For emulation purposes the tag is stored in a two-level array containing
 * fixed size bitmaps. To reduce the amount of memory needed the tag flag array
 * is allocated sparsely, 4K tags at at time, and on demand.
 * This 4K number is arbitary and depending on the workload other sizes may be
 * better.
 * Note: We also support an mode where we use one byte per tag. This makes it
 * This requires eight times the memory.
 * As tag accesses are not atomic with regard to data writes/reads spurious
 * invalid capabilities could be created in a threaded context.
 * Therefore, we don't use atomic bitwise RMW operations and the one byte per
 * tag variant actually performs slightly worse due to increased memory usage.
 * FIXME: find a solution to make tags safe (or just always disable multi-tcg)
 *
 * FIXME: rewrite using somethign more like the upcoming MTE changes (https://github.com/rth7680/qemu/commits/tgt-arm-mte-user)
#define CAP_TAGBLK_MSK      ((1 << CAP_TAGBLK_SHFT) - 1)
#define CAP_TAGBLK_SIZE       (1 << CAP_TAGBLK_SHFT)
#define TAGS_PER_PAGE        (TARGET_PAGE_SIZE / CHERI_CAP_SIZE)
#endif
#else
#define CAP_TAG_GET_MANY_MASK ((1 << (1UL << CAP_TAG_GET_MANY_SHFT)) - 1UL)
#define CAP_TAG_MANY_DATA_SIZE (CHERI_CAP_SIZE << CAP_TAG_GET_MANY_SHFT)
static inline size_t num_tagblocks(RAMBlock* ram)
{
    uint64_t memory_size = memory_region_size(ram->mr);
    size_t result = DIV_ROUND_UP(memory_size, CHERI_CAP_SIZE * CAP_TAGBLK_SIZE);
    }
    return result;
}
static CheriTagBlock *cheri_tag_new_tagblk(RAMBlock *ram, uint64_t tagidx)
{
    CheriTagBlock *tagblk, *old;
    tagblk = g_malloc0(sizeof(CheriTagBlock));
    if (tagblk == NULL) {
        error_report("Can't allocate tag block.");
        exit(1);
    CheriTagBlock **tagmem = (CheriTagBlock **)ram->cheri_tags;
    size_t tagblock_index = (tagidx >> CAP_TAGBLK_SHFT);
    /* Possible race here so use atomic compare and swap. */
    cheri_debug_assert(tagblock_index < num_tagblocks(ram) &&
                       "Tag index out of bounds");
    old = qatomic_cmpxchg(&tagmem[tagblock_index], NULL, tagblk);
    if (old != NULL) {
        /* Lost the race, free. */
        g_free(tagblk);
        return old;
    } else {
        return tagblk;
    }
}
static inline QEMU_ALWAYS_INLINE CheriTagBlock *cheri_tag_block(size_t tag_index,
                                                                RAMBlock *ram)
{
    const size_t tagbock_index = tag_index >> CAP_TAGBLK_SHFT;
    cheri_debug_assert(ram->cheri_tags);
    }
    return tagmem[tagbock_index];
static inline QEMU_ALWAYS_INLINE bool tagblock_get_tag(CheriTagBlock *block,
                                                       size_t block_index)
static inline QEMU_ALWAYS_INLINE void
    } else {
static inline QEMU_ALWAYS_INLINE void tagblock_clear_tag(CheriTagBlock *block,
    assert(memory_region_is_ram(mr));
    assert(memory_region_size(mr) == memory_size &&
           "Incorrect tag mem size passed?");
    assert(mr->ram_block->cheri_tags == NULL && "Already initialized?");
                         (uintmax_t)vaddr, ram ? ram->idstr : NULL,
                         (uintmax_t)ram_offset);
        return ALL_ZERO_TAGBLK;
#ifndef TARGET_AARCH64
    // AArch64 seems to use different sizes. Might be worth looking into.
    cheri_debug_assert(size == TARGET_PAGE_SIZE && "Unexpected size");
#endif
    CheriTagBlock *tagblk = cheri_tag_block(tag, ram);
        /*
         */
#else
        /*
         */
        /*
         */
#endif
    if (tagblk != NULL) {
        const size_t tagblk_index = CAP_TAGBLK_IDX(tag);
        return tagblk->tag_bitmap + BIT_WORD(tagblk_index);
#endif
                                                bool isWrite,
    /* XXXAR: see mte_helper.c */
     * Find the iotlbentry for ptr.  This *must* be present in the TLB
     * because we just found the mapping.
     * TODO: Perhaps there should be a cputlb helper that returns a
     * matching tlb entry + iotlb entry.
#ifdef CONFIG_DEBUG_TCG
    CPUTLBEntry *entry = cheri_tlb_entry(env_cpu(env), mmu_idx, vaddr);
    g_assert(tlb_hit(isWrite ? cheri_tlb_addr_write(entry) : entry->addr_read, vaddr));
#if defined(CHERI_UNALIGNED)
    if (unlikely((first_addr & TARGET_PAGE_MASK) !=
        warn_report("Got unaligned %d-byte store across page "
        return NULL;
        get_tagmem_from_iotlb_entry(env, vaddr, mmu_idx, true, &tagmem_flags);
    if (qemu_log_instr_enabled(env)) {
        qemu_log_instr_extra(
            env,
            "    Cap Tag Write [" TARGET_FMT_lx "/" RAM_ADDR_FMT "] %d -> 0\n",
            vaddr, qemu_ram_addr_from_host(host_addr), old_value);
    if (!ram->cheri_tags) {
        CheriTagBlock *tagblk = cheri_tag_block(tag, ram);
#ifdef TARGET_MIPS
        if (tagmem_flags & TLBENTRYCAP_FLAG_TRAP) {
    probe_read(env, vaddr, CAP_TAG_MANY_DATA_SIZE, mmu_idx, pc);
    if ((result && (tagmem_flags & TLBENTRYCAP_FLAG_TRAP)) ||
     * We call probe_(cap)_write rather than probe_access since the branches
     * checking access_type can be eliminated.
    if (tags) {

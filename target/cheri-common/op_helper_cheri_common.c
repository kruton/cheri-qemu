 */
#include "qemu/osdep.h"
#include "cheri_tagmem.h"
#endif
#else
#endif
#define CHERI_HELPER_IMPL(name)                                                \
    __attribute__(                                                             \
        (deprecated("Do not call the helper directly, it will crash at "       \
                    "runtime. Call the _impl variant instead"))) helper_##name
#endif
/*
 */
{
}
{
#endif
    if (unlikely(cptr->cr_tag && is_cap_sealed(cptr))) {
    }
    if (likely(addr_in_cap_bounds(cptr, new_addr))) {
        /* Common case: updating an in-bounds capability. */
    }
    /* Result is out-of-bounds, check if it's representable. */
#endif
        }
        /* (Possibly) out-of-bounds but still representable. */
        check_out_of_bounds_stat(env, oob_info,
                                 get_readonly_capreg(env, regnum_dst),
    }
}
                                        target_ulong num_bytes))
{
                       "Should have been checked before bounds!");
              /*instavail=*/true, GETPC());
}
#ifdef TARGET_AARCH64
                                              target_ulong addr,
{
              /*instavail=*/true, GETPC());
}
#endif
void CHERI_HELPER_IMPL(pcc_check_bounds(CPUArchState *env, target_ulong addr,
{
    const cap_register_t *pcc = cheri_get_recent_pcc(env);
    cheri_debug_assert(pcc->cr_tag && cap_is_unsealed(pcc) &&
    check_cap(env, pcc, 0, addr, CHERI_EXC_REGNUM_PCC, num_bytes,
              /*instavail=*/true, GETPC());
}
{
}
                                        target_ulong rs))
{
}
}
     * CGetBase: Move Base to a General-Purpose Register.
    return (target_ulong)cap_get_base(get_readonly_capreg(env, cb));
    const cap_register_t *cbp = get_readonly_capreg(env, cb);
                       "Unknown permission bits set!");
#endif
     * CGetTag: Move Tag to a General-Purpose Register
    const target_long otype = cap_get_otype_signext(cbp);
#else
    cap_register_t result = *cbp;
    result.cr_tag = 0;
    update_capreg(env, cd, &result);
    update_target_for_jump(env, &next_pcc, cjalr_flags);
#else
    cheri_debug_assert(cap_is_unsealed(target) || cap_is_sealed_entry(target));
    if (next_pcc.cr_tag && cap_is_sealed_entry(&next_pcc)) {
        next_pcc.cr_tag = 0;
    if (link_reg != NULL_CAPREG_INDEX) {
#ifdef TARGET_AARCH64
        result._cr_cursor = link_pc;
        // The return capability should always be a sentry
            cap_make_sealed_entry(&result);
                                 uintptr_t _host_return_address)
#ifdef TARGET_RISCV
void CHERI_HELPER_IMPL(cjalr(CPUArchState *env, uint32_t cd,
    const target_ulong cursor = cap_get_cursor(cbp);
    GET_HOST_RETPC();
        raise_cheri_exception_branch(env, CapEx_SealViolation, data_regnum);
    } else if (!cap_has_perms(code_cap, CAP_PERM_CINVOKE)) {
    } else if (!cap_has_perms(data_cap, CAP_PERM_CINVOKE)) {
    } else if (!cap_is_unsealed(csp)) {
    cap_register_t result = *csp;
                                  target_ulong rt))
    } else if ((cap_get_all_perms(csp) & rt) != rt) {
        raise_cheri_exception(env, CapEx_UserDefViolation, cs);
    // Previously QEMU return (1<<64)-1 for a representable length of 1<<64
    // (similar to CGetLen), but all other implementations just strip the
    // high bit instead. Note: This allows a subsequent CSetBoundsExact to
    // succeed instead of trapping.
    // TODO: We may want to change CRRL to trap in this case. This could avoid
    //  potential bugs caused by accientally returning a zero-length capability.
    //  However, most code should already be guarding against large inputs so
    //  it is unclear if this makes much of a difference, and knowing that the
    //  instruction never traps could be useful for optimization purposes.
    // See also https://github.com/CTSRD-CHERI/cheri-architecture/issues/32
    return (target_ulong)cap_get_length_full(&tmpcap);
}
{
}
{
void CHERI_HELPER_IMPL(cbuildcap(CPUArchState *env, uint32_t cd, uint32_t cb,
                                 uint32_t ct))
    cap_register_t result = *ctp;
    if (cb == 0) {
        result.cr_tag = false;
#endif
    const cap_register_t *cbp = get_capreg_0_is_ddc(env, cb);
    } else if (cap_get_base(ctp) < cap_get_base(cbp)) {
    } else if (cap_get_top_full(ctp) > cap_get_top_full(cbp)) {
    } else if (cap_get_base(ctp) > cap_get_top_full(ctp)) {
        // check for length < 0 - possible because cs2 might be untagged
    } else if ((cap_get_all_perms(ctp) & cap_get_all_perms(cbp)) !=
               cap_get_all_perms(ctp)) {
    } else if (cap_has_reserved_bits_set(ctp)) {
#ifndef TARGET_AARCH64
#endif
        if (cap_is_sealed_entry(ctp)) {
            cap_make_sealed_entry(&derived);
            /*
             */
            RESULT_VALID = false;
            /* For reserved otypes we return a null-derived value. */
static void cseal_common(CPUArchState *env, uint32_t cd, uint32_t cs,
                         uintptr_t _host_return_address)
    /*
     */
            update_capreg(env, cd, csp);
    } else if (conditional && !cap_is_unsealed(csp)) {
    } else if (conditional && !cap_cursor_in_bounds(ctp)) {
    } else if (!conditional && !cap_is_unsealed(csp)) {
        raise_cheri_exception_or_invalidate(env, CapEx_PermitSealViolation, ct);
    } else if (!conditional && !cap_cursor_in_bounds(ctp)) {
static inline QEMU_ALWAYS_INLINE void
cincoffset_impl(CPUArchState *env, uint32_t cd, uint32_t cb, target_ulong rt,
                uintptr_t retpc, struct oob_stats_info *oob_info)
void CHERI_HELPER_IMPL(candaddr(CPUArchState *env, uint32_t cd, uint32_t cb,
    target_ulong cursor = get_capreg_cursor(env, cb);
    target_ulong target_addr = cursor & rt;
    cincoffset_impl(env, cd, cb, diff, GETPC(), OOB_INFO(csetoffset));
    GET_HOST_RETPC();
    // CFromPtr traps on cbp == NULL so we use reg0 as $ddc to save encoding
                         uint32_t cb, target_ulong length,
                         uintptr_t _host_return_address)
            raise_cheri_exception(env, CapEx_TagViolation, cb);
            raise_cheri_exception(env, CapEx_SealViolation, cb);
            raise_cheri_exception(env, CapEx_LengthViolation, cb);
        assert(cap_get_top_full(&result) <= cap_get_top_full(cbp) &&
    if (cbp->cr_tag && !cap_is_unsealed(cbp)) {
    bool is_subset = false;
    if (cbp->cr_tag == ctp->cr_tag &&
        /* is_cap_sealed(cbp) == is_cap_sealed(ctp) && */
        cap_get_base(cbp) <= cap_get_base(ctp) &&
        cap_get_top_full(ctp) <= cap_get_top_full(cbp) &&
            cap_get_all_perms(ctp)) {
        is_subset = true;
        raise_cheri_exception(env, CapEx_TagViolation, ct);
        return (target_ulong)0;
#ifdef TARGET_AARCH64
    const cap_register_t *cbp = get_load_store_base_cap(env, cb);
                                /*unaligned_handler=*/NULL);
                                              target_ulong offset,
                                              uint32_t size))
                                            target_ulong offset, uint32_t size))
    target_ulong offset, uint32_t size))
    return cap_check_common(CAP_PERM_LOAD | CAP_PERM_STORE, env, cb, offset,
target_ulong CHERI_HELPER_IMPL(cap_check_addr(CPUArchState *env,
                                              uint32_t required_perms))
    const cap_register_t *ddc = cheri_get_ddc(env);
    const target_ulong checked_addr =
    if (tag && (prot & PAGE_LC_CLEAR)) {
    if ((tag && (prot & PAGE_LC_TRAP)) || (prot & PAGE_LC_TRAP_ANY))
        if (cap_is_unsealed(&tmp)) {
#else
        CAP_cc(decompress_raw_ext)(*pesbt, *cursor, tag, lvbits, &ncd);
        tag = cheri_tag_prot_clear_or_trap(env, vaddr, cb, source, prot, retpc,
        if (tag) {
    if (tag)
#if defined(TARGET_RISCV) && defined(CONFIG_RVFI_DII)
    env->rvfi_dii_trace.MEM.rvfi_mem_addr = vaddr;
    env->rvfi_dii_trace.MEM.rvfi_mem_rdata[0] = *cursor;
    env->rvfi_dii_trace.MEM.rvfi_mem_rdata[2] = tag;
    env->rvfi_dii_trace.MEM.rvfi_mem_rmask = (1 << CHERI_CAP_SIZE) - 1;
    // TODO: Add one extra bit to include the tag?
    env->rvfi_dii_trace.available_fields |= RVFI_MEM_DATA;
bool load_cap_from_memory_raw_tag(CPUArchState *env, target_ulong *pesbt,
                                  target_ulong *cursor, uint32_t cb,
                                  const cap_register_t *source,
                                  target_ulong vaddr, uintptr_t retpc,
                                  hwaddr *physaddr, bool *raw_tag)
bool load_cap_from_memory_raw(CPUArchState *env, target_ulong *pesbt,
                              const cap_register_t *source, target_ulong vaddr,
    target_ulong vaddr, uintptr_t retpc, hwaddr *physaddr)
    target_ulong pesbt_for_mem = get_capreg_pesbt(env, cs) ^ CAP_MEM_XOR_MASK;
#ifdef CONFIG_DEBUG_TCG
    if (get_capreg_state(cheri_get_gpcrs(env), cs) == CREG_INTEGER) {
        tcg_debug_assert(pesbt_for_mem == 0 && "Integer values should have NULL PESBT");
        tcg_debug_assert(pesbt_for_mem == 0 && "Wrong value for cnull?");
        tcg_debug_assert(cursor == 0 && "Wrong value for cnull?");
        tcg_debug_assert(!tag && "Wrong value for cnull?");
    env->rvfi_dii_trace.MEM.rvfi_mem_wdata[0] = cursor;
G_NORETURN static inline void
raise_pcc_fault(CPUArchState *env, CheriCapExcCause cause, target_ulong addr)
    cheri_debug_assert(pc_is_current(env));
     * Note: we set pc=0 since PC will have been saved prior to calling the
     * helper. Therefore, we don't need to recompute it from the generated code.
     * The PC fetched from the generated code will often be out-of-bounds, so
     * fetching it will trigger an assertion.
    raise_cheri_exception_if(env, cause, addr, CHERI_EXC_REGNUM_PCC);
void CHERI_HELPER_IMPL(raise_exception_pcc_perms(CPUArchState *env))
    CheriCapExcCause cause;
    raise_pcc_fault(env, cause, PC_ADDR(env));
void CHERI_HELPER_IMPL(raise_exception_pcc_perms_not_if(
    CPUArchState *env, target_ulong addr, uint32_t required_perms))
    check_cap(env, pcc, required_perms, addr, CHERI_EXC_REGNUM_PCC, 1,
              /*instavail=*/true, GETPC());
                                                  target_ulong addr,
    cap_check_common_reg(required_perms, env, CHERI_EXC_REGNUM_DDC, addr, 1,
                         GETPC(), ddc, 1, NULL);
              /*instavail=*/true, GETPC());
void CHERI_HELPER_IMPL(debug_cap(CPUArchState *env, uint32_t regndx))
    GPCapRegs *gpcrs = cheri_get_gpcrs(env);
    /* Index manually in order not to decompress */
    const cap_register_t *cap;
        cap = get_cap_in_gpregs(gpcrs, regndx);
    bool stateMeansTagged = state == CREG_TAGGED_CAP;
    bool decompressedMeansTagged =
        (state == CREG_FULLY_DECOMPRESSED) && cap->cr_tag;
    target_ulong pesbt = cap->cr_pesbt;
    printf("Debug Cap %2d: Cursor " TARGET_FMT_lx ". Pesbt " TARGET_FMT_lx
           ". Tagged %d (%d,%d). Type " TARGET_FMT_lx ". "
           "Perms " TARGET_FMT_lx "\n",
           regndx, cap->_cr_cursor, pesbt ^ CAP_MEM_XOR_MASK,
           stateMeansTagged || decompressedMeansTagged, state, cap->cr_tag,
    if (state == CREG_FULLY_DECOMPRESSED) {
        printf("Base: " TARGET_FMT_lx ". Top " TARGET_FMT_lu TARGET_FMT_lx
               ".\n",
               cap->cr_base, (target_ulong)(cap->_cr_top >> CAP_CC(ADDR_WIDTH)),
               (target_ulong)cap->_cr_top);
    }
void helper_capreg_state_debug(CPUArchState *env, uint32_t regnum,
                               uint64_t flags, uint64_t pc)
{
    GPCapRegs *gpcrs = cheri_get_gpcrs(env);
    CapRegState regstate = get_capreg_state(gpcrs, regnum);
    // Should include the actual state
    assert((flags & (1 << (uint64_t)regstate)) && pc);

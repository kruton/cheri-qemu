 */
#include "qemu/osdep.h"
#include "cheri_tagmem.h"
#ifndef TARGET_CHERI
#endif
#else
#endif
#define CHERI_HELPER_IMPL(name)                                                \
    __attribute__(                                                             \
        (deprecated("Do not call the helper directly, it will crash at "       \
                    "runtime. Call the _impl variant instead"))) helper_##name
#endif
/*
 * These semantics are used for Morello and CHERI-RISC-V, whereas (legacy)
 * CHERI-MIPS raises exceptions on invalid modifications.
 */
{
}
                   bool precise_repr_check, uintptr_t retpc,
{
    DEFINE_RESULT_VALID;
#endif
    if (unlikely(cptr->cr_tag && is_cap_sealed(cptr))) {
        raise_cheri_exception_or_invalidate_impl(env, CapEx_SealViolation,
    }
#ifndef TARGET_MORELLO
    /*
     */
    if (likely(addr_in_cap_bounds(cptr, new_addr))) {
        /* Common case: updating an in-bounds capability. */
    }
    /* Result is out-of-bounds, check if it's representable. */
#endif
        }
        cap_register_t result = *cptr;
    } else {
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
{
}
}
/*
 */
    }
}
}
     * CGetBase: Move Base to a General-Purpose Register.
    return (target_ulong)cap_get_base(get_readonly_capreg(env, cb));
}
     * CGetLen: Move Length to a General-Purpose Register.
    const cap_register_t *cbp = get_readonly_capreg(env, cb);
    target_ulong perms = cap_get_all_perms(cbp);
                       "Unknown permission bits set!");
#endif
    return (target_ulong)cap_get_offset(get_readonly_capreg(env, cb));
target_ulong CHERI_HELPER_IMPL(cgettag(CPUArchState *env, uint32_t cb))
     * CGetTag: Move Tag to a General-Purpose Register
    const target_long otype = cap_get_otype_signext(cbp);
#else
#endif
    cap_register_t result = *cbp;
    result.cr_tag = 0;
    update_capreg(env, cd, &result);
    update_target_for_jump(env, &next_pcc, cjalr_flags);
#else
    cheri_debug_assert(cap_is_unsealed(target) || cap_is_sealed_entry(target));
#endif
    if (next_pcc.cr_tag && cap_is_sealed_entry(&next_pcc)) {
        qemu_log_mask_and_addr(CPU_LOG_INSTR | LOG_GUEST_ERROR,
                       cpu_get_recent_pc(env),
                       "Requested jump to sentry but got invalid cap."
                       "\n  Current PCC: " PRINT_CAP_FMTSTR
                       "\n  Target cap: " PRINT_CAP_FMTSTR  "\n",
                       PRINT_CAP_ARGS(cheri_get_recent_pcc(env)),
                       PRINT_CAP_ARGS(target));
        next_pcc.cr_tag = 0;
#endif
    if (link_reg != NULL_CAPREG_INDEX) {
#ifdef TARGET_AARCH64
        result._cr_cursor = link_pc;
        // The return capability should always be a sentry
            cap_make_sealed_entry(&result);
                                 uintptr_t _host_return_address)
#ifdef TARGET_RISCV
    /* On RISC-V we mask the LSB of the target to match JALR behaviour. */
        raise_cheri_exception_branch(env, CapEx_TagViolation, target_reg);
        raise_cheri_exception_branch(env, CapEx_SealViolation, target_reg);
    } else if (!cap_has_perms(target, CAP_PERM_EXECUTE)) {
        raise_cheri_exception_branch(env, CapEx_PermitExecuteViolation,
void CHERI_HELPER_IMPL(cjalr(CPUArchState *env, uint32_t cd,
    const target_ulong cursor = cap_get_cursor(cbp);
    GET_HOST_RETPC();
    } else if (!data_cap->cr_tag) {
        raise_cheri_exception_branch(env, CapEx_SealViolation, code_regnum);
        raise_cheri_exception_branch(env, CapEx_SealViolation, data_regnum);
        raise_cheri_exception_branch(env, CapEx_TypeViolation, code_regnum);
    } else if (!cap_has_perms(code_cap, CAP_PERM_CINVOKE)) {
    } else if (!cap_has_perms(data_cap, CAP_PERM_CINVOKE)) {
    } else if (!cap_has_perms(code_cap, CAP_PERM_EXECUTE)) {
        raise_cheri_exception_branch(env, CapEx_LengthViolation, code_regnum);
    GET_HOST_RETPC_IF_TRAPPING_CHERI_ARCH();
    DEFINE_RESULT_VALID;
    if (!csp->cr_tag) {
        raise_cheri_exception_or_invalidate(env, CapEx_TagViolation, cs);
    } else if (!cap_is_unsealed(csp)) {
        raise_cheri_exception_or_invalidate(env, CapEx_SealViolation, cs);
#ifdef TARGET_MIPS
     * The legacy MIPS testsuite expects traps when attempting to seal
     * non-executable capabilities with CSealEntry.
     * Keep this code rather than fixing the MIPS testsuite. We can GC this
     * workaround once we completely drop MIPS support (most likely once we
     * have a CHERI-RISC-V testsuite).
    if (!cap_has_perms(csp, CAP_PERM_EXECUTE)) {
        raise_cheri_exception(env, CapEx_PermitExecuteViolation, cs);
    cap_register_t result = *csp;
    if (!RESULT_VALID) {
        result.cr_tag = 0;
    CAP_cc(update_otype)(&result, CAP_OTYPE_SENTRY);
    update_capreg(env, cd, &result);
                                  target_ulong rt))
    GET_HOST_RETPC();
        raise_cheri_exception(env, CapEx_TagViolation, cs);
    } else if ((cap_get_all_perms(csp) & rt) != rt) {
        raise_cheri_exception(env, CapEx_UserDefViolation, cs);
    CAP_cc(setbounds)(&tmpcap, len);
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
    }
    return result;
}
void CHERI_HELPER_IMPL(cbuildcap(CPUArchState *env, uint32_t cd, uint32_t cb,
                                 uint32_t ct))
{
    GET_HOST_RETPC_IF_TRAPPING_CHERI_ARCH();
    DEFINE_RESULT_VALID;
    cap_register_t result = *ctp;
#ifdef TARGET_CHERI_RISCV_STD
    if (cb == 0) {
        result.cr_tag = false;
        update_capreg(env, cd, &result);
        return;
    }
#endif
    const cap_register_t *cbp = get_capreg_0_is_ddc(env, cb);
        raise_cheri_exception_or_invalidate(env, CapEx_TagViolation, cb);
        raise_cheri_exception_or_invalidate(env, CapEx_LengthViolation, cb);
        raise_cheri_exception_or_invalidate(env, CapEx_SealViolation, cb);
    } else if (cap_get_base(ctp) < cap_get_base(cbp)) {
        raise_cheri_exception_or_invalidate(env, CapEx_LengthViolation, cb);
    } else if (cap_get_top_full(ctp) > cap_get_top_full(cbp)) {
    } else if (cap_get_base(ctp) > cap_get_top_full(ctp)) {
        // check for length < 0 - possible because cs2 might be untagged
        raise_cheri_exception_or_invalidate(env, CapEx_LengthViolation, ct);
    } else if ((cap_get_all_perms(ctp) & cap_get_all_perms(cbp)) !=
               cap_get_all_perms(ctp)) {
        raise_cheri_exception_or_invalidate(env, CapEx_UserDefViolation, cb);
    } else if (cap_has_reserved_bits_set(ctp)) {
        raise_cheri_exception_or_invalidate(env, CapEx_LengthViolation, ct);
    }
    if (!RESULT_VALID) {
        result.cr_tag = 0; /* Not a valid subset. */
    } else {
        /* Check if the capability bounds are canonical by deriving. */
        cap_register_t derived = *cbp;
        if (!cap_is_unsealed(&derived)) {
            derived.cr_tag = 0;
        }
        cap_set_cursor(&derived, cap_get_base(&result));
        CAP_cc(setbounds)(&derived, cap_get_length_full(&result));
        cap_set_cursor(&derived, cap_get_cursor(&result));
                      cap_get_all_perms(cbp) & cap_get_all_perms(ctp));
#ifndef TARGET_AARCH64
        cap_set_exec_mode(&derived, cap_get_exec_mode(ctp));
#endif
        if (cap_is_sealed_entry(ctp)) {
            cap_make_sealed_entry(&derived);
        }
        result.cr_tag = 1; /* Set tag to true for comparison with derived. */
        if (cap_exactly_equal(&result, &derived)) {
            /*
             * If this was a valid derivation sequence return that to ensure
             * canonical bounds encoding.
             */
            result = derived;
        } else {
            /* Valid subset but not canonical -> return the untagged input. */
            result.cr_tag = 0;
        }
    update_capreg(env, cd, &result);
    GET_HOST_RETPC_IF_TRAPPING_CHERI_ARCH();
    DEFINE_RESULT_VALID;
    const cap_register_t *cbp = get_readonly_capreg(env, cb);
    if (!cbp->cr_tag) {
        raise_cheri_exception_or_invalidate(env, CapEx_TagViolation, cb);
        raise_cheri_exception_or_invalidate(env, CapEx_SealViolation, cb);
    if (cap_is_sealed_with_reserved_otype(ctp) || cap_is_unsealed(ctp)) {
            RESULT_VALID = false;
        } else {
            /* For reserved otypes we return a null-derived value. */
            update_capreg(env, cd, &result);
            return;
    if (cap_get_otype_unsigned(ctp) < cap_get_base(cbp)) {
        raise_cheri_exception_or_invalidate(env, CapEx_LengthViolation, cb);
    cap_register_t result = *cbp;
    if (!RESULT_VALID) {
        result.cr_tag = 0;
    try_set_cap_cursor(env, &result, cb, cd, cap_get_otype_signext(ctp),
                       /*precise_repr_check=*/true, GETPC(),
                       OOB_INFO(ccopytype));
static void cseal_common(CPUArchState *env, uint32_t cd, uint32_t cs,
                         uintptr_t _host_return_address)
    DEFINE_RESULT_VALID;
    /*
     */
    if (!ctp->cr_tag) {
        if (conditional) {
            update_capreg(env, cd, csp);
        raise_cheri_exception_or_invalidate(env, CapEx_TagViolation, ct);
    } else if (!csp->cr_tag) {
        raise_cheri_exception_or_invalidate(env, CapEx_TagViolation, cs);
    } else if (conditional && !cap_is_unsealed(csp)) {
        update_capreg(env, cd, csp);
    } else if (conditional && !cap_cursor_in_bounds(ctp)) {
    } else if (conditional &&
               cap_get_cursor(ctp) == CAP_OTYPE_UNSEALED_SIGNED) {
    } else if (!conditional && !cap_is_unsealed(csp)) {
        raise_cheri_exception_or_invalidate(env, CapEx_SealViolation, cs);
        raise_cheri_exception_or_invalidate(env, CapEx_SealViolation, ct);
        raise_cheri_exception_or_invalidate(env, CapEx_PermitSealViolation, ct);
    } else if (!conditional && !cap_cursor_in_bounds(ctp)) {
    } else if (!is_representable_cap_with_addr(csp, cap_get_cursor(csp))) {
        raise_cheri_exception_or_invalidate(env, CapEx_InexactBounds, cs);
    cap_register_t result = *csp;
    if (!RESULT_VALID) {
        result.cr_tag = false;
        uint32_t new_otype = (uint32_t)ct_base_plus_offset;
        new_otype &= CAP_OTYPE_ALL_BITS;
        CAP_cc(update_otype)(&result, new_otype);
    } else {
    }
    update_capreg(env, cd, &result);
}
{
    /*
     */
}
    /*
     */
}
    GET_HOST_RETPC_IF_TRAPPING_CHERI_ARCH();
    DEFINE_RESULT_VALID;
    /*
     */
        raise_cheri_exception_or_invalidate(env, CapEx_TagViolation, cs);
        raise_cheri_exception_or_invalidate(env, CapEx_SealViolation, cs);
    } else if (!cap_is_sealed_with_type(csp)) {
        raise_cheri_exception_or_invalidate(env, CapEx_PermitUnsealViolation,
        raise_cheri_exception_or_invalidate(env, CapEx_LengthViolation, ct);
    cap_register_t result = *csp;
    } else {
    } else {
        CAP_cc(update_otype)(&result, CAP_OTYPE_UNSEALED);
    update_capreg(env, cd, &result);
#endif
static inline QEMU_ALWAYS_INLINE void
cincoffset_impl(CPUArchState *env, uint32_t cd, uint32_t cb, target_ulong rt,
                uintptr_t retpc, struct oob_stats_info *oob_info)
    /*
     */
    target_ulong new_addr = cap_get_cursor(cbp) + rt;
    GET_HOST_RETPC_IF_TRAPPING_CHERI_ARCH();
    DEFINE_RESULT_VALID;
    if (!cbp->cr_tag) {
        raise_cheri_exception_or_invalidate(env, CapEx_TagViolation, cb);
        raise_cheri_exception_or_invalidate(env, CapEx_SealViolation, cb);
    cap_register_t result = *cbp;
    if (!RESULT_VALID) {
        result.cr_tag = 0;
#endif
    update_capreg(env, cd, &result);
    cincoffset_impl(env, cd, cb, rt, GETPC(), OOB_INFO(cincoffset));
void CHERI_HELPER_IMPL(candaddr(CPUArchState *env, uint32_t cd, uint32_t cb,
    target_ulong cursor = get_capreg_cursor(env, cb);
    target_ulong target_addr = cursor & rt;
    cap_register_t result;
    cincoffset_impl(env, cd, cb, diff, GETPC(), OOB_INFO(csetoffset));
    GET_HOST_RETPC();
    DEFINE_RESULT_VALID;
#endif
    // CFromPtr traps on cbp == NULL so we use reg0 as $ddc to save encoding
        return;
        raise_cheri_exception_or_invalidate(env, CapEx_TagViolation, cb);
    } else if (is_cap_sealed(cbp)) {
        raise_cheri_exception_or_invalidate(env, CapEx_SealViolation, cb);
    cap_register_t result = *cbp;
    if (!is_representable_cap_with_addr(cbp, new_addr)) {
                         uint32_t cb, target_ulong length,
                         uintptr_t _host_return_address)
    cap_register_t result = *cbp;
    bool exact;
    if (!CHERI_TAG_CLEAR_ON_INVALID(env)) {
         * The setbounds call will invalidate any results with larger bounds
         * than the input, but for trapping architectures we still need to
         * perform these checks here.
            raise_cheri_exception(env, CapEx_TagViolation, cb);
            raise_cheri_exception(env, CapEx_SealViolation, cb);
        } else if (!cap_is_in_bounds(cbp, cap_get_cursor(cbp), length)) {
            raise_cheri_exception(env, CapEx_LengthViolation, cb);
        /* Use checked_setbounds to ensure we didn't missed any checks. */
        exact = CAP_cc(checked_setbounds)(&result, length);
        exact = CAP_cc(setbounds)(&result, length);
        RESULT_VALID = cbp->cr_tag && result.cr_tag;
     * memory addresses to be wider than requested so it is representable.
        assert(cap_is_representable(&result) &&
        assert(cap_get_top_full(&result) <= cap_get_top_full(cbp) &&
        result.cr_tag = 0;
#ifndef TARGET_AARCH64
/* Morello does not have flags in the capability metadata */
target_ulong CHERI_HELPER_IMPL(cgetflags(CPUArchState *env, uint32_t cb))
     * CGetFlags: Move Flags to a General-Purpose Register.
     * Returns 1 for capability mode, 0 for integer mode.
    CheriExecMode mode = cap_get_exec_mode(get_readonly_capreg(env, cb));
    return mode == CHERI_EXEC_CAPMODE ? 1 : 0;
    GET_HOST_RETPC_IF_TRAPPING_CHERI_ARCH();
    if (cbp->cr_tag && !cap_is_unsealed(cbp)) {
    cap_register_t result = *cbp;
    bool is_subset = false;
    if (cbp->cr_tag == ctp->cr_tag &&
        /* is_cap_sealed(cbp) == is_cap_sealed(ctp) && */
        cap_get_base(cbp) <= cap_get_base(ctp) &&
        cap_get_top_full(ctp) <= cap_get_top_full(cbp) &&
            cap_get_all_perms(ctp)) {
        is_subset = true;
    return (target_ulong)is_subset;
    GET_HOST_RETPC_IF_TRAPPING_CHERI_ARCH();
    if (!CHERI_TAG_CLEAR_ON_INVALID(env) && !ctp->cr_tag) {
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
    GET_HOST_RETPC();
    const cap_register_t *cbp = get_capreg_or_special(env, authreg);
    GET_HOST_RETPC();
    const cap_register_t *ddc = cheri_get_ddc(env);
    const target_ulong checked_addr =
    GET_HOST_RETPC();
    GET_HOST_RETPC();
    if (tag && (prot & PAGE_LC_CLEAR)) {
    if (tag && !cap_has_perms(cbp, CAP_PERM_LOAD_CAP)) {
    if ((tag && (prot & PAGE_LC_TRAP)) || (prot & PAGE_LC_TRAP_ANY))
    if (!cap_has_perms(source, CAP_PERM_MUTABLE_LOAD)) {
#if defined(TARGET_AARCH64)
            perms &= ~(CAP_PERM_MUTABLE_LOAD | CAP_PERM_STORE_LOCAL |
                       CAP_PERM_STORE_CAP | CAP_PERM_STORE);
#elif defined(TARGET_CHERI_RISCV_STD)
        if (cap_is_unsealed(&tmp)) {
    /* No TLB fault possible, should be safe to get a host pointer now */
    void *host = probe_read(env, vaddr, CHERI_CAP_SIZE, mmu_idx, retpc);
#else
                 CAP_MEM_XOR_MASK;
        *pesbt =
            cpu_ld_cap_word_ra(env, vaddr + CHERI_MEM_OFFSET_METADATA, retpc) ^
    bool tag =
        cheri_tag_get(env, vaddr, cb, physaddr, &prot, retpc, mmu_idx, host);
        CAP_cc(decompress_raw_ext)(*pesbt, *cursor, tag, lvbits, &ncd);
        tag = cheri_tag_prot_clear_or_trap(env, vaddr, cb, source, prot, retpc,
        if (tag) {
    if (tag)
#if defined(TARGET_RISCV) && defined(CONFIG_RVFI_DII)
    env->rvfi_dii_trace.MEM.rvfi_mem_addr = vaddr;
    env->rvfi_dii_trace.MEM.rvfi_mem_rdata[0] = *cursor;
    env->rvfi_dii_trace.MEM.rvfi_mem_rdata[1] = *pesbt ^ CAP_MEM_XOR_MASK;
    env->rvfi_dii_trace.MEM.rvfi_mem_rdata[2] = tag;
    env->rvfi_dii_trace.MEM.rvfi_mem_rmask = (1 << CHERI_CAP_SIZE) - 1;
    // TODO: Add one extra bit to include the tag?
    env->rvfi_dii_trace.available_fields |= RVFI_MEM_DATA;
#endif
bool load_cap_from_memory_raw_tag(CPUArchState *env, target_ulong *pesbt,
                                  target_ulong *cursor, uint32_t cb,
                                  const cap_register_t *source,
                                  target_ulong vaddr, uintptr_t retpc,
                                  hwaddr *physaddr, bool *raw_tag)
bool load_cap_from_memory_raw(CPUArchState *env, target_ulong *pesbt,
                              const cap_register_t *source, target_ulong vaddr,
cap_register_t load_and_decompress_cap_from_memory_raw(
    CPUArchState *env, uint32_t cb, const cap_register_t *source,
    target_ulong vaddr, uintptr_t retpc, hwaddr *physaddr)
    target_ulong pesbt, cursor;
    bool tag = load_cap_from_memory_raw(env, &pesbt, &cursor, cb, source, vaddr,
                                        retpc, physaddr);
    CAP_cc(decompress_raw_ext)(pesbt, cursor, tag, lvbits, &result);
    return result;
/*
 * cs is the register of the capability that will be stored
 * cb is the register of the authorizing capability
 */
                                   uint32_t cb __attribute__((unused)),
    target_ulong pesbt_for_mem = get_capreg_pesbt(env, cs) ^ CAP_MEM_XOR_MASK;
#ifdef CONFIG_DEBUG_TCG
    if (get_capreg_state(cheri_get_gpcrs(env), cs) == CREG_INTEGER) {
        tcg_debug_assert(pesbt_for_mem == 0 && "Integer values should have NULL PESBT");
        tcg_debug_assert(pesbt_for_mem == 0 && "Wrong value for cnull?");
        tcg_debug_assert(cursor == 0 && "Wrong value for cnull?");
        tcg_debug_assert(!tag && "Wrong value for cnull?");
    void *host = NULL;
        host = cheri_tag_set(env, vaddr, cs, NULL, retpc, mmu_idx);
        host = cheri_tag_invalidate_aligned(env, vaddr, retpc, mmu_idx);
#else
#if defined(TARGET_RISCV) && defined(CONFIG_RVFI_DII)
    env->rvfi_dii_trace.MEM.rvfi_mem_wdata[0] = cursor;
    env->rvfi_dii_trace.MEM.rvfi_mem_wdata[1] = pesbt_for_mem;
        const target_ulong pesbt = pesbt_for_mem ^ CAP_MEM_XOR_MASK;
    GET_HOST_RETPC();
    target_ulong result = cheri_tag_get_many(env, addr, cb, NULL, GETPC());
    /* For RVFI tracing, sail reports the valu of th last capability read. */
    target_ulong unused1, unused2;
    (void)load_cap_from_memory_raw(env, &unused1, &unused2, cb, cbp,
                                   addr + sizealign - CHERI_CAP_SIZE,
                                   _host_return_address, NULL);
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
           cap_get_otype_unsigned(cap), cap_get_all_perms(cap));
    if (state == CREG_FULLY_DECOMPRESSED) {
        printf("Base: " TARGET_FMT_lx ". Top " TARGET_FMT_lu TARGET_FMT_lx
               ".\n",
               cap->cr_base, (target_ulong)(cap->_cr_top >> CAP_CC(ADDR_WIDTH)),
               (target_ulong)cap->_cr_top);
    }
}
void helper_capreg_state_debug(CPUArchState *env, uint32_t regnum,
                               uint64_t flags, uint64_t pc)
{
    GPCapRegs *gpcrs = cheri_get_gpcrs(env);
    CapRegState regstate = get_capreg_state(gpcrs, regnum);
    // Should include the actual state
    assert((flags & (1 << (uint64_t)regstate)) && pc);
cap_register_t cap_scaddr(target_ulong addr, cap_register_t dest)
{
    if (is_cap_sealed(&dest)) {
        dest.cr_tag = false;
    // cap_set_cursor checks the representable range
    cap_set_cursor(&dest, addr);
    return dest;

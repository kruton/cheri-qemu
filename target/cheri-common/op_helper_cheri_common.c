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
    }
    }
        }
                                 get_readonly_capreg(env, regnum_dst),
    }
}
                                        target_ulong num_bytes))
{
                       "Should have been checked before bounds!");
              /*instavail=*/true, GETPC());
}
{
}
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
     * CGetBase: Move Base to a General-Purpose Register.
    const cap_register_t *cbp = get_readonly_capreg(env, cb);
                       "Unknown permission bits set!");
     * CGetTag: Move Tag to a General-Purpose Register
    cap_register_t result = *cbp;
    result.cr_tag = 0;
    if (link_reg != NULL_CAPREG_INDEX) {
        // The return capability should always be a sentry
            cap_make_sealed_entry(&result);
#ifdef TARGET_RISCV
void CHERI_HELPER_IMPL(cjalr(CPUArchState *env, uint32_t cd,
        raise_cheri_exception_branch(env, CapEx_SealViolation, data_regnum);
    } else if (!cap_has_perms(code_cap, CAP_PERM_CINVOKE)) {
    } else if (!cap_has_perms(data_cap, CAP_PERM_CINVOKE)) {
    } else if (!cap_is_unsealed(csp)) {
                                  target_ulong rt))
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
{
void CHERI_HELPER_IMPL(cbuildcap(CPUArchState *env, uint32_t cd, uint32_t cb,
                                 uint32_t ct))
    cap_register_t result = *ctp;
    if (cb == 0) {
        result.cr_tag = false;
    const cap_register_t *cbp = get_capreg_0_is_ddc(env, cb);
    } else if (cap_get_base(ctp) < cap_get_base(cbp)) {
    } else if (cap_get_top_full(ctp) > cap_get_top_full(cbp)) {
    } else if (cap_get_base(ctp) > cap_get_top_full(ctp)) {
        // check for length < 0 - possible because cs2 might be untagged
        if (cap_is_sealed_entry(ctp)) {
            cap_make_sealed_entry(&derived);
            /* For reserved otypes we return a null-derived value. */
                         uintptr_t _host_return_address)
            update_capreg(env, cd, csp);
    } else if (conditional && !cap_is_unsealed(csp)) {
    } else if (conditional && !cap_cursor_in_bounds(ctp)) {
    } else if (!conditional && !cap_is_unsealed(csp)) {
        raise_cheri_exception_or_invalidate(env, CapEx_PermitSealViolation, ct);
    } else if (!conditional && !cap_cursor_in_bounds(ctp)) {
void CHERI_HELPER_IMPL(candaddr(CPUArchState *env, uint32_t cd, uint32_t cb,
    target_ulong cursor = get_capreg_cursor(env, cb);
    target_ulong target_addr = cursor & rt;
    cincoffset_impl(env, cd, cb, diff, GETPC(), OOB_INFO(csetoffset));
    // CFromPtr traps on cbp == NULL so we use reg0 as $ddc to save encoding
                         uint32_t cb, target_ulong length,
            raise_cheri_exception(env, CapEx_TagViolation, cb);
            raise_cheri_exception(env, CapEx_SealViolation, cb);
            raise_cheri_exception(env, CapEx_LengthViolation, cb);
    if (cbp->cr_tag && !cap_is_unsealed(cbp)) {
    bool is_subset = false;
    if (cbp->cr_tag == ctp->cr_tag &&
        /* is_cap_sealed(cbp) == is_cap_sealed(ctp) && */
        cap_get_base(cbp) <= cap_get_base(ctp) &&
        cap_get_top_full(ctp) <= cap_get_top_full(cbp) &&
        is_subset = true;
        raise_cheri_exception(env, CapEx_TagViolation, ct);
        return (target_ulong)0;
    const cap_register_t *cbp = get_load_store_base_cap(env, cb);
                                /*unaligned_handler=*/NULL);
                                              target_ulong offset,
                                              uint32_t size))
                                            target_ulong offset, uint32_t size))
    target_ulong offset, uint32_t size))
    return cap_check_common(CAP_PERM_LOAD | CAP_PERM_STORE, env, cb, offset,
target_ulong CHERI_HELPER_IMPL(cap_check_addr(CPUArchState *env,
    const target_ulong checked_addr =
        if (cap_is_unsealed(&tmp)) {
        CAP_cc(decompress_raw_ext)(*pesbt, *cursor, tag, lvbits, &ncd);
        tag = cheri_tag_prot_clear_or_trap(env, vaddr, cb, source, prot, retpc,
        if (tag) {
#if defined(TARGET_RISCV) && defined(CONFIG_RVFI_DII)
    env->rvfi_dii_trace.MEM.rvfi_mem_addr = vaddr;
    env->rvfi_dii_trace.MEM.rvfi_mem_rdata[0] = *cursor;
    env->rvfi_dii_trace.MEM.rvfi_mem_rdata[2] = tag;
    env->rvfi_dii_trace.MEM.rvfi_mem_rmask = (1 << CHERI_CAP_SIZE) - 1;
    // TODO: Add one extra bit to include the tag?
    env->rvfi_dii_trace.available_fields |= RVFI_MEM_DATA;
    target_ulong pesbt_for_mem = get_capreg_pesbt(env, cs) ^ CAP_MEM_XOR_MASK;
#ifdef CONFIG_DEBUG_TCG
    if (get_capreg_state(cheri_get_gpcrs(env), cs) == CREG_INTEGER) {
        tcg_debug_assert(pesbt_for_mem == 0 && "Integer values should have NULL PESBT");
        tcg_debug_assert(pesbt_for_mem == 0 && "Wrong value for cnull?");
        tcg_debug_assert(cursor == 0 && "Wrong value for cnull?");
        tcg_debug_assert(!tag && "Wrong value for cnull?");
    env->rvfi_dii_trace.MEM.rvfi_mem_wdata[0] = cursor;
    cheri_debug_assert(pc_is_current(env));
     * Note: we set pc=0 since PC will have been saved prior to calling the
     * helper. Therefore, we don't need to recompute it from the generated code.
    raise_cheri_exception_if(env, cause, addr, CHERI_EXC_REGNUM_PCC);
    CheriCapExcCause cause;
    const cap_register_t *cap;

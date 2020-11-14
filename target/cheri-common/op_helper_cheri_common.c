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
    }
}
}
{
}
{
              /*instavail=*/true, GETPC());
}
{
                                        target_ulong rs))
    const cap_register_t *cbp = get_readonly_capreg(env, cb);
                       "Unknown permission bits set!");
    cap_register_t result = *cbp;
    result.cr_tag = 0;
        // The return capability should always be a sentry
            cap_make_sealed_entry(&result);
#ifdef TARGET_RISCV
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
void CHERI_HELPER_IMPL(cbuildcap(CPUArchState *env, uint32_t cd, uint32_t cb,
                                 uint32_t ct))
    cap_register_t result = *ctp;
    if (cb == 0) {
    const cap_register_t *cbp = get_capreg_0_is_ddc(env, cb);
    } else if (cap_get_base(ctp) < cap_get_base(cbp)) {
    } else if (cap_get_top_full(ctp) > cap_get_top_full(cbp)) {
    } else if (cap_get_base(ctp) > cap_get_top_full(ctp)) {
        // check for length < 0 - possible because cs2 might be untagged
        if (cap_is_sealed_entry(ctp)) {
            cap_make_sealed_entry(&derived);
            /* For reserved otypes we return a null-derived value. */
            update_capreg(env, cd, csp);
    } else if (conditional && !cap_is_unsealed(csp)) {
    } else if (conditional && !cap_cursor_in_bounds(ctp)) {
    } else if (!conditional && !cap_is_unsealed(csp)) {
    } else if (!conditional && !cap_cursor_in_bounds(ctp)) {
void CHERI_HELPER_IMPL(candaddr(CPUArchState *env, uint32_t cd, uint32_t cb,
    target_ulong cursor = get_capreg_cursor(env, cb);
    target_ulong target_addr = cursor & rt;
    cincoffset_impl(env, cd, cb, diff, GETPC(), OOB_INFO(csetoffset));
    // CFromPtr traps on cbp == NULL so we use reg0 as $ddc to save encoding
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
    return cap_check_common(CAP_PERM_LOAD | CAP_PERM_STORE, env, cb, offset,
target_ulong CHERI_HELPER_IMPL(cap_check_addr(CPUArchState *env,
        if (cap_is_unsealed(&tmp)) {
        CAP_cc(decompress_raw_ext)(*pesbt, *cursor, tag, lvbits, &ncd);
        tag = cheri_tag_prot_clear_or_trap(env, vaddr, cb, source, prot, retpc,
        if (tag) {
#if defined(TARGET_RISCV) && defined(CONFIG_RVFI_DII)
    env->rvfi_dii_trace.MEM.rvfi_mem_addr = vaddr;
    env->rvfi_dii_trace.MEM.rvfi_mem_rdata[0] = *cursor;
    target_ulong pesbt_for_mem = get_capreg_pesbt(env, cs) ^ CAP_MEM_XOR_MASK;
#ifdef CONFIG_DEBUG_TCG
    if (get_capreg_state(cheri_get_gpcrs(env), cs) == CREG_INTEGER) {
        tcg_debug_assert(pesbt_for_mem == 0 && "Integer values should have NULL PESBT");
        tcg_debug_assert(pesbt_for_mem == 0 && "Wrong value for cnull?");
        tcg_debug_assert(cursor == 0 && "Wrong value for cnull?");
        tcg_debug_assert(!tag && "Wrong value for cnull?");
    cheri_debug_assert(pc_is_current(env));
     * Note: we set pc=0 since PC will have been saved prior to calling the
     * helper. Therefore, we don't need to recompute it from the generated code.
    raise_cheri_exception_if(env, cause, addr, CHERI_EXC_REGNUM_PCC);
    CheriCapExcCause cause;

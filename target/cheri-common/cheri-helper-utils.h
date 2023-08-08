 */
}
#endif
    // Note: we can use a "stale" PCC value with an outdated cursor here since
    // we only really care about the bounds and permissions to derive the
    // resulting capability (e.g. auipcc or CGetPCCIncOffset).
    // If the result is not representable it will be untagged.
    return;
#endif
    if (cap_exactly_equal(pcc, src_cap) && new_pc == cap_get_cursor(pcc)) {
        if (!pcc->cr_tag || !cap_has_perms(pcc, CAP_PERM_EXECUTE) ||
            !cap_cursor_in_bounds(pcc)) {
            /* Warn about infinite trap loops instead of silently freezing. */
            error_report_once("Detected infinite trap loop due to invalid "
                              "exception handler: " PRINT_CAP_FMTSTR "\r",
                              PRINT_CAP_ARGS(pcc));
                     PRINT_CAP_ARGS(pcc));
    /*
     * Morello does not require ASR when executing ERET, it will just detag
     * the result. However, this helper is only used for MIPS/RISC-V.
    assert(cap_has_perms(pcc, CAP_ACCESS_SYS_REGS) &&
           "Attempting to return from exception without ASR in PCC");
     * On exception return we unseal sentry capabilities (if the address
     * matches).
        if (new_cursor == cap_get_cursor(pcc)) {
            return;
                         "addr: " PRINT_CAP_FMTSTR "\r",
        if (new_cursor == cap_get_cursor(pcc)) {
    uint32_t perms = CAP_PERM_STORE;
    if (get_capreg_tag(env, cs))
        perms |= CAP_PERM_STORE_CAP;
    } else if (MISSING_REQUIRED_PERM(CAP_PERM_LOAD_CAP)) {
        raise_cheri_exception_addr_wnr(env, CapEx_PermitLoadCapViolation, cb,

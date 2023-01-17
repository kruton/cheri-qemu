 */
    // Note: we can use a "stale" PCC value with an outdated cursor here since
    // we only really care about the bounds and permissions to derive the
    // resulting capability (e.g. auipcc or CGetPCCIncOffset).
    // If the result is not representable it will be untagged.
    /*
     * Morello does not require ASR when executing ERET, it will just detag
     * the result. However, this helper is only used for MIPS/RISC-V.
    assert(cap_has_perms(pcc, CAP_ACCESS_SYS_REGS) &&
           "Attempting to return from exception without ASR in PCC");
     * On exception return we unseal sentry capabilities (if the address
     * matches).
    uint32_t perms = CAP_PERM_STORE;
    if (get_capreg_tag(env, cs))
        perms |= CAP_PERM_STORE_CAP;
    } else if (MISSING_REQUIRED_PERM(CAP_PERM_LOAD_CAP)) {
        raise_cheri_exception_addr_wnr(env, CapEx_PermitLoadCapViolation, cb,

#endif
#else
{
}
}
static inline bool
is_cap_sealed(const cap_register_t *cp)
{
}
    switch(size) {
    default:
    } else {
    else
        return (target_ulong)0;
        return (target_ulong)0;
    if (!csp->cr_tag) {
    } else if (!cap_has_perms(csp, CAP_PERM_EXECUTE)) {
    switch (hwr) {
        break;
    case CP2HWR_KCC:
    case CP2HWR_KDC:
    case CP2HWR_EPCC:
    } else if (is_cap_sealed(cbp)) {
        do_raise_c0_exception(env, EXCP_AdEL, addr);
    } else if (is_cap_sealed(cbp)) {
    } else if (!cap_has_perms(cbp, CAP_PERM_STORE)) {
        // cheri_tag_invalidate(env, addr, size);
    } else if (!cap_has_perms(cbp, CAP_PERM_STORE_CAP)) {
    } else if (!cap_has_perms(cbp, CAP_PERM_STORE_LOCAL) && csp->cr_tag &&
    char name[8];
    cpu_fprintf(f, "DEBUG CAP COREID 0\n");
        // snprintf(name, sizeof(name), "C%02d", i);
        snprintf(name, sizeof(name), "REG %02d", i);
                        cpu_fprintf);
    cheri_dump_creg(&env->active_tc.CHWR.EPCC,       "HWREG 31 (EPCC)", "", f, cpu_fprintf);
    } else if (!cbp->cr_tag) {

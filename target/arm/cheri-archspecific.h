#define CAP_TAG_GET_MANY_SHFT 2
    }
    if (hostpc) {
        // AARCH's cpu_restore_state will reset syndrome, so don't use
        // raise_exception_ra here.
        CPUState *cs = env_cpu(env);
        cpu_restore_state(cs, hostpc);
    raise_cheri_exception_impl_if_wnr(env, CapEx_TLBNoStoreCap, cb, va, false,

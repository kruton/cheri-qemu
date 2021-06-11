    if (cheri_debugger_on_unrepresentable)
        do_raise_exception(env, EXCP_DEBUG, retpc);
#elif defined(TARGET_AARCH64)
        HELPER(exception_internal)(env, EXCP_DEBUG);
// Note: despite taking both CPUArchState and retpc, this function does not throw CPU
// exceptions. The retpc parameter is there purely for diagnostic reporting.
 static inline int64_t _howmuch_out_of_bounds(CPUArchState *env,

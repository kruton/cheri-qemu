        do_raise_exception(env, EXCP_DEBUG, retpc);
// Note: despite taking both CPUArchState and retpc, this function does not throw CPU
// exceptions. The retpc parameter is there purely for diagnostic reporting.
 static inline int64_t _howmuch_out_of_bounds(CPUArchState *env,

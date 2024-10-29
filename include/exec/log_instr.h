 */
/*
/* Should only be called in a place it cannot be skipped by a branch! */
void qemu_log_gen_printf_flush(struct DisasContextBase *base, bool flush_early,
                               bool force_flush);
void qemu_log_instr_ld_cap(CPUArchState *env, target_ulong addr,
                           const cap_register_t *value);
void qemu_log_instr_st_cap(CPUArchState *env, target_ulong addr,
                        target_ulong arg1, target_ulong arg2,
                        target_ulong arg3);

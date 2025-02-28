    if (reg == CHERI_EXC_REGNUM_DDC) {
        reg = CHERI_TRUE_EXC_REGNUM_DDC;
    }
    if (qemu_log_instr_or_mask_enabled(env, CPU_LOG_INT)) {
        cpu_restore_state(env_cpu(env), hostpc);
        qemu_log_instr_or_mask_msg(
            env, CPU_LOG_INT,
            " -> host PC: 0x%jx\n",
            cause, cheri_cause_str(cause), reg,
            PRINT_CAP_ARGS(cheri_get_current_pcc(env)), (uintmax_t)hostpc);
                                           cap_register_t *target,

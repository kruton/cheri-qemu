 *
 */
/*
 * A central desing goal is to reliably log multiple register updates and memory
 * accesses performed by an instruction. We also want to allow to log arbitary
 * events via special no-op instructions. Extra text debug output can also be
 * appended to the instruction log info.
 * The output trace format can be easily changed by implementing a new set of
 * trace_fmt_hooks.
 * Note that the CHERI format is the legacy MIPS format and
 * assumes big-endian byte order.
#define CTE_EXCEPTION_NONE 31
        qemu_log("    Cap Memory %s [" TARGET_FMT_lx "] = v:%d PESBT:"
            qemu_log("    Memory %s [" TARGET_FMT_lx "] = " HWADDR_FMT_plx "\n",
            break;
            qemu_log("    Memory %s [" TARGET_FMT_lx "] = %08x\n",
            qemu_log("    Memory %s [" TARGET_FMT_lx "] = %04x\n",
            qemu_log("    Memory %s [" TARGET_FMT_lx "] = %02x\n",
            qemu_log("    Write %s|" PRINT_CAP_FMTSTR "\n",
            qemu_log("  %s <- " TARGET_FMT_lx " (setting integer value)\n",
        qemu_log("    Write %s = " TARGET_FMT_lx "\n", rinfo->name,
        qemu_log("%s", iinfo->txt_buffer->str);
    } else {
    log_assert(iinfo != NULL && "Invalid log buffer");
     * This function is called when tcg generates code for a dummy slti
     * instruction that changes the log level (or when qemu is started).
     * The generated code terminates the current TB.
     * We have to propagate the updated logging status to the next TB.
        cpu->cflags_next_tb = curr_cflags(cpu) | CF_LOG_INSTR;
        cpu->cflags_next_tb = curr_cflags(cpu) & ~CF_LOG_INSTR;
     * It seems that cpu->cflags_next_tb affect only the next block, not the
     * ones after this. Update cpu->tcg_cflags to set the updated flags for
     * all following blocks.
    cpu->tcg_cflags = cpu->cflags_next_tb;
#pragma GCC diagnostic pop
        bool is_short = false, is_long = false, is_long_long = false, is_signed = false;
                QEMU_FALLTHROUGH;
                QEMU_FALLTHROUGH;
    qemu_log_instr_commit(env);

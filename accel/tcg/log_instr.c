 *
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
            qemu_log("    Memory %s [" TARGET_FMT_lx "] = %08x\n",
            qemu_log("    Memory %s [" TARGET_FMT_lx "] = %04x\n",
            qemu_log("    Memory %s [" TARGET_FMT_lx "] = %02x\n",
            qemu_log("    Write %s|" PRINT_CAP_FMTSTR "\n",
            qemu_log("  %s <- " TARGET_FMT_lx " (setting integer value)\n",
        qemu_log("    Write %s = " TARGET_FMT_lx "\n", rinfo->name,
        qemu_log("%s", iinfo->txt_buffer->str);
    log_assert(iinfo != NULL && "Invalid log buffer");
        bool is_short = false, is_long = false, is_long_long = false, is_signed = false;
    qemu_log_instr_commit(env);

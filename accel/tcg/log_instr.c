        qemu_log("    Cap Memory %s [" TARGET_FMT_lx "] = v:%d PESBT:"
            qemu_log("    Memory %s [" TARGET_FMT_lx "] = " HWADDR_FMT_plx "\n",
            qemu_log("    Memory %s [" TARGET_FMT_lx "] = %08x\n",
            qemu_log("    Memory %s [" TARGET_FMT_lx "] = %04x\n",
            qemu_log("    Memory %s [" TARGET_FMT_lx "] = %02x\n",
            qemu_log("    Write %s|" PRINT_CAP_FMTSTR "\n",
            qemu_log("  %s <- " TARGET_FMT_lx " (setting integer value)\n",
        qemu_log("    Write %s = " TARGET_FMT_lx "\n", rinfo->name,
        qemu_log("%s", iinfo->txt_buffer->str);

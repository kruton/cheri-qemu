    } else if (!cap_has_perms(csp, CAP_PERM_EXECUTE)) {
    char name[8];
    cpu_fprintf(f, "DEBUG CAP COREID 0\n");
        // snprintf(name, sizeof(name), "C%02d", i);
        snprintf(name, sizeof(name), "REG %02d", i);
                        cpu_fprintf);
    cheri_dump_creg(&env->active_tc.CHWR.EPCC,       "HWREG 31 (EPCC)", "", f, cpu_fprintf);

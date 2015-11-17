#endif
{
}
#else
static void simple_dump_state(CPUMIPSState *env, FILE *f,
                              fprintf_function cpu_fprintf)
    cpu_fprintf(f, "hi = 0x" TARGET_FMT_lx "    lo = 0x" TARGET_FMT_lx "\n",
            env->active_tc.HI[0], env->active_tc.LO[0]);
    cpu_fprintf(f, "                       ""    s0 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[16]);
    cpu_fprintf(f, "at = 0x" TARGET_FMT_lx "    s1 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[1], env->active_tc.gpr[17]);
    cpu_fprintf(f, "v0 = 0x" TARGET_FMT_lx "    s2 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[2], env->active_tc.gpr[18]);
    cpu_fprintf(f, "v1 = 0x" TARGET_FMT_lx "    s3 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[3], env->active_tc.gpr[19]);
    cpu_fprintf(f, "a0 = 0x" TARGET_FMT_lx "    s4 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[4], env->active_tc.gpr[20]);
    cpu_fprintf(f, "a1 = 0x" TARGET_FMT_lx "    s5 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[5], env->active_tc.gpr[21]);
    cpu_fprintf(f, "a2 = 0x" TARGET_FMT_lx "    s6 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[6], env->active_tc.gpr[22]);
    cpu_fprintf(f, "a3 = 0x" TARGET_FMT_lx "    s7 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[7], env->active_tc.gpr[23]);
    cpu_fprintf(f, "t0 = 0x" TARGET_FMT_lx "    t8 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[8], env->active_tc.gpr[24]);
    cpu_fprintf(f, "t1 = 0x" TARGET_FMT_lx "    t9 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[9], env->active_tc.gpr[25]);
    cpu_fprintf(f, "t2 = 0x" TARGET_FMT_lx "    k0 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[10], env->active_tc.gpr[26]);
    cpu_fprintf(f, "t3 = 0x" TARGET_FMT_lx "    k1 = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[11], env->active_tc.gpr[27]);
    cpu_fprintf(f, "t4 = 0x" TARGET_FMT_lx "    gp = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[12], env->active_tc.gpr[28]);
    cpu_fprintf(f, "t5 = 0x" TARGET_FMT_lx "    sp = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[13], env->active_tc.gpr[29]);
    cpu_fprintf(f, "t6 = 0x" TARGET_FMT_lx "    fp = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[14], env->active_tc.gpr[30]);
    cpu_fprintf(f, "t7 = 0x" TARGET_FMT_lx "    ra = 0x" TARGET_FMT_lx "\n",
            env->active_tc.gpr[15], env->active_tc.gpr[31]);
    cpu_fprintf(f, "DEBUG MIPS REG 00 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[0]);

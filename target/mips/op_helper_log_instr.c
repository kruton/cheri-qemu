 *
 */
#endif
/*
 */
{
}
/*
 */
/*
 */
{
}
{
}
/*
            break;
            break;
        default:
            break;
#else
static void simple_dump_state(CPUMIPSState *env, FILE *f,
                              fprintf_function cpu_fprintf)
/* gxemul compat:
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
*/
    /* sim compatible register dump: */
    cpu_fprintf(f, "DEBUG MIPS COREID 0\n");
    cpu_fprintf(f, "DEBUG MIPS REG 00 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[0]);
    cpu_fprintf(f, "DEBUG MIPS REG 01 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[1]);
    cpu_fprintf(f, "DEBUG MIPS REG 02 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[2]);
    cpu_fprintf(f, "DEBUG MIPS REG 03 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[3]);
    cpu_fprintf(f, "DEBUG MIPS REG 04 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[4]);
    cpu_fprintf(f, "DEBUG MIPS REG 05 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[5]);
    cpu_fprintf(f, "DEBUG MIPS REG 06 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[6]);
    cpu_fprintf(f, "DEBUG MIPS REG 07 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[7]);
    cpu_fprintf(f, "DEBUG MIPS REG 08 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[8]);
    cpu_fprintf(f, "DEBUG MIPS REG 09 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[9]);
    cpu_fprintf(f, "DEBUG MIPS REG 10 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[10]);
    cpu_fprintf(f, "DEBUG MIPS REG 11 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[11]);
    cpu_fprintf(f, "DEBUG MIPS REG 12 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[12]);
    cpu_fprintf(f, "DEBUG MIPS REG 13 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[13]);
    cpu_fprintf(f, "DEBUG MIPS REG 14 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[14]);
    cpu_fprintf(f, "DEBUG MIPS REG 15 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[15]);
    cpu_fprintf(f, "DEBUG MIPS REG 16 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[16]);
    cpu_fprintf(f, "DEBUG MIPS REG 17 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[17]);
    cpu_fprintf(f, "DEBUG MIPS REG 18 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[18]);
    cpu_fprintf(f, "DEBUG MIPS REG 19 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[19]);
    cpu_fprintf(f, "DEBUG MIPS REG 20 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[20]);
    cpu_fprintf(f, "DEBUG MIPS REG 21 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[21]);
    cpu_fprintf(f, "DEBUG MIPS REG 22 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[22]);
    cpu_fprintf(f, "DEBUG MIPS REG 23 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[23]);
    cpu_fprintf(f, "DEBUG MIPS REG 24 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[24]);
    cpu_fprintf(f, "DEBUG MIPS REG 25 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[25]);
    cpu_fprintf(f, "DEBUG MIPS REG 26 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[26]);
    cpu_fprintf(f, "DEBUG MIPS REG 27 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[27]);
    cpu_fprintf(f, "DEBUG MIPS REG 28 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[28]);
    cpu_fprintf(f, "DEBUG MIPS REG 29 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[29]);
    cpu_fprintf(f, "DEBUG MIPS REG 30 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[30]);
    cpu_fprintf(f, "DEBUG MIPS REG 31 0x" TARGET_FMT_lx "\n", env->active_tc.gpr[31]);

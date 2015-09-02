{
    }
    TCGv t0 = tcg_temp_new();
    gen_load_gpr(t0, rt);
        break;
        break;
    default:
static void gen_mtc2(DisasContext *ctx, TCGv arg, int reg, int sel)
    const char *rn = "invalid";
    switch (reg) {
    case 0:
        switch (sel) {
        case 6:
            gen_helper_mtc2_dumpcstate(tcg_env, arg);
            rn = "capdump";
            goto out;
            goto cp2_unimplemented;
out:
    (void)rn; /* avoid a compiler warning */
    LOG_DISAS("mtc2 %s (reg %d sel %d)\n", rn, reg, sel);
    /* For simplicity assume that all writes can cause interrupts.  */
    if (ctx->base.tb->cflags & CF_USE_ICOUNT) {
    return;
cp2_unimplemented:
#if defined(TARGET_CHERI)
static void gen_cp2 (DisasContext *ctx, uint32_t opc, int r16, int r11, int r6)
    const char *opn = "cp2inst";
                gen_mtc2(ctx, t0, r11, ctx->opcode & 0x7);
            opn = "mtc2";
    (void)opn; /* avoid a compiler warning */
    MIPS_INVAL(opn);
    generate_exception (ctx, EXCP_RI);
#endif /* TARGET_CHERI */

{
    }
}
static inline int32_t sign_extend(int32_t x, int offset)
{
    int32_t const mask = 1U << (offset - 1);
    return (x ^ mask) - mask;
}
{
}
static inline void generate_ccall(int32_t cs, int32_t cb)
{
    TCGv_i32 tcs = tcg_constant_i32(cs);
    TCGv_i32 tcb = tcg_constant_i32(cb);
    gen_helper_ccall(tcg_env, tcs, tcb);
}
{
        generate_exception(ctx, EXCP_RI);
        TCGv_i32 tcs = tcg_constant_i32(cs);
        TCGv_i32 tcb = tcg_constant_i32(cb);
    }
}
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv t0 = tcg_temp_new();
    gen_load_gpr(t0, rt);
}
{
        TCGv_i32 tcb = tcg_constant_i32(cb);
        TCGv_i32 toffset = tcg_constant_i32(offset);
        ctx->btarget = ctx->base.pc_next + 4 * offset + 4;
        /* Set conditional branch and branch delay slot flags */
        ctx->hflags |= (MIPS_HFLAG_BC | MIPS_HFLAG_BDS32);
    }
}
{
}
{
}
static inline void generate_cbts(DisasContext *ctx, int32_t cb, int32_t offset)
{
}
static inline void generate_cbtu(DisasContext *ctx, int32_t cb, int32_t offset)
{
}
{
        TCGv_i32 tcd = tcg_constant_i32(cd);
        TCGv_i32 tcb = tcg_constant_i32(cb);
    }
}
{
        TCGv_i32 tcb = tcg_constant_i32(cb);
    }
}
static inline void generate_ccheckperm(int32_t cs, int32_t rt)
{
    TCGv t0 = tcg_temp_new();
    gen_load_gpr(t0, rt);
    gen_helper_ccheckperm(tcg_env, tcs, t0);
}
static inline void generate_cchecktype(int32_t cs, int32_t cb)
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    gen_helper_cchecktype(tcg_env, tcs, tcb);
}
static inline void generate_ccleartag(int32_t cd, int32_t cb)
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tcd = tcg_constant_i32(cd);
    gen_helper_ccleartag(tcg_env, tcd, tcb);
}
static inline void generate_cfromptr(int32_t cd, int32_t cb, int32_t rt)
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv t0 = tcg_temp_new();
    gen_load_gpr(t0, rt);
    gen_helper_cfromptr(tcg_env, tcd, tcb, t0);
}
{
    TCGv t0 = tcg_temp_new();
    gen_store_gpr(t0, rd);
}
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
}
{
    gen_helper_cgetcause(t0, tcg_env);
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
    gen_helper_cgetpcc(tcg_env, tcd);
    TCGv_i32 tcd = tcg_constant_i32(cd);
static inline void generate_cincoffset(int32_t cd, int32_t cb, int32_t rt)
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tcd = tcg_constant_i32(cd);
    gen_helper_cincoffset(tcg_env, tcd, tcb, t0);
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
    gen_helper_cincoffset(tcg_env, tcd, tcs, t0);
static inline void generate_cmove(int32_t cd, int32_t cs)
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
static inline void generate_cbuildcap(int32_t cd, int32_t cb, int32_t ct)
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tct = tcg_constant_i32(ct);
static inline void generate_ccseal(int32_t cd, int32_t cs, int32_t ct)
    TCGv_i32 tct = tcg_constant_i32(ct);
static inline void generate_ccopytype(int32_t cd, int32_t cb, int32_t ct)
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tct = tcg_constant_i32(ct);
    TCGv_i32 tcb = tcg_constant_i32(cb);
static inline void generate_creturn(void)
static inline void generate_cseal(int32_t cd, int32_t cb, int32_t ct)
    TCGv_i32 tcb = tcg_constant_i32(cb);
    gen_helper_cseal(tcg_env, tcd, tcb, tct);
static inline void generate_csetbounds(int32_t cd, int32_t cb, int32_t rt)
    TCGv_i32 tcb = tcg_constant_i32(cb);
    gen_helper_csetbounds(tcg_env, tcd, tcb, t0);
static inline void generate_candaddr(int32_t cd, int32_t cb, int32_t rt)
    TCGv_i32 tcb = tcg_constant_i32(cb);
    gen_helper_candaddr(tcg_env, tcd, tcb, t0);
static inline void generate_csetaddr(int32_t cd, int32_t cb, int32_t rt)
    gen_helper_csetaddr(tcg_env, tcd, tcb, t0);
    TCGv t1 = tcg_temp_new();
static inline void generate_csetboundsexact(int32_t cd, int32_t cb, int32_t rt)
    gen_helper_csetboundsexact(tcg_env, tcd, tcb, t0);
    gen_helper_csetbounds(tcg_env, tcd, tcb, t0);
static inline void generate_csetcause(int32_t rd)
    gen_helper_csetcause(tcg_env, t0);
static inline void generate_csetoffset(int32_t cd, int32_t cb, int32_t rt)
    gen_helper_csetoffset(tcg_env, tcd, tcb, t0);
    gen_helper_ctoptr(t0, tcg_env, tcb, tct);
static inline void generate_cunseal(int32_t cd, int32_t cb, int32_t ct)
static inline int generate_cclearregs(DisasContext *ctx, int32_t regset, int32_t mask)
    int i;
    TCGv t0;
    TCGv_i32 tcr0;
    switch(regset) {
    case 0: /* ClearLO */
        if (!mask)
            return 0;
        t0 = tcg_temp_new();
        tcg_gen_movi_tl(t0, 0);
        mask = mask >> 1; /* Skip R0, the zero register */
        for(i = 1; i < 16; i++) {
            if (mask & 0x1)
                gen_store_gpr(t0, i);
            mask = mask >> 1;
        break;
    case 1: /* ClearHi */
        for(i = 16; i < 32; i++) {
        break;
    case 2: /* CClearLO */
        tcr0 = tcg_constant_i32(mask);
        gen_helper_cclearreg(tcg_env, tcr0);
        break;
    case 3: /* CClearHi */
        break;
    default:
        return 1; /* Invalid */
    gen_helper_ceq(t0, tcg_env, tcb, tct);
    gen_helper_cne(t0, tcg_env, tcb, tct);
static inline void generate_clt(DisasContext *ctx, int32_t rd, int32_t cb,
    gen_helper_clt(t0, tcg_env, tcb, tct);
    gen_helper_cle(t0, tcg_env, tcb, tct);
static inline void generate_cltu(DisasContext *ctx, int32_t rd, int32_t cb,
    gen_helper_cltu(t0, tcg_env, tcb, tct);
    gen_helper_cleu(t0, tcg_env, tcb, tct);
    x = x & ((1U << 8) - 1);
/* Load Via Capability Register */
    gen_load_gpr(t1, rt);
    TCGv_i32 tlen = tcg_constant_i32(len);
#define GEN_CAP_CHECK_STORE(addr, offset, len) \
static inline void generate_ccheck_load_pcrel(TCGv addr, int32_t len)
    gen_helper_ccheck_load_pcrel(tcg_env, addr, tlen);
static void gen_mtc2(DisasContext *ctx, TCGv arg, int reg, int sel)
    const char *rn = "invalid";
    switch (reg) {
    case 0:
        switch (sel) {
        case 6:
            gen_helper_mtc2_dumpcstate(tcg_env, arg);
            rn = "capdump";
            goto out;
        default:
            goto cp2_unimplemented;
    default:
out:
    (void)rn; /* avoid a compiler warning */
    LOG_DISAS("mtc2 %s (reg %d sel %d)\n", rn, reg, sel);
    /* For simplicity assume that all writes can cause interrupts.  */
    if (ctx->base.tb->cflags & CF_USE_ICOUNT) {
    return;
cp2_unimplemented:
#else /* ! TARGET_CHERI */
#endif /* ! TARGET_CHERI */
#if defined(TARGET_CHERI)
static void gen_cp2 (DisasContext *ctx, uint32_t opc, int r16, int r11, int r6)
    const char *opn = "cp2inst";
    switch (MASK_CP2(opc)) {
            opn = "cgetperm";
            break;
            opn = "cgettype";
            break;
            opn = "cgetbase";
            break;
            opn = "cgetlen";
            break;
            opn = "cgetcause";
            break;
            opn = "cgettag";
            break;
        case OPC_CGETSEALED:        /* 0x06 */
            opn = "cgetsealed";
            opn = "cgetpcc";
            opn = "cseal";
            opn = "cunseal";
            opn = "candperm";
            opn = "csetoffset";
            opn = "csetbounds";
            opn = "cincoffset";
            opn = "ctoptr";
            opn = "ceq";
            opn = "cne";
            opn = "clt";
            opn = "cle";
            opn = "cltu";
            opn = "cleu";
                opn = "cgetoffset";
                opn = "ccheckperm";
                opn = "cchecktype";
                opn = "ccleartag";
                opn = "cjalr";
                    opn = "csetcause";
                    opn = "cjr";
                    goto invalid;
                goto invalid;
            opn = "cget";
            goto invalid;
    case OPC_CSETBOUNDS: /* 0x01 */
    case OPC_CSEAL:  /* 0x02 */
    case OPC_CUNSEAL: /* 0x03 */
    case OPC_CMISC: /* 0x04 */
        switch(MASK_CAP3(opc)) {
        case OPC_CANDPERM: /* 0x0 */
        case OPC_CSETCAUSE: /* 0x4 */
        case OPC_CCLEARTAG: /* 0x5 */
        case OPC_MTC2SEL6: /* 0x6 */
                gen_mtc2(ctx, t0, r11, ctx->opcode & 0x7);
            opn = "mtc2";
            opn = "cmisc";
            goto invalid;
    case OPC_CCALL: /* 0x05 */
            opn = "creturn";
            opn = "ccall";
            goto invalid;
    case OPC_CRETURN: /* 0x06 */
    case OPC_CJALR: /* 0x07 */
    case OPC_CJR: /* 0x08 */
    case OPC_CBTU: /* 0x09 */
        opn = "cbtu";
        generate_cbtu(ctx, r16, (int16_t)(ctx->opcode));
    case OPC_CBTS: /* 0x0a */
        opn = "cbts";
        generate_cbts(ctx, r16, (int16_t)(ctx->opcode));
    case OPC_CCHECK: /* 0x0b */
        case OPC_CCHECKPERM: /* 0x0 */
        case OPC_CCHECKTYPE: /* 0x1 */
            opn = "ccheck";
            goto invalid;
    case OPC_CTOPTR: /* 0x0c */
    case OPC_COFFSET: /* 0x0d */
        case OPC_CINCOFFSET: /* 0x0 */
        case OPC_CSETOFFSET: /* 0x1 */
        case OPC_CGETOFFSET: /* 0x2 */
            opn = "coffset";
            goto invalid;
    case OPC_CPTRCMP: /* 0x0e */
        case OPC_CEQ:  /* 0x0 */
        case OPC_CNE:  /* 0x1 */
        case OPC_CLT:  /* 0x2 */
        case OPC_CLE:  /* 0x3 */
        case OPC_CLTU: /* 0x4 */
        case OPC_CLEU: /* 0x5 */
            opn = "cptrcmp";
    case OPC_CCLEARREGS: /* 0x0f */
        opn = "cclearregs";
    case OPC_CLL:   /* 0x10 */
        switch(MASK_CAP4(opc)) {
        case OPC_CSCB: /* 0x0 */
            opn = "cscb";
        case OPC_CSCH: /* 0x1 */
            opn = "csch";
        case OPC_CSCW: /* 0x2 */
            opn = "cscw";
        case OPC_CSCD: /* 0x3 */
            opn = "cscd";
        case OPC_CSCC: /* 0x7 */
        case OPC_CLLB: /* 0xc */
            opn = "cllb";
        case OPC_CLLH: /* 0xd */
            opn = "cllh";
        case OPC_CLLW: /* 0xe */
            opn = "cllw";
        case OPC_CLLD: /* 0xb */
            opn = "clld";
        case OPC_CLLBU: /* 0x8 */
                                     MO_UB | ctx->default_tcg_memop_mask,
            opn = "cllbu";
        case OPC_CLLHU: /* 0x9 */
            opn = "cllhu";
        case OPC_CLLWU: /* 0xa */
            opn = "cllwu";
            opn = "cll";
    (void)opn; /* avoid a compiler warning */
    return;
invalid:
    MIPS_INVAL(opn);
    generate_exception (ctx, EXCP_RI);
#endif /* TARGET_CHERI */

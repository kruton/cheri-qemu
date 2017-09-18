 */
/* Verify that the processor is running with CHERI instructions enabled. */
static inline void check_cop2x(DisasContext *ctx)
{
    if (unlikely(!(ctx->hflags & MIPS_HFLAG_COP2X))) {
        generate_exception_err(ctx, EXCP_CpU, 2);
    }
        save_cpu_state(ctx, 0);
}
static inline int32_t sign_extend(int32_t x, int offset)
{
    int32_t const mask = 1U << (offset - 1);
    x = x & ((1U << offset) - 1);
    return (x ^ mask) - mask;
}
/*
static inline bool is_cop2x_enabled(DisasContext *ctx)
{
    return (likely(ctx->hflags & MIPS_HFLAG_COP2X));
}
static inline void generate_ccall(int32_t cs, int32_t cb)
{
    TCGv_i32 tcs = tcg_constant_i32(cs);
    TCGv_i32 tcb = tcg_constant_i32(cb);
    gen_helper_ccall(tcg_env, tcs, tcb);
}
{
    if (ctx->hflags & MIPS_HFLAG_BMASK) {
#ifdef MIPS_DEBUG_DISAS
        LOG_DISAS("Branch in delay / forbidden slot at PC 0x"
                  TARGET_FMT_lx "\n", ctx->base.pc_next);
#endif
        generate_exception(ctx, EXCP_RI);
    } else {
        TCGv_i32 tcs = tcg_constant_i32(cs);
        TCGv_i32 tcb = tcg_constant_i32(cb);
            gen_helper_ccall_notrap2(btarget, tcg_env, tcs, tcb);
        ctx->hflags |= (MIPS_HFLAG_BRCCALL);
        save_cpu_state(ctx, 0);
    }
}
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv t0 = tcg_temp_new();
    gen_load_gpr(t0, rt);
}
{
    if (ctx->hflags & MIPS_HFLAG_BMASK) {
#ifdef MIPS_DEBUG_DISAS
        LOG_DISAS("Branch in delay / forbidden slot at PC 0x"
                TARGET_FMT_lx "\n", ctx->base.pc_next);
#endif
        generate_exception(ctx, EXCP_RI);
    } else {
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
static inline void generate_cjalr(DisasContext *ctx, int32_t cd, int32_t cb)
{
        generate_exception(ctx, EXCP_RI);
        TCGv_i32 tcd = tcg_constant_i32(cd);
        TCGv_i32 tcb = tcg_constant_i32(cb);
        TCGv toff = tcg_constant_tl(0);
        /* Set branch and delay slot flags */
        ctx->hflags |= (MIPS_HFLAG_BRC | MIPS_HFLAG_BDS32);
        /* Save capability register index that is new PCC */
        // ctx->btcr = cb;
    }
}
static inline void generate_cjr(DisasContext *ctx, int32_t cb)
{
        generate_exception(ctx, EXCP_RI);
        TCGv_i32 tcb = tcg_constant_i32(cb);
        gen_helper_cjr(btarget, tcg_env, tcb);
        /* Set branch and delay slot flags */
        ctx->hflags |= (MIPS_HFLAG_BRC | MIPS_HFLAG_BDS32);
        /* Save capability register index that is new PCC */
        // ctx->btcr = cb;
    }
}
static inline void generate_ccheckperm(int32_t cs, int32_t rt)
{
    TCGv_i32 tcs = tcg_constant_i32(cs);
    TCGv t0 = tcg_temp_new();
    gen_load_gpr(t0, rt);
    gen_helper_ccheckperm(tcg_env, tcs, t0);
}
static inline void generate_cchecktype(int32_t cs, int32_t cb)
{
    TCGv_i32 tcs = tcg_constant_i32(cs);
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
    TCGv_i32 tcs = tcg_constant_i32(cs);
    TCGv t0 = tcg_temp_new();
    gen_store_gpr(t0, rd);
}
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv ttags = tcg_temp_new();
}
{
    TCGv t0 = tcg_temp_new();
    gen_helper_cgetcause(t0, tcg_env);
    gen_store_gpr(t0, rd);
}
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
    gen_helper_cgetpcc(tcg_env, tcd);
}
static inline void
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv t0 = tcg_temp_new();
}
static inline void generate_cincoffset(int32_t cd, int32_t cb, int32_t rt)
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv t0 = tcg_temp_new();
    gen_load_gpr(t0, rt);
    gen_helper_cincoffset(tcg_env, tcd, tcb, t0);
}
static inline void generate_cincoffset_imm(int32_t cd, int32_t cs, int32_t increment)
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv_i32 tcs = tcg_constant_i32(cs);
    TCGv t0 = tcg_temp_new();
    gen_helper_cincoffset(tcg_env, tcd, tcs, t0);
}
static inline void generate_cmove(int32_t cd, int32_t cs)
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv_i32 tcs = tcg_constant_i32(cs);
}
static inline void generate_cmovz(int32_t cd, int32_t cs, int32_t rs)
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv t0 = tcg_temp_new();
    gen_load_gpr(t0, rs);
    gen_helper_cmovz(tcg_env, tcd, tcs, t0);
}
static inline void generate_cmovn(int32_t cd, int32_t cs, int32_t rs)
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv t0 = tcg_temp_new();
    gen_load_gpr(t0, rs);
    gen_helper_cmovn(tcg_env, tcd, tcs, t0);
}
static inline void generate_cbuildcap(int32_t cd, int32_t cb, int32_t ct)
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tct = tcg_constant_i32(ct);
}
static inline void generate_ccseal(int32_t cd, int32_t cs, int32_t ct)
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv_i32 tct = tcg_constant_i32(ct);
    gen_helper_ccseal(tcg_env, tcd, tcs, tct);
}
static inline void generate_ccopytype(int32_t cd, int32_t cb, int32_t ct)
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tct = tcg_constant_i32(ct);
{
    TCGv t0 = tcg_temp_new();
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tct = tcg_constant_i32(ct);
    gen_helper_ctestsubset(t0, tcg_env, tcb, tct);
    gen_store_gpr(t0, rd);
static inline void generate_creturn(void)
{
static inline void generate_cseal(int32_t cd, int32_t cb, int32_t ct)
{
    TCGv_i32 tcd = tcg_constant_i32(cd);
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tct = tcg_constant_i32(ct);
    gen_helper_cseal(tcg_env, tcd, tcb, tct);
static inline void generate_csetbounds(int32_t cd, int32_t cb, int32_t rt)
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv t0 = tcg_temp_new();
    gen_helper_csetbounds(tcg_env, tcd, tcb, t0);
static inline void generate_candaddr(int32_t cd, int32_t cb, int32_t rt)
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    gen_helper_candaddr(tcg_env, tcd, tcb, t0);
static inline void generate_csetaddr(int32_t cd, int32_t cb, int32_t rt)
    TCGv_i32 tcb = tcg_constant_i32(cb);
    gen_helper_csetaddr(tcg_env, tcd, tcb, t0);
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv t1 = tcg_temp_new();
    gen_store_gpr(t1, rd);
static inline void generate_csetboundsexact(int32_t cd, int32_t cb, int32_t rt)
    TCGv_i32 tcb = tcg_constant_i32(cb);
    gen_helper_csetboundsexact(tcg_env, tcd, tcb, t0);
static inline void generate_csetbounds_imm(int32_t cd, int32_t cb, int32_t length)
    TCGv_i32 tcb = tcg_constant_i32(cb);
    tcg_gen_movi_tl(t0, length);
    gen_helper_csetbounds(tcg_env, tcd, tcb, t0);
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tct = tcg_constant_i32(ct);
    gen_helper_csub(t0, tcg_env, tcb, tct);
    gen_store_gpr(t0, rd);
static inline void generate_csetcause(int32_t rd)
    gen_load_gpr(t0, rd);
    gen_helper_csetcause(tcg_env, t0);
static inline void generate_csetoffset(int32_t cd, int32_t cb, int32_t rt)
    gen_helper_csetoffset(tcg_env, tcd, tcb, t0);
    gen_helper_ctoptr(t0, tcg_env, tcb, tct);
    gen_store_gpr(t0, rd);
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
        }
        break;
    case 1: /* ClearHi */
        tcg_gen_movi_tl(t0, 0);
        for(i = 16; i < 32; i++) {
        }
        break;
    case 2: /* CClearLO */
        tcr0 = tcg_constant_i32(mask);
        gen_helper_cclearreg(tcg_env, tcr0);
        break;
    case 3: /* CClearHi */
        break;
    default:
        return 1; /* Invalid */
    }
}
static inline void generate_ceq(DisasContext *ctx, int32_t rd, int32_t cb,
                                int32_t ct)
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv_i32 tct = tcg_constant_i32(ct);
    TCGv t0 = tcg_temp_new();
    gen_helper_ceq(t0, tcg_env, tcb, tct);
    gen_store_gpr(t0, rd);
}
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv t0 = tcg_temp_new();
    gen_helper_cne(t0, tcg_env, tcb, tct);
    gen_store_gpr(t0, rd);
}
static inline void generate_clt(DisasContext *ctx, int32_t rd, int32_t cb,
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv t0 = tcg_temp_new();
    gen_helper_clt(t0, tcg_env, tcb, tct);
    gen_store_gpr(t0, rd);
static inline void generate_cle(DisasContext *ctx, int32_t rd, int32_t cb,
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv t0 = tcg_temp_new();
    gen_helper_cle(t0, tcg_env, tcb, tct);
    gen_store_gpr(t0, rd);
static inline void generate_cltu(DisasContext *ctx, int32_t rd, int32_t cb,
{
    TCGv_i32 tcb = tcg_constant_i32(cb);
    TCGv t0 = tcg_temp_new();
    gen_helper_cltu(t0, tcg_env, tcb, tct);
static inline void generate_cleu(DisasContext *ctx, int32_t rd, int32_t cb,
    gen_helper_cleu(t0, tcg_env, tcb, tct);
    tcg_gen_xori_i64(t0, t0, 1);
    x = x & ((1U << 8) - 1);
    return (x ^ mask) - mask;
/* Load Via Capability Register */
    TCGv t1 = tcg_temp_new();
    gen_load_gpr(t1, rt);
    gen_store_gpr(t1, rd);
    check_cop2x(ctx);
    gen_helper_cloadlinked(taddr, tcg_env, tcb, tlen);
/*
 *
 */
    TCGv_i32 tlen = tcg_constant_i32(len);
    gen_helper_cstorecond(taddr, tcg_env, tcb, tlen);
    check_cop2x(ctx);
    TCGLabel *l1 = gen_new_label();
    /* Write rs to memory. */
    gen_load_gpr(t0, rs);
    gen_set_label(l1);
static inline void generate_cstore(DisasContext *ctx, int32_t rs, int32_t cb,
    x = x & ((1U << bits) - 1);
static inline void generate_clc(DisasContext *ctx, int32_t cd, int32_t cb,
    TCGv_i32 tcd = tcg_constant_i32(cd);
        TCGv taddr = tcg_temp_new();
        tcg_gen_add_tl(taddr, taddr, toffset);
static inline void generate_cllc(DisasContext *ctx, int32_t cd, int32_t cb)
    TCGv_i32 tcd = tcg_constant_i32(cd);
static inline void generate_csc(DisasContext *ctx, int32_t cs, int32_t cb,
    TCGv_i32 tcs = tcg_constant_i32(cs);
        TCGv taddr = tcg_temp_new();
        tcg_gen_add_tl(taddr, taddr, toffset);
static inline void generate_cscc(DisasContext *ctx, int32_t cs, int32_t cb,
        int32_t rd)
    TCGv_i32 tcs = tcg_constant_i32(cs);
    /* Check the cap registers and compute the address. */
#define GEN_CAP_CHECK_STORE(addr, offset, len) \
    generate_ccheck_store(addr, offset, len)
static inline void generate_ccheck_load_right(TCGv_cap_checked_ptr addr, TCGv offset, int32_t len)
    TCGv_i32 tlen = tcg_constant_i32(len);
    gen_helper_ccheck_load_right(addr, tcg_env, offset, tlen);
static inline void generate_ccheck_load_pcrel(TCGv addr, int32_t len)
    TCGv_i32 tlen = tcg_constant_i32(len);
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
        switch(MASK_CAP6(opc)) {
        case OPC_CGETPERM:          /* 0x00 */
            opn = "cgetperm";
            break;
        case OPC_CGETTYPE:          /* 0x01 */
            opn = "cgettype";
            break;
        case OPC_CGETBASE:          /* 0x02 */
            opn = "cgetbase";
            break;
        case OPC_CGETLEN:           /* 0x03 */
            opn = "cgetlen";
            break;
        case OPC_CGETCAUSE:         /* 0x04 */
            check_cop2x(ctx);
            opn = "cgetcause";
            break;
        case OPC_CGETTAG:           /* 0x05 */
            opn = "cgettag";
            break;
        case OPC_CGETSEALED:        /* 0x06 */
            opn = "cgetsealed";
            break;
        case OPC_CGETPCC:           /* 0x07 */
            check_cop2x(ctx);
            generate_cgetpcc(ctx, r11);
            opn = "cgetpcc";
            break;
                                    /* 0x08 */
        case OPC_CSETBOUNDSEXACT:   /* 0x09 */
            check_cop2x(ctx);
            generate_csetboundsexact(r16, r11, r6);
            opn = "csetboundsexact";
            break;
        case OPC_CSUB:              /* 0x0a */
            check_cop2x(ctx);
            generate_csub(ctx, r16, r11, r6);
            opn = "csub";
            break;
        case OPC_CSEAL_NI: /* 0x0b */
            check_cop2x(ctx);
            generate_cseal(r16, r11, r6);
            opn = "cseal";
            break;
        case OPC_CUNSEAL_NI: /* 0x0c */
            check_cop2x(ctx);
            generate_cunseal(r16, r11, r6);
            opn = "cunseal";
            break;
        case OPC_CANDPERM_NI: /* 0x0d */
            opn = "candperm";
            break;
        case OPC_CSETOFFSET_NI: /* 0x0f */
            check_cop2x(ctx);
            generate_csetoffset(r16, r11, r6);
            opn = "csetoffset";
        case OPC_CSETBOUNDS_NI: /* 0x10 */
            generate_csetbounds(r16, r11, r6);
            opn = "csetbounds";
        case OPC_CINCOFFSET_NI: /* 0x11 */
            generate_cincoffset(r16, r11, r6);
            opn = "cincoffset";
        case OPC_CTOPTR_NI: /* 0x12 */
            opn = "ctoptr";
        case OPC_CFROMPTR_NI: /* 0x13 */
            generate_cfromptr(r16, r11, r6);
            opn = "cfromptr";
        case OPC_CEQ_NI: /* 0x14 */
            opn = "ceq";
        case OPC_CNE_NI: /* 0x15 */
            opn = "cne";
        case OPC_CLT_NI: /* 0x16 */
            opn = "clt";
        case OPC_CLE_NI: /* 0x17 */
            opn = "cle";
        case OPC_CLTU_NI: /* 0x18 */
            generate_cltu(ctx, r16, r11, r6);
            opn = "cltu";
        case OPC_CLEU_NI: /* 0x19 */
            generate_cleu(ctx, r16, r11, r6);
            opn = "cleu";
        case OPC_CEXEQ_NI: /* 0x1a */
            generate_cexeq(ctx, r16, r11, r6);
            opn = "cexeq";
        case OPC_CMOVZ_NI: /* 0x1b */
            generate_cmovz(r16, r11, r6);
            opn = "cmovz";
        case OPC_CMOVN_NI: /* 0x1c */
            generate_cmovn(r16, r11, r6);
            opn = "cmovn";
            generate_cnexeq(ctx, r16, r11, r6);
            opn = "cnexeq";
            generate_candaddr(r16, r11, r6);
        /* Two-operand cap instructions. */
        case OPC_C2OPERAND_NI:         /* 0x3f */
            switch(MASK_CAP7(opc)) {
            case OPC_CGETPERM_NI:   /* 0x00 << 6 */
                opn = "cgetperm";
            case OPC_CGETTYPE_NI:   /* 0x01 << 6 */
                opn = "cgettype";
            case OPC_CGETBASE_NI:   /* 0x02 << 6 */
                opn = "cgetbase";
            case OPC_CGETLEN_NI:    /* 0x03 << 6 */
                opn = "cgetlen";
            case OPC_CGETTAG_NI:    /* 0x04 << 6 */
                opn = "cgettag";
            case OPC_CGETSEALED_NI: /* 0x05 << 6 */
                opn = "cgetsealed";
            case OPC_CGETOFFSET_NI: /* 0x06 << 6 */
                opn = "cgetoffset";
            case OPC_CGETPCCSETOFF_NI: /* 0x07 << 6 */
                opn = "cgetpccsetoffset";
            case OPC_CCHECKPERM_NI:    /* 0x08 << 6 */
                generate_ccheckperm(r16, r11);
                opn = "ccheckperm";
            case OPC_CCHECKTYPE_NI:    /* 0x09 << 6 */
                generate_cchecktype(r16, r11);
                opn = "cchecktype";
            case OPC_CMOVE_NI:      /* 0x0a << 6 */
                generate_cmove(r16, r11);
                opn = "cmove";
            case OPC_CCLEARTAG_NI:  /* 0x0b << 6 */
                generate_ccleartag(r16, r11);
                opn = "ccleartag";
            case OPC_CJALR_NI:      /* 0x0c << 6 */
                generate_cjalr(ctx, r16, r11);
                opn = "cjalr";
            case OPC_CRAP_NI:   /* 0x10 << 6 */
                TCGv t1 = tcg_temp_new();
                gen_load_gpr(t0, r11);
                TCGv t1 = tcg_temp_new();
                gen_load_gpr(t0, r11);
            /* One-operand cap instructions. */
            case OPC_C1OPERAND_NI:     /* 0x1f << 6 */
                switch(MASK_CAP8(opc)) {
                case OPC_CGETPCC_NI:    /* 0x00 << 11 */
                    generate_cgetpcc(ctx, r16);
                    opn = "cgetpcc";
                case OPC_CGETCAUSE_NI:  /* 0x01 << 11 */
                    opn = "cgetcause";
                case OPC_CSETCAUSE_NI:  /* 0x02 << 11 */
                    generate_csetcause(r16);
                    opn = "csetcause";
                case OPC_CJR_NI:        /* 0x03 << 11 */
                    generate_cjr(ctx, r16);
                    opn = "cjr";
                default:
                    opn = "c1operand";
                    goto invalid;
            default:
                opn = "c2operand";
                goto invalid;
            opn = "cget";
            goto invalid;
    case OPC_CSETBOUNDS: /* 0x01 */
        opn = "csetbounds";
    case OPC_CSEAL:  /* 0x02 */
        generate_cseal(r16, r11, r6);
        opn = "cseal";
    case OPC_CUNSEAL: /* 0x03 */
        opn = "cunseal";
    case OPC_CMISC: /* 0x04 */
        switch(MASK_CAP3(opc)) {
        case OPC_CANDPERM: /* 0x0 */
            opn = "candperm";
        case OPC_CSETCAUSE: /* 0x4 */
            generate_csetcause(r6);
            opn = "csetcause";
        case OPC_CCLEARTAG: /* 0x5 */
            opn = "ccleartag";
        case OPC_MTC2SEL6: /* 0x6 */
                gen_load_gpr(t0, r16);
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
        generate_cjalr(ctx, r16, r11);
        opn = "cjalr";
    case OPC_CJR: /* 0x08 */
        generate_cjr(ctx, r11);
        opn = "cjr";
    case OPC_CBTU: /* 0x09 */
        opn = "cbtu";
        generate_cbtu(ctx, r16, (int16_t)(ctx->opcode));
    case OPC_CBTS: /* 0x0a */
        opn = "cbts";
        generate_cbts(ctx, r16, (int16_t)(ctx->opcode));
    case OPC_CCHECK: /* 0x0b */
        switch(MASK_CAP3(opc)) {
        case OPC_CCHECKPERM: /* 0x0 */
            generate_ccheckperm(r16, r6);
            opn = "ccheckperm";
        case OPC_CCHECKTYPE: /* 0x1 */
            opn = "cchecktype";
            opn = "ccheck";
            goto invalid;
    case OPC_CTOPTR: /* 0x0c */
        opn = "ctoptr";
    case OPC_COFFSET: /* 0x0d */
        case OPC_CINCOFFSET: /* 0x0 */
            opn = "cincoffset";
        case OPC_CSETOFFSET: /* 0x1 */
            generate_csetoffset(r16, r11, r6);
            opn = "csetoffset";
        case OPC_CGETOFFSET: /* 0x2 */
            opn = "cgetoffset";
            opn = "coffset";
            goto invalid;
    case OPC_CPTRCMP: /* 0x0e */
        case OPC_CEQ:  /* 0x0 */
            opn = "ceq";
        case OPC_CNE:  /* 0x1 */
            opn = "cne";
        case OPC_CLT:  /* 0x2 */
            opn = "clt";
        case OPC_CLE:  /* 0x3 */
            opn = "cle";
        case OPC_CLTU: /* 0x4 */
            opn = "cltu";
        case OPC_CLEU: /* 0x5 */
            opn = "cleu";
        case OPC_CEXEQ: /* 0x6 */
            generate_cexeq(ctx, r16, r11, r6);
            opn = "cexeq";
        case OPC_CNEXEQ: /* 0x7 */
        default: /* Can't happen, because all possible values are allocated */
            opn = "cptrcmp";
            goto invalid;
    case OPC_CCLEARREGS: /* 0x0f */
        opn = "cclearregs";
            goto invalid;
    case OPC_CLL:   /* 0x10 */
        switch(MASK_CAP4(opc)) {
        case OPC_CSCB: /* 0x0 */
            opn = "cscb";
        case OPC_CSCH: /* 0x1 */
                                    MO_TEUW | ctx->default_tcg_memop_mask,
            opn = "csch";
        case OPC_CSCW: /* 0x2 */
                                    MO_TEUL | ctx->default_tcg_memop_mask,
            opn = "cscw";
        case OPC_CSCD: /* 0x3 */
                                    MO_TEUQ | ctx->default_tcg_memop_mask,
            opn = "cscd";
        case OPC_CSCC: /* 0x7 */
        case OPC_CLLB: /* 0xc */
            opn = "cllb";
        case OPC_CLLH: /* 0xd */
                                     MO_TESW | ctx->default_tcg_memop_mask,
            opn = "cllh";
        case OPC_CLLW: /* 0xe */
            opn = "cllw";
        case OPC_CLLD: /* 0xb */
                                     MO_TEUQ | ctx->default_tcg_memop_mask,
            opn = "clld";
        case OPC_CLLBU: /* 0x8 */
                                     MO_UB | ctx->default_tcg_memop_mask,
            opn = "cllbu";
        case OPC_CLLHU: /* 0x9 */
            opn = "cllhu";
        case OPC_CLLWU: /* 0xa */
            opn = "cllwu";
            opn = "cll";
            goto invalid;
        generate_cbez(ctx, r16, (int16_t)opc);
        generate_cincoffset_imm(r16, r11, (opc & 0x7ff));
        opn = "cincoffsetimmediate";
        generate_csetbounds_imm(r16, r11, (opc & 0x7ff));
        opn = "csetboundsimmediate";
        goto invalid;
    (void)opn; /* avoid a compiler warning */
    return;
invalid:
    MIPS_INVAL(opn);
    generate_exception (ctx, EXCP_RI);
#endif /* TARGET_CHERI */

/*
 *
 */
#define DO_TRANSLATE_HELPER(name, gen_helper, helper_name, ...)                \
        return gen_helper(ctx, __VA_ARGS__, &gen_helper_##helper_name);        \
    }
#define DO_TRANSLATE(name, gen_helper, ...)                                    \
    DO_TRANSLATE_HELPER(name, gen_helper, name, __VA_ARGS__)
typedef void(cheri_int_cap_helper)(TCGv, TCGv_env, TCGv_i32);
static inline bool gen_cheri_int_cap(DisasContext *ctx, arg_rc *a,
                                     cheri_int_cap_helper *gen_func)
{
    gen_set_gpr(ctx, a->rd, result);
    return true;
}
#define TRANSLATE_INT_CAP_HELPER(name, helper)                                 \
                                     cheri_cap_cap_helper *gen_func)
{
}
#define TRANSLATE_CAP_CAP_HELPER(name, helper)                                 \
    DO_TRANSLATE_HELPER(name, gen_cheri_cap_cap, helper, a)
#define TRANSLATE_CAP_CAP(name) TRANSLATE_CAP_CAP_HELPER(name, name)
static inline QEMU_ALWAYS_INLINE bool
gen_cheri_cap_int_plus_imm(DisasContext *ctx, int cd, int rs, target_long imm,
                           cheri_cap_int_helper *gen_func)
    tcg_gen_addi_tl(gpr_value, gpr_value, imm);
    DO_TRANSLATE_HELPER(name, gen_cheri_cap_cap_cap, helper, a)
                                         cheri_cap_cap_int_helper *gen_func)
#define TRANSLATE_CAP_CAP_INT_HELPER(name, helper)                             \
    DO_TRANSLATE_HELPER(name, gen_cheri_cap_cap_int, helper, a)
#define TRANSLATE_CAP_CAP_INT(name) TRANSLATE_CAP_CAP_INT_HELPER(name, name)
static inline bool gen_cheri_cap_loadstore(DisasContext *ctx, int srcdst,
static inline bool gen_cheri_int_cap_cap(DisasContext *ctx, arg_rcc *a,
                                         cheri_int_cap_cap_helper *gen_func)
#define TRANSLATE_INT_CAP_CAP_HELPER(name, helper)                             \
    DO_TRANSLATE_HELPER(name, gen_cheri_int_cap_cap, helper, a)
#define TRANSLATE_INT_CAP_CAP(name) TRANSLATE_INT_CAP_CAP_HELPER(name, name)
static inline bool gen_cheri_cap_cap_imm(int cd, int cs1, target_long imm,
#define TRANSLATE_CAP_CAP_IMM(name)                                            \
    /* Mask the LSB to match the RISC-V spec for JAL. */
    target_ulong next_pc = (ctx->base.pc_next + imm) & ~(target_ulong)1;
    TCGv target_addr = tcg_constant_tl(next_pc);
    TCGv link_addr = tcg_constant_tl(ctx->pc_succ_insn);
    /*
     * helper_cjal() checks for misalignment and capability bounds. It also
     * ensures that the written value is a sentry and marks PC as up-to-date.
     */
    gen_helper_cjal(tcg_env, tcg_constant_i32(rd), target_addr, link_addr);
    /* No bounds check needed here since we did it in helper_cjal(). */
    TCGv t0 = tcg_constant_tl(ctx->pc_succ_insn); /* Link addr + resulting pc */
    gen_helper_cjalr(tcg_env, tcg_constant_i32(cd), tcg_constant_i32(cs1),
                     tcg_constant_tl(imm), t0);
    ctx->base.is_jmp = DISAS_NORETURN;
TRANSLATE_INT_CAP(cgethigh)
TRANSLATE_INT_CAP(cloadtags)
    if (gen_cheri_cap_cap_cap(ctx, a, &gen_helper_cspecialrw)) {
        if (a->cs1 != 0 && a->cs2 == CheriSCR_DDC) {
            tcg_gen_exit_tb(NULL, 0);
TRANSLATE_CAP_CAP_INT(csethigh)
TRANSLATE_INT_CAP_CAP(cseqx)
static inline bool gen_cap_load(DisasContext *ctx, int32_t rd, int32_t cs,
static inline bool do_trans_modesw(DisasContext *ctx, bool to_capmode)
    if (ctx->capmode == to_capmode) {
        qemu_log_mask_and_addr(CPU_LOG_INSTR, ctx->base.pc_first,
                               "Redundant modesw at %" VADDR_PRIx " (%s)",
                               ctx->base.pc_first,
                               lookup_symbol(ctx->base.pc_first));
    gen_helper_modesw(tcg_env, tcg_constant_i32(to_capmode));
     * The current execution mode is checked at translation time (not at
     * execution time) and is part of the translation block flags, so these
     * flags are no longer correct after executing modesw -> we have to process
     * the mode update and exit the translation block.
     *
     * Note: Translating the same code with a different initial mode will never
     * find a cached block with incorrect initial mode since the mode is part of
     * the TB flags and they are used as part of the hash table lookup.
     * TODO: it should be possible to update the flag in DisasContext and
     * continue translation after the modesw, but I am not confident this will
     * be correct. Once we have some unit tests that we can run we should try
     * to make this change since it will improve the performance of hybrid code.
     * See Morello code which uses DISAS_UPDATE_EXIT.
     */
    /* create tcg instruction to exit the tb */
    /* This indicates to riscv_tr_tb_stop that no cleanup is needed. */
}
static inline bool trans_modesw_cap(DisasContext *ctx, arg_modesw_cap *a)
{
    return do_trans_modesw(ctx, /*to_capmode=*/true);
}
static inline bool trans_modesw_int(DisasContext *ctx, arg_modesw_int *a)
{
    return do_trans_modesw(ctx, /*to_capmode=*/false);
}
// Reuses gen_lr_impl, defined in trans_rva.c.inc
    }
/*
 * Instructions from the RISC-V CHERI standard.
TRANSLATE_INT_CAP_HELPER(gctag, cgettag)
TRANSLATE_INT_CAP_HELPER(gcperm, cgetperm)
TRANSLATE_INT_CAP_HELPER(gchi, cgethigh)
TRANSLATE_INT_CAP_HELPER(gcbase, cgetbase)
TRANSLATE_INT_CAP_HELPER(gclen, cgetlen)
TRANSLATE_CAP_CAP_HELPER(sentry, csealentry)
static bool trans_cadd(DisasContext *ctx, arg_cadd *a)
{
    assert(a->rs2 != 0 && "This encoding is reserved");
    return gen_cheri_cap_cap_int(ctx, a, &gen_helper_cincoffset);
TRANSLATE_CAP_CAP_INT_HELPER(scaddr, csetaddr)
TRANSLATE_CAP_CAP_INT_HELPER(scbnds, csetboundsexact)
TRANSLATE_CAP_CAP_INT_HELPER(scbndsr, csetbounds)
TRANSLATE_CAP_CAP_INT_HELPER(schi, csethigh)
TRANSLATE_INT_CAP_CAP_HELPER(sceq, cseqx)
static bool trans_scbndsi(DisasContext *ctx, arg_scbndsi *a)
    if (a->scale == 1 && a->imm <= 1) {
        return false; /* Reserved redundant encodings */
    tcg_debug_assert(a->imm >= 0);
    target_ulong imm = a->scale ? a->imm << 4 : a->imm;
    return gen_cheri_int_int(ctx, a, &gen_helper_cram);
static bool trans_caddi(DisasContext *ctx, arg_caddi *a)
    return gen_cheri_cap_cap_imm(a->cd, a->cs1, a->imm, &gen_helper_cincoffset);

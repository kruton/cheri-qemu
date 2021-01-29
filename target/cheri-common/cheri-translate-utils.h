}
    }
#endif
// TODO Move to target specific headers
#define target_get_gpr(ctx, t, reg) gen_load_gpr((TCGv)t, reg)
#define MERGED_FILE 0
#elif defined(TARGET_AARCH64)
#define target_get_gpr(ctx, t, reg)                                            \
    if (reg == NULL_CAPREG_INDEX)                                              \
        tcg_gen_movi_tl((TCGv)t, 0);                                           \
    else                                                                       \
        tcg_gen_mov_i64((TCGv)t, cpu_reg_sp(ctx, reg))
#define MERGED_FILE 1
#elif defined(TARGET_RISCV)
#define target_get_gpr(ctx, t, reg) gen_get_gpr(ctx, (TCGv)t, reg)
#else
#error "Don't know how to fetch a GPR value"
#else
        return;
    if (unlikely(do_checks)) {
#ifdef TARGET_AARCH64
    if (have_cheri_tb_flags(ctx, TB_FLAG_CHERI_PCC_FULL_AS)) {
    // Note: JR/JALR will often be used in hybrid/non-CHERI cases, so we can
    // skip the less than check if pcc.base is zero and top is MAX:
    // We can skip the check of pcc.base if it is zero (common case in
    // hybrid/non-CHERI  mode).
        tcg_gen_brcondi_tl(TCG_COND_LTU, addr, ctx->base.pcc_base,
                           bounds_violation);
        tcg_gen_brcondi_tl(TCG_COND_GEU, addr, ctx->base.pcc_top,
    if (qemu_ctx_logging_enabled(ctx)) {
        TCGv_ptr name = tcg_constant_ptr(str_name);
        gen_helper_qemu_log_instr_cap(tcg_env, name, reg,
        gen_ensure_cap_decompressed(ctx, regnum);
        gen_helper_qemu_log_instr_reg(tcg_env, name, new_val,
        TCGv new_val = tcg_temp_new();
        gen_cap_get_cursor(ctx, regnum, new_val);
        const char *str_name =
            cheri_gp_int_regnames[regnum];
            cheri_gp_regnames[regnum];
        // TODO: Add some integer names to riscv/mips
        return;
    if (regnum == NULL_CAPREG_INDEX)

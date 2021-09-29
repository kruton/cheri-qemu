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
    }
#else
        return;
    if (unlikely(do_checks)) {
#ifdef TARGET_AARCH64
            cheri_debug_assert(!(req_perms & CAP_PERM_STORE));
    if (have_cheri_tb_flags(ctx, TB_FLAG_CHERI_PCC_FULL_AS)) {
    // Note: JR/JALR will often be used in hybrid/non-CHERI cases, so we can
    // skip the less than check if pcc.base is zero and top is MAX:
    // We can skip the check of pcc.base if it is zero (common case in
    // hybrid/non-CHERI  mode).
        tcg_gen_brcondi_tl(TCG_COND_LTU, addr, ctx->base.pcc_base,
                           bounds_violation);
        tcg_gen_brcondi_tl(TCG_COND_GEU, addr, ctx->base.pcc_top,
                    sizeof(cap_register_t), sizeof(aligned_cap_register_t));
                    sizeof(cap_register_t), sizeof(aligned_cap_register_t));
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
    // Exponent
    tcg_gen_movi_tl(temp, CAP_CC(NULL_EXP));
    tcg_gen_st8_tl(temp, tcg_env, offset + offsetof(cap_register_t, cr_exp));
    if (!lazy_capreg_number_is_special(regnum))
// Does addr + offset <= top. If offset non zero, Addr MUST be a multiple of
// offset.
                                          TCGv_i64 addr, TCGv result,
                                          int offset)
    // Because of the above invariant,
    // Offsets of less than one can be folded into the comparison
    if (offset > 1) {
        TCGv_i64 addrtmp = tcg_temp_new_i64();
        tcg_gen_movi_i64(addrtmp, offset);
        tcg_gen_add_i64(addrtmp, addrtmp, addr);
        addr = addrtmp;
    tcg_gen_setcond_i64(offset == 1 ? TCG_COND_LTU : TCG_COND_LEU, result, addr,
                        temp);
        // The only overflow that can occur will make address exactly 0.
        tcg_gen_movi_i64(temp, 0);
        tcg_gen_setcond_i64(TCG_COND_NE, temp, addr, temp);
        // doing this before the or below will make full length caps still work
        // properly
        tcg_gen_and_i64(result, result, temp);
// Handles sealed and unrepresentable caps when the cursor is changed. If
        tcg_gen_and_tl(temp0, temp0, new_type);
        // This handles the CAP_NO_SEALING case
        // success == type == CAP_NO_SEALING
        // TODO: This belongs in another header
#define CAP_NO_SEALING -1l
        tcg_gen_movi_tl(temp0, CAP_NO_SEALING);
        tcg_gen_setcond_tl(TCG_COND_EQ, success, new_type, temp0);
    tcg_gen_setcond_i64(TCG_COND_LEU, result, tempa, tempb);

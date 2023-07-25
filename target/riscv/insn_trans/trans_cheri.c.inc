/*
 */
    }
typedef void(cheri_int_cap_helper)(TCGv, TCGv_env, TCGv_i32);
static inline bool gen_cheri_int_cap(DisasContext *ctx, arg_rc *a,
                                     cheri_int_cap_helper *gen_func)
{
}
static inline QEMU_ALWAYS_INLINE bool
gen_cheri_cap_int_plus_imm(DisasContext *ctx, int cd, int rs, target_long imm,
                           cheri_cap_int_helper *gen_func)
    tcg_gen_addi_tl(gpr_value, gpr_value, imm);
                                         cheri_cap_cap_int_helper *gen_func)
    /* Mask the LSB to match the RISC-V spec for JAL. */
    target_ulong next_pc = (ctx->base.pc_next + imm) & ~(target_ulong)1;
    TCGv target_addr = tcg_constant_tl(next_pc);
    TCGv link_addr = tcg_constant_tl(ctx->pc_succ_insn);
     * helper_cjal() checks for misalignment and capability bounds. It also
     * ensures that the written value is a sentry and marks PC as up-to-date.
    gen_helper_cjal(tcg_env, tcg_constant_i32(rd), target_addr, link_addr);
    /* No bounds check needed here since we did it in helper_cjal(). */
TRANSLATE_INT_CAP(cgethigh)
TRANSLATE_INT_CAP(cloadtags)
TRANSLATE_CAP_CAP_INT(csethigh)
static inline bool gen_cap_load(DisasContext *ctx, int32_t rd, int32_t cs,
// Reuses gen_lr_impl, defined in trans_rva.c.inc

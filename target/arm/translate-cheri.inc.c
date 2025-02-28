{
    disas_capreg_state_set_unknown(ctx, cd);
    return true;
}
{
    return true;
}
{
    }
}
        QEMU_FALLTHROUGH;
}
        QEMU_FALLTHROUGH;
        break;
        } else {
    } else {
    if (regnum == NULL_CAPREG_INDEX) {
        return cpu_reg(ctx, 31);
        return cpu_reg_sp(ctx, regnum);
static inline TCGv_i64 read_cpu_reg_maybe_0(DisasContext *ctx, int regnum)
        return read_cpu_reg(ctx, 31, 1);
        return read_cpu_reg_sp(ctx, regnum, 1);
    bool alternate_base, bool pcc_base, bool exclusive, int acquire_release,
    int swap, int option, unsigned int shift, bool unpriv)
    printf(
        "Memop: %s vec:%d rd:%d rd2:%d size:%d extend:%d rn:%d rm:%d imm:%ld. "
        "AB? %d. CB? %d. pcc_base? %d. pre %d. post %d. opt: %d. shift %d.\n",
        is_load ? "load" : "store", vector, rd, rd2, size, extend_size, rn, rm,
        imm, alternate_base, capability_base, pcc_base, pre_inc, post_inc,
        option, shift);
        gen_cap_debug(ctx, rn);
    if (rm != REG_NONE)
        gen_cap_debug(ctx, rm);
#endif
    if (rn == 31)
        gen_check_sp_alignment(ctx);
        TCGv_i32 tcg_rd2 = NULL;
            tcg_rd2 = tcg_constant_i32(rd2);
            if (rd2 != REG_NONE) {
            tcg_debug_assert(!unpriv);
                                                      tcg_base_reg, addr);
                    tcg_env, tcg_rm, tcg_rd, tcg_rd2, tcg_base_reg, addr);
                         : gen_helper_store_cap_via_cap_mmu_idx)(
                    tcg_env, tcg_rd, tcg_base_reg, addr, tcg_idx);
                (is_load ? gen_helper_load_cap_via_cap
                         : gen_helper_store_cap_via_cap)(tcg_env, tcg_rd, addr,
            else
            if (exclusive || acquire_release)
                memop = finalize_memop(ctx, memop);  /* enforce alignment */
                assert(rd2 == REG_NONE);
        gen_reg_modified_cap(ctx, a->Rd);
        gen_lazy_cap_set_int(ctx, a->Rd);
    gen_reg_modified_cap(ctx, a->Cd);
                return false;
                return false;
    disas_capreg_state_set(ctx, cd, CREG_FULLY_DECOMPRESSED);
    TCGv_i64 result = cpu_reg(ctx, a->Rd);
        switch (a->opc) {
            gen_cap_get_sealed_i32(ctx, a->Cn, sealed);
        uint32_t source = AS_ZERO(a->Cn);
        disas_capreg_state_set_unknown(ctx, AS_ZERO(a->Cn));
        ctx->base.is_jmp = DISAS_JUMP;
    disas_capreg_state_set(ctx, a->Cn, CREG_FULLY_DECOMPRESSED);
    if (ctx->current_el == 0)
TRANS_F(GC)
    int regnum = a->Cn;
    case 0b000: // base
        gen_cap_get_base(ctx, regnum, result);
    case 0b001: // len
        gen_cap_get_length(ctx, regnum, result);
    case 0b010: // value
        gen_cap_get_cursor(ctx, regnum, result);
    case 0b011: // off
        gen_cap_get_offset(ctx, regnum, result);
    case 0b100: // tag
        gen_cap_get_tag(ctx, regnum, result);
    case 0b101: // seal
        gen_cap_get_sealed(ctx, regnum, result);
    case 0b110: // perm
        gen_cap_get_perms(ctx, regnum, result);
    case 0b111: // type
        gen_cap_get_type(ctx, regnum, result);
               a->Ct);
    helper(cpu_reg(ctx, a->Rd), tcg_env, cpu_reg(ctx, a->Rn));
    gen_cheri_cap_cap_imm(ctx, a->Cd, a->Cn, length,
                          &gen_helper_csetboundsexact);
    if (!(a->opc & 2)) {
        cheri_cap_cap_int_helper *helper = NULL;
        if (a->opc == 0) {
            helper = &gen_helper_csetbounds;
        } else if (a->opc == 1) {
            helper = &gen_helper_csetboundsexact;
        return gen_cheri_cap_cap_int(ctx, a->Cd, a->Cn, a->Rm, helper);
    if (a->Rn == 31)

{
    return true;
}
        break;
        } else {
        TCGv_i32 tcg_rd2 = NULL;
            tcg_rd2 = tcg_constant_i32(rd2);
            if (rd2 != REG_NONE) {
                                                      tcg_base_reg, addr);
                    tcg_env, tcg_rm, tcg_rd, tcg_rd2, tcg_base_reg, addr);
                         : gen_helper_store_cap_via_cap_mmu_idx)(
                    tcg_env, tcg_rd, tcg_base_reg, addr, tcg_idx);
                (is_load ? gen_helper_load_cap_via_cap
                         : gen_helper_store_cap_via_cap)(tcg_env, tcg_rd, addr,
                assert(rd2 == REG_NONE);
        gen_lazy_cap_set_int(ctx, a->Rd);
    TCGv_i64 result = cpu_reg(ctx, a->Rd);
        switch (a->opc) {
            gen_cap_get_sealed_i32(ctx, a->Cn, sealed);
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

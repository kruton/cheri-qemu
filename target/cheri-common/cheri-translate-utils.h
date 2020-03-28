}
        return;
    if (unlikely(do_checks)) {
    // Note: JR/JALR will often be used in hybrid/non-CHERI cases, so we can
    // skip the less than check if pcc.base is zero and top is MAX:
    // We can skip the check of pcc.base if it is zero (common case in
    // hybrid/non-CHERI  mode).
        tcg_gen_brcondi_tl(TCG_COND_LTU, addr, ctx->base.pcc_base,
                           bounds_violation);
        tcg_gen_brcondi_tl(TCG_COND_GEU, addr, ctx->base.pcc_top,

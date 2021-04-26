typedef void(cheri_int_cap_helper)(TCGv, TCGv_env, TCGv_i32);
static inline bool gen_cheri_int_cap(DisasContext *ctx, arg_rc *a,
                                     cheri_int_cap_helper *gen_func)
                           cheri_cap_int_helper *gen_func)
static inline bool gen_cap_load(DisasContext *ctx, int32_t rd, int32_t cs,
// Reuses gen_lr_impl, defined in trans_rva.c.inc

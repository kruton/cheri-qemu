{
    }
#define ALL_CAPREG_STATES 0b1111
static inline void disas_capreg_reset_all(DisasContextBase *ctx)
    for (size_t i = 0; i != NUM_LAZY_CAP_REGS; i++) {
        ctx->cap_compression_states[i] = (lazy_capreg_number_is_special(i))
                                             ? (1 << CREG_FULLY_DECOMPRESSED)
                                             : ALL_CAPREG_STATES;

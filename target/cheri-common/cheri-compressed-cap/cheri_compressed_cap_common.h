#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {
    // For the reset capability we use an internal exponent and need
    // 2^ADDR_WIDTH, which uses the max exponent.
    _CC_N(RESET_EXP) = _CC_N(MAX_EXPONENT),
    _CC_N(RESET_T) = 1u << (_CC_N(ADDR_WIDTH) - _CC_N(RESET_EXP) - _CC_N(FIELD_EXPONENT_HIGH_PART_SIZE)),
#ifdef CC_IS_MORELLO
    _CC_N(NULL_EXP) = _CC_N(MAX_ENCODABLE_EXPONENT),
    _CC_N(NULL_T) = 0,
#else
    // NULL uses identical bounds encoding to the reset capability.
    _CC_N(NULL_EXP) = _CC_N(RESET_EXP),
    _CC_N(NULL_T) = _CC_N(RESET_T),
#endif
                         _CC_ENCODE_FIELD(_CC_N(OTYPE_UNSEALED), OTYPE),
                      _CC_ENCODE_FIELD(_CC_N(NULL_T), EXP_NONZERO_TOP) | _CC_ENCODE_FIELD(0, EXP_NONZERO_BOTTOM),
    // We mask on store/load so this invisibly keeps null 0 whatever we choose it to be.
    _CC_N(MEM_XOR_MASK) = _CC_N(NULL_PESBT),
};
#pragma GCC diagnostic pop
}
static inline _cc_addr_t _cc_N(cap_bounds_address)(_cc_addr_t addr) {
    // Remove flags bits
    _cc_addr_t cursor = addr & _CC_CURSOR_MASK;
    // Sign extend
    if (cursor & ((_CC_CURSOR_MASK >> 1) + 1))
        cursor |= ~_CC_CURSOR_MASK;
    return cursor;
static inline bool _cc_N(is_representable_cap_exact)(const _cc_cap_t* cap) {
           _CC_ENCODE_FIELD(bot_ie, EXP_NONZERO_BOTTOM);

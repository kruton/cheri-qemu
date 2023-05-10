 */
#ifdef TARGET_AARCH64
#else
#endif
static inline target_ulong cap_get_cursor(const cap_register_t *c)
{
}
static inline target_ulong cap_get_base(const cap_register_t *c)
{
}
static inline cap_offset_t cap_get_offset(const cap_register_t *c)
{
}
{
}
/*
 */
    /*
#endif
#endif
#endif
    return false;
#else
#ifndef TARGET_AARCH64
    // TODO: should handle last byte of address space properly
static inline cap_length_t cap_get_length_full(const cap_register_t *c)
#ifndef TARGET_AARCH64
    cheri_debug_assert((!c->cr_tag || c->_cr_top >= c->cr_base) &&
                       "Tagged capabilities must be in bounds!");
static inline bool cap_otype_is_reserved(target_ulong otype)
    target_ulong otype = CAP_cc(get_otype)(c);
     * It is impossible to have out-of-range otypes in all targets for the
     * currently used capability compression schemes.
    cheri_debug_assert(otype <= CAP_MAX_REPRESENTABLE_OTYPE);
    return otype;
        return result;
    return result < CAP_CC(MIN_RESERVED_OTYPE)
static inline bool cap_is_sealed_with_reserved_otype(const cap_register_t *c)
    target_ulong otype = cap_get_otype_unsigned(c);
    assert(cap_is_unsealed(c) && "Should only use this with unsealed caps");
    assert(!cap_otype_is_reserved(type) &&
           "Can't use this to set reserved otypes");
    assert(cap_is_sealed_with_type(c) &&
           "should not use this to unseal reserved types");
    CAP_cc(update_otype)(c, CAP_OTYPE_UNSEALED);
static inline void cap_unseal_reserved_otype(cap_register_t *c)
    assert(c->cr_tag && cap_is_sealed_with_reserved_otype(c) &&
           "Should only be used with reserved object types");
#ifdef TARGET_AARCH64
    // Invalid exponent caps are always considered out of bounds.
    if (!c->cr_bounds_valid)
        if (c->cr_tag)
            warn_report("Found capability access that wraps around: 0x" TARGET_FMT_lx
                        " + %zd. Authorizing cap: " PRINT_CAP_FMTSTR,
                        addr, num_bytes, PRINT_CAP_ARGS(c));
    cr->cr_extra = CREG_FULLY_DECOMPRESSED;
static inline void cap_set_cursor(cap_register_t *cap, uint64_t new_addr)
    if (!is_representable_cap_with_addr(cap, new_addr)) {
        cap_mark_unrepresentable(new_addr, cap);
    } else {
        cap->_cr_cursor = new_addr;
static inline void cap_increment_offset(cap_register_t *cap, uint64_t offset)
    uint64_t new_addr = cap->_cr_cursor + offset;
    return cap_set_cursor(cap, new_addr);

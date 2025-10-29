 */
#ifdef TARGET_AARCH64
#else
#endif
#define PRINT_CAP_FMTSTR                                                       \
    "v:%d %s p:%2x ct:" TARGET_FMT_ld " b:" TARGET_FMT_lx " a:" TARGET_FMT_lx  \
#define PRINT_CAP_ARGS(cr)                                                     \
    (cr)->cr_tag, PRINT_CAP_MODE(cr), (unsigned)cap_get_all_perms(cr),         \
        cap_get_otype_signext(cr), cap_get_base(cr), cap_get_cursor(cr),       \
        cap_get_top(cr), (cr)->cr_bounds_valid
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
    return CAP_cc(get_all_permissions)(c);
}
/*
 */
{
    /*
     */
        }
    }
#endif
#endif
#endif
            return true;
#endif
    return false;
/**
 */
    /*
#else
    bool success = CAP_cc(set_permissions)(c, perms);
    assert(success);
#ifndef TARGET_AARCH64
#else
    // TODO: should handle last byte of address space properly
static inline cap_length_t cap_get_length_full(const cap_register_t *c)
#ifndef TARGET_AARCH64
    cheri_debug_assert((!c->cr_tag || c->_cr_top >= c->cr_base) &&
                       "Tagged capabilities must be in bounds!");
static inline bool cap_otype_is_reserved(target_ulong otype)
    /* Silence -Wtype-limits by using an intermediate variable. */
    target_ulong min = CAP_CC(MIN_RESERVED_OTYPE);
    return otype >= min && otype <= CAP_CC(MAX_RESERVED_OTYPE);
    target_ulong otype = CAP_cc(get_otype)(c);
    /*
     * It is impossible to have out-of-range otypes in all targets for the
     * currently used capability compression schemes.
    cheri_debug_assert(otype <= CAP_MAX_REPRESENTABLE_OTYPE);
    return otype;
        return result;
#if defined(TARGET_AARCH64) || defined(TARGET_CHERI_RISCV_STD)
    /*
     * Morello and the RISC-V standard encodings do not sign extend like the
     * ISAv9 version of CHERI.
    return result < CAP_CC(MIN_RESERVED_OTYPE)
static inline bool cap_is_sealed_with_reserved_otype(const cap_register_t *c)
    target_ulong otype = cap_get_otype_unsigned(c);
static inline bool cap_is_unsealed(const cap_register_t *c)
    target_ulong otype = cap_get_otype_unsigned(c);
    return otype == CAP_OTYPE_UNSEALED;
static inline void cap_set_sealed(cap_register_t *c, uint32_t type)
    assert(c->cr_tag);
    assert(cap_is_unsealed(c) && "Should only use this with unsealed caps");
    assert(!cap_otype_is_reserved(type) &&
           "Can't use this to set reserved otypes");
    CAP_cc(update_otype)(c, type);
static inline void cap_set_unsealed(cap_register_t *c)
    assert(cap_is_sealed_with_type(c) &&
           "should not use this to unseal reserved types");
    CAP_cc(update_otype)(c, CAP_OTYPE_UNSEALED);
static inline bool cap_is_sealed_entry(const cap_register_t *c)
    return cap_get_otype_unsigned(c) == CAP_OTYPE_SENTRY;
static inline void cap_unseal_reserved_otype(cap_register_t *c)
    assert(c->cr_tag && cap_is_sealed_with_reserved_otype(c) &&
           "Should only be used with reserved object types");
    CAP_cc(update_otype)(c, CAP_OTYPE_UNSEALED);
static inline void cap_unseal_entry(cap_register_t *c)
    assert(c->cr_tag && cap_is_sealed_entry(c) &&
           "Should only be used with sentry capabilities");
static inline void cap_make_sealed_entry(cap_register_t *c)
    assert(c->cr_tag && cap_is_unsealed(c) &&
           "Should only be used with unsealed capabilities");
    CAP_cc(update_otype)(c, CAP_OTYPE_SENTRY);
#ifdef TARGET_AARCH64
    // Invalid exponent caps are always considered out of bounds.
    if (!c->cr_bounds_valid)
     * Use __builtin_add_overflow to detect avoid wrapping around the end of
     * the address space. However, we have to be careful to allow accesses to
     * the last byte (wrapping to exactly zero) since that is fine when
     * checking against given an omnipotent capability.
    if (unlikely(__builtin_add_overflow(addr, num_bytes, &access_end_addr))) {
        /* Only do the extended precision addition if we do overflow. */
        if (cap_get_top_full(c) >= (cap_length_t)addr + num_bytes) {
        if (c->cr_tag)
            warn_report("Found capability access that wraps around: 0x" TARGET_FMT_lx
                        " + %zd. Authorizing cap: " PRINT_CAP_FMTSTR,
                        addr, num_bytes, PRINT_CAP_ARGS(c));
    if (access_end_addr > cap_get_top_full(c)) {
 * Clear the tag bit of a capability that became unrepresentable and update
     * Recompute the decompressed bounds relative to the new address. In most
     * cases they will refer to a different region of memory now.
    CAP_cc(decompress_raw_ext)(cr->cr_pesbt, addr, false, lvbits, cr);
    cr->cr_extra = CREG_FULLY_DECOMPRESSED;
#ifdef TARGET_AARCH64
static inline void cap_set_cursor(cap_register_t *cap, uint64_t new_addr)
    if (!is_representable_cap_with_addr(cap, new_addr)) {
        cap_mark_unrepresentable(new_addr, cap);
    } else {
        cap->_cr_cursor = new_addr;
static inline void cap_increment_offset(cap_register_t *cap, uint64_t offset)
    uint64_t new_addr = cap->_cr_cursor + offset;
    return cap_set_cursor(cap, new_addr);
    assert(reg.cr_pesbt == CAP_MEM_XOR_MASK);

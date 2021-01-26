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
/*
#endif
    return false;
#ifndef TARGET_AARCH64
    // TODO: should handle last byte of address space properly
static inline cap_length_t cap_get_length_full(const cap_register_t *c)
    cheri_debug_assert((!c->cr_tag || c->_cr_top >= c->cr_base) &&
                       "Tagged capabilities must be in bounds!");
        return result;
#ifdef TARGET_AARCH64
    // Invalid exponent caps are always considered out of bounds.
    if (!c->cr_bounds_valid)
static inline void cap_set_cursor(cap_register_t *cap, uint64_t new_addr)
    if (!is_representable_cap_with_addr(cap, new_addr)) {
        cap_mark_unrepresentable(new_addr, cap);
    } else {
        cap->_cr_cursor = new_addr;
static inline void cap_increment_offset(cap_register_t *cap, uint64_t offset)
    uint64_t new_addr = cap->_cr_cursor + offset;
    return cap_set_cursor(cap, new_addr);

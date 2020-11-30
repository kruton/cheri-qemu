}
    // TODO: should handle last byte of address space properly
static inline cap_length_t cap_get_length_full(const cap_register_t *c)
    cheri_debug_assert((!c->cr_tag || c->_cr_top >= c->cr_base) &&
                       "Tagged capabilities must be in bounds!");

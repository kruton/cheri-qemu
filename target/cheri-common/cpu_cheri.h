    cheri_debug_assert(!pcc->cr_tag || cap_is_unsealed(pcc) ||
                       pcc->_cr_cursor == pc_addr);
    if (pcc->cr_tag && cap_is_unsealed(pcc)) {

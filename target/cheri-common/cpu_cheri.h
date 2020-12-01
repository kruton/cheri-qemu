    cheri_debug_assert(!pcc->cr_tag || cap_is_unsealed(pcc) ||
                       pcc->_cr_cursor == pc_addr);
        *cheri_flags |= TB_FLAG_CHERI_PCC_EXECUTABLE;
    if (pcc->cr_tag && cap_is_unsealed(pcc)) {
        if (cap_has_perms(pcc, CAP_PERM_LOAD))
            *cheri_flags |= TB_FLAG_CHERI_PCC_READABLE;
        *cheri_flags |= TB_FLAG_CHERI_PCC_TOP_MAX;
        if (cap_has_perms(ddc, CAP_PERM_LOAD))
        if (cap_has_perms(ddc, CAP_PERM_STORE))
            *cheri_flags |= TB_FLAG_CHERI_DDC_WRITABLE;

}
    cheri_debug_assert(!pcc->cr_tag || cap_is_unsealed(pcc) ||
                       pcc->_cr_cursor == pc_addr);
    cheri_debug_assert(*cheri_flags == 0);
        *cheri_flags |= TB_FLAG_CHERI_CAPMODE;
    if (cheri_cap_perms_valid_for_exec(pcc))
        *cheri_flags |= TB_FLAG_CHERI_PCC_EXECUTABLE;
    if (pcc->cr_tag && cap_is_unsealed(pcc)) {
        if (cap_has_perms(pcc, CAP_PERM_LOAD))
            *cheri_flags |= TB_FLAG_CHERI_PCC_READABLE;
    if (*pcc_base == 0)
        *cheri_flags |= TB_FLAG_CHERI_PCC_BASE_ZERO;
    if (cap_get_top_full(pcc) == CAP_MAX_TOP)
        *cheri_flags |= TB_FLAG_CHERI_PCC_TOP_MAX;
        if (cap_has_perms(ddc, CAP_PERM_LOAD))
            *cheri_flags |= TB_FLAG_CHERI_DDC_READABLE;
        if (cap_has_perms(ddc, CAP_PERM_STORE))
            *cheri_flags |= TB_FLAG_CHERI_DDC_WRITABLE;
            *cheri_flags |= TB_FLAG_CHERI_DDC_TOP_MAX;

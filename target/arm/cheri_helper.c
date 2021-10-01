    cap_check_common_reg(min_perms_for_store(env, cd), env, cb, addr,
                         CHERI_CAP_SIZE, _host_return_address, cbp,
                         CHERI_CAP_SIZE, raise_unaligned_store_exception);
    store_cap_to_memory(env, cd, cb, addr, _host_return_address);
    cap_check_common_reg(min_perms_for_store(env, cd2), env, cb,
                         addr + CHERI_CAP_SIZE, CHERI_CAP_SIZE,
                        _host_return_address);
    // Now do a probe early, so that we get the store fault with priority
    // (LC/SC MMU fault priority) is the reverse of cap permissions)
    bool cd_tagged = get_without_decompress_tag(env, cd);
    int mmu_index = cpu_mmu_index(env_cpu(env), false);
    if (cd_tagged)
        probe_cap_write(env, addr, CHERI_CAP_SIZE, mmu_index,
    } else {
        cd_tagged = get_without_decompress_tag(env, cd);
        // Even if there is no store, we possibly need an MMU permission fault
        if (!cd_tagged)
    assert(!tags || (cheri_is_system(env) &&
                     !arm_is_tag_setting_disabled(env, arm_current_el(env))));

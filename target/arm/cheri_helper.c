    bool cd_tagged = get_without_decompress_tag(env, cd);
    int mmu_index = cpu_mmu_index(env_cpu(env), false);
    if (cd_tagged)
    } else {
        // Even if there is no store, we possibly need an MMU permission fault

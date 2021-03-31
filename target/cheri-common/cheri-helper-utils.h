    // Note: we can use a "stale" PCC value with an outdated cursor here since
    // we only really care about the bounds and permissions to derive the
    // resulting capability (e.g. auipcc or CGetPCCIncOffset).
    // If the result is not representable it will be untagged.
    uint32_t perms = CAP_PERM_STORE;
    if (get_capreg_tag(env, cs))
        perms |= CAP_PERM_STORE_CAP;

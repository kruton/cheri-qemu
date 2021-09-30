get_capreg_state(const GPCapRegs *gpcrs, unsigned reg)
{
    }
    cheri_debug_assert(gpcrs->decompressed[reg].cap.cr_extra <=
}
static inline void sanity_check_capreg(GPCapRegs *gpcrs, unsigned regnum)
{
#ifdef CONFIG_DEBUG_TCG
        cheri_debug_assert(CAP_cc(compress_raw)(c) ==
         * accessed. However, the remaining fields must remain valid.
    }
                           CAP_NULL_PESBT);
                               CREG_FULLY_DECOMPRESSED &&
                           "Null should always be fully decompressed");
    } else if (get_capreg_state(gpcrs, regnum) == CREG_INTEGER) {
    }
#endif // CONFIG_DEBUG_TCG
}
static inline QEMU_ALWAYS_INLINE void
set_capreg_state(GPCapRegs *gpcrs, unsigned regnum, CapRegState new_state)
{
        cheri_debug_assert(new_state == CREG_FULLY_DECOMPRESSED &&
                           "NULL/scratch is always fully decompressed");
    }
    sanity_check_capreg(gpcrs, regnum);
{
#endif
static inline __attribute__((always_inline)) const cap_register_t *
    GPCapRegs *gpcrs = cheri_get_gpcrs(env);
    case CREG_INTEGER: {
        cheri_debug_assert(result->cr_pesbt == CAP_NULL_PESBT);
        return result;
        sanity_check_capreg(gpcrs, regnum);
        g_assert_not_reached();
static inline __attribute__((always_inline)) bool
get_without_decompress_tag(CPUArchState *env, unsigned regnum)
    CapRegState state = get_capreg_state(gpcrs, regnum);
    bool tag = (state == CREG_FULLY_DECOMPRESSED) &&
               get_cap_in_gpregs(gpcrs, regnum)->cr_tag;
    tag |= (state == CREG_TAGGED_CAP);
    return tag;
static inline __attribute__((always_inline)) target_ulong
get_without_decompress_cursor(CPUArchState *env, unsigned regnum)
    return get_cap_in_gpregs(gpcrs, regnum)->_cr_cursor;
get_without_decompress_pesbt(CPUArchState *env, unsigned regnum)
    return get_cap_in_gpregs(gpcrs, regnum)->cr_pesbt;
// Return a CREG or DDC or PCC.
get_capreg_or_special(CPUArchState *env, unsigned regnum)
    if (unlikely(regnum == CHERI_EXC_REGNUM_PCC))
        return _cheri_get_pcc_unchecked(env);
    if (unlikely(regnum == CHERI_EXC_REGNUM_DDC))
        return cheri_get_ddc(env);
    else
        return get_readonly_capreg(env, regnum);
/// 0 can only be DDC on mips/risv. On Morello 0 is always normal register.
/// Having the switch here rather than in general code makes things slightly
/// neater. We could always call this "0_is_maybe_ddc" to be less confusing.
#ifdef TARGET_AARCH64
    return get_capreg_or_special(env, regnum);
#else
    return get_capreg_or_special(env,
                                 regnum == 0 ? CHERI_EXC_REGNUM_DDC : regnum);
#endif
#endif
#endif
static inline void rvfi_changed_capreg(CPUArchState *env, unsigned regnum,
                                       target_ulong cursor)
#if defined(TARGET_RISCV) && defined(CONFIG_RVFI_DII)
    env->rvfi_dii_trace.INTEGER.rvfi_rd_addr = regnum;
    env->rvfi_dii_trace.INTEGER.rvfi_rd_wdata = cursor;
    env->rvfi_dii_trace.available_fields |= RVFI_INTEGER_DATA;
                                 const cap_register_t *newval)
    if (get_capreg_state(gpcrs, regnum) == CREG_INTEGER) {
    case CREG_INTEGER:
        cheri_debug_assert(result == 0);
static inline void reset_capregs(CPUArchState *env)
        sanity_check_capreg(gpcrs, i);
    sanity_check_capreg(gpcrs, NULL_CAPREG_INDEX);

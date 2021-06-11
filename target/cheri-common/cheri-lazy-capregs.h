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
        cheri_debug_assert(new_state == CREG_FULLY_DECOMPRESSED &&
                           "NULL/scratch is always fully decompressed");
    sanity_check_capreg(gpcrs, regnum);
#endif
    case CREG_INTEGER: {
        cheri_debug_assert(result->cr_pesbt == CAP_NULL_PESBT);
        return result;
        sanity_check_capreg(gpcrs, regnum);
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

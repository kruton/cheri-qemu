extern bool cheri_debugger_on_trap;
{
    env->badaddr = addr;
#endif
    // Allow drop into debugger on first CHERI trap:
    // FIXME: allow c command to work by adding another boolean flag to skip
    // this breakpoint when GDB asks to continue
    if (cheri_debugger_on_trap)
        riscv_raise_exception(env, EXCP_DEBUG, hostpc);
}
    CPUArchState *env, CheriCapExcCause cause, unsigned regnum,
{
}
static inline void G_NORETURN raise_load_tag_exception(
    CPUArchState *env, target_ulong va, int cb, uintptr_t retpc)
#ifdef TARGET_RISCV32
    g_assert_not_reached();
#else
    env->badaddr = va;
    riscv_raise_exception(env, RISCV_EXCP_LOAD_CAP_PAGE_FAULT, retpc);
}
                                                           uintptr_t retpc)
static inline void G_NORETURN raise_unaligned_load_exception(
    CPUArchState *env, target_ulong addr, uintptr_t retpc)
    riscv_raise_exception(env, RISCV_EXCP_LOAD_ADDR_MIS, retpc);
static inline void G_NORETURN raise_unaligned_store_exception(
    // Note: RISCV_EXCP_STORE_AMO_ADDR_MIS means "Store/AMO address misaligned"
    riscv_raise_exception(env, RISCV_EXCP_STORE_AMO_ADDR_MIS, retpc);
static inline bool validate_jump_target(CPUArchState *env,
                                        const cap_register_t *cap,
    unsigned min_insn_size = riscv_has_ext(env, RVC) ? 2 : 4;
    target_ulong base = cap_get_base(cap);
        raise_cheri_exception_branch_impl(env, CapEx_UnalignedBase, regnum,
    // XXX: Sail only checks bit 1 why not also bit zero? Is it because that is
    if (!riscv_has_ext(env, RVC) && (addr & 0x2)) {
        riscv_raise_exception(env, RISCV_EXCP_INST_ADDR_MIS, retpc);
    return true;

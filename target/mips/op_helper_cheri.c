/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2015-2016 Stacey Son <sson@FreeBSD.org>
 * Copyright (c) 2016-2018 Alfredo Mazzinghi <am2419@cl.cam.ac.uk>
 * Copyright (c) 2016-2018 Alex Richardson <Alexander.Richardson@cl.cam.ac.uk>
 * All rights reserved.
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-10-C-0237
 * ("CTSRD"), as part of the DARPA CRASH research programme.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#include "qemu/osdep.h"
#include "qemu/main-loop.h"
#include "cpu.h"
#include "internal.h"
#include "qemu/host-utils.h"
#include "qemu/error-report.h"
#include "qemu/qemu-print.h"
#include "exec/cputlb.h"
#include "exec/helper-proto.h"
#ifndef TARGET_CHERI
#error "This file should only be compiled for CHERI"
#endif
#include "cheri_tagmem.h"
#include "cheri-helper-utils.h"
#include "cheri-lazy-capregs.h"
#include "disas/disas.h"
#include "disas/dis-asm.h"
#ifdef __clang__
#pragma clang diagnostic error "-Wdeprecated-declarations"
#else
#pragma GCC diagnostic error "-Wdeprecated-declarations"
#endif
#define CHERI_HELPER_IMPL(name) \
    __attribute__((deprecated("Do not call the helper directly, it will crash at runtime. Call the _impl variant instead"))) helper_##name
void cheri_cpu_dump_statistics_f(CPUState *cs, FILE* f, int flags)
{
#ifndef DO_CHERI_STATISTICS
    qemu_fprintf(f, "CPUSTATS DISABLED, RECOMPILE WITH -DDO_CHERI_STATISTICS\n");
#else
    dump_out_of_bounds_stats(f, &oob_info_cincoffset);
    dump_out_of_bounds_stats(f, &oob_info_csetoffset);
    dump_out_of_bounds_stats(f, &oob_info_cfromptr);
    dump_out_of_bounds_stats(f, &oob_info_cgetpccsetoffset);
#endif
}
void cheri_cpu_dump_statistics(CPUState *cs, int flags) {
    cheri_cpu_dump_statistics_f(cs, NULL, flags);
}
static inline bool
is_cap_sealed(const cap_register_t *cp)
{
    // TODO: remove this function and update all callers to use the correct function
}
    } while (0)
#else
#endif
static inline int align_of(int size, uint64_t addr)
{
    switch(size) {
    case 1:
        return 0;
    case 2:
        return (addr & 0x1);
    case 4:
        return (addr & 0x3);
    case 8:
        return (addr & 0x7);
    case 16:
        return (addr & 0xf);
    case 32:
        return (addr & 0x1f);
    default:
        return 1;
    }
}
static inline void update_ddc(CPUArchState *env, const cap_register_t* new_ddc) {
    if (!cap_exactly_equal(&env->active_tc.CHWR.DDC, new_ddc)) {
        // TODO: in the future we may want to move $ddc to the guest -> host addr
        // translation. This would allow skipping $ddc checks for all pages that
        // are fully covered by $ddc for the second load/store check
        // (QEMU has separate TLBs for both cases already).
        // If we implment this, we will have to flush the entire TLB whenever
        // $ddc changes (or at least flush all pages affected by the $ddc chaged)
        // XXX: tlb_flush(env_cpu(env));
        env->active_tc.CHWR.DDC = *new_ddc;
    } else {
    }
}
target_ulong CHERI_HELPER_IMPL(cbez(CPUArchState *env, uint32_t cb, uint32_t offset))
{
    const cap_register_t *cbp = get_readonly_capreg(env, cb);
    /*
     * CBEZ: Branch if NULL
     */
        return (target_ulong)1;
    else
        return (target_ulong)0;
}
target_ulong CHERI_HELPER_IMPL(cbnz(CPUArchState *env, uint32_t cb, uint32_t offset))
{
    const cap_register_t *cbp = get_readonly_capreg(env, cb);
    /*
     * CBEZ: Branch if not NULL.
     */
        return (target_ulong)0;
    else
        return (target_ulong)1;
}
    const cap_register_t *cbp = get_readonly_capreg(env, cb);
    /*
     * CBTS: Branch if tag is set
     */
    return (target_ulong)cbp->cr_tag;
}
    /*
     * CBTU: Branch if tag is unset
     */
    return (target_ulong)!cbp->cr_tag;
}
static target_ulong ccall_common(CPUArchState *env, uint32_t cs, uint32_t cb, uint32_t selector, uintptr_t _host_return_address)
    const cap_register_t *csp = get_readonly_capreg(env, cs);
    /*
     * CCall: Call into a new security domain
    if (!csp->cr_tag) {
        raise_cheri_exception(env, CapEx_TagViolation, cs);
        raise_cheri_exception(env, CapEx_TagViolation, cb);
        raise_cheri_exception(env, CapEx_SealViolation, cs);
        raise_cheri_exception(env, CapEx_SealViolation, cb);
        raise_cheri_exception(env, CapEx_TypeViolation, cs);
    } else if (!cap_has_perms(csp, CAP_PERM_EXECUTE)) {
        raise_cheri_exception(env, CapEx_PermitExecuteViolation, cs);
        raise_cheri_exception(env, CapEx_PermitExecuteViolation, cb);
        // TODO: check for at least one instruction worth of data? Like cjr/cjalr?
        raise_cheri_exception(env, CapEx_LengthViolation, cs);
    } else {
            raise_cheri_exception(env, CapEx_CallTrap, cs);
            raise_cheri_exception(env, CapEx_PermitCCallViolation, cs);
            raise_cheri_exception(env, CapEx_PermitCCallViolation, cb);
        } else {
            cap_register_t idc = *cbp;
            // The capability register is loaded into PCC during delay slot
            env->active_tc.CapBranchTarget = *csp;
            // XXXAR: clearing these fields is not strictly needed since they
            // aren't copied from the CapBranchTarget to $pcc but it does make
            // the LOG_INSTR output less confusing.
            // Return the branch target address
            return cap_get_cursor(csp);
    return (target_ulong)0;
void CHERI_HELPER_IMPL(ccall(CPUArchState *env, uint32_t cs, uint32_t cb))
target_ulong CHERI_HELPER_IMPL(ccall_notrap(CPUArchState *env, uint32_t cs, uint32_t cb))
    // Register zero means $ddc here since it is useful to clear $ddc on a
    // sandbox switch whereas clearing $NULL is useless
    if (mask & 0x1) {
    for (int creg = 1; creg < 32; creg++) {
        if (mask & (0x1 << creg)) {
     * CGetCause: Move the Capability Exception Cause Register to a
     * General- Purpose Register
    } else {
        return (target_ulong)env->CP2_CapCause;
     * CGetPCC: Move PCC to capability register
     * See Chapter 4 in CHERI Architecture manual.
void helper_cmovz(CPUArchState *env, uint32_t cd, uint32_t cs, target_ulong rs)
    const cap_register_t *csp = get_readonly_capreg(env, cs);
     * CMOVZ: conditionally move capability on zero
    if (rs == 0) {
        update_capreg(env, cd, csp);
void helper_cmovn(CPUArchState *env, uint32_t cd, uint32_t cs, target_ulong rs)
    helper_cmovz(env, cd, cs, rs == 0);
     * CJR: Jump Capability Register
    if (!cbp->cr_tag) {
        raise_cheri_exception(env, CapEx_TagViolation, cb);
        raise_cheri_exception(env, CapEx_SealViolation, cb);
    } else if (!cap_has_perms(cbp, CAP_PERM_EXECUTE)) {
        raise_cheri_exception(env, CapEx_PermitExecuteViolation, cb);
    } else if (!cap_is_in_bounds(cbp, cap_get_cursor(cbp), 4)) {
        raise_cheri_exception(env, CapEx_LengthViolation, cb);
    } else if (align_of(4, cap_get_cursor(cbp))) {
        do_raise_c0_exception(env, EXCP_AdEL, cap_get_cursor(cbp));
    } else {
        env->active_tc.CapBranchTarget = *cbp;
            cap_unseal_entry(&env->active_tc.CapBranchTarget);
    return (target_ulong)0;
static inline cap_register_t *
    cheri_debug_assert((int)hwr >= (int)CP2HWR_BASE_INDEX);
    cheri_debug_assert((int)hwr < (int)(CP2HWR_BASE_INDEX + 32));
    switch (hwr) {
    case CP2HWR_DDC: /* always accessible */
        break;
    case CP2HWR_USER_TLS:  /* always accessible */
        return &env->active_tc.CHWR.UserTlsCap;
    case CP2HWR_PRIV_TLS:
        if (!access_sysregs) {
        return &env->active_tc.CHWR.PrivTlsCap;
    case CP2HWR_K1RC:
        if (!in_kernel_mode(env) || !access_sysregs) {
        return &env->active_tc.CHWR.KR1C;
    case CP2HWR_K2RC:
        if (!in_kernel_mode(env) || !access_sysregs) {
        return &env->active_tc.CHWR.KR2C;
    case CP2HWR_ErrorEPCC:
    case CP2HWR_KCC:
        return &env->active_tc.CHWR.KCC;
    case CP2HWR_KDC:
        return &env->active_tc.CHWR.KDC;
    case CP2HWR_EPCC:
        return &env->active_tc.CHWR.EPCC;
    /* unknown cap hardware register */
    return NULL;  // silence warning
static inline const cap_register_t *
check_readonly_cap_hwr_access(CPUArchState *env, enum CP2HWR hwr, target_ulong pc) {
    // Currently there is no difference for access permissions between read
    // and write access but that may change in the future
        return &env->active_tc.CHWR.DDC;
    return check_writable_cap_hwr_access(env, hwr, pc);
    if (!in_kernel_mode(env)) {
        do_raise_exception(env, EXCP_RI, GETPC());
    if (!in_kernel_mode(env)) {
    cap_register_t result = *check_readonly_cap_hwr_access(
    update_capreg(env, cd, &result);
    if (hwr == CP2HWR_DDC) {
        return;
    cap_register_t *cdp = check_writable_cap_hwr_access(
    *cdp = *csp;
     * CSetCause: Set the Capability Exception Cause Register
    } else {
        env->CP2_CapCause = (uint16_t)(rt & 0xffffUL);
 * CPtrCmp Instructions. Capability Pointer Compare.
    const cap_register_t *ctp = get_readonly_capreg(env, ct);
     * CEQ: Capability pointers equal (compares only the cursor)
    return (target_ulong)(cap_get_cursor(cbp) == cap_get_cursor(ctp));
target_ulong CHERI_HELPER_IMPL(cne(CPUArchState *env, uint32_t cb, uint32_t ct))
     * CNE: Capability pointers not equal (compares only the cursor)
  return (target_ulong)(cap_get_cursor(cbp) != cap_get_cursor(ctp));
     * CLT: Capability pointers less than (signed)
    int64_t cursor1_signed = (int64_t)cap_get_cursor(cbp);
    int64_t cursor2_signed = (int64_t)cap_get_cursor(ctp);
    return (target_ulong)(cursor1_signed < cursor2_signed);
     * CLE: Capability pointers less than equal (signed)
    return (target_ulong)(cursor1_signed <= cursor2_signed);
     * CLTU: Capability pointers less than (unsigned)
    uint64_t cursor1_unsigned = cap_get_cursor(cbp);
    uint64_t cursor2_unsigned = cap_get_cursor(ctp);
    return (target_ulong)(cursor1_unsigned < cursor2_unsigned);
     * CLEU: Capability pointers less than equal (unsigned)
    return (target_ulong)(cursor1_unsigned <= cursor2_unsigned);
    target_ulong addr = get_capreg_cursor(env, cb);
target_ulong CHERI_HELPER_IMPL(cloadlinked(CPUArchState *env, uint32_t cb, uint32_t size))
    // CLL[BHWD][U] traps on cbp == NULL so we use reg0 as $ddc to save encoding
    // space and increase code density since loading relative to $ddc is common
    // in the hybrid ABI (and also for backwards compat with old binaries).
    const cap_register_t *cbp = get_capreg_0_is_ddc(env, cb);
    uint64_t addr = cap_get_cursor(cbp);
    if (!cbp->cr_tag) {
    } else if (is_cap_sealed(cbp)) {
    } else if (!cap_has_perms(cbp, CAP_PERM_LOAD)) {
        raise_cheri_exception(env, CapEx_PermitLoadViolation, cb);
    } else if (!cap_is_in_bounds(cbp, addr, size)) {
    } else if (align_of(size, addr)) {
        // TODO: should #if (CHERI_UNALIGNED) also disable this check?
        do_raise_c0_exception(env, EXCP_AdEL, addr);
    } else {
        env->CP0_LLAddr = cpu_mips_translate_address(env, addr, 0, _host_return_address);
        return addr;
    return 0;
target_ulong CHERI_HELPER_IMPL(cstorecond(CPUArchState *env, uint32_t cb, uint32_t size))
    // CSC[BHWD] traps on cbp == NULL so we use reg0 as $ddc to save encoding
    // space and increase code density since storing relative to $ddc is common
    // in the hybrid ABI (and also for backwards compat with old binaries).
    const cap_register_t *cbp = get_capreg_0_is_ddc(env, cb);
    uint64_t addr = cap_get_cursor(cbp);
    if (!cbp->cr_tag) {
    } else if (is_cap_sealed(cbp)) {
    } else if (!cap_has_perms(cbp, CAP_PERM_STORE)) {
        do_raise_c0_exception(env, EXCP_AdES, addr);
    } else {
        // Can't do this here.  It might miss in the TLB.
        // cheri_tag_invalidate(env, addr, size);
        // Also, rd is set by the actual store conditional operation.
    // CSCC traps on cbp == NULL so we use reg0 as $ddc to save encoding
    if (!cbp->cr_tag) {
        return (target_ulong)0;
    } else if (is_cap_sealed(cbp)) {
        return (target_ulong)0;
    } else if (!cap_has_perms(cbp, CAP_PERM_STORE)) {
        return (target_ulong)0;
    } else if (!cap_has_perms(cbp, CAP_PERM_STORE_CAP)) {
        return (target_ulong)0;
    } else if (!cap_has_perms(cbp, CAP_PERM_STORE_LOCAL) && csp->cr_tag &&
        return (target_ulong)0;
    } else if (!cap_is_in_bounds(cbp, addr, CHERI_CAP_SIZE)) {
    } else if (align_of(CHERI_CAP_SIZE, addr)) {
        do_raise_c0_exception(env, EXCP_AdES, addr);
    return (target_ulong)addr;
    // CLLC traps on cbp == NULL so we use reg0 as $ddc to save encoding
    // space and increase code density since loading relative to $ddc is common
    if (!cbp->cr_tag) {
    } else if (is_cap_sealed(cbp)) {
    } else if (!cap_has_perms(cbp, CAP_PERM_LOAD)) {
    } else if (align_of(CHERI_CAP_SIZE, addr)) {
        do_raise_c0_exception(env, EXCP_AdEL, addr);
#endif
target_ulong CHERI_HELPER_IMPL(ccheck_load_right(CPUArchState *env, target_ulong offset, uint32_t len))
#error "This check is only valid for big endian targets, for little endian the load/store left instructions need to be checked"
    // For lwr/ldr we load all bytes if offset & 3/7 == 0 we load only the first byte, if all low bits are set we load the full amount
    uint32_t low_bits = (uint32_t)offset & (len - 1);
    uint32_t loaded_bytes = low_bits + 1;
    // From spec:
    //if BigEndianMem = 1 then
    //  pAddr <- pAddr(PSIZE-1)..3 || 000 (for ldr), 00 for lwr
    //endif
    // clear the low bits in offset to perform the length check
    target_ulong read_offset = offset & ~((target_ulong)len - 1);
    // fprintf(stderr, "%s: len=%d, offset=%zd, read_offset=%zd: will touch %d bytes\n",
    //      __func__, len, (size_t)offset, (size_t)read_offset, loaded_bytes);
    // return the actual address by adding the low bits (this is expected by translate.c
    return check_ddc(env, CAP_PERM_LOAD, read_offset, loaded_bytes, GETPC()) + low_bits;
target_ulong CHERI_HELPER_IMPL(ccheck_store(CPUArchState *env, target_ulong offset, uint32_t len))
    return check_ddc(env, CAP_PERM_STORE, offset, len, GETPC());
target_ulong CHERI_HELPER_IMPL(ccheck_load(CPUArchState *env, target_ulong offset, uint32_t len))
    return check_ddc(env, CAP_PERM_LOAD, offset, len, GETPC());
void CHERI_HELPER_IMPL(ccheck_load_pcrel(CPUArchState *env, target_ulong addr,
static const char *cheri_cap_reg[] = {
  "DDC",  "",   "",      "",     "",    "",    "",    "",  /* C00 - C07 */
     "",  "",   "",      "",     "",    "",    "",    "",  /* C08 - C15 */
     "",  "",   "",      "",     "",    "",    "",    "",  /* C16 - C23 */
  "RCC",  "", "IDC", "KR1C", "KR2C", "KCC", "KDC", "EPCC"  /* C24 - C31 */
};
static void cheri_dump_creg(const cap_register_t *crp, const char *name,
                            fprintf_function cpu_fprintf)
    cpu_fprintf(f,
                "offset:0x%016lx base:0x%016lx length:0x%016lx\n",
                name, crp->cr_tag, is_cap_sealed(crp),
                (uint64_t)cap_get_offset(crp), cap_get_base(crp),
                /* testsuite expects UINT64_MAX for 1 << 64) */
void cheri_dump_state(CPUState *cs, FILE *f, fprintf_function cpu_fprintf, int flags)
    MIPSCPU *cpu = MIPS_CPU(cs);
    CPUArchState *env = &cpu->env;
    int i;
    char name[8];
    cpu_fprintf(f, "DEBUG CAP COREID 0\n");
    for (i = 0; i < 32; i++) {
        // snprintf(name, sizeof(name), "C%02d", i);
        snprintf(name, sizeof(name), "REG %02d", i);
                        cpu_fprintf);
    cheri_dump_creg(&env->active_tc.CHWR.DDC,        "HWREG 00 (DDC)", "", f, cpu_fprintf);
    cheri_dump_creg(&env->active_tc.CHWR.UserTlsCap, "HWREG 01 (CTLSU)", "", f, cpu_fprintf);
    cheri_dump_creg(&env->active_tc.CHWR.PrivTlsCap, "HWREG 08 (CTLSP)", "", f, cpu_fprintf);
    cheri_dump_creg(&env->active_tc.CHWR.KR1C,       "HWREG 22 (KR1C)", "", f, cpu_fprintf);
    cheri_dump_creg(&env->active_tc.CHWR.KR2C,       "HWREG 23 (KR2C)", "", f, cpu_fprintf);
    cheri_dump_creg(&env->active_tc.CHWR.ErrorEPCC,  "HWREG 28 (ErrorEPCC)", "", f, cpu_fprintf);
    cheri_dump_creg(&env->active_tc.CHWR.KCC,        "HWREG 29 (KCC)", "", f, cpu_fprintf);
    cheri_dump_creg(&env->active_tc.CHWR.KDC,        "HWREG 30 (KDC)", "", f, cpu_fprintf);
    cheri_dump_creg(&env->active_tc.CHWR.EPCC,       "HWREG 31 (EPCC)", "", f, cpu_fprintf);
    cpu_fprintf(f, "\n");
void CHERI_HELPER_IMPL(mtc2_dumpcstate(CPUArchState *env, target_ulong arg1))
void CHERI_HELPER_IMPL(cchecktype(CPUArchState *env, uint32_t cs, uint32_t cb))
    GET_HOST_RETPC();
    const cap_register_t *csp = get_readonly_capreg(env, cs);
     * CCheckType: Raise exception if otypes don't match
    if (!csp->cr_tag) {
        raise_cheri_exception(env, CapEx_TagViolation, cs);
    } else if (!cbp->cr_tag) {
        raise_cheri_exception(env, CapEx_TagViolation, cb);
    } else if (cap_is_unsealed(csp)) {
        raise_cheri_exception(env, CapEx_SealViolation, cs);
        raise_cheri_exception(env, CapEx_SealViolation, cb);
               !cap_is_sealed_with_type(csp)) {

/*
 * QEMU page protection definitions.
 *
 *  Copyright (c) 2003 Fabrice Bellard
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */
#ifndef EXEC_PAGE_PROT_COMMON_H
#define EXEC_PAGE_PROT_COMMON_H

/* same as PROT_xxx */
#define PAGE_READ      0x0001
#define PAGE_WRITE     0x0002
#define PAGE_EXEC      0x0004
#define PAGE_RWX       (PAGE_READ | PAGE_WRITE | PAGE_EXEC)
#define PAGE_VALID     0x0008
/*
 * Original state of the write flag (used when tracking self-modifying code)
 */
#define PAGE_WRITE_ORG 0x0010
/*
 * Invalidate the TLB entry immediately, helpful for s390x
 * Low-Address-Protection. Used with PAGE_WRITE in tlb_set_page_with_attrs()
 */
#define PAGE_WRITE_INV 0x0020
/* For use with page_set_flags: page is being replaced; target_data cleared. */
#define PAGE_RESET     0x0040
/* For linux-user, indicates that the page is MAP_ANON. */
#define PAGE_ANON      0x0080

/* Target-specific bits that will be used via page_get_flags().  */
#define PAGE_TARGET_1  0x0200
#define PAGE_TARGET_2  0x0400

/*
 * For linux-user, indicates that the page is mapped with the same semantics
 * in both guest and host.
 */
#define PAGE_PASSTHROUGH 0x0800

#define PAGE_LC_CLEAR	0x8000
#define PAGE_LC_TRAP	0x4000
#define PAGE_SC_TRAP 0x10000
#define PAGE_SC_CLEAR 0x20000
// Like PAGE_LC_TRAP but will also trap loads of untagged values
#define PAGE_LC_TRAP_ANY 0x40000
#define PAGE_C_BITS                                                            \
    (PAGE_LC_CLEAR | PAGE_LC_TRAP | PAGE_SC_TRAP | PAGE_SC_CLEAR |             \
     PAGE_LC_TRAP_ANY)


#endif


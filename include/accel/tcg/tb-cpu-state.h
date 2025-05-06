/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Definition of TCGTBCPUState.
 */

#ifndef EXEC_TB_CPU_STATE_H
#define EXEC_TB_CPU_STATE_H

#include "exec/vaddr.h"

typedef struct TCGTBCPUState {
    vaddr pc;
    uint32_t flags;
    uint32_t cflags;
    uint64_t cs_base;
    /* CHERI */
    vaddr pcc_base;
    vaddr pcc_top;
    uint32_t cheri_flags;
} TCGTBCPUState;

#endif

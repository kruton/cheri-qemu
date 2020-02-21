#include "system/memory.h"
void cheri_tag_init(MemoryRegion* mr, uint64_t memory_size);
void cheri_tag_invalidate(CPUArchState *env, target_ulong vaddr, int32_t size,
int cheri_tag_get_many(CPUArchState *env, target_ulong vaddr, int reg,
void *cheri_tag_set(CPUArchState *env, target_ulong vaddr, int reg,

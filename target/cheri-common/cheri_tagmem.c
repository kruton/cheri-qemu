#include "cheri_tagmem.h"
#include "cheri-helper-utils.h"
// XXX: use hbitmap? Or a different data structure?
#include "qemu/bitmap.h"
#endif
 *
 * FIXME: rewrite using somethign more like the upcoming MTE changes (https://github.com/rth7680/qemu/commits/tgt-arm-mte-user)
#define CAP_TAGBLK_MSK      ((1 << CAP_TAGBLK_SHFT) - 1)
#define CAP_TAGBLK_SIZE       (1 << CAP_TAGBLK_SHFT)
    assert(memory_region_is_ram(mr));
    assert(memory_region_size(mr) == memory_size &&
           "Incorrect tag mem size passed?");
    if (unlikely((first_addr & TARGET_PAGE_MASK) !=
        return NULL;

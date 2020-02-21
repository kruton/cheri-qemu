#include "qemu/osdep.h"
#include "cheri_tagmem.h"
#define CHERI_HELPER_IMPL(name)                                                \
    __attribute__(                                                             \
        (deprecated("Do not call the helper directly, it will crash at "       \
                    "runtime. Call the _impl variant instead"))) helper_##name
{
                                        target_ulong rs))

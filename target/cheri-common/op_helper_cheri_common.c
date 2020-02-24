#include "qemu/osdep.h"
#include "cheri_tagmem.h"
#define CHERI_HELPER_IMPL(name)                                                \
    __attribute__(                                                             \
        (deprecated("Do not call the helper directly, it will crash at "       \
                    "runtime. Call the _impl variant instead"))) helper_##name
{
}
{
    }
{
                                        target_ulong rs))
    const cap_register_t *cbp = get_readonly_capreg(env, cb);
                       "Unknown permission bits set!");
                                  target_ulong rt))
void CHERI_HELPER_IMPL(cbuildcap(CPUArchState *env, uint32_t cd, uint32_t cb,
                                 uint32_t ct))
    const cap_register_t *cbp = get_capreg_0_is_ddc(env, cb);
void CHERI_HELPER_IMPL(candaddr(CPUArchState *env, uint32_t cd, uint32_t cb,
    target_ulong cursor = get_capreg_cursor(env, cb);
    target_ulong target_addr = cursor & rt;
    cincoffset_impl(env, cd, cb, diff, GETPC(), OOB_INFO(csetoffset));
    // CFromPtr traps on cbp == NULL so we use reg0 as $ddc to save encoding
    bool is_subset = false;
    if (cbp->cr_tag == ctp->cr_tag &&
        /* is_cap_sealed(cbp) == is_cap_sealed(ctp) && */
        cap_get_base(cbp) <= cap_get_base(ctp) &&
        cap_get_top_full(ctp) <= cap_get_top_full(cbp) &&
        is_subset = true;

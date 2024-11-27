#include "hw/qdev-properties.h"
#ifdef TARGET_CHERI
#include "cheri_tagmem.h"
#endif
{
    assert(addr + size <= 0x10000);
    assert(size <= 8);
    if (addr + size > CMU_REGS_SIZE) {
    }
    uint64_t retval = 0;
    uint8_t *ptr = (uint8_t *)&retval;
        uint8_t *regptr = ((uint8_t *)&s->regs) + addr;
    while (size--) {
        *ptr++ = *regptr++;
    }
    return retval;
}
    CMUClass *c = CMU_DEVICE_GET_CLASS(s);
    ram_addr_t start_addr, end_addr, len;
    */
        return;
    /*
     * start_addr is the offset into the ram region. len is the size of the
     * area we want to clear. The region's length must be >= start_addr + len.
    if (qemu_ram_get_used_length(s->managed->ram_block) < (start_addr + len)) {
};
static const Property cmu_properties[] = {
    DEFINE_PROP_UINT64("ram-base", CMUDeviceState, base, 0),
    DEFINE_PROP_UINT64("ram-size", CMUDeviceState, size, 0),
    DEFINE_PROP_LINK("managed-ram", CMUDeviceState, managed,
            TYPE_MEMORY_REGION, MemoryRegion *),
static void cmu_class_init(ObjectClass *oc, const void *data)
    DeviceClass *dc = DEVICE_CLASS(oc);
    device_class_set_props(dc, cmu_properties);
    .class_init = cmu_class_init,

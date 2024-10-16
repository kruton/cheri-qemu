#include "hw/qdev-properties.h"
#ifdef TARGET_CHERI
#include "cheri_tagmem.h"
#endif
{
    }
    CMUClass *c = CMU_DEVICE_GET_CLASS(s);
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

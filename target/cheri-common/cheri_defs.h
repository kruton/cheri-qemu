#else
#endif
#define CHERI_DECLARE_ALIGNED_CC_CAP_T(suffix) \
    typedef struct cc##suffix##_aligned_cap_t {                       \
        cc##suffix##_cap_t cap;                                       \
    } QEMU_ALIGNED(32) cc##suffix##_aligned_cap_t;                    \
    _Static_assert(sizeof(cc##suffix##_aligned_cap_t) % 32 == 0,      \
                   "QEMU_ALIGNED() broken?");                         \
    _Static_assert(offsetof(cc##suffix##_aligned_cap_t, cap) == 0,    \
                   "QEMU_ALIGNED() broken?");
CHERI_DECLARE_ALIGNED_CC_CAP_T(64)
CHERI_DECLARE_ALIGNED_CC_CAP_T(128)
CHERI_DECLARE_ALIGNED_CC_CAP_T(128m)
#  define CHERI_CAP_SIZE 8
#  define CHERI_CAP_SIZE 16
#else
#endif
#  define CHERI_MEM_OFFSET_METADATA 0
#  define CHERI_MEM_OFFSET_CURSOR 0
#ifdef TARGET_MORELLO
#define CAP_PERMS_ALL CAP_CC(PERMS_ALL)
#define CAP_UPERMS_ALL CAP_CC(UPERMS_ALL)
#define CAP_UPERMS_SHFT CAP_CC(UPERMS_SHFT)
#define CAP_MAX_UPERM CAP_CC(MAX_UPERM)
#define CAP_MAX_REPRESENTABLE_OTYPE CAP_CC(MAX_REPRESENTABLE_OTYPE)
#define CAP_OTYPE_UNSEALED CAP_CC(OTYPE_UNSEALED)
#define CAP_OTYPE_SENTRY CAP_CC(OTYPE_SENTRY)
#define CAP_FLAGS_ALL_BITS CAP_CC(FIELD_FLAGS_MASK_NOT_SHIFTED)
#define CAP_MAX_LENGTH CAP_CC(MAX_LENGTH)
#define CAP_MAX_TOP CAP_CC(MAX_TOP)
typedef CAP_cc(cap_t) cap_register_t;
    CAP_PERM_EXECUTE = CAP_CC(PERM_EXECUTE),
    CAP_ACCESS_SYS_REGS = CAP_CC(PERM_ACCESS_SYS_REGS),
    CAP_PERM_GLOBAL = CAP_CC(PERM_GLOBAL),
    CAP_PERM_LOAD = CAP_CC(PERM_LOAD),
    CAP_PERM_STORE = CAP_CC(PERM_STORE),
    CAP_PERM_LOAD_CAP = CAP_CC(PERM_LOAD_CAP),
    CAP_PERM_STORE_CAP = CAP_CC(PERM_STORE_CAP),
    CAP_PERM_STORE_LOCAL = CAP_CC(PERM_STORE_LOCAL),
    CAP_PERM_SEAL = CAP_CC(PERM_SEAL),
    CAP_PERM_CINVOKE = CAP_CC(PERM_CINVOKE),
    CAP_PERM_UNSEAL = CAP_CC(PERM_UNSEAL),
    CAP_PERM_SETCID = CAP_CC(PERM_SETCID),
    /* DDC is tagged, unsealed and cursor (addresss) is zero */
    /* DDC is tagged, unsealed and top is max_addr  */

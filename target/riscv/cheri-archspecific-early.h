 * This controls how many tags are fetched with cgettags/csettags
#define CAP_TAG_GET_MANY_SHFT 3
#endif
#ifdef TARGET_CHERI_RISCV_STD_093
/* Cheri standard 0.9.3 Exception Types */
typedef enum {
    CapEx093_Type_InstrAccess = 0x0,
    CapEx093_Type_Data = 0x1,
    CapEx093_Type_Branch = 0x2,
    CapEx093_Type_Last = CapEx093_Type_Branch,
    CapEx093_Type_None = 0xff,
} Cheri093CapExcType;
    CapEx093_TagViolation = 0x0,
    CapEx093_SealViolation = 0x1,
    CapEx093_PermissionViolation = 0x2,
    CapEx093_InvalidAddressViolation = 0x3,
    CapEx093_BoundsViolation = 0x4,
    CapEx093_Last = CapEx093_BoundsViolation,
    CapEx093_None = 0xff,
} Cheri093CapExcCause;
#define CHERI_CONTROLFLOW_CHECK_AT_TARGET 0
/* TODO: switch tag clearing to true once CheriBSD is ready for it. */
#define CHERI_TAG_CLEAR_ON_INVALID 0
#define CHERI_TAG_CLEAR_ON_INVALID(env) true
#define CHERI_NO_RELOCATION(env)        true
#define CINVOKE_DATA_REGNUM 31
    cheri_debug_assert(env->ddc.cr_extra == CREG_FULLY_DECOMPRESSED);
#define CHERI_GPCAPREGS_MEMBER gpcapregs

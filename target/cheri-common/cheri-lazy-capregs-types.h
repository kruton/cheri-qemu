    CREG_INTEGER = 0b0,
    CREG_UNTAGGED_CAP = 0b01,
    CREG_TAGGED_CAP = 0b10,
    CREG_FULLY_DECOMPRESSED = 0b11,
static inline const char *cap_reg_state_string(CapRegState state)
{
    const char *strings[] = {"Int", "Untagged Cap", "Tagged Cap",
                             "Decompressed"};
    return strings[(int)state];
}

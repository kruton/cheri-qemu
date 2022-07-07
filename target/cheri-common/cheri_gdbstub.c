{
}
static inline void append_tag(GByteArray *buf, uint8_t tag)
    g_byte_array_append(buf, &tag, 1);
    append_tag(buf, cap->cr_tag);
    return CHERI_CAP_SIZE + 1;
    append_tag(buf, get_capreg_tag(env, regnum));

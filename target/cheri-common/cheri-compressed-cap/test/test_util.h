    }
}
std::ostream& operator<<(std::ostream& os, const _cc_bounds_bits& value);
std::ostream& operator<<(std::ostream& os, const _cc_bounds_bits& value) {
    os << "{ B: " << (unsigned)value.B << " T: " << (unsigned)value.T << " E: " << (unsigned)value.E
       << " IE: " << (unsigned)value.IE << " }";
    return os;
std::ostream& operator<<(std::ostream& os, const _cc_cap_t& value);
std::ostream& operator<<(std::ostream& os, const _cc_cap_t& value) {
std::ostream& operator<<(std::ostream& os, const cc128_length_t& value);

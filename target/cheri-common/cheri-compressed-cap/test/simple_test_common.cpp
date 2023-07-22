}
TEST_CASE("pesbt_is_correct ignores cr_extra", "") {
    TestAPICC::cap_t null_cap = TestAPICC::make_null_derived_cap(0);
    CHECK(_cc_N(pesbt_is_correct)(&null_cap));
    // Changing cr_extra previously triggered assertions, check that it is ignored.
    null_cap.cr_extra = 10;

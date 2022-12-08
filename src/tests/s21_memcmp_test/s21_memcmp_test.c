#include "../s21_string_tests.h"

START_TEST(s21_memcmp_1) {
        ck_assert_int_eq(1,1);
} END_TEST

Suite* s21_memcmp_create_suite(void) {
    Suite* s = suite_create("s21_memcmp");
    TCase* tc = tcase_create("Core of s21_memcmp");
    /*Tests*/
    tcase_add_test(tc,s21_memcmp_1);

    suite_add_tcase(s,tc);
    return s;
}

int s21_memcmp_run_test(void) {
    Suite* suite = s21_memcmp_create_suite();
    SRunner* srunner = srunner_create(suite);
    srunner_run_all(srunner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    if (failed_count != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
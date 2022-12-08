#include "../s21_string_tests.h"

START_TEST(s21_sprintf_1) {
        ck_assert_int_eq(1,1);
} END_TEST

        Suite* s21_sprintf_create_suite(void) {
    Suite* s = suite_create("s21_sprintf");
    TCase* tc = tcase_create("Core of s21_sprintf");
    /*Tests*/
    tcase_add_test(tc,s21_sprintf_1);

    suite_add_tcase(s,tc);
    return s;
}

int s21_sprintf_run_test(void) {
    Suite* suite = s21_sprintf_create_suite();
    SRunner* srunner = srunner_create(suite);
    srunner_run_all(srunner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    if (failed_count != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
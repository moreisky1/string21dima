#include "../s21_string_tests.h"

START_TEST(s21_strstr_1) {
        char str[] = "HHello";
        char str2[] = "Hello";
        //char* s21 = s21_strstr(str,str2);
        char* or = strstr(str,str2);
        printf("|%s| / ||\n",or);
        ck_assert_int_eq(1,1);

} END_TEST

START_TEST(s21_strstr_2) {
        ck_assert_int_eq(1,1);
} END_TEST

        Suite* s21_strstr_create_suite(void) {
    Suite* s = suite_create("s21_strstr");
    TCase* tc = tcase_create("Core of s21_strstr");
    /*Tests*/
    tcase_add_test(tc,s21_strstr_1);
    tcase_add_test(tc,s21_strstr_2);
    suite_add_tcase(s,tc);
    return s;
}

int s21_strstr_run_test(void) {
    Suite* suite = s21_strstr_create_suite();
    SRunner* srunner = srunner_create(suite);
    srunner_run_all(srunner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    if (failed_count != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
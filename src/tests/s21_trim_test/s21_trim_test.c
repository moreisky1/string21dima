#include "../s21_string_tests.h"

START_TEST(s21_trim_1) {
    char str[]="   hello             ";
    char ex[]="hello";
    char* s = s21_trim(str," ");
    ck_assert_str_eq(ex,s);
    free(s);
} END_TEST

START_TEST(s21_trim_2) {
    char str[]="   hello             !!!!";
    char ex[]="hello";
    char* s = s21_trim(str," !");
    ck_assert_str_eq(ex,s);
    free(s);
} END_TEST

START_TEST(s21_trim_3) {
    char str[]="   hello             !!!!";
    char* s = s21_trim(str," hello!");
    ck_assert_ptr_null(s);
} END_TEST

START_TEST(s21_trim_4) {
    char* str = NULL;
    char* s = s21_trim(str," !");
    ck_assert_ptr_null(s);
} END_TEST

START_TEST(s21_trim_5) {
    char str[]="   hello             !!!!";
    char ex[]="hello             !!!!";
    char* s = s21_trim(str,NULL);
    ck_assert_str_eq(ex,s);
    free(s);
} END_TEST

START_TEST(s21_trim_6) {
    char* s = s21_trim(NULL,NULL);
    ck_assert_ptr_null(s);
} END_TEST

START_TEST(s21_trim_7) {
    char str[]="   hello             !!!!";
    char ex[]="   hello             !!!!";
    char* s = s21_trim(str,"hello");
    ck_assert_str_eq(ex,s);
    free(s);
} END_TEST

Suite* s21_trim_create_suite(void) {
    Suite* s = suite_create("s21_trim");
    TCase* tc = tcase_create("Core of s21_trim");
    /*Tests*/
    tcase_add_test(tc,s21_trim_1);
    tcase_add_test(tc,s21_trim_2);
    tcase_add_test(tc,s21_trim_3);
    tcase_add_test(tc,s21_trim_4);
    tcase_add_test(tc,s21_trim_5);
    tcase_add_test(tc,s21_trim_6);
    tcase_add_test(tc,s21_trim_7);

    suite_add_tcase(s,tc);
    return s;
}

int s21_trim_run_test(void) {
    Suite* suite = s21_trim_create_suite();
    SRunner* srunner = srunner_create(suite);
    srunner_run_all(srunner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    if (failed_count != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
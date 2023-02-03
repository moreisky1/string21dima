#include "../s21_string_tests.h"

START_TEST(s21_memchr_1) {
    char* as = "Hello";
    char* ex = "Hello";
    char* res_as = (char*)s21_memchr(as,'e',5);
    char* res_ex = (char*)memchr(ex, 'e', 5);
        ck_assert_str_eq(res_as,res_ex);
} END_TEST

START_TEST(s21_memchr_2) {
    char* as = "Hello";
    char* ex = "Hello";
    char* res_as = (char*)s21_memchr(as,'e',3);
    char* res_ex = (char*)memchr(ex, 'e', 3);
    ck_assert_str_eq(res_as,res_ex);
} END_TEST

START_TEST(s21_memchr_3) {
    char* as = "Hello";
    char* ex = "Hello";
    char* res_as = (char*)s21_memchr(as,'l',1);
    char* res_ex = (char*)memchr(ex, 'l', 1);
    ck_assert_ptr_null(res_as);
    ck_assert_ptr_null(res_ex);
} END_TEST

START_TEST(s21_memchr_4) {
    char* as = "Hello";
    char* ex = "Hello";
    char* res_as = (char*)s21_memchr(as,'e',55);
    char* res_ex = (char*)memchr(ex, 'e', 55);
    ck_assert_str_eq(res_as,res_ex);
} END_TEST

START_TEST(s21_memchr_5) {
    char* as = "12341234\n\n\n\n\n\n";
    char* ex = "12341234\n\n\n\n\n\n";
    char* res_as = (char*)s21_memchr(as,'e',5);
    char* res_ex = (char*)memchr(ex, 'e', 5);
    ck_assert_ptr_null(res_as);
    ck_assert_ptr_null(res_ex);
} END_TEST

START_TEST(s21_memchr_6) {
    char* as = "\0";
    char* ex = "\0";
    char* res_as = (char*)s21_memchr("Hello",'e',5);
    char* res_ex = (char*)memchr("Hello", 'e', 5);
    ck_assert_str_eq(res_as,res_ex);
} END_TEST

Suite* s21_memchr_create_suite(void) {
    Suite* s = suite_create("s21_memchr");
    TCase* tc = tcase_create("Core of s21_memchr");
    /*Tests*/
    tcase_add_test(tc,s21_memchr_1);
    tcase_add_test(tc,s21_memchr_2);
    tcase_add_test(tc,s21_memchr_3);
    tcase_add_test(tc,s21_memchr_4);
    tcase_add_test(tc,s21_memchr_5);
    tcase_add_test(tc,s21_memchr_6);
    suite_add_tcase(s,tc);
    return s;
}

int s21_memchr_run_test(void) {
    Suite* suite = s21_memchr_create_suite();
    SRunner* srunner = srunner_create(suite);
    srunner_run_all(srunner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    if (failed_count != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
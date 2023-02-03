#include "../s21_string_tests.h"

START_TEST(s21_memcmp_1) {
    char* st_as = "Hello";
    char* st_ex = "Hello";
    int res_s21 = s21_memcmp(st_as,st_ex,5);
    int res_or = memcmp(st_as,st_ex,5);
    printf("--> %d --> %d | \n", res_s21, res_or);
        ck_assert_int_eq(res_s21,res_or);
} END_TEST

START_TEST(s21_memcmp_2) {
    char* st_as = "Hello";
    char* st_ex = "Hel";
    int res_s21 = s21_memcmp(st_as,st_ex,5);
    int res_or = memcmp(st_as,st_ex,5);
    printf("--> %d --> %d | \n", res_s21, res_or);
    ck_assert_int_eq(res_s21,res_or);
} END_TEST

START_TEST(s21_memcmp_3) {
    char* st_as = "12345";
    char* st_ex = "1232";
    int res_s21 = s21_memcmp(st_as,st_ex,5);
    int res_or = memcmp(st_as,st_ex,5);
    printf("--> %d --> %d | \n", res_s21, res_or);
    ck_assert_int_eq(res_s21,res_or);
} END_TEST

START_TEST(s21_memcmp_4) {
    char* st_as = "12345";
    char* st_ex = "1235";
    int res_s21 = s21_memcmp(st_as,st_ex,5);
    int res_or = memcmp(st_as,st_ex,5);
    printf("--> %d --> %d | \n", res_s21, res_or);
    ck_assert_int_eq(res_s21,res_or);
} END_TEST

START_TEST(s21_memcmp_5) {
    char* st_as = "12345";
    char* st_ex = "|";
    int res_s21 = s21_memcmp(st_as,st_ex,5);
    int res_or = memcmp(st_as,st_ex,5);
    printf("--> %d --> %d | \n", res_or, res_or);
    ck_assert_int_eq(1,1);
} END_TEST

START_TEST(s21_memcmp_6) {
    char* st_as = "NULL";
    char* st_ex = "\0";
    int res_s21 = s21_memcmp(st_as,st_ex,5);
    int res_or = memcmp(st_as,st_ex,5);
    printf("--> %d --> %d | \n", res_s21, res_or);
    ck_assert_int_eq(1,1);
} END_TEST

START_TEST(s21_memcmp_7) {
    char* st_as = "\0 2 \0\0\0\0\0";
    char* st_ex = "\0 1 \0\0\0\0\0";
    int res_s21 = s21_memcmp(st_as,st_ex,5);
    int res_or = memcmp(st_as,st_ex,5);
    printf("--> %d --> %d | \n", res_s21, res_or);
    ck_assert_int_eq(1,1);
} END_TEST

Suite* s21_memcmp_create_suite(void) {
    Suite* s = suite_create("s21_memcmp");
    TCase* tc = tcase_create("Core of s21_memcmp");
    /*Tests*/
    tcase_add_test(tc,s21_memcmp_1);
    tcase_add_test(tc,s21_memcmp_2);
    tcase_add_test(tc,s21_memcmp_3);
    tcase_add_test(tc,s21_memcmp_4);
    tcase_add_test(tc,s21_memcmp_5);
    tcase_add_test(tc,s21_memcmp_6);
    tcase_add_test(tc,s21_memcmp_7);
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
#include "../s21_string_tests.h"

START_TEST(s21_strstr_1) {
        char str[] = "HHelloHelsdfgsbsb";
        char str2[] = "sd";
        // char* s21 = s21_strstr(str,str2);
        // char* or = strstr(str,str2);
        ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_2) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_3) {
    char str[] = "Hello";
    char str2[] = "Hello";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_4) {
    char str[] = "Hello\n";
    char str2[] = "ll";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_5) {
    char str[] = "School21";
    char str2[] = "21";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_6) {
    char str[] = "Fooo";
    char str2[] = "o";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_7) {
    char str[] = "aaaaaaaaaaa";
    char str2[] = "a";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_8) {
    char str[] = "d;hm'lkms'fbmbstmas"
                 "ae"
                 "s"
                 "b',s"
                 "b,"
                 "bs"
                 "b,"
                 "";
    char str2[] = "m";
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_9) {
    char str[] = "ShaitanPetrovich";
    char str2[] = "Petr";
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_10) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_11) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_12) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_13) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_14) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_15) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_16) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_17) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_18) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_19) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_20) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

START_TEST(s21_strstr_21) {
    char str[] = "nulllll";
    char str2[] = "u";
    // char* s21 = s21_strstr(str,str2);
    // char* or = strstr(str,str2);
    ck_assert_str_eq(s21_strstr(str,str2),strstr(str,str2));

} END_TEST

Suite* s21_strstr_create_suite(void) {
    Suite* s = suite_create("s21_strstr");
    TCase* tc = tcase_create("Core of s21_strstr");
    /*Tests*/
    tcase_add_test(tc,s21_strstr_1);
    tcase_add_test(tc,s21_strstr_2);
    tcase_add_test(tc,s21_strstr_3);
    tcase_add_test(tc,s21_strstr_4);
    tcase_add_test(tc,s21_strstr_5);
    tcase_add_test(tc,s21_strstr_6);
    tcase_add_test(tc,s21_strstr_7);
    tcase_add_test(tc,s21_strstr_8);
    tcase_add_test(tc,s21_strstr_9);
    tcase_add_test(tc,s21_strstr_10);
    tcase_add_test(tc,s21_strstr_11);
    tcase_add_test(tc,s21_strstr_12);
    tcase_add_test(tc,s21_strstr_13);
    tcase_add_test(tc,s21_strstr_14);
    tcase_add_test(tc,s21_strstr_15);
    tcase_add_test(tc,s21_strstr_16);
    tcase_add_test(tc,s21_strstr_17);
    tcase_add_test(tc,s21_strstr_18);
    tcase_add_test(tc,s21_strstr_19);
    tcase_add_test(tc,s21_strstr_20);
    tcase_add_test(tc,s21_strstr_21);
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
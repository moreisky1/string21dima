#include "../s21_string_tests.h"

START_TEST(s21_strncmp_1) {
    char* str1 = "Hello";
    char* str2 = "Hello";
    int n = 5;
    int ac = s21_strncmp(str1,str2,n);
    int ex = strncmp(str1,str2,n);
    //printf("--> %d --> %d \n",ac,ex);
        ck_assert_int_eq(ac,ex);
} END_TEST

START_TEST(s21_strncmp_2) {
    char* str1 = "Hello";
    char* str2 = "Hel";
    int n = 5;
    int ac = s21_strncmp(str1,str2,n);
    int ex = strncmp(str1,str2,n);
    //printf("--> %d --> %d \n",ac,ex);
    ck_assert_int_eq(ac,ex);
} END_TEST

START_TEST(s21_strncmp_3) {
    char* str1 = "Hel";
    char* str2 = "Hello";
    int n = 5;
    int ac = s21_strncmp(str1,str2,n);
    int ex = strncmp(str1,str2,n);
    //printf("--> %d --> %d \n",ac,ex);
    ck_assert_int_eq(ac,ex);
} END_TEST

START_TEST(s21_strncmp_4) {
    char* str1 = "Hello";
    char* str2 = "Hel234234";
    int n = 2;
    int ac = s21_strncmp(str1,str2,n);
    int ex = strncmp(str1,str2,n);
    //printf("--> %d --> %d \n",ac,ex);
    ck_assert_int_eq(ac,ex);
} END_TEST

START_TEST(s21_strncmp_5) {
    char* str1 = "123123123";
    char* str2 = "Hello";
    int n = 100;
    int ac = s21_strncmp(str1,str2,n);
    int ex = strncmp(str1,str2,n);
    //printf("--> %d --> %d \n",ac,ex);
    ck_assert_int_eq(ac,ex);
} END_TEST

        Suite* s21_strncmp_create_suite(void) {
    Suite* s = suite_create("s21_strncmp");
    TCase* tc = tcase_create("Core of s21_strncmp");
    /*Tests*/
    tcase_add_test(tc,s21_strncmp_1);
    tcase_add_test(tc,s21_strncmp_2);
    tcase_add_test(tc,s21_strncmp_3);
    tcase_add_test(tc,s21_strncmp_4);
    tcase_add_test(tc,s21_strncmp_5);
    suite_add_tcase(s,tc);
    return s;
}

int s21_strncmp_run_test(void) {
    Suite* suite = s21_strncmp_create_suite();
    SRunner* srunner = srunner_create(suite);
    srunner_run_all(srunner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    if (failed_count != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
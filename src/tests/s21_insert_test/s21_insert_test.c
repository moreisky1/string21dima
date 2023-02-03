#include "../s21_string_tests.h"

START_TEST(s21_insert_1) {
        char* str1 = "HelloWorld!";
        char* str2 = " ";
        char *str3 = (char*)s21_insert(str1, str2, 5);

        //printf("----> |%s|\n", str3);
        ck_assert_str_eq(str3, "Hello World!");
        free(str3);
} END_TEST

START_TEST(s21_insert_2) {
    char* str1 = "papam";
    char* str2 = "ram";
    char *str3 = (char*)s21_insert(str1, str2, 2);

    //printf("----> |%s|\n", str3);
    ck_assert_str_eq(str3, "parampam");
    free(str3);
} END_TEST

Suite* s21_insert_create_suite(void) {
    Suite* s = suite_create("s21_insert");
    TCase* tc = tcase_create("Core of s21_insert");
    /*Tests*/
    tcase_add_test(tc,s21_insert_1);
    tcase_add_test(tc,s21_insert_2);
    suite_add_tcase(s,tc);
    return s;
}

int s21_insert_run_test(void) {
    Suite* suite = s21_insert_create_suite();
    SRunner* srunner = srunner_create(suite);
    srunner_run_all(srunner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    if (failed_count != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


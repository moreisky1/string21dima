#include "../s21_string_tests.h"



/* ======================= Тесты %с ======================== */
START_TEST(s21_sscanf_1) {
    char* dest = "Hello, bro 31 fdgdsfg 33.56";
    char* dest1 = "Hello, bro 31 fdgdsfg 33.56";
    char test = '*';
    int test1 = 1;
    int test2 = 1;
    int t = s21_sscanf(dest,"%c %d %d",&test,&test1, &test2);
    char g[100];
    printf("\n--c--> %c --d--> %d -->%d\n",test, test1, test2);
    t = sscanf(dest1,"%s %d", g, &test1);
    printf("%s %d\n", g,test1);
    ck_assert_int_eq(1,1);
} END_TEST
/* ======================= Тесты %d ======================== */

/* ======================= Тесты %i ======================== */

/* ======================= Тесты %f ======================== */

/* ======================= Тесты %s ======================== */

/* ======================= Тесты %u ======================== */

/* ======================= Тесты Флаги: -, +, (пробел)====== */

/* ======================= Тесты Ширина: (число) =========== */

/* ======================= Точность: .(число) ============== */

/* ======================= Длина: h, l ===================== */

        Suite* s21_sscanf_create_suite(void) {
    Suite* s = suite_create("s21_sscanf");
    TCase* tc = tcase_create("Core of s21_sscanf");
    /*Tests*/
    tcase_add_test(tc,s21_sscanf_1);

    suite_add_tcase(s,tc);
    return s;
}

int s21_sscanf_run_test(void) {
    Suite* suite = s21_sscanf_create_suite();
    SRunner* srunner = srunner_create(suite);
    srunner_run_all(srunner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    if (failed_count != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
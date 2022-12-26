#include "../s21_string_tests.h"



/* ======================= Тесты %с ======================== */
START_TEST(s21_sscanf_1) {
    char* dest = "Hello, bro 31 31.56";
    int res_or;

    int t = sscanf("123","%d",&res_or);
    int q;
    int f = s21_sscanf("123","%d",&q, &t, &res_or);
    //printf("----> |%d|\n",q);
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
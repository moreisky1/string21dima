#include "../s21_string_tests.h"

START_TEST(s21_strrchr_1) {
  char str[] = "Hello World";
  char c = 'l';
  char *ac = s21_strrchr(str, c);
  char *ex = strrchr(str, c);
  // printf("--> |%s| --> |%s|\n", ac, ex);
  ck_assert_str_eq(ac, ex);
}
END_TEST

START_TEST(s21_strrchr_2) {
  char str[] = "Hello World";
  char c = 'W';
  char *ac = s21_strrchr(str, c);
  char *ex = strrchr(str, c);
  // printf("--> |%s| --> |%s|\n", ac, ex);
  ck_assert_str_eq(ac, ex);
}
END_TEST

START_TEST(s21_strrchr_3) {
  char str[] = "Hello World";
  char c = 'H';
  char *ac = s21_strrchr(str, c);
  char *ex = strrchr(str, c);
  // printf("--> |%s| --> |%s|\n", ac, ex);
  ck_assert_str_eq(ac, ex);
}
END_TEST

START_TEST(s21_strrchr_4) {
  char str[] = "Hello World";
  char c = 'i';
  char *ac = s21_strrchr(str, c);
  char *ex = strrchr(str, c);
  // printf("--> |%s| --> |%s|\n", ac, ex);
  ck_assert_ptr_null(ac);
  ck_assert_ptr_null(ex);
}
END_TEST

START_TEST(s21_strrchr_5) {
  char str[] = "Hello World";
  char c = '\0';
  char *ac = s21_strrchr(str, c);
  char *ex = strrchr(str, c);
  // printf("--> |%s| --> |%s|\n", ac, ex);
  ck_assert_str_eq(ac, ex);
}
END_TEST

Suite *s21_strrchr_create_suite(void) {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("Core of s21_strrchr");
  /*Tests*/
  tcase_add_test(tc, s21_strrchr_1);
  tcase_add_test(tc, s21_strrchr_2);
  tcase_add_test(tc, s21_strrchr_3);
  tcase_add_test(tc, s21_strrchr_4);
  tcase_add_test(tc, s21_strrchr_5);
  suite_add_tcase(s, tc);
  return s;
}

int s21_strrchr_run_test(void) {
  Suite *suite = s21_strrchr_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
#include "../s21_string_tests.h"

START_TEST(s21_strerror_1) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(s21_strerror_2) {
  int n = -1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

Suite *s21_strerror_create_suite(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("Core of s21_strerror");
  /*Tests*/
  tcase_add_test(tc, s21_strerror_1);
  tcase_add_test(tc, s21_strerror_2);

  suite_add_tcase(s, tc);
  return s;
}

int s21_strerror_run_test(void) {
  Suite *suite = s21_strerror_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
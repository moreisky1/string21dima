#include "../s21_string_tests.h"

START_TEST(s21_strncpy_1) {
  char src[10] = "Hello";
  char dest_ac[10];
  s21_strncpy(dest_ac, src, 10);
  char dest_ex[10];
  strncpy(dest_ex, src, 10);

  ck_assert_str_eq(dest_ac, src);
  ck_assert_str_eq(src, dest_ex);
  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

START_TEST(s21_strncpy_2) {
  char src[10] = "";
  char dest_ac[10];
  s21_strncpy(dest_ac, src, 1);
  char dest_ex[10];
  strncpy(dest_ex, src, 1);

  ck_assert_str_eq(dest_ac, src);
  ck_assert_str_eq(src, dest_ex);
  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

START_TEST(s21_strncpy_3) {
  char src[100] = "aaaaaaaaaaa|";
  char dest_ac[100];
  char dest_ex[100];
  s21_strncpy(dest_ex, src, 5);
  strncpy(dest_ac, src, 5);

  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

START_TEST(s21_strncpy_4) {
  char *src = "\n\n\n\n\n\n";
  char dest_ac[10];
  s21_strncpy(dest_ac, src, 3);
  char dest_ex[10];
  strncpy(dest_ex, src, 3);

  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

START_TEST(s21_strncpy_5) {
  char src[100] = "Hello\n Wor\0ld ";
  char dest_ac[100];
  s21_strncpy(dest_ac, src, 5);
  char dest_ex[100];
  strncpy(dest_ex, src, 5);

  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

START_TEST(s21_strncpy_6) {
  char src[10] = "\0";
  char dest_ac[10];
  s21_strncpy(dest_ac, src, 1);
  char dest_ex[10];
  strncpy(dest_ex, src, 1);

  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

Suite *s21_strncpy_create_suite(void) {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc = tcase_create("Core of s21_strncpy");
  /*Tests*/
  tcase_add_test(tc, s21_strncpy_1);
  tcase_add_test(tc, s21_strncpy_2);
  tcase_add_test(tc, s21_strncpy_3);
  tcase_add_test(tc, s21_strncpy_4);
  tcase_add_test(tc, s21_strncpy_5);
  tcase_add_test(tc, s21_strncpy_6);

  suite_add_tcase(s, tc);
  return s;
}

int s21_strncpy_run_test(void) {
  Suite *suite = s21_strncpy_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
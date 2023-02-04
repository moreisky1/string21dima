#include "../s21_string_tests.h"

START_TEST(s21_strcpy_1) {
  char src[10] = "Hello";
  char dest_ac[10];
  s21_strcpy(dest_ac, src);
  char dest_ex[10];
  strcpy(dest_ex, src);

  ck_assert_str_eq(dest_ac, src);
  ck_assert_str_eq(src, dest_ex);
  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

START_TEST(s21_strcpy_2) {
  char src[10] = "";
  char dest_ac[10];
  s21_strcpy(dest_ac, src);
  char dest_ex[10];
  strcpy(dest_ex, src);

  ck_assert_str_eq(dest_ac, src);
  ck_assert_str_eq(src, dest_ex);
  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

START_TEST(s21_strcpy_3) {
  char src[100] = "^^^^^|\n ;oerkg;dogn\bsdrd";
  char dest_ac[100];
  s21_strcpy(dest_ac, src);
  char dest_ex[100];
  strcpy(dest_ex, src);

  ck_assert_str_eq(dest_ac, src);
  ck_assert_str_eq(src, dest_ex);
  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

START_TEST(s21_strcpy_4) {
  char *src = "\n\n\n\n\n\n";
  char dest_ac[10];
  s21_strcpy(dest_ac, src);
  char dest_ex[10];
  strcpy(dest_ex, src);

  ck_assert_str_eq(dest_ac, src);
  ck_assert_str_eq(src, dest_ex);
  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

START_TEST(s21_strcpy_5) {
  char src[100] = "Hello\n Wor\0ld ";
  char dest_ac[100];
  s21_strcpy(dest_ac, src);
  char dest_ex[100];
  strcpy(dest_ex, src);

  ck_assert_str_eq(dest_ac, src);
  ck_assert_str_eq(src, dest_ex);
  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

START_TEST(s21_strcpy_6) {
  char src[10] = "\0";
  char dest_ac[10];
  s21_strcpy(dest_ac, src);
  char dest_ex[10];
  strcpy(dest_ex, src);

  ck_assert_str_eq(dest_ac, src);
  ck_assert_str_eq(src, dest_ex);
  ck_assert_str_eq(dest_ac, dest_ex);
}
END_TEST

Suite *s21_strcpy_create_suite(void) {
  Suite *s = suite_create("s21_strcpy");
  TCase *tc = tcase_create("Core of s21_strcpy");
  /*Tests*/
  tcase_add_test(tc, s21_strcpy_1);
  tcase_add_test(tc, s21_strcpy_2);
  tcase_add_test(tc, s21_strcpy_3);
  tcase_add_test(tc, s21_strcpy_4);
  tcase_add_test(tc, s21_strcpy_5);
  tcase_add_test(tc, s21_strcpy_6);
  suite_add_tcase(s, tc);
  return s;
}

int s21_strcpy_run_test(void) {
  Suite *suite = s21_strcpy_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
#include "../s21_string_tests.h"

START_TEST(s21_strspn_1) {
  const char *str1 = "Hello World";
  const char *str2 = "Hello";
  size_t ac = s21_strspn(str1, str2);
  size_t ex = strspn(str1, str2);
  // printf("--> %d --> %d\n", ac, ex);
  ck_assert_int_eq(ac, ex);
}
END_TEST

START_TEST(s21_strspn_2) {
  const char *str1 = "Hello World";
  const char *str2 = "World";
  size_t ac = s21_strspn(str1, str2);
  size_t ex = strspn(str1, str2);
  // printf("--> %d --> %d\n", ac, ex);
  ck_assert_int_eq(ac, ex);
}
END_TEST

START_TEST(s21_strspn_3) {
  const char *str1 = "Hello World";
  const char *str2 = "Vap";
  size_t ac = s21_strspn(str1, str2);
  size_t ex = strspn(str1, str2);
  // printf("--> %d --> %d\n", ac, ex);
  ck_assert_int_eq(ac, ex);
}
END_TEST

START_TEST(s21_strspn_4) {
  const char *str1 = "Hello World";
  const char *str2 = "\0";
  size_t ac = s21_strspn(str1, str2);
  size_t ex = strspn(str1, str2);
  // printf("--> %d --> %d\n", ac, ex);
  ck_assert_int_eq(ac, ex);
}
END_TEST

START_TEST(s21_strspn_5) {
  const char *str1 = "Hello World";
  const char *str2 = "dlroW olleH";
  size_t ac = s21_strspn(str1, str2);
  size_t ex = strspn(str1, str2);
  // printf("--> %d --> %d\n", ac, ex);
  ck_assert_int_eq(ac, ex);
}
END_TEST

Suite *s21_strspn_create_suite(void) {
  Suite *s = suite_create("s21_strspn");
  TCase *tc = tcase_create("Core of s21_strspn");
  /*Tests*/
  tcase_add_test(tc, s21_strspn_1);
  tcase_add_test(tc, s21_strspn_2);
  tcase_add_test(tc, s21_strspn_3);
  tcase_add_test(tc, s21_strspn_4);
  tcase_add_test(tc, s21_strspn_5);
  suite_add_tcase(s, tc);
  return s;
}

int s21_strspn_run_test(void) {
  Suite *suite = s21_strspn_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
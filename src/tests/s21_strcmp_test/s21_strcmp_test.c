#include "../s21_string_tests.h"

START_TEST(s21_strcmp_1) {
  const char *str1 = "Hello";
  const char *str2 = "Hello";
  int res_as = s21_strcmp(str1, str2);
  int res_ex = strcmp(str1, str2);
  // printf("--> %d --> %d\n",res_as,res_ex);
  ck_assert_int_eq(res_ex, res_as);
}
END_TEST

START_TEST(s21_strcmp_2) {
  const char *str1 = "Hello";
  const char *str2 = "Hel";
  int res_as = s21_strcmp(str1, str2);
  int res_ex = strcmp(str1, str2);
  // printf("--> %d --> %d\n",res_as,res_ex);
  ck_assert_int_eq(res_ex, res_as);
}
END_TEST

START_TEST(s21_strcmp_3) {
  const char *str1 = "123456";
  const char *str2 = "123467";
  int res_as = s21_strcmp(str1, str2);
  int res_ex = strcmp(str1, str2);
  // printf("--> %d --> %d\n",res_as,res_ex);
  ck_assert_int_eq(res_as, res_ex);
}
END_TEST

START_TEST(s21_strcmp_4) {
  const char *str1 = "123456";
  const char *str2 = "1222222";
  int res_as = s21_strcmp(str1, str2);
  int res_ex = strcmp(str1, str2);
  // printf("--> %d --> %d\n",res_as,res_ex);
  ck_assert_int_eq(res_as, res_ex);
}
END_TEST

START_TEST(s21_strcmp_5) {
  const char *str1 = "";
  const char *str2 = "";
  int res_as = s21_strcmp(str1, str2);
  int res_ex = strcmp(str1, str2);
  // printf("--> %d --> %d\n",res_as,res_ex);
  ck_assert_int_eq(res_as, res_ex);
}
END_TEST

Suite *s21_strcmp_create_suite(void) {
  Suite *s = suite_create("s21_strcmp");
  TCase *tc = tcase_create("Core of s21_strcmp");
  /*Tests*/
  tcase_add_test(tc, s21_strcmp_1);
  tcase_add_test(tc, s21_strcmp_2);
  tcase_add_test(tc, s21_strcmp_3);
  tcase_add_test(tc, s21_strcmp_4);
  tcase_add_test(tc, s21_strcmp_5);

  suite_add_tcase(s, tc);
  return s;
}

int s21_strcmp_run_test(void) {
  Suite *suite = s21_strcmp_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
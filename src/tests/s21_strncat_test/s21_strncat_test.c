#include "../s21_string_tests.h"

START_TEST(s21_strncat_1) {
  char str_dest_as[100] = "Hello";
  char str_dest_eq[100] = "Hello";
  const char str_src[] = " World";
  ck_assert_str_eq(s21_strncat(str_dest_as, str_src, 100),
                   strncat(str_dest_eq, str_src, 100));
}
END_TEST

START_TEST(s21_strncat_2) {
  char str_dest_as[100] = "Hello";
  char str_dest_eq[100] = "Hello";
  const char str_src[] = " World";
  ck_assert_str_eq(s21_strncat(str_dest_as, str_src, 2),
                   strncat(str_dest_eq, str_src, 2));
}
END_TEST

START_TEST(s21_strncat_3) {
  char str_dest_as[100] = "Hello";
  char str_dest_eq[100] = "Hello";
  const char str_src[] = " World";
  ck_assert_str_eq(s21_strncat(str_dest_as, str_src, 0),
                   strncat(str_dest_eq, str_src, 0));
}
END_TEST

START_TEST(s21_strncat_4) {
  char str_dest_as[100] = "\0";
  char str_dest_eq[100] = "\0";
  const char *str_src = "Hello";
  ck_assert_str_eq(s21_strncat(str_dest_as, str_src, 3),
                   strncat(str_dest_eq, str_src, 3));
}
END_TEST

START_TEST(s21_strncat_5) {
  char str_dest_as[100] = "Hello";
  char str_dest_eq[100] = "Hello";
  const char str_src[] = " \0";
  ck_assert_str_eq(s21_strncat(str_dest_as, str_src, 1),
                   strncat(str_dest_eq, str_src, 1));
}
END_TEST

START_TEST(s21_strncat_6) {
  char str_dest_as[100] = "Hello";
  char str_dest_eq[100] = "Hello";
  const char str_src[] = "\0";
  ck_assert_str_eq(s21_strncat(str_dest_as, str_src, 5),
                   strncat(str_dest_eq, str_src, 5));
}
END_TEST

START_TEST(s21_strncat_7) {
  char str_dest_as[100] = "\0";
  char str_dest_eq[100] = "\0";
  const char str_src[] = "\0";
  ck_assert_str_eq(s21_strncat(str_dest_as, str_src, 1),
                   strncat(str_dest_eq, str_src, 1));
}
END_TEST

Suite *s21_strncat_create_suite(void) {
  Suite *s = suite_create("s21_strncat");
  TCase *tc = tcase_create("Core of s21_strncat");
  /*Tests*/
  tcase_add_test(tc, s21_strncat_1);
  tcase_add_test(tc, s21_strncat_2);
  tcase_add_test(tc, s21_strncat_3);
  tcase_add_test(tc, s21_strncat_4);
  tcase_add_test(tc, s21_strncat_5);
  tcase_add_test(tc, s21_strncat_6);
  tcase_add_test(tc, s21_strncat_7);
  suite_add_tcase(s, tc);
  return s;
}

int s21_strncat_run_test(void) {
  Suite *suite = s21_strncat_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
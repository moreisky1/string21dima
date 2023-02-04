#include "../s21_string_tests.h"

START_TEST(s21_memmove_1) {
  char dest_as[100] = "Hello";
  char dest_ex[100] = "Hello";
  const char *src = " World";
  size_t n = 5;

  memmove(dest_ex, src, n);
  s21_memmove(dest_as, src, n);
  //   printf("--> |%s| --> |%s|\n",dest_as, dest_ex);

  int res_as = memcmp(dest_as, dest_ex, n);
  int res_ex = memcmp(dest_as, dest_ex, n);
  ck_assert_int_eq(res_ex, res_as);
}
END_TEST

START_TEST(s21_memmove_2) {
  char dest_as[100] = "Hello";
  char dest_ex[100] = "Hello";
  const char *src = " Wor\0ld";
  size_t n = 10;

  memmove(dest_ex, src, n);
  s21_memmove(dest_as, src, n);
  //   printf("--> |%s| --> |%s|\n",dest_as, dest_ex);

  int res_as = memcmp(dest_as, dest_ex, n);
  int res_ex = memcmp(dest_as, dest_ex, n);
  ck_assert_int_eq(res_ex, res_as);
}
END_TEST

START_TEST(s21_memmove_3) {
  char dest_as[100] = "Hello";
  char dest_ex[100] = "Hello";
  const char *src = "";
  size_t n = 10;

  memmove(dest_ex, src, n);
  s21_memmove(dest_as, src, n);
  //   printf("--> |%s| --> |%s|\n",dest_as, dest_ex);

  int res_as = memcmp(dest_as, dest_ex, n);
  int res_ex = memcmp(dest_as, dest_ex, n);
  ck_assert_int_eq(res_ex, res_as);
}
END_TEST

START_TEST(s21_memmove_4) {
  char dest_as[100] = "Hello";
  char dest_ex[100] = "Hello";
  const char *src = "Wiii";
  size_t n = 0;

  memmove(dest_ex, src, n);
  s21_memmove(dest_as, src, n);
  //    printf("--> |%s| --> |%s|\n",dest_as, dest_ex);

  int res_as = memcmp(dest_as, dest_ex, n);
  int res_ex = memcmp(dest_as, dest_ex, n);
  ck_assert_int_eq(res_ex, res_as);
}
END_TEST

START_TEST(s21_memmove_5) {
  char dest_as[100] = "Hello";
  char dest_ex[100] = "Hello";
  const char *src = "\0\0\0\0\0\0\0\0\0\0\0\n";
  size_t n = 10;

  memmove(dest_ex, src, n);
  s21_memmove(dest_as, src, n);
  //    printf("--> |%s| --> |%s|\n",dest_as, dest_ex);

  int res_as = memcmp(dest_as, dest_ex, n);
  int res_ex = memcmp(dest_as, dest_ex, n);
  ck_assert_int_eq(res_ex, res_as);
}
END_TEST

Suite *s21_memmove_create_suite(void) {
  Suite *s = suite_create("s21_memmove");
  TCase *tc = tcase_create("Core of s21_memmove");
  /*Tests*/
  tcase_add_test(tc, s21_memmove_1);
  tcase_add_test(tc, s21_memmove_2);
  tcase_add_test(tc, s21_memmove_3);
  tcase_add_test(tc, s21_memmove_4);
  tcase_add_test(tc, s21_memmove_5);

  suite_add_tcase(s, tc);
  return s;
}

int s21_memmove_run_test(void) {
  Suite *suite = s21_memmove_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

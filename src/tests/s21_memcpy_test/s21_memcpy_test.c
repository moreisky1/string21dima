#include "../s21_string_tests.h"

START_TEST(s21_memcpy_1) {
  char dest_as[10] = "Hello";
  char dest_ex[10] = "Hello";
  char src[10] = " World";
  s21_memcpy(dest_as, src, 10);
  memcpy(dest_ex, src, 10);
  //    printf("--> |%s| --> |%s|\n",dest_as, dest_ex);
  ck_assert_str_eq(dest_ex, dest_as);
}
END_TEST

START_TEST(s21_memcpy_2) {
  char dest_as[10] = "Hello";
  char dest_ex[10] = "Hello";
  char src[10] = " Wor\0ld";
  s21_memcpy(dest_as, src, 10);
  memcpy(dest_ex, src, 10);
  //    printf("--> |%s| --> |%s|\n",dest_as, dest_ex);
  ck_assert_str_eq(dest_ex, dest_as);
}
END_TEST

START_TEST(s21_memcpy_3) {
  char dest_as[20] = "\0\0\0\0\0\0\0";
  char dest_ex[20] = "\0\0\0\0\0\0\0";
  char src[20] = " W\n\n\n\n\n\t\0ld";
  s21_memcpy(dest_as, src, 10);
  memcpy(dest_ex, src, 10);
  //    printf("--> |%s| --> |%s|\n",dest_as, dest_ex);
  ck_assert_str_eq(dest_ex, dest_as);
}
END_TEST

START_TEST(s21_memcpy_4) {
  char dest_as[10] = "Hello";
  char dest_ex[10] = "Hello";
  char src[10] = " Wor\nld";
  s21_memcpy(dest_as, src, 10);
  memcpy(dest_ex, src, 10);
  //    printf("--> |%s| --> |%s|\n",dest_as, dest_ex);
  ck_assert_str_eq(dest_ex, dest_as);
}
END_TEST

START_TEST(s21_memcpy_5) {
  char dest_as[10] = "Hello";
  char dest_ex[10] = "Hello";
  char src[10] = " Dranick\n";
  s21_memcpy(dest_as, src, 10);
  memcpy(dest_ex, src, 10);
  //    printf("--> |%s| --> |%s|\n",dest_as, dest_ex);
  ck_assert_str_eq(dest_ex, dest_as);
}
END_TEST

Suite *s21_memcpy_create_suite(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc = tcase_create("Core of s21_memcpy");
  /*Tests*/
  tcase_add_test(tc, s21_memcpy_1);
  tcase_add_test(tc, s21_memcpy_2);
  tcase_add_test(tc, s21_memcpy_3);
  tcase_add_test(tc, s21_memcpy_4);
  tcase_add_test(tc, s21_memcpy_5);
  suite_add_tcase(s, tc);
  return s;
}

int s21_memcpy_run_test(void) {
  Suite *suite = s21_memcpy_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

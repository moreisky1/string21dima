#include "test_me.h"

START_TEST(test_insert_1) {}
END_TEST

START_TEST(test_insert_2) {}
END_TEST

START_TEST(test_insert_3) {}
END_TEST

START_TEST(test_insert_4) {}
END_TEST

START_TEST(test_insert_5) {}
END_TEST

START_TEST(test_insert_6) {}
END_TEST

START_TEST(test_insert_7) {}
END_TEST

START_TEST(test_insert_8) {}
END_TEST

START_TEST(test_insert_9) {}
END_TEST

START_TEST(test_insert_10) {}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("\033[45m-=S21_INSERT=-\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, test_insert_1);
  tcase_add_test(tc, test_insert_2);
  tcase_add_test(tc, test_insert_3);
  tcase_add_test(tc, test_insert_4);
  tcase_add_test(tc, test_insert_5);
  tcase_add_test(tc, test_insert_6);
  tcase_add_test(tc, test_insert_7);
  tcase_add_test(tc, test_insert_8);
  tcase_add_test(tc, test_insert_9);
  tcase_add_test(tc, test_insert_10);

  suite_add_tcase(s, tc);
  return s;
}

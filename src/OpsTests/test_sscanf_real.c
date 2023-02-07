#include "test_me.h"

Suite *test_sscanf_real(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_REAL=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf1);
  tcase_add_test(tc, sscanf2);
  tcase_add_test(tc, sscanf3);
  tcase_add_test(tc, sscanf4);
  tcase_add_test(tc, sscanf5);
  tcase_add_test(tc, sscanf6);
  tcase_add_test(tc, sscanf7);
  tcase_add_test(tc, sscanf8);
  tcase_add_test(tc, sscanf9);
  tcase_add_test(tc, sscanf_0);
  tcase_add_test(tc, sscanf_1);
  tcase_add_test(tc, sscanf_2);
  tcase_add_test(tc, sscanf_3);
  tcase_add_test(tc, sscanf_4);
  tcase_add_test(tc, sscanf_5);
  tcase_add_test(tc, sscanf_8);
  tcase_add_test(tc, sscanf_9);

  suite_add_tcase(s, tc);
  return s;
}
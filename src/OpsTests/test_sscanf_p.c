#include "test_me.h"

Suite *test_sscanf_p(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_P=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_);
  tcase_add_test(tc, sscanf_);
  tcase_add_test(tc, sscanf_);
  tcase_add_test(tc, sscanf_);
  tcase_add_test(tc, sscanf_);
  tcase_add_test(tc, sscanf_);
  tcase_add_test(tc, sscanf_);
  tcase_add_test(tc, sscanf_);
  tcase_add_test(tc, sscanf_);
  tcase_add_test(tc, sscanf_0);
  tcase_add_test(tc, sscanf_1);
  tcase_add_test(tc, sscanf_2);
  tcase_add_test(tc, sscanf_3);
  tcase_add_test(tc, sscanf_4);
  tcase_add_test(tc, sscanf_5);

  suite_add_tcase(s, tc);
  return s;
}

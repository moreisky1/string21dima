#include "test_me.h"

Suite *test_sscanf_i(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_I=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  suite_add_tcase(s, tc);
  return s;
}
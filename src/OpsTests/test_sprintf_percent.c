#include "test_me.h"

Suite *test_sprintf_percent(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_PERCENT=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, s21_sprintf_102);

  suite_add_tcase(s, tc);
  return s;
}

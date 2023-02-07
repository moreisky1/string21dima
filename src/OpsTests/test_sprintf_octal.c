#include "test_me.h"

Suite *test_sprin(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRIN=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_9);
  tcase_add_test(tc, sprintf_9);
  tcase_add_test(tc, sprintf_9);
  tcase_add_test(tc, sprintf_9);
  tcase_add_test(tc, sprintf_9);
  tcase_add_test(tc, sprintf_9);

  suite_add_tcase(s, tc);
  return s;
}

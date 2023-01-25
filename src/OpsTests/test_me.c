#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {
                              test_sprintf_c(),
                              test_sprintf_e(),
                              test_sprintf_f(),
                              test_sprintf_octal(),
                              test_sprintf_percent(),
                              test_sprintf_n(),
                              test_sprintf_string(),
                              test_sprintf_unsigned(),
                              test_sprintf_HEX(),
                              test_sprintf_hex(),
                              test_sprintf_signed(),
                              test_sprintf_signed_i(),
                              test_sprintf_pointer(),
                              test_sprintf_g(),
                              NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
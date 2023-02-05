#include "test_me.h"

START_TEST(s21_sprintf_81) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%i><%i><%i>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_82) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%li><%li><%hi><%hi>";
  long int val = 3088675747373646;
  signed long val2 = -125;
  short int val3 = -22600;
  short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_83) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%6.5i><%.23i><%3.i><%.i>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_84) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%-10.5i><%-.8i><%-7i><%-.i>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_85) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+i><%+3.i><%+5.7i><%+10i>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_86) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%i><%3.i><%5.7i><%10i><%#i><%-i><%+i><%.i><% .i>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_87) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<% i><% 3.i><% 5.7i><% 10i><%.i>";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_88) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+i><%+3.i><%+5.7i><%+10i><%+.i>";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_89) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0d><%06i><%05.7i><%0.7i><%0.i>";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprint(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINT=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_8);

  suite_add_tcase(s, tc);
  return s;
}

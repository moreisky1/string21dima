#include "test_me.h"

START_TEST(s21_sprintf_12) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%d>|<%d>";
  int val = 01225;
  int val2 = -017;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_13) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%ld>|<%ld>|<%hd>|<%hd>";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  short int val3 = 22600;
  short val4 = -120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_14) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%3d>|<%5d>";
  int val = -3015;
  int val2 = -11234;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_15) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%6.5d>|<%.23d>|<%3.d>|<%.d>|<%.6d>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  int val5 = -100;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_16) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%-10.5d>|<%-.8d>|<%-7d>|<%-.d>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_17) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0d>|<%0.d>|<%0.0d>|<%0d>|<%.d>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_18) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+d>|<%+3.d>|<%+5.7d>|<%+10d>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_19) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%d>|<%3.d>|<%5.7d>|<%10d>|<%#d>|<%-d>|<%+d>|<%.d>|<% .d>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_20) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<% d>|<% 3.d>|<% 5.7d>|<% 10d>|<%.d>";
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

START_TEST(s21_sprintf_21) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+d>|<%+3.d>|<%+5.7d>|<%+10d>|<%+.d>";
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

START_TEST(s21_sprintf_22) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%#d>|<%#3d>|<%#5.7d>|<%#.7d Oof %#.d>";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_23) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0d>|<%06d>|<%05.7d>|<%0.7d Oof %0.d>";
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

START_TEST(s21_sprintf_24) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%*d>|<%-*d>|<%*.*d>|<%.*d>";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_s21_sprintf_oid) {
  Suite *s = suite_create("\033[45m-=S21_s21_SPRINTF_\033[0m");
  TCase *tc = tcase_create("s21_sprintf_ tcase_add_test(tc, s21_sprintf_);
  
  tcase_add_test(tc, s21_sprintf_);
  tcase_add_test(tc, s21_sprintf_);
  tcase_add_test(tc, s21_sprintf_);
  tcase_add_test(tc, s21_sprintf_);
  tcase_add_test(tc, s21_sprintf_);

  suite_add_tcase(s, tc);
  return s;
}

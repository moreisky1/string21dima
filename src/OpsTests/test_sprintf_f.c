#include "test_me.h"

START_TEST(s21_sprintf_37) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%f>|<%.f>|<%4f>|<%4.f>|<%5.10f>";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_38) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%f>|<%.f>|<%3f>|<%4.f>|<%5.10f>";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_39) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lf>|<%.Lf>|<%+-#Lf>|<%+#.Lf>|<%-#.Lf>";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_40) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%5f>|<%6.1f>|<%8.2f>";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_41) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+15.f>|<%+#16.f>|<%+#18.0f>";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_42) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%15.13f>|<%26.15f>";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_43) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+- 14f>|<%+ 10f>|<% +25f>";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_44) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+- 010.2f>|<%- 025.7f>|<%+- 18.4f>";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_45) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<% 15.1Lf>|<% -26.13Lf>|<%- 30.8Lf>";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_46) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lf>|<%.2Lf>|<%.3Lf>";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_47) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lf>|<%.2Lf>|<%.3Lf>";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_48) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lf>|<%.2Lf>|<%.3Lf>";
  long double num = -236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_49) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lf>|<%.2Lf>|<%.3Lf>";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_50) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+ 0Lf>|<%.6Lf>|<%.15Lf>";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_51) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+ 0Lf>|<%060Lf>|<%.15Lf>";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_52) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%-+.1Lf>|<%- .2Lf>|<%-0.3Lf>";
  long double num = -0.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(s21_sprintf_53) {
//   char str1[400] = "";
//   char str2[400] = "";
//   char *str3 = "<%+ 0Lf>|<%.6Lf>|<%.15Lf>";
//   long double num = -236310753.6495633;
//   ck_assert_int_eq(sprintf(str1, str3, num, num, num),
//                    s21_sprintf(str2, str3, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

Suite *test_sprintf_(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_=-\033[0m");
  TCase *tc = tcase_create("sprintf_c");

  tcase_add_test(tc, sprintf_37);
  tcase_add_test(tc, sprintf_38);
  tcase_add_test(tc, sprintf_39);
  tcase_add_test(tc, sprintf_40);
  tcase_add_test(tc, sprintf_41);
  tcase_add_test(tc, sprintf_42);
  tcase_add_test(tc, sprintf_43);
  tcase_add_test(tc, sprintf_44);
  tcase_add_test(tc, sprintf_45);
  tcase_add_test(tc, sprintf_46);
  tcase_add_test(tc, sprintf_47);
  tcase_add_test(tc, sprintf_48);
  tcase_add_test(tc, sprintf_49);
  tcase_add_test(tc, sprintf_50);
  tcase_add_test(tc, sprintf_51);
  tcase_add_test(tc, sprintf_52);
  // tcase_add_test(tc, sprintf_53);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  // tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);
  tcase_add_test(tc, sprintf_);

  suite_add_tcase(s, tc);
  return s;
}

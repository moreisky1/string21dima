<h1> Использование библиотеки "check.h"</h1>

<pre>
</pre>
<h2>Установка</h2>
<pre>
sudo apt install -y texinfo
git clone https://github.com/libcheck/check.git
cd check/
autoreconf --install
./configure
make
make check
sudo make install
</pre>
<h2>Основные концепции</h2>
<pre>
<code>
#include "check.h>
#include "stdlib.h>

START_TEST(name_test_1) {
    ....
} END_TEST

START_TEST(name_test_2) {
    ....
} END_TEST

Suite *name_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("name Test"); // Создание пустого Suite
  tc_core = tcase_create("Core of name"); // Создание пустой структуры для набора тестов

  tcase_add_test(tc_core, name_test_1); // Добавление теста
  tcase_add_test(tc_core, name_test_2); // Добавление теста

  suite_add_tcase(suite, tc_core); // Добавление всех тестов в suite для возврата 

  return suite;
}

int main(void) {
  Suite *suite = name_suite();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
</code>
</pre>

<h2>Функции</h2>

<pre>
    ck_assert_int_eq(int value, int value); // Тест целочисленного значения
</pre>

<h3>Suite</h3>
<pre>
    ck_assert_int_eq(int value, int value); // Тест целочисленного значения
</pre>
<pre>
    ck_assert_int_eq(int value, int value); // Тест целочисленного значения
</pre>

<h3>Runner</h3>
<pre>
    ck_assert_int_eq(int value, int value); // Тест целочисленного значения
</pre>
<pre>
    ck_assert_int_eq(int value, int value); // Тест целочисленного значения
</pre>

<h3>Тесты</h3>
<pre>
    ck_assert_ldouble_eq_tol(long double ex, long double ac, EPS); // Тест (long double) значения с EPS
</pre>
<pre>
    ck_assert_int_eq(int ex, int ac); // Тест (int) значения
</pre>
<pre>
    ck_assert_ldouble_eq(long double ex, long double ac); // Тест (long double) значения без EPS
</pre>
<pre>
    ck_assert_int_eq(int value, int value); // Тест целочисленного значения
</pre>
<pre>
    ck_assert_int_eq(int value, int value); // Тест целочисленного значения
</pre>
<pre>
    ck_assert_int_eq(int value, int value); // Тест целочисленного значения
</pre>
<h2>Компиляция</h2>
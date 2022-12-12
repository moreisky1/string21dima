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

check.h File Reference
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <check_stdint.h>
#include <sys/types.h>
Go to the source code of this file.

Data Structures
struct  	TTest

Macros
#define 	CK_DIAGNOSTIC_PUSH_IGNORE(w)

#define 	CK_DIAGNOSTIC_POP(w)

#define 	tcase_add_test(tc, tf)   tcase_add_test_raise_signal(tc,tf,0)

#define 	tcase_add_test_raise_signal(tc, ttest, signal)   _tcase_add_test((tc),(ttest),(signal), 0, 0, 1)

#define 	tcase_add_exit_test(tc, ttest, expected_exit_value)   _tcase_add_test((tc),(ttest),0,(expected_exit_value),0,1)

#define 	tcase_add_loop_test(tc, ttest, s, e)   _tcase_add_test((tc),(ttest),0,0,(s),(e))

#define 	tcase_add_loop_test_raise_signal(tc, ttest, signal, s, e)   _tcase_add_test((tc),(ttest),(signal),0,(s),(e))

#define 	tcase_add_loop_exit_test(tc, ttest, expected_exit_value, s, e)   _tcase_add_test((tc),(ttest),0,(expected_exit_value),(s),(e))

#define 	START_TEST(__testname)

#define 	END_TEST

#define 	ck_assert(expr)   ck_assert_msg(expr, NULL)

#define 	ck_assert_msg(expr, ...)

#define 	ck_abort()   ck_abort_msg(NULL)

#define 	ck_abort_msg(...)   _ck_assert_failed(__FILE__, __LINE__, "Failed" , ## __VA_ARGS__)

#define 	ck_assert_int_eq(X, Y)   _ck_assert_int(X, ==, Y)

#define 	ck_assert_int_ne(X, Y)   _ck_assert_int(X, !=, Y)

#define 	ck_assert_int_lt(X, Y)   _ck_assert_int(X, <, Y)

#define 	ck_assert_int_le(X, Y)   _ck_assert_int(X, <=, Y)

#define 	ck_assert_int_gt(X, Y)   _ck_assert_int(X, >, Y)

#define 	ck_assert_int_ge(X, Y)   _ck_assert_int(X, >=, Y)

#define 	ck_assert_uint_eq(X, Y)   _ck_assert_uint(X, ==, Y)

#define 	ck_assert_uint_ne(X, Y)   _ck_assert_uint(X, !=, Y)

#define 	ck_assert_uint_lt(X, Y)   _ck_assert_uint(X, <, Y)

#define 	ck_assert_uint_le(X, Y)   _ck_assert_uint(X, <=, Y)

#define 	ck_assert_uint_gt(X, Y)   _ck_assert_uint(X, >, Y)

#define 	ck_assert_uint_ge(X, Y)   _ck_assert_uint(X, >=, Y)

#define 	CK_FLOATING_DIG   6

#define 	ck_assert_float_eq(X, Y)   _ck_assert_floating(X, ==, Y, float, "")

#define 	ck_assert_float_ne(X, Y)   _ck_assert_floating(X, !=, Y, float, "")

#define 	ck_assert_float_lt(X, Y)   _ck_assert_floating(X, <, Y, float, "")

#define 	ck_assert_float_le(X, Y)   _ck_assert_floating(X, <=, Y, float, "")

#define 	ck_assert_float_gt(X, Y)   _ck_assert_floating(X, >, Y, float, "")

#define 	ck_assert_float_ge(X, Y)   _ck_assert_floating(X, >=, Y, float, "")

#define 	ck_assert_float_eq_tol(X, Y, T)   _ck_assert_floating_absdiff_op_tol(X, Y, <, T, float, "")

#define 	ck_assert_float_ne_tol(X, Y, T)   _ck_assert_floating_absdiff_op_tol(X, Y, >=, T, float, "")

#define 	ck_assert_float_ge_tol(X, Y, T)   _ck_assert_floating_op_tol(X, >, Y, T, -1, float, "")

#define 	ck_assert_float_le_tol(X, Y, T)   _ck_assert_floating_op_tol(X, <, Y, T, 1, float, "")

#define 	ck_assert_float_finite(X)   _ck_assert_floating_finite(X, float, "")

#define 	ck_assert_float_infinite(X)   _ck_assert_floating_infinite(X, float, "")

#define 	ck_assert_float_nan(X)   _ck_assert_floating_nan(X, float, "")

#define 	ck_assert_float_nonnan(X)   _ck_assert_floating_nonnan(X, float, "")

#define 	ck_assert_double_eq(X, Y)   _ck_assert_floating(X, ==, Y, double, "")

#define 	ck_assert_double_ne(X, Y)   _ck_assert_floating(X, !=, Y, double, "")

#define 	ck_assert_double_lt(X, Y)   _ck_assert_floating(X, <, Y, double, "")

#define 	ck_assert_double_le(X, Y)   _ck_assert_floating(X, <=, Y, double, "")

#define 	ck_assert_double_gt(X, Y)   _ck_assert_floating(X, >, Y, double, "")

#define 	ck_assert_double_ge(X, Y)   _ck_assert_floating(X, >=, Y, double, "")

#define 	ck_assert_double_eq_tol(X, Y, T)   _ck_assert_floating_absdiff_op_tol(X, Y, <, T, double, "")

#define 	ck_assert_double_ne_tol(X, Y, T)   _ck_assert_floating_absdiff_op_tol(X, Y, >=, T, double, "")

#define 	ck_assert_double_ge_tol(X, Y, T)   _ck_assert_floating_op_tol(X, >, Y, T, -1, double, "")

#define 	ck_assert_double_le_tol(X, Y, T)   _ck_assert_floating_op_tol(X, <, Y, T, 1, double, "")

#define 	ck_assert_double_finite(X)   _ck_assert_floating_finite(X, double, "")

#define 	ck_assert_double_infinite(X)   _ck_assert_floating_infinite(X, double, "")

#define 	ck_assert_double_nan(X)   _ck_assert_floating_nan(X, double, "")

#define 	ck_assert_double_nonnan(X)   _ck_assert_floating_nonnan(X, double, "")

#define 	ck_assert_ldouble_eq(X, Y)   _ck_assert_floating(X, ==, Y, long double, "L")

#define 	ck_assert_ldouble_ne(X, Y)   _ck_assert_floating(X, !=, Y, long double, "L")

#define 	ck_assert_ldouble_lt(X, Y)   _ck_assert_floating(X, <, Y, long double, "L")

#define 	ck_assert_ldouble_le(X, Y)   _ck_assert_floating(X, <=, Y, long double, "L")

#define 	ck_assert_ldouble_gt(X, Y)   _ck_assert_floating(X, >, Y, long double, "L")

#define 	ck_assert_ldouble_ge(X, Y)   _ck_assert_floating(X, >=, Y, long double, "L")

#define 	ck_assert_ldouble_eq_tol(X, Y, T)   _ck_assert_floating_absdiff_op_tol(X, Y, <, T, long double, "L")

#define 	ck_assert_ldouble_ne_tol(X, Y, T)   _ck_assert_floating_absdiff_op_tol(X, Y, >=, T, long double, "L")

#define 	ck_assert_ldouble_ge_tol(X, Y, T)   _ck_assert_floating_op_tol(X, >, Y, T, -1, long double, "L")

#define 	ck_assert_ldouble_le_tol(X, Y, T)   _ck_assert_floating_op_tol(X, <, Y, T, 1, long double, "L")

#define 	ck_assert_ldouble_finite(X)   _ck_assert_floating_finite(X, long double, "L")

#define 	ck_assert_ldouble_infinite(X)   _ck_assert_floating_infinite(X, long double, "L")

#define 	ck_assert_ldouble_nan(X)   _ck_assert_floating_nan(X, long double, "L")

#define 	ck_assert_ldouble_nonnan(X)   _ck_assert_floating_nonnan(X, long double, "L")

#define 	ck_assert_str_eq(X, Y)   _ck_assert_str(X, ==, Y, 0, 0)

#define 	ck_assert_str_ne(X, Y)   _ck_assert_str(X, !=, Y, 0, 0)

#define 	ck_assert_str_lt(X, Y)   _ck_assert_str(X, <, Y, 0, 0)

#define 	ck_assert_str_le(X, Y)   _ck_assert_str(X, <=, Y, 0, 0)

#define 	ck_assert_str_gt(X, Y)   _ck_assert_str(X, >, Y, 0, 0)

#define 	ck_assert_str_ge(X, Y)   _ck_assert_str(X, >=, Y, 0, 0)

#define 	ck_assert_pstr_eq(X, Y)   _ck_assert_str(X, ==, Y, 1, 0)

#define 	ck_assert_pstr_ne(X, Y)   _ck_assert_str(X, !=, Y, 0, 1)

#define 	CK_MAX_ASSERT_MEM_PRINT_SIZE   64

#define 	ck_assert_mem_eq(X, Y, L)   _ck_assert_mem(X, ==, Y, L)

#define 	ck_assert_mem_ne(X, Y, L)   _ck_assert_mem(X, !=, Y, L)

#define 	ck_assert_mem_lt(X, Y, L)   _ck_assert_mem(X, <, Y, L)

#define 	ck_assert_mem_le(X, Y, L)   _ck_assert_mem(X, <=, Y, L)

#define 	ck_assert_mem_gt(X, Y, L)   _ck_assert_mem(X, >, Y, L)

#define 	ck_assert_mem_ge(X, Y, L)   _ck_assert_mem(X, >=, Y, L)

#define 	ck_assert_ptr_eq(X, Y)   _ck_assert_ptr(X, ==, Y)

#define 	ck_assert_ptr_ne(X, Y)   _ck_assert_ptr(X, !=, Y)

#define 	ck_assert_ptr_null(X)   _ck_assert_ptr_null(X, ==)

#define 	ck_assert_ptr_nonnull(X)   _ck_assert_ptr_null(X, !=)

#define 	mark_point()   _mark_point(__FILE__,__LINE__)

Typedefs
typedef struct TCase 	TCase

typedef void(* 	TFun) (int)

typedef void(* 	SFun) (void)

typedef struct Suite 	Suite

typedef struct TTest 	TTest

typedef struct SRunner 	SRunner

typedef struct TestResult 	TestResult

Enumerations
enum  	test_result { CK_TEST_RESULT_INVALID, CK_PASS, CK_FAILURE, CK_ERROR }

enum  	print_output {
CK_SILENT, CK_MINIMAL, CK_NORMAL, CK_VERBOSE,
CK_ENV, CK_LAST
}

enum  	ck_result_ctx { CK_CTX_INVALID, CK_CTX_SETUP, CK_CTX_TEST, CK_CTX_TEARDOWN }

enum  	fork_status { CK_FORK_GETENV, CK_FORK, CK_NOFORK }

Functions
CK_DLL_EXP Suite *CK_EXPORT 	suite_create (const char *name)

CK_DLL_EXP int CK_EXPORT 	suite_tcase (Suite *s, const char *tcname)

CK_DLL_EXP void CK_EXPORT 	suite_add_tcase (Suite *s, TCase *tc)

CK_DLL_EXP TCase *CK_EXPORT 	tcase_create (const char *name)

CK_DLL_EXP void CK_EXPORT 	tcase_set_tags (TCase *tc, const char *tags)

CK_DLL_EXP void CK_EXPORT 	tcase_add_unchecked_fixture (TCase *tc, SFun setup, SFun teardown)

CK_DLL_EXP void CK_EXPORT 	tcase_add_checked_fixture (TCase *tc, SFun setup, SFun teardown)

CK_DLL_EXP void CK_EXPORT 	tcase_set_timeout (TCase *tc, double timeout)

CK_DLL_EXP void CK_EXPORT 	tcase_fn_start (const char *fname, const char *file, int line)

CK_DLL_EXP const char *CK_EXPORT 	tcase_name (void)

CK_DLL_EXP int CK_EXPORT 	tr_rtype (TestResult *tr)

CK_DLL_EXP enum ck_result_ctx CK_EXPORT 	tr_ctx (TestResult *tr)

CK_DLL_EXP const char *CK_EXPORT 	tr_msg (TestResult *tr)

CK_DLL_EXP int CK_EXPORT 	tr_lno (TestResult *tr)

CK_DLL_EXP const char *CK_EXPORT 	tr_lfile (TestResult *tr)

CK_DLL_EXP const char *CK_EXPORT 	tr_tcname (TestResult *tr)

CK_DLL_EXP SRunner *CK_EXPORT 	srunner_create (Suite *s)

CK_DLL_EXP void CK_EXPORT 	srunner_add_suite (SRunner *sr, Suite *s)

CK_DLL_EXP void CK_EXPORT 	srunner_free (SRunner *sr)

CK_DLL_EXP void CK_EXPORT 	srunner_run_all (SRunner *sr, enum print_output print_mode)

CK_DLL_EXP void CK_EXPORT 	srunner_run (SRunner *sr, const char *sname, const char *tcname, enum print_output print_mode)

CK_DLL_EXP void CK_EXPORT 	srunner_run_tagged (SRunner *sr, const char *sname, const char *tcname, const char *include_tags, const char *exclude_tags, enum print_output print_mode)

CK_DLL_EXP int CK_EXPORT 	srunner_ntests_failed (SRunner *sr)

CK_DLL_EXP int CK_EXPORT 	srunner_ntests_run (SRunner *sr)

CK_DLL_EXP TestResult **CK_EXPORT 	srunner_failures (SRunner *sr)

CK_DLL_EXP TestResult **CK_EXPORT 	srunner_results (SRunner *sr)

CK_DLL_EXP void CK_EXPORT 	srunner_print (SRunner *sr, enum print_output print_mode)

CK_DLL_EXP void CK_EXPORT 	srunner_set_log (SRunner *sr, const char *fname)

CK_DLL_EXP int CK_EXPORT 	srunner_has_log (SRunner *sr)

CK_DLL_EXP const char *CK_EXPORT 	srunner_log_fname (SRunner *sr)

CK_DLL_EXP void CK_EXPORT 	srunner_set_xml (SRunner *sr, const char *fname)

CK_DLL_EXP int CK_EXPORT 	srunner_has_xml (SRunner *sr)

CK_DLL_EXP const char *CK_EXPORT 	srunner_xml_fname (SRunner *sr)

CK_DLL_EXP void CK_EXPORT 	srunner_set_tap (SRunner *sr, const char *fname)

CK_DLL_EXP int CK_EXPORT 	srunner_has_tap (SRunner *sr)

CK_DLL_EXP const char *CK_EXPORT 	srunner_tap_fname (SRunner *sr)

CK_DLL_EXP enum fork_status CK_EXPORT 	srunner_fork_status (SRunner *sr)

CK_DLL_EXP void CK_EXPORT 	srunner_set_fork_status (SRunner *sr, enum fork_status fstat)

CK_DLL_EXP pid_t CK_EXPORT 	check_fork (void)

CK_DLL_EXP void CK_EXPORT 	check_waitpid_and_exit (pid_t pid) CK_ATTRIBUTE_NORETURN

CK_DLL_EXP void CK_EXPORT 	check_set_max_msg_size (size_t max_msg_size)

Macro Definition Documentation
§ ck_abort
#define ck_abort	(		)	   ck_abort_msg(NULL)
Unconditionally fail the test

Note
Once called, the remaining of the test is aborted
Since
0.9.6
§ ck_abort_msg
#define ck_abort_msg	(	 	...	)	   _ck_assert_failed(__FILE__, __LINE__, "Failed" , ## __VA_ARGS__)
Unconditionally fail the test; print a message

Parameters
...	message to print (in printf format)
Note
Once called, the remaining of the test is aborted
Since
0.9.6
§ ck_assert
#define ck_assert	(	 	expr	)	   ck_assert_msg(expr, NULL)
Fail the test if expression is false

Parameters
expr	expression to evaluate
Note
If the check fails, the remaining of the test is aborted
Since
0.9.6
§ ck_assert_double_eq
#define ck_assert_double_eq	(	 	X,
Y
)		   _ck_assert_floating(X, ==, Y, double, "")
Check two double precision floating point numbers to determine if X == Y.

Note that the usefulness of this assertion is very limited. If you want to compare two floating point numbers for equality, you probably want to use ck_assert_double_eq_tol instead.

If not X == Y, the test fails.

Parameters
X	floating point number (double)
Y	floating point number (double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_eq_tol
#define ck_assert_double_eq_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_absdiff_op_tol(X, Y, <, T, double, "")
Check two double precision floating point numbers to determine if X≈Y with specified tolerance

If not X ≈ Y with error < T, the test fails.

Parameters
X	floating point number (double)
Y	floating point number (double) to compare against X
T	tolerance (double)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_finite
#define ck_assert_double_finite	(	 	X	)	   _ck_assert_floating_finite(X, double, "")
Check that a double precision floating point number is finite; i.e. is not +infinity, -infinity, or "Not a Number" (NaN)

If X is +INFINITY or X is -INFINITY, or X is NaN, the test fails.

Parameters
X	floating point number (double) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_ge
#define ck_assert_double_ge	(	 	X,
Y
)		   _ck_assert_floating(X, >=, Y, double, "")
Check two double precision floating point numbers to determine if X >= Y

If not X >= Y, the test fails.

Parameters
X	floating point number (double)
Y	floating point number (double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_ge_tol
#define ck_assert_double_ge_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_op_tol(X, >, Y, T, -1, double, "")
Check two double precision floating point numbers to determine if X>≈Y with specified tolerance

If not X >≈ Y with error < T, the test fails.

Parameters
X	floating point number (double)
Y	floating point number (double) to compare against X
T	tolerance (double)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_gt
#define ck_assert_double_gt	(	 	X,
Y
)		   _ck_assert_floating(X, >, Y, double, "")
Check two double precision floating point numbers to determine if X > Y

If not X > Y, the test fails.

Parameters
X	floating point number (double)
Y	floating point number (double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_infinite
#define ck_assert_double_infinite	(	 	X	)	   _ck_assert_floating_infinite(X, double, "")
Check that a double precision floating point number is infinite, either +infinity or -infinity

If X is not +INFINITY and X is not -INFINITY, the test fails.

Parameters
X	floating point number (double) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_le
#define ck_assert_double_le	(	 	X,
Y
)		   _ck_assert_floating(X, <=, Y, double, "")
Check two double precision floating point numbers to determine if X <= Y

If not X <= Y, the test fails.

Parameters
X	floating point number (double)
Y	floating point number (double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_le_tol
#define ck_assert_double_le_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_op_tol(X, <, Y, T, 1, double, "")
Check two double precision floating point numbers to determine if X<≈Y with specified tolerance

If not X <≈ Y with error < T, the test fails.

Parameters
X	floating point number (double)
Y	floating point number (double) to compare against X
T	tolerance (double)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_lt
#define ck_assert_double_lt	(	 	X,
Y
)		   _ck_assert_floating(X, <, Y, double, "")
Check two double precision floating point numbers to determine if X < Y

If not X < Y, the test fails.

Parameters
X	floating point number (double)
Y	floating point number (double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_nan
#define ck_assert_double_nan	(	 	X	)	   _ck_assert_floating_nan(X, double, "")
Check that a double precision floating point number is "Not a Number" (NaN)

If X is not NaN, the test fails.

Parameters
X	floating point number (double) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_ne
#define ck_assert_double_ne	(	 	X,
Y
)		   _ck_assert_floating(X, !=, Y, double, "")
Check two double precision floating point numbers to determine if X != Y.

Note that the usefulness of this assertion is very limited. If you want to compare two floating point numbers for equality, you probably want to use ck_assert_double_ne_tol instead.

If not X != Y, the test fails.

Parameters
X	floating point number (double)
Y	floating point number (double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_ne_tol
#define ck_assert_double_ne_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_absdiff_op_tol(X, Y, >=, T, double, "")
Check two double precision floating point numbers to determine if not X≈Y with specified tolerance

If X ≈ Y with error < T, the test fails.

Parameters
X	floating point number (double)
Y	floating point number (double) to compare against X
T	tolerance (double)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_double_nonnan
#define ck_assert_double_nonnan	(	 	X	)	   _ck_assert_floating_nonnan(X, double, "")
Check that a double precision floating point number is not "Not a Number" (NaN)

If X is NaN, the test fails.

Parameters
X	floating point number (double) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_eq
#define ck_assert_float_eq	(	 	X,
Y
)		   _ck_assert_floating(X, ==, Y, float, "")
Check two single precision floating point numbers to determine if X == Y.

Note that the usefulness of this assertion is very limited. If you want to compare two floating point numbers for equality, you probably want to use ck_assert_float_eq_tol instead.

If not X == Y, the test fails.

Parameters
X	floating point number (float)
Y	floating point number (float) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_eq_tol
#define ck_assert_float_eq_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_absdiff_op_tol(X, Y, <, T, float, "")
Check two single precision floating point numbers to determine if X≈Y with specified tolerance

If not X ≈ Y with error < T, the test fails.

Parameters
X	floating point number (float)
Y	floating point number (float) to compare against X
T	tolerance (float)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_finite
#define ck_assert_float_finite	(	 	X	)	   _ck_assert_floating_finite(X, float, "")
Check that a single precision floating point number is finite; i.e. is not +infinity, -infinity, or "Not a Number" (NaN)

If X is +INFINITY or X is -INFINITY, or X is NaN, the test fails.

Parameters
X	floating point number (float) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_ge
#define ck_assert_float_ge	(	 	X,
Y
)		   _ck_assert_floating(X, >=, Y, float, "")
Check two single precision floating point numbers to determine if X >= Y

If not X >= Y, the test fails.

Parameters
X	floating point number (float)
Y	floating point number (float) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_ge_tol
#define ck_assert_float_ge_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_op_tol(X, >, Y, T, -1, float, "")
Check two single precision floating point numbers to determine if X>≈Y with specified tolerance

If not X >≈ Y with error < T, the test fails.

Parameters
X	floating point number (float)
Y	floating point number (float) to compare against X
T	tolerance (float)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_gt
#define ck_assert_float_gt	(	 	X,
Y
)		   _ck_assert_floating(X, >, Y, float, "")
Check two single precision floating point numbers to determine if X > Y

If not X > Y, the test fails.

Parameters
X	floating point number (float)
Y	floating point number (float) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_infinite
#define ck_assert_float_infinite	(	 	X	)	   _ck_assert_floating_infinite(X, float, "")
Check that a single precision floating point number is infinite, either +infinity or -infinity

If X is not +INFINITY and X is not -INFINITY, the test fails.

Parameters
X	floating point number (float) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_le
#define ck_assert_float_le	(	 	X,
Y
)		   _ck_assert_floating(X, <=, Y, float, "")
Check two single precision floating point numbers to determine if X <= Y

If not X <= Y, the test fails.

Parameters
X	floating point number (float)
Y	floating point number (float) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_le_tol
#define ck_assert_float_le_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_op_tol(X, <, Y, T, 1, float, "")
Check two single precision floating point numbers to determine if X<≈Y with specified tolerance

If not X <≈ Y with error < T, the test fails.

Parameters
X	floating point number (float)
Y	floating point number (float) to compare against X
T	tolerance (float)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_lt
#define ck_assert_float_lt	(	 	X,
Y
)		   _ck_assert_floating(X, <, Y, float, "")
Check two single precision floating point numbers to determine if X < Y

If not X < Y, the test fails.

Parameters
X	floating point number (float)
Y	floating point number (float) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_nan
#define ck_assert_float_nan	(	 	X	)	   _ck_assert_floating_nan(X, float, "")
Check that a single precision floating point number is "Not a Number" (NaN)

If X is not NaN, the test fails.

Parameters
X	floating point number (float) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_ne
#define ck_assert_float_ne	(	 	X,
Y
)		   _ck_assert_floating(X, !=, Y, float, "")
Check two single precision floating point numbers to determine if X != Y.

Note that the usefulness of this assertion is very limited. If you want to compare two floating point numbers for equality, you probably want to use ck_assert_float_ne_tol instead.

If not X != Y, the test fails.

Parameters
X	floating point number (float)
Y	floating point number (float) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_ne_tol
#define ck_assert_float_ne_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_absdiff_op_tol(X, Y, >=, T, float, "")
Check two single precision floating point numbers to determine if not X≈Y with specified tolerance

If X ≈ Y with error < T, the test fails.

Parameters
X	floating point number (float)
Y	floating point number (float) to compare against X
T	tolerance (float)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_float_nonnan
#define ck_assert_float_nonnan	(	 	X	)	   _ck_assert_floating_nonnan(X, float, "")
Check that a single precision floating point number is not "Not a Number" (NaN)

If X is NaN, the test fails.

Parameters
X	floating point number (float) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_int_eq
#define ck_assert_int_eq	(	 	X,
Y
)		   _ck_assert_int(X, ==, Y)
Check two signed integers to determine if X==Y

If not X==Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.6
§ ck_assert_int_ge
#define ck_assert_int_ge	(	 	X,
Y
)		   _ck_assert_int(X, >=, Y)
Check two signed integers to determine if X>=Y

If not X>=Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_int_gt
#define ck_assert_int_gt	(	 	X,
Y
)		   _ck_assert_int(X, >, Y)
Check two signed integers to determine if X>Y

If not X>Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_int_le
#define ck_assert_int_le	(	 	X,
Y
)		   _ck_assert_int(X, <=, Y)
Check two signed integers to determine if X<=Y

If not X<=Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_int_lt
#define ck_assert_int_lt	(	 	X,
Y
)		   _ck_assert_int(X, <, Y)
Check two signed integers to determine if X<Y

If not X<Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_int_ne
#define ck_assert_int_ne	(	 	X,
Y
)		   _ck_assert_int(X, !=, Y)
Check two signed integers to determine if X!=Y

If not X!=Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.6
§ ck_assert_ldouble_eq
#define ck_assert_ldouble_eq	(	 	X,
Y
)		   _ck_assert_floating(X, ==, Y, long double, "L")
Check two double precision floating point numbers to determine if X == Y.

Note that the usefulness of this assertion is very limited. If you want to compare two floating point numbers for equality, you probably want to use ck_assert_ldouble_eq_tol instead.

If not X == Y, the test fails.

Parameters
X	floating point number (long double)
Y	floating point number (long double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_eq_tol
#define ck_assert_ldouble_eq_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_absdiff_op_tol(X, Y, <, T, long double, "L")
Check two double precision floating point numbers to determine if X≈Y with specified tolerance

If not X ≈ Y with error < T, the test fails.

Parameters
X	floating point number (long double)
Y	floating point number (long double) to compare against X
T	tolerance (long double)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_finite
#define ck_assert_ldouble_finite	(	 	X	)	   _ck_assert_floating_finite(X, long double, "L")
Check that a double precision floating point number is finite; i.e. is not +infinity, -infinity, or "Not a Number" (NaN)

If X is +INFINITY or X is -INFINITY, or X is NaN, the test fails.

Parameters
X	floating point number (long double) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_ge
#define ck_assert_ldouble_ge	(	 	X,
Y
)		   _ck_assert_floating(X, >=, Y, long double, "L")
Check two double precision floating point numbers to determine if X >= Y

If not X >= Y, the test fails.

Parameters
X	floating point number (long double)
Y	floating point number (long double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_ge_tol
#define ck_assert_ldouble_ge_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_op_tol(X, >, Y, T, -1, long double, "L")
Check two double precision floating point numbers to determine if X>≈Y with specified tolerance

If not X >≈ Y with error < T, the test fails.

Parameters
X	floating point number (long double)
Y	floating point number (long double) to compare against X
T	tolerance (long double)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_gt
#define ck_assert_ldouble_gt	(	 	X,
Y
)		   _ck_assert_floating(X, >, Y, long double, "L")
Check two double precision floating point numbers to determine if X > Y

If not X > Y, the test fails.

Parameters
X	floating point number (long double)
Y	floating point number (long double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_infinite
#define ck_assert_ldouble_infinite	(	 	X	)	   _ck_assert_floating_infinite(X, long double, "L")
Check that a double precision floating point number is infinite, either +infinity or -infinity

If X is not +INFINITY and X is not -INFINITY, the test fails.

Parameters
X	floating point number (long double) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_le
#define ck_assert_ldouble_le	(	 	X,
Y
)		   _ck_assert_floating(X, <=, Y, long double, "L")
Check two double precision floating point numbers to determine if X <= Y

If not X <= Y, the test fails.

Parameters
X	floating point number (long double)
Y	floating point number (long double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_le_tol
#define ck_assert_ldouble_le_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_op_tol(X, <, Y, T, 1, long double, "L")
Check two double precision floating point numbers to determine if X<≈Y with specified tolerance

If not X <≈ Y with error < T, the test fails.

Parameters
X	floating point number (long double)
Y	floating point number (long double) to compare against X
T	tolerance (long double)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_lt
#define ck_assert_ldouble_lt	(	 	X,
Y
)		   _ck_assert_floating(X, <, Y, long double, "L")
Check two double precision floating point numbers to determine if X < Y

If not X < Y, the test fails.

Parameters
X	floating point number (long double)
Y	floating point number (long double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_nan
#define ck_assert_ldouble_nan	(	 	X	)	   _ck_assert_floating_nan(X, long double, "L")
Check that a double precision floating point number is "Not a Number" (NaN)

If X is not NaN, the test fails.

Parameters
X	floating point number (long double) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_ne
#define ck_assert_ldouble_ne	(	 	X,
Y
)		   _ck_assert_floating(X, !=, Y, long double, "L")
Check two double precision floating point numbers to determine if X != Y.

Note that the usefulness of this assertion is very limited. If you want to compare two floating point numbers for equality, you probably want to use ck_assert_ldouble_ne_tol instead.

If not X != Y, the test fails.

Parameters
X	floating point number (long double)
Y	floating point number (long double) to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_ne_tol
#define ck_assert_ldouble_ne_tol	(	 	X,
Y,
T
)		   _ck_assert_floating_absdiff_op_tol(X, Y, >=, T, long double, "L")
Check two double precision floating point numbers to determine if not X≈Y with specified tolerance

If X ≈ Y with error < T, the test fails.

Parameters
X	floating point number (long double)
Y	floating point number (long double) to compare against X
T	tolerance (long double)
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ldouble_nonnan
#define ck_assert_ldouble_nonnan	(	 	X	)	   _ck_assert_floating_nonnan(X, long double, "L")
Check that a double precision floating point number is not "Not a Number" (NaN)

If X is NaN, the test fails.

Parameters
X	floating point number (long double) to be checked
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_mem_eq
#define ck_assert_mem_eq	(	 	X,
Y,
L
)		   _ck_assert_mem(X, ==, Y, L)
Check two memory locations to determine if 0==memcmp(X,Y,L)

If not 0==memcmp(X,Y,L), the test fails.

Parameters
X	memory location
Y	memory location to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_mem_ge
#define ck_assert_mem_ge	(	 	X,
Y,
L
)		   _ck_assert_mem(X, >=, Y, L)
Check two memory locations to determine if 0>=memcmp(X,Y,L) (e.g. memcmp(X,Y,L)<=0)

If not 0>=memcmp(X,Y,L), the test fails.

Parameters
X	memory location
Y	memory location to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_mem_gt
#define ck_assert_mem_gt	(	 	X,
Y,
L
)		   _ck_assert_mem(X, >, Y, L)
Check two memory locations to determine if 0<memcmp(X,Y,L) (e.g. memcmp(X,Y,L)>0)

If not 0<memcmp(X,Y,L), the test fails.

Parameters
X	memory location
Y	memory location to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_mem_le
#define ck_assert_mem_le	(	 	X,
Y,
L
)		   _ck_assert_mem(X, <=, Y, L)
Check two memory locations to determine if 0<=memcmp(X,Y,L) (e.g. memcmp(X,Y,L)>=0)

If not 0<=memcmp(X,Y,L), the test fails.

Parameters
X	memory location
Y	memory location to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_mem_lt
#define ck_assert_mem_lt	(	 	X,
Y,
L
)		   _ck_assert_mem(X, <, Y, L)
Check two memory locations to determine if 0<memcmp(X,Y,L), (e.g. memcmp(X,Y,L)>0)

If not 0<memcmp(X,Y,L), the test fails.

Parameters
X	memory location
Y	memory location to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_mem_ne
#define ck_assert_mem_ne	(	 	X,
Y,
L
)		   _ck_assert_mem(X, !=, Y, L)
Check two memory locations to determine if 0!=memcmp(X,Y,L)

If not 0!=memcmp(X,Y,L), the test fails.

Parameters
X	memory location
Y	memory location to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_msg
#define ck_assert_msg	(	 	expr,
...
)		
Value:
(expr) ? \
_mark_point(__FILE__, __LINE__) : \
_ck_assert_failed(__FILE__, __LINE__, "Assertion '"#expr"' failed" , ## __VA_ARGS__)
Fail the test if the expression is false; print message on failure

Parameters
expr	expression to evaluate
...	message to print (in printf format) if expression is false
Note
If the check fails, the remaining of the test is aborted
Since
0.9.6
§ ck_assert_pstr_eq
#define ck_assert_pstr_eq	(	 	X,
Y
)		   _ck_assert_str(X, ==, Y, 1, 0)
Check two strings to determine if 0==strcmp(X,Y) or if both are undefined

If both X and Y are NULL the test passes. However, if only one is NULL the test fails. If not ((X==NULL)&&(Y==NULL)) || (0==strcmp(X,Y)), the test fails.

Parameters
X	string
Y	string to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_pstr_ne
#define ck_assert_pstr_ne	(	 	X,
Y
)		   _ck_assert_str(X, !=, Y, 0, 1)
Check two strings to determine if 0!=strcmp(X,Y) or one of them is undefined

If either X or Y is NULL the test passes, however if both are NULL the test fails. If not (X!=NULL)&&(Y!=NULL)&&(0!=strcmp(X,Y)), the test fails.

Parameters
X	string
Y	string to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ptr_eq
#define ck_assert_ptr_eq	(	 	X,
Y
)		   _ck_assert_ptr(X, ==, Y)
Check if two pointers are equal.

If the two passed pointers are not equal, the test fails.

Parameters
X	pointer
Y	pointer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_ptr_ne
#define ck_assert_ptr_ne	(	 	X,
Y
)		   _ck_assert_ptr(X, !=, Y)
Check if two pointers are not.

If the two passed pointers are equal, the test fails.

Parameters
X	pointer
Y	pointer to compare against X
Since
0.9.10
§ ck_assert_ptr_nonnull
#define ck_assert_ptr_nonnull	(	 	X	)	   _ck_assert_ptr_null(X, !=)
Check if a pointer is not equal to NULL.

If X == NULL, the test fails.

Parameters
X	pointer to compare against NULL
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_ptr_null
#define ck_assert_ptr_null	(	 	X	)	   _ck_assert_ptr_null(X, ==)
Check if a pointer is equal to NULL.

If X != NULL, the test fails.

Parameters
X	pointer to compare against NULL
Note
If the check fails, the remaining of the test is aborted
Since
0.11.0
§ ck_assert_str_eq
#define ck_assert_str_eq	(	 	X,
Y
)		   _ck_assert_str(X, ==, Y, 0, 0)
Check two strings to determine if 0==strcmp(X,Y)

If X or Y is NULL the test fails. If not 0==strcmp(X,Y), the test fails.

Parameters
X	string
Y	string to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.6
§ ck_assert_str_ge
#define ck_assert_str_ge	(	 	X,
Y
)		   _ck_assert_str(X, >=, Y, 0, 0)
Check two strings to determine if 0>=strcmp(X,Y) (e.g. strcmp(X,Y)<=0)

If X or Y is NULL the test fails. If not 0>=strcmp(X,Y), the test fails.

Parameters
X	string
Y	string to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_str_gt
#define ck_assert_str_gt	(	 	X,
Y
)		   _ck_assert_str(X, >, Y, 0, 0)
Check two strings to determine if 0<strcmp(X,Y) (e.g. strcmp(X,Y)>0)

If X or Y is NULL the test fails. If not 0<strcmp(X,Y), the test fails.

Parameters
X	string
Y	string to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_str_le
#define ck_assert_str_le	(	 	X,
Y
)		   _ck_assert_str(X, <=, Y, 0, 0)
Check two strings to determine if 0<=strcmp(X,Y) (e.g. strcmp(X,Y)>=0)

If X or Y is NULL the test fails. If not 0<=strcmp(X,Y), the test fails.

Parameters
X	string
Y	string to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_str_lt
#define ck_assert_str_lt	(	 	X,
Y
)		   _ck_assert_str(X, <, Y, 0, 0)
Check two strings to determine if 0<strcmp(X,Y), (e.g. strcmp(X,Y)>0)

If X or Y is NULL the test fails. If not 0<strcmp(X,Y), the test fails.

Parameters
X	string
Y	string to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_str_ne
#define ck_assert_str_ne	(	 	X,
Y
)		   _ck_assert_str(X, !=, Y, 0, 0)
Check two strings to determine if 0!=strcmp(X,Y)

If X or Y is NULL the test fails. If not 0!=strcmp(X,Y), the test fails.

Parameters
X	string
Y	string to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.6
§ ck_assert_uint_eq
#define ck_assert_uint_eq	(	 	X,
Y
)		   _ck_assert_uint(X, ==, Y)
Check two unsigned integers to determine if X==Y

If not X==Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_uint_ge
#define ck_assert_uint_ge	(	 	X,
Y
)		   _ck_assert_uint(X, >=, Y)
Check two unsigned integers to determine if X>=Y

If not X>=Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_uint_gt
#define ck_assert_uint_gt	(	 	X,
Y
)		   _ck_assert_uint(X, >, Y)
Check two unsigned integers to determine if X>Y

If not X>Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_uint_le
#define ck_assert_uint_le	(	 	X,
Y
)		   _ck_assert_uint(X, <=, Y)
Check two unsigned integers to determine if X<=Y

If not X<=Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_uint_lt
#define ck_assert_uint_lt	(	 	X,
Y
)		   _ck_assert_uint(X, <, Y)
Check two unsigned integers to determine if X<Y

If not X<Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ ck_assert_uint_ne
#define ck_assert_uint_ne	(	 	X,
Y
)		   _ck_assert_uint(X, !=, Y)
Check two unsigned integers to determine if X!=Y

If not X!=Y, the test fails.

Parameters
X	signed integer
Y	signed integer to compare against X
Note
If the check fails, the remaining of the test is aborted
Since
0.9.10
§ CK_DIAGNOSTIC_POP
#define CK_DIAGNOSTIC_POP	(	 	w	)
§ CK_DIAGNOSTIC_PUSH_IGNORE
#define CK_DIAGNOSTIC_PUSH_IGNORE	(	 	w	)
§ CK_FLOATING_DIG
#define CK_FLOATING_DIG   6
§ CK_MAX_ASSERT_MEM_PRINT_SIZE
#define CK_MAX_ASSERT_MEM_PRINT_SIZE   64
§ END_TEST
#define END_TEST
End a unit test

Since
0.6.0
§ mark_point
#define mark_point	(		)	   _mark_point(__FILE__,__LINE__)
Mark the last point reached in a unit test.

If the test throws a signal or exits, the location noted with the failure is the last location of a ck_assert*() or ck_abort() call. Use mark_point() to record intermediate locations (useful for tracking down crashes or exits).

Since
0.6.0
§ START_TEST
#define START_TEST	(	 	__testname	)
Value:
static void __testname ## _fn (int _i CK_ATTRIBUTE_UNUSED);\
static const TTest __testname ## _ttest = {""# __testname, __testname ## _fn, __FILE__, __LINE__};\
static const TTest * __testname = & __testname ## _ttest;\
static void __testname ## _fn (int _i CK_ATTRIBUTE_UNUSED)
Start a unit test with START_TEST(unit_name), end with END_TEST.

One must use braces within a START_/END_ pair to declare new variables

Since
0.6.0
§ tcase_add_exit_test
#define tcase_add_exit_test	(	 	tc,
ttest,
expected_exit_value
)		   _tcase_add_test((tc),(ttest),0,(expected_exit_value),0,1)
Add a test function with an expected exit value to a test case

The added test is expected to terminate by exiting with the given value

Parameters
tc	test case to add test to
tf	test function to add to test case
expected_exit_value	exit value for test function to return in order for the test to be considered passing
Since
0.9.7
§ tcase_add_loop_exit_test
#define tcase_add_loop_exit_test	(	 	tc,
ttest,
expected_exit_value,
s,
e
)		   _tcase_add_test((tc),(ttest),0,(expected_exit_value),(s),(e))
Add a looping test function with an expected exit value to a test case

The test will be called in a for(i = s; i < e; i++) loop with each iteration being executed in a new context. The loop variable 'i' is available in the test.

The added test is expected to terminate by exiting with the given value

Parameters
tc	test case to add test to
tf	function to add to test case
expected_exit_value	exit value for test function to return in order for the test to be considered passing
s	starting index for value "i" in test
e	ending index for value "i" in test
Since
0.9.7
§ tcase_add_loop_test
#define tcase_add_loop_test	(	 	tc,
ttest,
s,
e
)		   _tcase_add_test((tc),(ttest),0,0,(s),(e))
Add a looping test function to a test case

The test will be called in a for(i = s; i < e; i++) loop with each iteration being executed in a new context. The loop variable 'i' is available in the test.

Parameters
tc	test case to add test to
tf	function to add to test case
s	starting index for value "i" in test
e	ending index for value "i" in test
Since
0.9.4
§ tcase_add_loop_test_raise_signal
#define tcase_add_loop_test_raise_signal	(	 	tc,
ttest,
signal,
s,
e
)		   _tcase_add_test((tc),(ttest),(signal),0,(s),(e))
Add a looping test function with signal handling to a test case

The test will be called in a for(i = s; i < e; i++) loop with each iteration being executed in a new context. The loop variable 'i' is available in the test.

The added test is expected to terminate by throwing the given signal

Parameters
tc	test case to add test to
tf	function to add to test case
signal	expected signal for test function to throw in order for the test to be considered passing
s	starting index for value "i" in test
e	ending index for value "i" in test
Since
0.9.5
§ tcase_add_test
#define tcase_add_test	(	 	tc,
tf
)		   tcase_add_test_raise_signal(tc,tf,0)
Add a test function to a test case

Parameters
tc	test case to add test to
tf	test function to add to test case
Since
0.6.0
§ tcase_add_test_raise_signal
#define tcase_add_test_raise_signal	(	 	tc,
ttest,
signal
)		   _tcase_add_test((tc),(ttest),(signal), 0, 0, 1)
Add a test function with signal handling to a test case

The added test is expected to terminate by throwing the given signal

Parameters
tc	test case to add test to
tf	test function to add to test case
signal	expected signal for test function to throw in order for the test to be considered passing
Since
0.9.2
Typedef Documentation
§ SFun
typedef void(* SFun) (void)
Type for a setup/teardown function

§ SRunner
typedef struct SRunner SRunner
Holds state for a running of a test suite

§ Suite
typedef struct Suite Suite
Type for a test suite

§ TCase
typedef struct TCase TCase
Type for a test case

A TCase represents a test case. Create with tcase_create, free with tcase_free. For the moment, test cases can only be run through a suite

§ TestResult
typedef struct TestResult TestResult
Opaque type for a test failure

§ TFun
typedef void(* TFun) (int)
Type for a test function

§ TTest
typedef struct TTest TTest
Type for a test, which wraps a test function

Enumeration Type Documentation
§ ck_result_ctx
enum ck_result_ctx
Enum representing the types of contexts for a test

Enumerator
CK_CTX_INVALID 	
Default value; should not encounter this

CK_CTX_SETUP 	
Setup before a test

CK_CTX_TEST 	
Body of test itself

CK_CTX_TEARDOWN 	
Teardown after a test

§ fork_status
enum fork_status
Enum describing the current fork usage.

Enumerator
CK_FORK_GETENV 	
look in the environment for CK_FORK

CK_FORK 	
call fork to run tests

CK_NOFORK 	
don't call fork

§ print_output
enum print_output
Enum specifying the verbosity of output a SRunner should produce

Enumerator
CK_SILENT 	
No output

CK_MINIMAL 	
Only summary output

CK_NORMAL 	
All failed tests

CK_VERBOSE 	
All tests

CK_ENV 	
Look at environment var CK_VERBOSITY for what verbosity to use, which can be either "silent", "minimal", "normal", or "verbose". If the environment variable is not set, then CK_NORMAL will be used.

CK_LAST 	
Not a valid option

§ test_result
enum test_result
Enum describing the possible results of a test

Enumerator
CK_TEST_RESULT_INVALID 	
Default value; should not encounter this

CK_PASS 	
Test passed

CK_FAILURE 	
Test completed but failed

CK_ERROR 	
Test failed to complete (unexpected signal or non-zero early exit)

Function Documentation
§ check_fork()
CK_DLL_EXP pid_t CK_EXPORT check_fork	(	void 		)
Invoke fork() during a test and assign the child to the same process group that the rest of the test case uses.

One can invoke fork() directly during a test; however doing so may not guarantee that any children processes are destroyed once the test finishes. Once a test has completed, all processes in the process group will be killed; using this wrapper will prevent orphan processes.

If Check is compiled without fork() support this call simply return -1 and does nothing.

Returns
On success, the PID of the child process is returned in the parent, and 0 is returned in the child. On failure, a value of -1 is returned to the parent process and no child process is created.
Since
0.9.3
§ check_set_max_msg_size()
CK_DLL_EXP void CK_EXPORT check_set_max_msg_size	(	size_t 	max_msg_size	)
Set the maximal assertion message size.

This protects the code against unintentional extremely large assertion messages (values of up to 4GB were seen in the wild). The usual size for a message is less than 80 bytes.

If the environment variable CK_MAX_MSG_SIZE is defined to a positive value, it is used. Otherwise, if a positive maximal message size is set via this function, it is used. Otherwise, the maximal message size is one assigned at compile time (4K bytes).

Parameters
max_msg_size	the maximal assertion message size.
Since
0.12.0
§ check_waitpid_and_exit()
CK_DLL_EXP void CK_EXPORT check_waitpid_and_exit	(	pid_t 	pid	)
Wait for the pid and exit.

This is to be used in conjunction with check_fork(). When called, will wait for the given process to terminate. If the process exited without error, exit(EXIT_SUCCESS) is invoked; otherwise exit(EXIT_FAILURE) is invoked.

If Check is compiled without support for fork(), this invokes exit(EXIT_FAILURE).

Parameters
pid	process to wait for, created by check_fork()
Since
0.9.3
§ srunner_add_suite()
CK_DLL_EXP void CK_EXPORT srunner_add_suite	(	SRunner * 	sr,
Suite * 	s
)		
Add an additional suite to a suite runner.

The first suite in a suite runner is always added in srunner_create(). This call adds additional suites to a suite runner.

Parameters
sr	suite runner to add the given suite
s	suite to add to the given suite runner
Since
0.7.0
§ srunner_create()
CK_DLL_EXP SRunner* CK_EXPORT srunner_create	(	Suite * 	s	)
Creates a suite runner for the given suite.

Once created, additional suites can be added to the suite runner using srunner_add_suite(), and the suite runner can be run with srunner_run_all(). Once finished, the suite runner must be freed with srunner_free().

Parameters
s	suite to generate a suite runner for
Returns
suite runner for the given suite
Since
0.6.0
§ srunner_failures()
CK_DLL_EXP TestResult** CK_EXPORT srunner_failures	(	SRunner * 	sr	)
Return an array of results for all failures found by a suite runner.

Number of results is equal to srunner_nfailed_tests().

Information about individual results can be queried using: tr_rtype(), tr_ctx(), tr_msg(), tr_lno(), tr_lfile(), and tr_tcname().

Memory is malloc'ed and must be freed; however free the entire structure instead of individual test cases.

Parameters
sr	suite runner to retrieve results from
Returns
array of TestResult objects
Since
0.6.0
§ srunner_fork_status()
CK_DLL_EXP enum fork_status CK_EXPORT srunner_fork_status	(	SRunner * 	sr	)
Retrieve the current fork status for the given suite runner

Parameters
sr	suite runner to check fork status of
Since
0.8.0
§ srunner_free()
CK_DLL_EXP void CK_EXPORT srunner_free	(	SRunner * 	sr	)
Frees a suite runner, including all contained suite and test cases.

This call is responsible for freeing all resources related to a suite runner and all contained suites and test cases. Suite and test cases need not be freed individually, as this call handles that.

Parameters
sr	suite runner to free
Since
0.6.0
§ srunner_has_log()
CK_DLL_EXP int CK_EXPORT srunner_has_log	(	SRunner * 	sr	)
Checks if the suite runner is assigned a file for log output.

Parameters
sr	suite runner to check
Returns
1 iff the suite runner currently is configured to output in log format; 0 otherwise
Since
0.7.1
§ srunner_has_tap()
CK_DLL_EXP int CK_EXPORT srunner_has_tap	(	SRunner * 	sr	)
Checks if the suite runner is assigned a file for TAP output.

Parameters
sr	suite runner to check
Returns
1 iff the suite runner currently is configured to output in TAP format; 0 otherwise
Since
0.9.12
§ srunner_has_xml()
CK_DLL_EXP int CK_EXPORT srunner_has_xml	(	SRunner * 	sr	)
Checks if the suite runner is assigned a file for XML output.

Parameters
sr	suite runner to check
Returns
1 iff the suite runner currently is configured to output in XML format; 0 otherwise
Since
0.9.1
§ srunner_log_fname()
CK_DLL_EXP const char* CK_EXPORT srunner_log_fname	(	SRunner * 	sr	)
Retrieves the name of the currently assigned file for log output, if any exists.

Returns
the name of the log file, or NULL if none is configured
Since
0.7.1
§ srunner_ntests_failed()
CK_DLL_EXP int CK_EXPORT srunner_ntests_failed	(	SRunner * 	sr	)
Retrieve the number of failed tests executed by a suite runner.

This value represents both test failures and errors.

Parameters
sr	suite runner to query for all failed tests
Returns
number of test failures and errors found by the suite runner
Since
0.6.1
§ srunner_ntests_run()
CK_DLL_EXP int CK_EXPORT srunner_ntests_run	(	SRunner * 	sr	)
Retrieve the total number of tests run by a suite runner.

Parameters
sr	suite runner to query for all tests run
Returns
number of all tests run by the suite runner
Since
0.6.1
§ srunner_print()
CK_DLL_EXP void CK_EXPORT srunner_print	(	SRunner * 	sr,
enum print_output 	print_mode
)		
Print the results contained in an SRunner to stdout.

Parameters
sr	suite runner to print results for to stdout
print_mode	the print_output (verbosity) to use to report the result
Since
0.7.0
§ srunner_results()
CK_DLL_EXP TestResult** CK_EXPORT srunner_results	(	SRunner * 	sr	)
Return an array of results for all tests run by a suite runner.

Number of results is equal to srunner_ntests_run(), and excludes failures due to setup function failure.

Information about individual results can be queried using: tr_rtype(), tr_ctx(), tr_msg(), tr_lno(), tr_lfile(), and tr_tcname().

Memory is malloc'ed and must be freed; however free the entire structure instead of individual test cases.

Parameters
sr	suite runner to retrieve results from
Returns
array of TestResult objects
Since
0.6.1
§ srunner_run()
CK_DLL_EXP void CK_EXPORT srunner_run	(	SRunner * 	sr,
const char * 	sname,
const char * 	tcname,
enum print_output 	print_mode
)		
Run a specific suite or test case from a suite runner, printing results to stdout as specified by the print_mode.

In addition to running any applicable suites or test cases, if the suite runner has been configured to output to a log, that is also performed.

Note that if the sname and tcname parameters are passed as null then the function will fallback to using the environment variables CK_RUN_SUITE and CK_RUN_CASE respectively in order to select the suite/cases.

Similarly if the CK_INCLUDE_TAGS and/or CK_EXCLUDE_TAGS environment variables are defined then these will further filter the test cases (see srunner_run_tagged, below).

Parameters
sr	suite runner where the given suite or test case must be
sname	suite name to run. A NULL means use the value of the environment variable CK_RUN_SUITE if set, otherwise run "any/every suite".
tcname	test case name to run. A NULL means use the value of the environment variable CK_RUN_CASE if set, otherwise run "any/every case".
print_mode	the verbosity in which to report results to stdout
Since
0.9.9
§ srunner_run_all()
CK_DLL_EXP void CK_EXPORT srunner_run_all	(	SRunner * 	sr,
enum print_output 	print_mode
)		
Runs a suite runner and all contained suite, printing results to stdout as specified by the print_mode.

In addition to running all suites, if the suite runner has been configured to output to a log, that is also performed.

Note that if the CK_RUN_CASE, CK_RUN_SUITE, CK_INCLUDE_TAGS and/or CK_EXCLUDE_TAGS environment variables are defined, then only the named suites or test cases will run.

Parameters
sr	suite runner to run all suites from
print_mode	the verbosity in which to report results to stdout
Since
0.6.0
§ srunner_run_tagged()
CK_DLL_EXP void CK_EXPORT srunner_run_tagged	(	SRunner * 	sr,
const char * 	sname,
const char * 	tcname,
const char * 	include_tags,
const char * 	exclude_tags,
enum print_output 	print_mode
)		
Run a specific suite or test case or testcases with specific tags from a suite runner, printing results to stdout as specified by the print_mode.

In addition to running any applicable suites or test cases, if the suite runner has been configured to output to a log, that is also performed.

Note that if sname, tcname, include_tags, exclude_tags parameters are passed as NULL then if the environment variables CK_RUN_SUITE, CK_RUN_CASE, CK_INCLUDE_TAGS, CK_EXCLUDE_TAGS are defined then these values will be used instead.

Parameters
sr	suite runner where the given suite or test case must be
sname	suite name to run. A NULL means use the value of the environment variable CK_RUN_SUITE if set, otherwise run "any/every suite".
tcname	test case name to run. A NULL means use the value of the environment variable CK_RUN_CASE if set, otherwise run "any/every case".
include_tags	space separate list of tags. Only run test cases that share one of these tags. A NULL means use the value of the environment variable CK_INCLUDE_TAGS if set, otherwise run "any/every test case".
exclude_tags	space separate list of tags. Only run test cases that do not share one of these tags even if they are selected by an included tag. A NULL means use the value of the environment variable CK_EXCLUDE_TAGS if set, otherwise run "any/every test case".
print_mode	the verbosity in which to report results to stdout
Since
0.11.0
§ srunner_set_fork_status()
CK_DLL_EXP void CK_EXPORT srunner_set_fork_status	(	SRunner * 	sr,
enum fork_status 	fstat
)		
Set the fork status for a given suite runner.

The default fork status is CK_FORK_GETENV, which will look for the CK_FORK environment variable, which can be set to "yes" or "no". If the environment variable is not present, CK_FORK will be used if fork() is available on the system, otherwise CK_NOFORK is used.

If set to CK_FORK or CK_NOFORK, the environment variable if defined is ignored.

If Check is compiled without support for fork(), attempting to set the status to CK_FORK is ignored.

Parameters
sr	suite runner to assign the fork status to
fstat	fork status to assign
Since
0.8.0
§ srunner_set_log()
CK_DLL_EXP void CK_EXPORT srunner_set_log	(	SRunner * 	sr,
const char * 	fname
)		
Set the suite runner to output the result in log format to the given file.

Note: log file setting is an initialize only operation – it should be done immediately after SRunner creation, and the log file can't be changed after being set.

This setting does not conflict with the other log output types; all logging types can occur concurrently if configured.

Parameters
sr	suite runner to log results of in log format
fname	file name to output log results to
Since
0.7.1
§ srunner_set_tap()
CK_DLL_EXP void CK_EXPORT srunner_set_tap	(	SRunner * 	sr,
const char * 	fname
)		
Set the suite runner to output the result in TAP format to the given file.

Note: TAP file setting is an initialize only operation – it should be done immediately after SRunner creation, and the TAP file can't be changed after being set.

This setting does not conflict with the other log output types; all logging types can occur concurrently if configured.

Parameters
sr	suite runner to log results of in TAP format
fname	file name to output TAP results to
Since
0.9.12
§ srunner_set_xml()
CK_DLL_EXP void CK_EXPORT srunner_set_xml	(	SRunner * 	sr,
const char * 	fname
)		
Set the suite runner to output the result in XML format to the given file.

Note: XML file setting is an initialize only operation – it should be done immediately after SRunner creation, and the XML file can't be changed after being set.

This setting does not conflict with the other log output types; all logging types can occur concurrently if configured.

Parameters
sr	suite runner to log results of in XML format
fname	file name to output XML results to
Since
0.9.1
§ srunner_tap_fname()
CK_DLL_EXP const char* CK_EXPORT srunner_tap_fname	(	SRunner * 	sr	)
Retrieves the name of the currently assigned file for TAP output, if any exists.

Returns
the name of the TAP file, or NULL if none is configured
Since
0.9.12
§ srunner_xml_fname()
CK_DLL_EXP const char* CK_EXPORT srunner_xml_fname	(	SRunner * 	sr	)
Retrieves the name of the currently assigned file for XML output, if any exists.

Returns
the name of the XML file, or NULL if none is configured
Since
0.9.1
§ suite_add_tcase()
CK_DLL_EXP void CK_EXPORT suite_add_tcase	(	Suite * 	s,
TCase * 	tc
)		
Add a test case to a suite.

Note that if the TCase has already been added attempting to add it again will be ignored.

Parameters
s	suite to add test case to
tc	test case to add to suite
Since
0.6.0
§ suite_create()
CK_DLL_EXP Suite* CK_EXPORT suite_create	(	const char * 	name	)
Creates a test suite with the given name.

Create a suite, which will contain test cases. Once created, use suite_add_tcase() to add test cases. When finished, create a suite runner from the suite using srunner_create()

Parameters
name	name of the suite
Returns
suite
Since
0.6.0
§ suite_tcase()
CK_DLL_EXP int CK_EXPORT suite_tcase	(	Suite * 	s,
const char * 	tcname
)		
Determines whether a given test suite contains a case named after a given string.

Parameters
s	suite to check
tcname	test case to look for
Returns
1 iff the given test case is within the given suite; 0 otherwise
Since
0.9.9
§ tcase_add_checked_fixture()
CK_DLL_EXP void CK_EXPORT tcase_add_checked_fixture	(	TCase * 	tc,
SFun 	setup,
SFun 	teardown
)		
Add checked fixture setup/teardown functions to a test case

Checked fixture functions are run before and after each unit test inside of the address space of the test. Thus, if using CK_FORK mode the separate process running the unit test will survive signals or unexpected exits in the fixture function. Also, if the setup function is idempotent, unit test behavior will be the same in CK_FORK and CK_NOFORK modes.

However, since fixture functions are run before and after each unit test, they should not be expensive code.

Note that if a setup function fails, the remaining setup functions will be omitted, as will the test and the teardown functions. If a teardown function fails the remaining teardown functins will be omitted.

Parameters
tc	test case to add checked fixture setup/teardown to
setup	function to add to be executed before each unit test in the test case; if NULL no setup function is added
teardown	function to add to be executed after each unit test in the test case; if NULL no teardown function is added
Since
0.8.0
§ tcase_add_unchecked_fixture()
CK_DLL_EXP void CK_EXPORT tcase_add_unchecked_fixture	(	TCase * 	tc,
SFun 	setup,
SFun 	teardown
)		
Add unchecked fixture setup/teardown functions to a test case

Unchecked fixture functions are run at the start and end of the test case, and not before and after unit tests. Further, unchecked fixture functions are not run in a separate address space, like test functions, and so must not exit or signal (e.g., segfault).

Also, when run in CK_NOFORK mode, unchecked fixture functions may lead to different unit test behavior if unit tests change data setup by the fixture functions.

Note that if a setup function fails, the remaining setup functions will be omitted, as will the test case and the teardown functions. If a teardown function fails the remaining teardown functins will be omitted.

Parameters
tc	test case to add unchecked fixture setup/teardown to
setup	function to add to be executed before the test case; if NULL no setup function is added
teardown	function to add to be executed after the test case; if NULL no teardown function is added
Since
0.8.0
§ tcase_create()
CK_DLL_EXP TCase* CK_EXPORT tcase_create	(	const char * 	name	)
Create a test case.

Once created, tests can be added with the tcase_add_test() function, and the test case assigned to a suite with the suite_add_tcase() function.

Parameters
name	name of the test case
Returns
test case containing no tests
Since
0.6.0
§ tcase_fn_start()
CK_DLL_EXP void CK_EXPORT tcase_fn_start	(	const char * 	fname,
const char * 	file,
int 	line
)		
§ tcase_name()
CK_DLL_EXP const char* CK_EXPORT tcase_name	(	void 		)
Retreive the name of the current running test. This is the name of the test passed to START_TEST. This is only valid when called from a running test. The value return outside of a running test is undefined.

Since
0.11.0
§ tcase_set_tags()
CK_DLL_EXP void CK_EXPORT tcase_set_tags	(	TCase * 	tc,
const char * 	tags
)		
Associate a test case with certain tags. Replaces any existing tags with the new set.

Parameters
tc	the test case
tags	string containing arbitrary tags separated by spaces. This will be copied. Passing NULL clears all tags.
Since
0.11.0
§ tcase_set_timeout()
CK_DLL_EXP void CK_EXPORT tcase_set_timeout	(	TCase * 	tc,
double 	timeout
)		
Set the timeout for all tests in a test case.

A test that lasts longer than the timeout (in seconds) will be killed and thus fail with an error.

If not set, the default timeout is one assigned at compile time. If the environment variable CK_DEFAULT_TIMEOUT is defined and no timeout is set, the value in the environment variable is used.

If Check is compile without fork() support this call is ignored, as timeouts are not possible.

Parameters
tc	test case to assign timeout to
timeout	to use, in seconds. If the value contains a decimal portion, but no high resolution timer is available, the value is rounded up to the nearest second.
Since
0.9.2
§ tr_ctx()
CK_DLL_EXP enum ck_result_ctx CK_EXPORT tr_ctx	(	TestResult * 	tr	)
Retrieve context in which the result occurred for the given test result.

The types of contents include the test setup, teardown, or the body of the test itself.

Parameters
tr	test result to retrieve context from
Returns
context to which the given test result applies
Since
0.8.0
§ tr_lfile()
CK_DLL_EXP const char* CK_EXPORT tr_lfile	(	TestResult * 	tr	)
Retrieve file name at which a failure occurred, if applicable.

Returns
If the test resulted in a failure, returns a string containing the name of the file where the failure occurred; otherwise returns NULL.
Since
0.6.0
§ tr_lno()
CK_DLL_EXP int CK_EXPORT tr_lno	(	TestResult * 	tr	)
Retrieve line number at which a failure occurred, if applicable.

Returns
If the test resulted in a failure, returns the line number that the failure occurred on; otherwise returns -1.
Since
0.6.0
§ tr_msg()
CK_DLL_EXP const char* CK_EXPORT tr_msg	(	TestResult * 	tr	)
Retrieve failure message from test result, if applicable.

Returns
pointer to a message, if one exists. NULL otherwise.
Since
0.6.0
§ tr_rtype()
CK_DLL_EXP int CK_EXPORT tr_rtype	(	TestResult * 	tr	)
Retrieve type of result that the given test result represents.

This is a member of test_result, and can represent a pass, failure, or error.

Parameters
tr	test result to retrieve result from
Returns
result of given test
Since
0.6.0
§ tr_tcname()
CK_DLL_EXP const char* CK_EXPORT tr_tcname	(	TestResult * 	tr	)
Retrieve test case name in which a failure occurred, if applicable.

Returns
If the test resulted in a failure, returns a string containing the name of the test suite where the failure occurred; otherwise returns NULL.
Since
0.6.0
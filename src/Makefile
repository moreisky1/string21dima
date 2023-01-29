#
USERNAME_1= barbreye
USERNAME1=$(shell users)
BRANCH_NAME=$(shell git branch | grep "*" | sed "s/^.//" | sed "s/^.//")
BRANCH= develop

#
GCC= gcc
GCC_C= gcc -c
GCC_G= gcc -g
FLAGS= -Wall -Werror -Wextra -std=c11
TESTS_UBUNTU= -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
GCOV_FLAGS= -fprofile-arcs -ftest-coverage -fPIC
#======================================== 
UNAME:=$(shell uname -s)
ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck_pic -lsubunit -lm -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck -lm
	OPEN_CM=open
endif
#======================================== 
#
F_H= s21_string.h
F_C_1= common/s21_insert.c common/s21_memcmp.c common/s21_memcpy.c
F_C_2= common/s21_memchr.c common/s21_memmove.c common/s21_memset.c
F_C_3= common/s21_sprintf.c common/s21_sscanf.c common/s21_strcat.c
F_C_4= common/s21_strchr.c common/s21_strcmp.c common/s21_strcpy.c
F_C_5= common/s21_strerror.c common/s21_strlen.c common/s21_strncat.c
F_C_6= common/s21_strncmp.c common/s21_strncpy.c common/s21_strpbrk.c
F_C_7= common/s21_strrchr.c common/s21_strspn.c common/s21_strstr.c
F_C_8= common/s21_strtok.c common/s21_to_lower.c common/s21_to_upper.c
F_C_9= common/s21_trim.c common/s21_strcspn.c
#
F_OUT = -o test
F_H_T= tests/s21_string_tests.h
F_C_T= tests/main.c
F_C_T_1= tests/s21_insert_test/s21_insert_test.c tests/s21_memcmp_test/s21_memcmp_test.c tests/s21_memcpy_test/s21_memcpy_test.c
F_C_T_2= tests/s21_memchr_test/s21_memchr_test.c tests/s21_memmove_test/s21_memmove_test.c tests/s21_memset_test/s21_memset_test.c
F_C_T_3= tests/s21_sprintf_test/s21_sprintf_test.c tests/s21_sscanf_test/s21_sscanf_test.c tests/s21_strcat_test/s21_strcat_test.c
F_C_T_4= tests/s21_strchr_test/s21_strchr_test.c tests/s21_strcmp_test/s21_strcmp_test.c tests/s21_strcpy_test/s21_strcpy_test.c
F_C_T_5= tests/s21_strerror_test/s21_strerror_test.c tests/s21_strlen_test/s21_strlen_test.c tests/s21_strncat_test/s21_strncat_test.c
F_C_T_6= tests/s21_strncmp_test/s21_strncmp_test.c tests/s21_strncpy_test/s21_strncpy_test.c tests/s21_strpbrk_test/s21_strpbrk_test.c
F_C_T_7= tests/s21_strrchr_test/s21_strrchr_test.c tests/s21_strspn_test/s21_strspn_test.c tests/s21_strstr_test/s21_strstr_test.c
F_C_T_8= tests/s21_strtok_test/s21_strtok_test.c tests/s21_to_lower_test/s21_to_lower_test.c tests/s21_to_upper_test/s21_to_upper_test.c
F_C_T_9= tests/s21_trim_test/s21_trim_test.c tests/s21_strcspn_test/s21_strcspn_test.c
SOURCE_TESTS= -o test
#======================================== ALL =========================================================================
all: clean s21_string.a

te: clean s21_string.a
	${GCC_G} ${FLAGS} me.c s21_string.a -o me -lm
	./me

t: clean s21_string.a
	${GCC_G} ${FLAGS} sprintfT.c s21_string.a -o me -lm
	./me 

#======================================== STATIC LIB ==================================================================
s21_string.a: clean
	${GCC_C} -g common/*.c
	ar rc s21_string.a *.o
	ranlib s21_string.a
	make clean.o

gs21_string.a: clean
	${GCC_C} -g common/*.c ${GCOV_FLAGS}
	ar rc s21_string.a *.o
	ranlib s21_string.a
	make clean.o

#======================================== TEST ========================================================================
test: clean s21_string.a
	${GCC_G} ${F_C_T_1} ${F_C_T_2} ${F_C_T_3} ${F_C_T_4} ${F_C_T_5} ${F_C_T_6} ${F_C_T_7} ${F_C_T_8} ${F_C_T_9} tests/main.c s21_string.a  -o run_test ${LDFLAGS}

test1: clean s21_string.a
	${GCC_G} ${FLAGS} OpsTests/*sscanf_d.c OpsTests/*sscanf_i.c OpsTests/*sscanf_o.c OpsTests/*sscanf_x.c OpsTests/test_me.c s21_string.a  -o st ${LDFLAGS}
	./st

test.a:
	${GCC_C} ${F_C_T_1} ${F_C_T_2} ${F_C_T_3} ${F_C_T_4} ${F_C_T_5} ${F_C_T_6} ${F_C_T_7} ${F_C_T_8} ${F_C_T_9}
	ar rc tests/s21_string_tests.a *.o
	ranlib tests/s21_string_tests.a
	make clean.o
#======================================== GCOV ========================================================================
gcov_report: clean s21_string.a
	${GCC_G} ${FLAGS} ${F_C_T_1} ${F_C_T_2} ${F_C_T_3} ${F_C_T_4} ${F_C_T_5} ${F_C_T_6} ${F_C_T_7} ${F_C_T_8} ${F_C_T_9} tests/main.c s21_string.a ${SOURCE_TESTS} ${TESTS_UBUNTU} ${GCOV_FLAGS}
	./test
	gcov test_s21_*.gcda
	gcovr -b
	gcovr
	mkdir report
	gcovr --html-details -o report/report.html
	rm -rf *.gcda *gcno

gcov_repo:  gs21_string.a
	${GCC_G} ${FLAGS} tests/*/*.c tests/*.c s21_string.a ${SOURCE_TESTS} ${LDFLAGS} ${GCOV_FLAGS}
	./test
	rm -rf *_test.gcda *_test.gcno main.gc*
	gcovr -p
	mkdir report
	gcovr -p --html-details -o report/report.html
	open report/report.html
	rm -rf *.gcda *gcno

#======================================== GIT =========================================================================
git:
	git add .
	git commit -m "${BRANCH} ---> ${USERNAME_1} ---> developing"
	git push origin master

gi:
	git commit --all -m "${BRANCH_NAME} --> ${USERNAME1} --> developing"
	git push origin ${BRANCH_NAME}

#======================================== VALGRIND ====================================================================

valgrind_test:

valgrind_test_gcov:

#======================================== Style    ====================================================================

#======================================== CLEAN =======================================================================
clean.o:
	rm -rf *.o

clean.a:
	rm -rf tests/*.a
	rm -rf *.a
# ======================================= Clean =======================================================================

clean.o:
	rm -rf *.o

clean.a:
	rm -rf *.a

clean.gcno:
	rm -rf *.gcno

clean.gcda:
	rm -rf *.gcda

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf run_test
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.txt
	rm -rf *.html
	rm -rf *.css
	rm -rf report

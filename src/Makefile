# all, clean, test, s21_matrix.a, gcov_report

CC=gcc
STRICT_CFLAGS=-Wall -Werror -Wextra -std=c11 -pedantic

CHECK_CFLAGS=$(shell pkg-config --cflags check)
CHECK_LFLAGS=$(shell pkg-config --libs check)

# GCOVR_CFLAGS=$(shell pkg-config --cflags gcovr)
GCOVR_CFLAGS=-fprofile-arcs -ftest-coverage -fPIC
# -fprofile-arcs -ftest-coverage
# GCOVR_LFLAGS=$(shell pkg-config --libs gcovr)
GCOVR_LFLAGS=-lgcov


REPORT_DIRECTORY=report


all: tests_no_check


gcov_report: test
		-./test.out	
		mkdir -p $(REPORT_DIRECTORY)
		gcovr . --html --html-details -o $(REPORT_DIRECTORY)/coverage_report.html
		open $(REPORT_DIRECTORY)/coverage_report.functions.html
		open $(REPORT_DIRECTORY)/coverage_report.s21_eq_matrix*
		

test: test.out
		-./test.out


test.out: tests/s21_all_tests.o s21_eq_matrix.o
		$(CC) $^ -o $@ $(GCOVR_LFLAGS) $(CHECK_LFLAGS)
		-./test.out

tests/s21_all_tests.o: tests/s21_all_tests.c s21_matrix.h
# $(CC) -c $(GCOVR_CFLAGS) $(CHECK_LFLAGS) $< -o $@
		$(CC) -c $< -o $@ $(STRICT_CFLAGS) $(CHECK_CFLAGS)


s21_create_matrix.o: s21_create_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_remove_matrix.o: s21_remove_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_eq_matrix.o: s21_eq_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_sum_matrix.o: s21_sum_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_sub_matrix.o: s21_sub_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_mult_number.o: s21_mult_number.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_mult_matrix.o: s21_mult_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)


# $(GCOVR_CFLAGS)

create_matrix_tests.o: tests/create_matrix_tests.c tests/all_tests_without_check.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
eq_matrix_tests.o: tests/eq_matrix_tests.c tests/all_tests_without_check.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
sum_matrix_tests.o: tests/sum_matrix_tests.c tests/all_tests_without_check.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
sub_matrix_tests.o: tests/sub_matrix_tests.c tests/all_tests_without_check.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
mult_number_tests.o: tests/mult_number_tests.c tests/all_tests_without_check.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
mult_matrix_tests.o: tests/mult_matrix_tests.c tests/all_tests_without_check.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@


print_matrix.o: tests/print_matrix.c tests/print_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@

clean:
		rm -rf report
		rm -f *.o
		rm -f *.gcda
		rm -f *.gcno
		rm -f tests/*.o
		rm -f tests/*.gcda
		rm -f tests/*.gcno
		rm -f test.out
		rm -f *.out

tests_no_check:	tests_no_check.out
		-./tests_no_check.out

tests_no_check.out: s21_create_matrix.o s21_remove_matrix.o all_tests_without_check.o create_matrix_tests.o print_matrix.o s21_eq_matrix.o eq_matrix_tests.o s21_sum_matrix.o sum_matrix_tests.o s21_sub_matrix.o sub_matrix_tests.o s21_mult_number.o mult_number_tests.o s21_mult_matrix.o mult_matrix_tests.o
		$(CC) -o $@ $^ $(GCOVR_LFLAGS)

all_tests_without_check.o: tests/all_tests_without_check.c tests/all_tests_without_check.h
		$(CC) -c $< -o $@ $(STRICT_CFLAGS) 
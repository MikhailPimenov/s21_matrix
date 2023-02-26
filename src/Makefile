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

s21_eq_matrix.o: s21_eq_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)


clean:
		rm -rf report
		rm -f *.o
		rm -f *.gcda
		rm -f *.gcno
		rm -f tests/*.o
		rm -f tests/*.gcda
		rm -f tests/*.gcno
		rm -f test.out
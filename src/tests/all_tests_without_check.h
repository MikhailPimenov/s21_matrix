#ifndef SRC_TESTS_ALL_TESTS_WITHOUT_CHECK_H_
#define SRC_TESTS_ALL_TESTS_WITHOUT_CHECK_H_

#include "../s21_matrix.h"

void create_matrix_tests(int algorithm(int, int, matrix_t*), const char* function_name);
void eq_matrix_tests(int algorithm(matrix_t*, matrix_t*), const char* function_name);

#endif  //  SRC_TESTS_ALL_TESTS_WITHOUT_CHECK_H_
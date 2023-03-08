#include <stdio.h>
#include "all_tests_without_check.h"
#include "../s21_matrix.h"

int main() {
    printf("Testing without check...\n");
    create_matrix_tests(s21_create_matrix, "s21_create_matrix(int rows, int columns, matrix_t*)");
    eq_matrix_tests(s21_eq_matrix, "s21_eq_matrix(matrix_t*, matrix_t*)");
    sum_matrix_tests(s21_sum_matrix, "s21_sum_matrix(const matrix_t*, const matrix_t*, matrix_t*)");
    printf("Testing is ended\n");
    return 0;
}
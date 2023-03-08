#include <stdio.h>
#include "../s21_matrix.h"

static void print_summary(const char* function_name, int test_number, int successful_test_number) {
    printf("Testing %s is over: %d / %d, %.2f%%\n", function_name, successful_test_number, test_number, 100.0f * (float)successful_test_number / (float)test_number);
}

void mult_number_tests(int algorithm(const matrix_t*, double, matrix_t*), const char* function_name) {
    int test_number = 0;
    int successful_test_number = 0;
    printf("Testing %s:\n", function_name);

    {//0========================================
        matrix_t m;
        const double number = 2.0;
        matrix_t actual_result;
        s21_create_matrix(1, 1, &m);
        s21_create_matrix(1, 1, &actual_result);

        m.matrix[0][0] = 1.23;

        const int expected_code = OK;
        const int actual_code = algorithm(&m, number, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(1, 1, &expected_result);
        expected_result.matrix[0][0] = 2.46;

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code && (actual_code != OK || s21_eq_matrix(&actual_result, &expected_result))) {
            printf("ok\n");
            ++successful_test_number;
        } else {
            printf("FAILED\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    print_summary(function_name, test_number, successful_test_number);
}
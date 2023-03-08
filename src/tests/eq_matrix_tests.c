#include <stdio.h>
#include "../s21_matrix.h"

static void print_summary(const char* function_name, int test_number, int successful_test_number) {
    printf("Testing %s is over: %d / %d, %.2f%%\n", function_name, successful_test_number, test_number, 100.0f * (float)successful_test_number / (float)test_number);
}

void eq_matrix_tests(int algorithm(const matrix_t*, const matrix_t*), const char* function_name) {
    int test_number = 0;
    int successful_test_number = 0;
    printf("Testing %s:\n", function_name);

    {
        matrix_t m1;
        matrix_t m2;

        s21_create_matrix(1, 1, &m1);
        s21_create_matrix(1, 1, &m2);

        m1.matrix[0][0] = 1.23;
        m2.matrix[0][0] = 1.23;

        const int expected = 1;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected) {
            printf("ok\n");
            ++successful_test_number;
        } else {
            printf("FAILED\n");
        }
    }
    ++test_number;

    print_summary(function_name, test_number, successful_test_number);
}
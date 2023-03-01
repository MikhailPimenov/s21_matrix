#include <stdlib.h>

#include "../s21_matrix.h"
#include "print_matrix.h"

void create_matrix_tests(int algorithm(int, int, matrix_t*)) {
    {
        matrix_t matrix;
        const int rows = 3;
        const int columns = 5;

        algorithm(rows, columns, &matrix);
        print_matrix(&matrix, "\t", "\n");

        free(matrix.matrix);
    }

    {
        matrix_t matrix;
        const int rows = 4;
        const int columns = 2;

        algorithm(rows, columns, &matrix);
        print_matrix(&matrix, "\t", "\n");

        free(matrix.matrix);
    }

    {
        matrix_t matrix;
        const int rows = 1;
        const int columns = 1;

        algorithm(rows, columns, &matrix);
        print_matrix(&matrix, "\t", "\n");

        free(matrix.matrix);
    }

    {
        matrix_t matrix;
        const int rows = 10;
        const int columns = 7;

        algorithm(rows, columns, &matrix);
        print_matrix(&matrix, "\t", "\n");

        free(matrix.matrix);
    }
}
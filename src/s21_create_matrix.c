#include "s21_matrix.h"

enum Error_allocation {
    OK = 0,
    ALLOCATION_ERROR = 1,
};

int s21_create_matrix(int rows, int columns, matrix_t* result) {
    double** matrix = malloc(sizeof(double) * rows * columns + sizeof(double*) * rows);
    if (!matrix)
        return ALLOCATION_ERROR;

    for (int row = 0; row < rows; ++row)
        *(matrix + row) = (double**)((double*)matrix + row * columns) + rows;

    result->matrix = matrix;
    result->rows = rows;
    result->columns = columns;
}
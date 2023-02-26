#include "s21_matrix.h"
#include <assert.h>
#include <stdio.h>

enum Result {
    NOT_EQUAL = 0,
    EQUAL = 1,
};

int s21_eq_matrix(matrix_t* a, matrix_t* b, int number) {
    printf("1111\n");
    printf("2222\n");
    printf("3333\n");
    printf("4444\n");
    printf("number = %d\n", number);
    // assert(0 && "inside s21_eq_matrix!!!!!!!!");

    if (!a || !b)
        return NOT_EQUAL;

    if (a->rows != b->rows || a->columns != b->rows)
        return NOT_EQUAL;

    for (int row = 0; row < a->rows; ++row)
       for (int column = 0; column < a->columns; ++column)
        //    if (not_equal(a->matrix[row][column], b->matrix[row][column]))
           if (a->matrix[row][column] != b->matrix[row][column])
               return NOT_EQUAL;

    return EQUAL;
}

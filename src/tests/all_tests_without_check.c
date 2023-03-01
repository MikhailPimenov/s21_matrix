#include <stdio.h>
#include "all_tests_without_check.h"
#include "../s21_matrix.h"

int main() {
    printf("Testing without check...\n");
    create_matrix_tests(s21_create_matrix);
    printf("Testing is ended\n");
    return 0;
}
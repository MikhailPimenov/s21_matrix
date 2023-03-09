#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_


enum Errors {
    OK = 0,
    INCORRECT_MATRIX = 1,
    CALCULATION_ERROR = 2,
};

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t* result);
void s21_remove_matrix(matrix_t* a);

#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t* a, matrix_t* b);
int s21_sum_matrix(matrix_t* a, matrix_t* b, matrix_t* result);
int s21_sub_matrix(matrix_t* a, matrix_t* b, matrix_t* result);
int s21_mult_number(matrix_t* a, double number, matrix_t* result);
int s21_mult_matrix(matrix_t* a, matrix_t* b, matrix_t* result);
int s21_transpose(matrix_t* a, matrix_t* result);
int s21_calc_complements(matrix_t* a, matrix_t* result);
int s21_determinant(matrix_t* a, double* result);
int s21_inverse_matrix(matrix_t* a, matrix_t* result);

int are_equal(double a, double b, double epsilon);
int not_equal(double a, double b, double epsilon);
int sign(int rows, int columns);
void get_little_matrix(const matrix_t* a, int row_to_exclude, int column_to_exclude, matrix_t* result);


#endif  //  SRC_S21_MATRIX_H_
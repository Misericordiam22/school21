#ifndef S21_MATRIX_S21_MATRIX_H_
#define S21_MATRIX_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

#define SUCCESS 1
#define FAILURE 0
int s21_eq_matrix(matrix_t *A, matrix_t *B);

#define OK 0
#define ERROR_MATRIX 1
#define ERROR_MEMORY 1
#define ERROR_CALC 2
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // S21_MATRIX_S21_MATRIX_H_
#include "s21_matrix.h"

int invalid_matrix(matrix_t *A) {
  int code = OK;
  if (A == NULL || A->matrix == NULL || (*A).rows < 1 || (*A).columns < 1) {
    code = ERROR_MATRIX;
  } else {
    for (int row = 0; row < A->rows && code != ERROR_MATRIX; row++) {
      if (!A->matrix[row]) code = ERROR_MATRIX;
    }
  }
  return code;
}

int is_not_equal_rows_columns(matrix_t *A, matrix_t *B) {
  return (A->rows != B->rows || A->columns != B->columns);
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int code = OK;
  if ((result == NULL) || rows < 1 || columns < 1) {
    code = ERROR_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      // code = ERROR_MEMORY;
    } else {
      for (int row = 0; row < rows && code != 1; ++row) {
        result->matrix[row] = (double *)calloc(columns, sizeof(double));
        // if (result->matrix[i] == NULL) {
        //   code = ERROR_MEMORY;
        //   for (int j = 0; j < i; ++j) {
        //     free(result->matrix[j]);
        //   }
        //   free(result->matrix);
        // }
      }
    }
  }
  return code;
}

void s21_remove_matrix(matrix_t *A) {
  if (!invalid_matrix(A)) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
      A->matrix[i] = NULL;
    }
    free(A->matrix);
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code = SUCCESS;
  if (is_not_equal_rows_columns(A, B)) {
    code = FAILURE;
  } else {
    double different = 0;
    for (int i = 0; i < (A->rows * A->columns) && code != 0; i++) {
      different = (*A).matrix[i / A->columns][i % A->columns] -
                  (*B).matrix[i / B->columns][i % B->columns];
      if (fabs(different) >= 1e-7) {
        code = FAILURE;
      }
    }
  }
  return code;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;
  if (result == NULL || invalid_matrix(A) || invalid_matrix(B)) {
    return ERROR_MATRIX;
  } else if (is_not_equal_rows_columns(A, B)) {
    return ERROR_CALC;
  }
  if (result->matrix == NULL)
    s21_create_matrix((*A).rows, (*A).columns, result);
  double temp = 0;
  for (int i = 0; i < A->rows && code != ERROR_CALC; i++) {
    for (int j = 0; j < A->columns && code != ERROR_CALC; j++) {
      temp = (*A).matrix[i][j] + (*B).matrix[i][j];
      if (isinf(temp) || isnan(temp)) {
        code = ERROR_CALC;
        s21_remove_matrix(result);
      } else {
        (*result).matrix[i][j] = temp;
      }
    }
  }
  return code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;
  if (result == NULL || invalid_matrix(A) || invalid_matrix(B)) {
    return ERROR_MATRIX;
  } else if (is_not_equal_rows_columns(A, B)) {
    return ERROR_CALC;
  }
  if (result->matrix == NULL)
    s21_create_matrix((*A).rows, (*A).columns, result);
  double temp = 0;
  for (int i = 0; i < A->rows && code != ERROR_CALC; i++) {
    for (int j = 0; j < A->columns && code != ERROR_CALC; j++) {
      temp = (*A).matrix[i][j] - (*B).matrix[i][j];
      if (isinf(temp) || isnan(temp)) {
        code = ERROR_CALC;
        s21_remove_matrix(result);
      } else {
        (*result).matrix[i][j] = temp;
      }
    }
  }
  return code;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code = OK;
  if (result == NULL || invalid_matrix(A)) {
    return ERROR_MATRIX;
  }
  if (result->matrix == NULL)
    s21_create_matrix((*A).rows, (*A).columns, result);
  double temp = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      temp = (*A).matrix[i][j] * number;
      if (isinf(temp) || isnan(temp)) {
        code = ERROR_CALC;
        s21_remove_matrix(result);
      } else {
        (*result).matrix[i][j] = temp;
      }
    }
  }
  return code;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;
  if (result == NULL || invalid_matrix(A) || invalid_matrix(B)) {
    return ERROR_MATRIX;
  } else if ((*A).columns != (*B).rows) {
    return ERROR_CALC;
  }
  if (result->matrix == NULL)
    s21_create_matrix((*A).rows, (*B).columns, result);
  double temp = 0;
  for (int row = 0; row < (*A).rows && code != ERROR_CALC; row++) {
    for (int column = 0; column < (*B).columns && code != ERROR_CALC;
         column++) {
      temp = 0;
      for (int k = 0; k < A->columns; k++) {
        temp += A->matrix[row][k] * B->matrix[k][column];
      }
      if (isinf(temp) || isnan(temp)) {
        code = ERROR_CALC;
        s21_remove_matrix(result);
      } else {
        (*result).matrix[row][column] = temp;
      }
    }
  }
  return code;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (result == NULL || invalid_matrix(A)) {
    return ERROR_MATRIX;
  } else {
    if (result->matrix == NULL) s21_create_matrix(A->columns, A->rows, result);
    for (int row = 0; row < result->rows; row++) {
      for (int column = 0; column < result->columns; column++) {
        result->matrix[row][column] = A->matrix[column][row];
      }
    }
  }
  return code;
}

void fill_minor_matrix(matrix_t A, matrix_t *A_minor, int scale, int row,
                       int column) {
  int skip_i = 0;
  int skip_j = 0;
  for (int i = 0; i < scale; i++) {
    skip_j = 0;
    if (i == row) {
      skip_i = 1;
      continue;
    }
    for (int j = 0; j < scale; j++) {
      if (j == column) {
        skip_j = 1;
        continue;
      }
      (*A_minor).matrix[i - skip_i][j - skip_j] = A.matrix[i][j];
    }
  }
}

double get_determinant(matrix_t A) {
  double result = 0;
  int scale = A.rows;
  if (scale == 1) {
    result = A.matrix[0][0];
  } else if (scale == 2) {
    result = A.matrix[0][0] * A.matrix[1][1] - A.matrix[0][1] * A.matrix[1][0];
  } else {
    matrix_t A_minor = {0};
    s21_create_matrix(scale - 1, scale - 1, &A_minor);
    for (int column = 0; column < scale; column++) {
      fill_minor_matrix(A, &A_minor, scale, 0, column);
      double coefficient = (column % 2 == 0) ? 1 : -1;
      result += A.matrix[0][column] * coefficient * get_determinant(A_minor);
    }
    s21_remove_matrix(&A_minor);
  }
  return result;
}

int s21_determinant(matrix_t *A, double *result) {
  int code = OK;
  if (result == NULL || invalid_matrix(A)) {
    code = ERROR_MATRIX;
  } else if ((*A).rows != (*A).columns) {
    code = ERROR_CALC;
  } else {
    *result = get_determinant(*A);
  }
  return code;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (result == NULL || invalid_matrix(A)) {
    return ERROR_MATRIX;
  } else if ((*A).rows != (*A).columns) {
    return ERROR_CALC;
  }
  if (result->matrix == NULL)
    s21_create_matrix((*A).rows, (*A).columns, result);
  int scale = A->rows;
  matrix_t A_minor = {0};
  s21_create_matrix(scale - 1, scale - 1, &A_minor);
  for (int row = 0; row < scale && code != ERROR_CALC; row++) {
    for (int column = 0; column < scale && code != ERROR_CALC; column++) {
      fill_minor_matrix(*A, &A_minor, scale, row, column);
      double coefficient = ((column + row) % 2 == 0) ? 1 : -1;
      double minor = get_determinant(A_minor);
      if (isinf(minor) || isnan(minor)) {
        code = ERROR_CALC;
        s21_remove_matrix(result);
      } else {
        (*result).matrix[row][column] = coefficient * minor;
      }
    }
  }
  s21_remove_matrix(&A_minor);
  return code;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (result == NULL || invalid_matrix(A)) {
    return ERROR_MATRIX;
  } else if ((*A).rows != (*A).columns) {
    return ERROR_CALC;
  }
  int scale = A->rows;
  if (result->matrix == NULL) s21_create_matrix(scale, scale, result);
  double determinant = get_determinant(*A);
  if (determinant == 0 || isinf(determinant) || isnan(determinant)) {
    s21_remove_matrix(result);
    code = ERROR_CALC;
  } else if (scale == 1) {
    (*result).matrix[0][0] = 1 / (*A).matrix[0][0];
  } else {
    matrix_t raw_matrix = {0};
    s21_create_matrix(scale, scale, &raw_matrix);
    code = s21_calc_complements(A, &raw_matrix);
    if (!code) code = s21_transpose(&raw_matrix, result);
    if (!code) code = s21_mult_number(result, (1.0 / determinant), result);
    s21_remove_matrix(&raw_matrix);
  }
  return code;
}

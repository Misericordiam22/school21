#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

void sort(int *a, int n, int m);
int input_size(int *n, int *m);
int input(int **matrix, int n, int m, int *matrixline);

void fill_array_vert(int **a, int n, int m, int *matrixline);
void fill_array(int **matrix, int n, int m, int *matrixline);
void output(int **matrix, int n, int m);

int main() {
    int n, m;
    if (input_size(&n, &m) == 0) {
        printf("n/a");
        return 0;
    }
    int **result = malloc(n * sizeof(int));
    int *result_val_array = malloc(n * m * sizeof(int));

    for (int i = 0; i < n; i++) {
        result[i] = result_val_array + m * i;
    };

    int **pointer_array = malloc(n * sizeof(int));
    int *values_array = malloc(n * m * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        pointer_array[i] = values_array + m * i;
    };

    int *matrixline = malloc(n * m * sizeof(int));
    if (input(pointer_array, n, m, matrixline) == 0) {
        printf("n/a");
        return 0;
    } else {
        sort(matrixline, n, m);
        fill_array_vert(pointer_array, n, m, matrixline);
    }

    sort_vertical(pointer_array, n, m, result);
    output(result, n, m);
    printf("\n\n");
    fill_array(pointer_array, n, m, matrixline);
    sort_horizontal(pointer_array, n, m, result);
    output(result, n, m);
}

int input_size(int *n, int *m) { return (scanf("%d %d", n, m) == 2); }

int input(int **a, int n, int m, int *matrixline) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                return 0;
            }
            matrixline[m * i + j] = a[i][j];
        }
    }
    return 1;
}

void fill_array(int **a, int n, int m, int *matrixline) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = matrixline[m * i + j];
        }
    }
}

void fill_array_vert(int **a, int n, int m, int *matrixline) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[j][i] = matrixline[n * i + j];
        }
    }
}

void sort(int *a, int n, int m) {
    int temp;
    for (int i = 0; i < n * m; i++) {
        for (int j = i + 1; j < n * m; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void output(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", a[i][j]);
            if (j < m - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }
}

void sort_vertical(int **a, int n, int m, int **result) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 != 0) {
                result[j][i] = a[n - j - 1][i];
            } else {
                result[j][i] = a[j][i];
            }
        }
    }
}

void sort_horizontal(int **a, int n, int m, int **result) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % 2 != 0) {
                result[i][j] = a[i][m - j - 1];
            } else {
                result[i][j] = a[i][j];
            }
        }
    }
}
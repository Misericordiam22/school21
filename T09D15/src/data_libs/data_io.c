#include "data_io.h"

int input(double *data, int n) {
    int flag = 1;
    for (double *p = data; p - data < n; p++) {
        if (scanf("%lf", &*p) != 1) flag = 0;
    }
    return flag;
}

void output(double *data, int n) {
    for (double *p = data; p - data < n; p++) {
        printf("%.2lf", *p);
        if (p - data != n - 1) {
            printf(" ");
        }
    }
}
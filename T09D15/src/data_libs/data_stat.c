#include "data_stat.h"

double max(double *data, int n) {
    double max_v = data[0];
    for (double *p = data + 1; p - data < n; p++) {
        if (*p > max_v) {
            max_v = *p;
        }
    }
    return max_v;
}
double min(double *data, int n) {
    double min_v = data[0];
    for (double *p = data + 1; p - data < n; p++) {
        if (*p < min_v) {
            min_v = *p;
        }
    }
    return min_v;
}
double mean(double *data, int n) {
    double sum = 0;
    int i;
    for (i = 0; i < n; ++i) sum += data[i];
    return sum / n;
}
double variance(double *data, int n) {
    double sum = 0, mean1 = mean(data, n);
    int i;
    for (i = 0; i < n; ++i) sum += (data[i] - mean1) * (data[i] - mean1);
    return sum / n;
}

void sort(double *a, int n) {
    int i, j, temp;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
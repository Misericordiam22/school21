#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    } else {
        printf("n/a");
    };
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1) {
        return 0;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", &*p) != 1) {
            return 0;
        };
    }
    return 1;
};
void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a != n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
};
int max(int *a, int n) {
    int max_v = a[0];
    for (int *p = a + 1; p - a < n; p++) {
        if (*p > max_v) {
            max_v = *p;
        }
    }
    return max_v;
}

int min(int *a, int n) {
    int min_v = a[0];
    for (int *p = a + 1; p - a < n; p++) {
        if (*p < min_v) {
            min_v = *p;
        }
    }
    return min_v;
};

double mean(int *a, int n) {
    double sum = 0;
    int i;
    for (i = 0; i < n; ++i) sum += a[i];
    return sum / n;
};

double variance(int *a, int n) {
    double sum = 0;
    double mean1 = mean(a, n);
    int i;
    for (i = 0; i < n; ++i) sum += (a[i] - mean1) * (a[i] - mean1);
    return sum / n;
};

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
};
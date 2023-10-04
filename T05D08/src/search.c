/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
int is_even(int num);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        double mean1 = mean(data, n);
        for (int *p = data; p - data < n; p++) {
            if (*p != 0 && is_even(*p) && (*p >= mean(data, n)) &&
                (*p <= mean1 + 3 * sqrt(variance(data, n)))) {
                printf("%d", *p);
                return 0;
            }
        }
        printf("%d", 0);
    } else {
        printf("n/a");
        return 0;
    }
}
int input(int *a, int *n) {
    if (scanf("%d", n) != 1) {
        return 0;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", &*p) != 1) {
            return 0;
        }
    }
    return 1;
}
void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a != n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}
int is_even(int num) {
    if (num % 2 == 0) {
        return 1;
    } else
        return 0;
}

double mean(int *a, int n) {
    double sum = 0;
    int i;

    for (i = 0; i < n; ++i) sum += a[i];

    return sum / n;
}

double variance(int *a, int n) {
    double sum = 0;
    double mean1 = mean(a, n);

    int i;

    for (i = 0; i < n; ++i) sum += (a[i] - mean1) * (a[i] - mean1);

    return sum / n;
};
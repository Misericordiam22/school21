#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int n = 10, data[NMAX];
    if (input(data, n) != 0) {
        sort(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (scanf("%d", &*p) != 1) {
            return 0;
        };
    }
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a != n - 1) {
            printf(" ");
        }
    }
}

void sort(int *a, int n) {
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
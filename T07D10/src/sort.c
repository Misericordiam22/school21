#include <stdio.h>
#include <stdlib.h>
int input_n(int *n);
int input(int *a, int n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int n;
    if (input_n(&n) == 0) {
        printf("n/a");
    } else {
        int *ip = (int *)malloc(n * sizeof(int));
        if (ip == NULL) {
            printf("n/a");

        } else if (input(ip, n) != 0) {
            sort(ip, n);
            output(ip, n);
        } else {
            printf("n/a");
        }
    }
    return 0;
}

int input_n(int *n) { return (scanf("%d", n) == 1); }

int input(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
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
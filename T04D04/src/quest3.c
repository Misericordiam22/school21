#include <stdio.h>

long int getFibon(int n);

int main() {
    int n;
    if ((scanf("%d", &n) != 1) || (n < 0)) {
        printf("n/a");
    } else {
        printf("%ld", getFibon(n));
    }
    return 1;
}

long int getFibon(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return (getFibon(n - 1) + getFibon(n - 2));
}
#include <stdio.h>

int getMax(int a, int b);

int main() {
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("n/a");
        return 0;
    }
    printf("%d", getMax(num1, num2));
    return 0;
}

int getMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
#include <math.h>
#include <stdio.h>

int isDivided(int a, int b);
int getDivision(int a, int b);

int main() {
    int a;

    if (scanf("%d", &a) != 1) {
        printf("n/a");
    } else {
        if (a < 0) {
            a = a * -1;
        }
        if (a >= 4) {
            int diviser = 2;
            while (diviser * diviser <= a) {
                if (isDivided(a, diviser)) {
                    a = getDivision(a, diviser);
                } else {
                    diviser++;
                }
            }
            printf("%d", a);
        } else if (a > 1) {
            printf("%d", a);
        } else {
            printf("n/a");
        }
    }
    return 1;
}

int isDivided(int a, int b) {
    while (a >= b) {
        a -= b;
    }
    if (a != 0) {
        return 0;
    }
    return 1;
}

int getDivision(int a, int b) {
    int count = 0;
    while (a >= b) {
        a -= b;
        count++;
    }
    return count;
}
#include <stdio.h>

int sum(int a, int b);

int diff(int a, int b);

int product(int a, int b);

int division(int a, int b);

int main() {
    int num1, num2;
    int not_number = 1;
    if (scanf("%d %d", &num1, &num2) != 2) {
        not_number = 1;
        printf("n/a");
        return 0;
    }
    int sumnum = sum(num1, num2);
    int diffnum = diff(num1, num2);
    int prodnum = product(num1, num2);
    char divnum[20];
    if (num2 == 0) {
        sprintf(divnum, "%s", "n/a");
    } else {
        int divn = division(num1, num2);
        sprintf(divnum, "%d", divn);
    }
    printf("%d %d %d %s", sumnum, diffnum, prodnum, divnum);
    return 0;
}

int sum(int a, int b) { return (a + b); }

int diff(int a, int b) { return (a - b); }

int product(int a, int b) { return (a * b); }

int division(int a, int b) { return (a / b); }
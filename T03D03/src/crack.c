#include <stdio.h>

char *inCircle(float a, float b);

int main() {
    float num1, num2;
    if (scanf("%f %f", &num1, &num2) != 2) {
        printf("n/a");
        return 0;
    }
    printf("%s", inCircle(num1, num2));
    return 0;
}

char *inCircle(float a, float b) {
    if ( (a * a + b * b) <= 25) {
        return "GOTCHA";
    } else {
        return "MISS";
    }
}
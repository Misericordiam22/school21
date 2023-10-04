#include <math.h>
#include <stdio.h>

float magic_function(float x);
// y = 7e-3 * x^4 + ((22.8 * x^⅓ - 1e3) * x + 3) / (x * x / 2) - x * (10 + x)^(2/x) - 1.01.

int main() {
    float float1;
    if (scanf("%f", &float1) != 1) {
        printf("n/a");
        return 0;
    }
    float1 = magic_function(float1);
    printf("%.1f", float1);
    return 0;
}

float magic_function(float x) {
    float res;
    float first_num = 7 * pow(10, -3) * pow(x, 4);
    float second_num = ((22.8 * pow(x, 1 / 3) - 1 * pow(10, 3)) * x + 3) / (x * x / 2);
    float third_num = x * pow((10 + x), (2 / x));
    res = first_num + second_num - third_num - 1.01;
    return res;
}
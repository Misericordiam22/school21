#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *number_shift);
void output(int *result_buffer, int length);
void shift_numbers(int *buffer, int *result_buffer, int length, int number_shift);

int main() {
    int n, data[NMAX], result_data[NMAX], number_shift;
    if (input(data, &n, &number_shift) != 0) {
        shift_numbers(data, result_data, n, number_shift);
        output(result_data, n);
    } else {
        printf("n/a");
    }
    return 0;
}
int input(int *buffer, int *length, int *number_shift) {
    if (scanf("%d", length) != 1 || *length > 10 || *length < 1) {
        return 0;
    }
    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d", &*p) != 1) {
            return 0;
        };
    }
    if (scanf("%d", number_shift) != 1) {
        return 0;
    }
    *number_shift = *number_shift % *length;
    return 1;
}

void output(int *result_buffer, int length) {
    for (int *p = result_buffer; p - result_buffer < length; p++) {
        printf("%d", *p);
        if (p - result_buffer != length - 1) {
            printf(" ");
        }
    }
}

void shift_numbers(int *buffer, int *result_buffer, int length, int number_shift) {
    int index;
    for (int *p = buffer; p - buffer < length; p++) {
        index = (p - buffer - number_shift + length) % length;
        result_buffer[index] = *p;
    }
}

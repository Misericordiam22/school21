#include <stdio.h>
#include <stdlib.h>
int input_modeAndSize(int *mode, int *str, int *col);
void output(int *a, int str, int col);
// int signle_array_matrix(int str, int col);

int main() {
    int mode, str, col;
    if (input_modeAndSize(&mode, &str, &col) == 0) {
        printf("n/a");
    } else {
        printf("n/a");
        switch (mode) {
            case 1:
                /* code */
                break;

            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            default:
                break;
        }
    }
    return 0;
}

int input_modeAndSize(int *mode, int *str, int *col) {
    int flag = 0;
    if (scanf("%d", mode) == 1 && *mode > 0 && *mode < 5) {
        if (scanf("%d %d", str, col) == 2 && *str <= 100 && *str > 0 && *col <= 100 && *col > 0) {
            flag = 1;
        }
    }
    return flag;
}

void output(int *a, int str, int col) {
    for (int *p = a; p - a - col < str; p++) {
        printf("%d", *p);
        col = 1;

        if (p - a != str - 1) {
            printf(" ");
        }
    }
}

// int signle_array_matrix(int str, int col) {
//     // int signle_array_matrix = malloc(str * col * sizeof(int)) + str * sizeof(int *);
//     return 1;
// }

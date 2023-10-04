#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    int n;
    if (scanf("%d", &n) != 0) {
        double *data = (double *)malloc(n * sizeof(double));
        if (input(data, n) != 0) {
            if (make_decision(data, n)) {
                printf("YES");
            } else {
                printf("NO");
            }
        }
    }
    return 0;
}
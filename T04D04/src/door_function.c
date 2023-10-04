#include <math.h>
#include <stdio.h>
double getAneze(double x);
double getBernul(double x);
double quadHyper(double x);
int main() {
    double pi = -M_PI;
    while (pi < M_PI) {
        if (isnan(getBernul(pi))) {
            printf("%.7lf | %.7lf | - | %.7lf\n", pi, getAneze(pi), quadHyper(pi));
        } else {
            printf("%.7lf | %.7lf | %.7lf | %.7lf\n", pi, getAneze(pi), getBernul(pi), quadHyper(pi));
        }
        pi += 2 * M_PI / 41;
    }
    return 1;
}

double getAneze(double x) {
    double res = 1 / (1 + x * x);
    return res;
}

double getBernul(double x) {
    double res = sqrt(sqrt(1 + 4 * x * x) - pow(x, 2) - 1);
    return res;
}

double quadHyper(double x) { return 1 / (x * x); }
#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n, int f);
void output(int a, int f);
double mean(int *a, int *n);
double sigma(int *a, int *n);
int call(int *a, int *n);

void output_result(int max_v, int min_v, double mean_v, double variance_v, int f);

int main() {
    int n, data[NMAX];
    int flag = 1;
    flag = input(data, &n, flag);
    int res = call(data, &n);
    output(res, flag);
    return 0;
}

int input(int *a, int *n, int f) {
    if (scanf("%d", n) != 1 && getchar() != '\n') {
        f = 0;
        *n = 0;
    } else if (*n > NMAX) {
        f = 0;
        *n = 0;
    } else {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                f = 0;
            }
        }
        if (getchar() != '\n') {
            f = 0;
        }
    }
    return f;
}

void output(int a, int f) {
    if (f == 1) {
        printf("%d\n", a);
    } else {
        printf("n/a\n");
    }
}

double mean(int *a, int *n) {
    double res = 0;
    for (int *p = a; p - a < *n; p++) {
        res += *p;
    }
    return (res / (*n));
}

double sigma(int *a, int *n) {
    double res = 0;
    for (int *p = a; p - a < *n; p++) {
        res += pow((*p - mean(a, n)), 2);
    }
    return sqrt(res / (*n));
}

int call(int *a, int *n) {
    int res = 0;
    for (int *p = a; p - a < *n; p++) {
        if ((*p) % 2 == 0 && (*p) >= mean(a, n) && (*p) != 0 && (*p) >= (mean(a, n) - 3 * sigma(a, n)) &&
            (*p) <= (mean(a, n) + 3 * sigma(a, n))) {
            res = *p;
            break;
        }
    }
    return res;
}

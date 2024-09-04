#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int f);
void output(int *a, int *n, int f);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n);

void output_result(int max_v, int min_v, double mean_v, double variance_v, int f);

int main() {
    int n, data[NMAX];
    int flag = 1;
    flag = input(data, &n, flag);
    output(data, &n, flag);
    // max(data, &n);
    output_result(max(data, &n), min(data, &n), mean(data, &n), variance(data, &n), flag);

    return 0;
}

int input(int *a, int *n, int f) {
    if (scanf("%d", n) != 1 && getchar() != '\n') {
        f = 0;
        *n = 0;
    } else if (*n > 10) {
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

void output(int *a, int *n, int f) {
    if (f == 1) {
        for (int *p = a; p - a < *n; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    } else {
        printf("n/a\n");
    }
}

int max(int *a, int *n) {
    int max = *a;
    for (int *p = a; p - a < *n; p++) {
        if (max < *p) {
            max = *p;
        }
    }
    return max;
}

int min(int *a, int *n) {
    int min = *a;
    for (int *p = a; p - a < *n; p++) {
        if (min > *p) {
            min = *p;
        }
    }
    return min;
}

double mean(int *a, int *n) {
    double res = 0;
    for (int *p = a; p - a < *n; p++) {
        res += *p;
    }
    return (res / (*n));
}

double variance(int *a, int *n) {
    double res = 0;
    for (int *p = a; p - a < *n; p++) {
        res += pow((*p - mean(a, n)), 2);
    }
    return (res / (*n));
}

void output_result(int max_v, int min_v, double mean_v, double variance_v, int f) {
    if (f == 1) {
        printf("%d %d %.6lf %.6lf\n", max_v, min_v, mean_v, variance_v);
    }
}
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int f);
void output(int *a, int *n, int f);
void squaring(int *a, int *n);

int main() {
    int n, data[NMAX];
    int flag = 1;
    flag = input(data, &n, flag);
    if (flag == 1) {
        squaring(data, &n);
    }
    output(data, &n, flag);

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

void squaring(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        *p = (*p) * (*p);
    }
}
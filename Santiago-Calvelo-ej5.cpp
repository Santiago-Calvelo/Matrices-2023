#include <stdio.h>

void print_matrix(int m[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void make_matrix(int m[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Valor %d%d de la matriz: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

int main(void) {
    int a[2][2];
    int b[2][2];
    int p[2][2];

    printf("Haga la primer matriz:\n");
    make_matrix(a);
    printf("Haga la segunda matriz:\n");
    make_matrix(b);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            p[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                p[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    print_matrix(p);
}
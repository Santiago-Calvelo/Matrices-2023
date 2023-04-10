#include <stdio.h>

int main(void) {
    int a[3][3];
    int ad[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Ingrese el valor %d%d de la matriz: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    ad[0][0]= a[1][1] * a[2][2] - a[2][1] * a[1][2];
    ad[1][0] = a[2][0] * a[1][2] - a[1][0] * a[2][2];
    ad[2][0] = a[1][0] * a[2][1] - a[2][0] * a[1][1];
    ad[0][1] = a[2][1] * a[0][2] - a[0][1] * a[2][2];
    ad[1][1] = a[0][0] * a[2][2] - a[2][0] * a[0][2];
    ad[2][1] = a[2][0] * a[0][1] - a[0][0] * a[2][1];
    ad[0][2] = a[0][1] * a[1][2] - a[1][1] * a[0][2];
    ad[1][2] = a[1][0] * a[0][2] - a[0][0] * a[1][2];
    ad[2][2] = a[0][0] * a[1][1] - a[1][0] * a[0][1];

    printf("La matriz adjunta:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", ad[i][j]);
        }
        printf("\n");
    }
}   
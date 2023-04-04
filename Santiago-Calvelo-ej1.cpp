#include <stdio.h>

int main(void) {
    int m[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Ingrese el valor %d%d de la matriz: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    printf("Matriz original:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("Matriz traspuesta:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", m[j][i]);
        }
        printf("\n");
    }
}
#include <stdio.h>

int main(void) {
    int meses[2][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0}
    };

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 12; j++) {
            if (meses[i][j] == 30)  meses[1][j] = 1;   
        }
    }
    printf("Los meses con 30 dias son: ");
    for (int i = 0; i < 12; i++) {
        if (meses[1][i] == 1) printf("%d ", i+1);
    }
    printf("\n");
}
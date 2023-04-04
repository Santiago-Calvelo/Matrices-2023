#include <stdio.h>

int main(void) {
    int a[3][3];
    int ad[3][3];
    int f, c, d;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Ingrese el valor %d%d de la matriz: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    

   for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int s[2][2];
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    if (k < i) f = k;
                    else       f = k+1;
                    
                    if (l < j) c = l;
                    else       c = l+1;
                    s[k][l] = a[f][c];
                }
            }
            d = s[0][0] * s[1][1] - s[0][1] * s[1][0];
            if ((i+j) % 2 == 0) ad[j][i] = d;
            else                ad[j][i] = d * -1;
        }
    }

    printf("La matriz adjunta:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", ad[i][j]);
        }
        printf("\n");
    }
}   
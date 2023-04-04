#include <stdio.h>

void calcule(int ad[3][3], int a[3][3]) {
    int f, c, d;
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
}

void printin(float in[3][3]) {
    printf("La inversa es:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", in[i][j]);
        }
        printf("\n");
    }
}

void inverse(float in[3][3], int ad[3][3], int d) {
    float fd = (float)d;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
             in[i][j] = 1.0/fd * ad[j][i];
        }
    }
}

int det(int a[3][3]) {
    return (a[0][0] * a[1][1] * a[2][2]) + (a[0][1] * a[1][2] * a[2][0]) 
          + (a[0][2] * a[1][0] * a[2][1]) - (a[0][2] * a[1][1] * a[2][0]) 
          - (a[0][1] * a[1][0] * a[2][2]) - (a[0][0] * a[1][2] * a[2][1]);
}

void make_matrix(int a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Ingrese el valor %d%d de la matriz: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

}

int main(void) {
    int a[3][3];
    int ad[3][3];
    float in[3][3];

    make_matrix(a);
    int d = det(a);
    if (d == 0) {
        printf("La matriz no tiene inversa\n");
        return 0;
    }
    calcule(ad,a);
    inverse(in,ad,d);
    printin(in);
}
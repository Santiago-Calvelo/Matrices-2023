#include <stdio.h>

void calcule(int ad[3][3], int a[3][3]) {
    ad[0][0]= a[1][1] * a[2][2] - a[2][1] * a[1][2];
    ad[1][0] = a[2][0] * a[1][2] - a[1][0] * a[2][2];
    ad[2][0] = a[1][0] * a[2][1] - a[2][0] * a[1][1];
    ad[0][1] = a[2][1] * a[0][2] - a[0][1] * a[2][2];
    ad[1][1] = a[0][0] * a[2][2] - a[2][0] * a[0][2];
    ad[2][1] = a[2][0] * a[0][1] - a[0][0] * a[2][1];
    ad[0][2] = a[0][1] * a[1][2] - a[1][1] * a[0][2];
    ad[1][2] = a[1][0] * a[0][2] - a[0][0] * a[1][2];
    ad[2][2] = a[0][0] * a[1][1] - a[1][0] * a[0][1];
}

void printin(float in[3][3]) {
    printf("La inversa es:\n");
    for (int i = 0; i < 3; i++) {   
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", in[j][i]);
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
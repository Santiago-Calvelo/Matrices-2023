#include <stdio.h>
#include <limits.h>

void new_valor(int j[9]) {
    char c;
    
    while (1) {
        int repetido = 0;
        printf("Ingrese la inicial del 4to jugador: ");
        scanf(" %c", &c);

        for (int i = 0; i < 9; i++) { 
            if (j[i] == c || j[i] == c-32) { repetido = 1; break; } 
        }

        if (repetido) printf("La inicial ya esta cargada\n"); 
        else          { j[3] = c; break; }
    }
   
}

int main(void) {
    char j[9] = {'a', 'f', 's', '\0', 'i', 'd', 'g', 'h', 'n'};
    char points[9][4] = {0};
    char n, p;
    
    new_valor(j);

    printf("Ingrese su inicial: ");
    scanf(" %c", &n);

    printf("Las posiciones validas son C, M, B, F\n");
    while (1) {
        char choice;
        for (int i = 0; i < 9; i++) {
        printf("Ingrese la posicion: ");
        scanf(" %c", &p);
        if      (p == 'c' || p == 'C') points[i][0] += 100;
        else if (p == 'm' || p == 'M') points[i][1] += 50;
        else if (p == 'b' || p == 'B') points[i][2] += 10;
        else if (p == 'f' || p == 'F') points[i][3] -= 10;
        else    printf("Ingrese una posicion valida\n");
        }
        
        printf("Deseas seguir ingresando datos? s/n\n");
        scanf(" %c", &choice);
        if (choice == 'n') break; 
    } 

}
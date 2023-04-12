#include <stdio.h>
#include <limits.h>

void print_results(char j[10][20], int points[9][4], int player, int tiros, int contC, int e, int participantes, char posicion[20]) {
    for (int i = 0; i < 9; i++) {
        if      (posicion[i] == 'c' || posicion[i] == 'C' && i == player) printf("\tc: %d\n", points[player][0]);
        else if (posicion[i] == 'm' || posicion[i] == 'M' && i == player) printf("\tm: %d\n", points[player][1]);
        else if (posicion[i] == 'b' || posicion[i] == 'B' && i == player) printf("\tb: %d\n", points[player][2]);
        else if (posicion[i] == 'f' || posicion[i] == 'F' && i == player) printf("\tf: %d\n", points[player][3]); 
    }
    printf("El porcentaje de tiros centrados del jugador es: %.2f\n", (contC * 100) / tiros);
    printf("El porcentaje de menores de edad es: %.2f\n", (e * 100) / participantes);
}

void game(char j[10][20], int points[9][4]) {
    int participantes = 0;

    while (1) {

        char n, p;
        int e;
        int contE = 0;
        printf("Ingrese su inicial: ");
        scanf(" %c", &n);

        int player = -1;
        for (int i = 0; i < 9; i++) { if (j[i][0] == n || j[i][0]+32 == n) player = i; }
        if (player == -1) printf("Ingrese una inicial valida, %d\n", player);
        
        printf("Ingrese su edad: ");
        scanf("%d", &e);
        
        if(e < 18) contE++;
        participantes++;
        while (1) {
        	int i = 0;
        	char posicion[20];
            int tiros = 0;
            int contC = 0;
            printf("Las posiciones validas son C, M, B, F\n");
            printf("Ingrese la posicion: ");
            scanf(" %c", &p);
            posicion[i] = p;
            if      (p == 'c' || p == 'C') { points[player][0] += 100; tiros++; contC++; }
            else if (p == 'm' || p == 'M') { points[player][1] += 50; tiros++; }
            else if (p == 'b' || p == 'B') { points[player][2] += 10; tiros++; }
            else if (p == 'f' || p == 'F') { points[player][3] -= 10; tiros++; }
            else                           printf("Ingrese una posicion valida\n");
            
            printf("Deseas seguir ingresando datos? s/n\n");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'n') {
                print_results(j,points,player,tiros,contC,e,participantes,posicion);
                break;
            }
            i++;
        }

        printf("Deseas seguir jugando? s/n\n");
        char choice2;
        scanf(" %c", &choice2);
        if (choice2 == 'n' && participantes >= 9) break;
        else if (participantes < 9) printf("Tienen que participar todos los jugadores\n");
    }
}

void new_valor(char j[10][20]) {
    char c;
    
    while (1) {
        int repetido = 0;
        printf("Ingrese la inicial del 4to jugador: ");
        scanf(" %c", &c);

        for (int i = 0; i < 9; i++) { 
            if (j[i][0] == c || j[i][0] == c-32) { repetido = 1; break; } 
        }

        if (repetido) printf("La inicial ya esta cargada\n"); 
        else { 
			j[3][0] = c;
			printf("La inicial se cargo correctamente\n"); 
			break; 
		}
    }
   
}

int main(void) {
    char j[10][20] = {"Ana", "Francisco", "Santiago", "\0", "Ignacio", "Diego", "Guido", "Hector", "Nahuel"};
    int points[9][4] = {0};
    
    new_valor(j);
    game(j,points);
}

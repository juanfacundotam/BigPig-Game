#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//DECLARACION DE FUNCIONES
void menu(char &opcion); //recibe la variable, la modifica para despues utilizarse en el main.
void inicio(string &primero, string &segundo); //va a recibir 2 parametros por referencia, modificando el valor de las variables del main.
void juego(string player1, string player2, string &ganador, int &puntaje);
void estadisticas(string vecGanador[], int, int vecPuntaje[], int); //Se carga con un vector, de manera que no se pise y que genere una lista
void creditos();
int tirar();
int dibujos(int numero);
void mayuscula (string &texto);
void reglas();

#endif // FUNCIONES_H_INCLUDED

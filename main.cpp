//TP: Integrador
//EJ: Gran Cerdo
//Comentarios:
#include<iostream>
#include<stdio.h>
#include<clocale>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<string>
#include<conio.h> //getch()


using namespace std;

#include "funciones.h"

//MAIN
int main()
{
    setlocale(LC_ALL, "Spanish");

    char opcion_menu;
    int puntaje, x;
    string ganador;
    string jugador1, jugador2;
    bool bandPuntaje;
    string vecGanador[10];
    int vecPuntaje[10] = {0};
    //Menu


    menu(opcion_menu); //la funcion menu le va a asignar un valor

    //OPCIONES
    while(opcion_menu != '0'){

        bandPuntaje = true;

        switch(opcion_menu){
            case '1':

                inicio(jugador1, jugador2); //una vez que resuelve el ganador
                juego(jugador1, jugador2, ganador, puntaje);


                //Estadisticas

                    for(x=0; x<10; x++){
                        if(vecPuntaje[x] == 0 && bandPuntaje){
                            vecGanador[x] = ganador;
                            vecPuntaje[x] = puntaje;
                            bandPuntaje = false;
                        }
                    }


            break;
            case '2':
                estadisticas(vecGanador, 10, vecPuntaje, 10);
            break;
            case '3':
                creditos();
            break;
            case '4':
                reglas();
            break;
            case '0':
                // salir
            break;
            default:
                cout << "La opción ingresada es incorrecta" << endl;
            break;

        }

    Sleep(3000);

    system("cls");

    menu(opcion_menu);
    }


    //OPCION SALIR
    system("cls");
    system("color 07");
    cout << "¡<<<<<Hasta la próxima>>>>>!" << endl;
    cout << "¡<<<<<<<Volve pronto>>>>>>>!" << endl;

    Beep(1200, 100);
    Beep(1100, 100);
    Beep(1000, 100);
    Beep(900, 100);

    return 0;

}







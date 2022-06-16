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



///MENU ================================
void menu(char &opcion)
{
    char confirmacion_salida;


    do{
        system("cls");
        system("color 07");
        Beep(300, 300);

        cout << "GRAN CERDO" << endl;
        cout << "------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADÍSTICAS" << endl;
        cout << "3 - CRÉDITOS" << endl;
        cout << "4 - REGLAS" << endl;
        cout << "------------------" << endl;
        cout << "0 - SALIR" << endl;
        cout << "------------------" << endl;

        cout << "Opción: ";
        cin >> opcion;

        if(opcion == '0'){
            do{
                cout << endl << "¿Deseas salir del juego? (S/N)" << endl;
                cin >> confirmacion_salida;
                confirmacion_salida = toupper(confirmacion_salida);
            }while(confirmacion_salida != 'S' && confirmacion_salida != 'N');
            if(confirmacion_salida == 'N')
                opcion = 'r';
        }


    }while(opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4' && opcion != '0');
}






///INICIO JUEGO======================================
void inicio(string &primero, string &segundo)
{
    string nombre1, nombre2;

    int uno_dado1, uno_dado2, dos_dado1, dos_dado2;
    int maximo1, maximo2;
    bool  bandInicio = false;


    system("color 47");
    Beep(400, 150);
    system("color 67");
    Beep(500, 150);
    system("color 37");
    Beep(600, 150);
    system("color 57");
    Beep(700, 150);
    system("cls");
    cin.ignore();
    cout <<"****¡Vienvenidos al Gran Cerdo!****" << endl;
    cout << endl << "Ingrese los nombres de los jugadores" << endl;

    cout << "Nombre Jugador 1: ";
    getline(cin, nombre1);

    cout << "Nombre Jugador 2: ";
    getline(cin, nombre2);

    mayuscula(nombre1);
    mayuscula(nombre2);

    Beep(500, 100);
    Beep(800, 100);
    Beep(700, 100);
    Beep(1000, 100);


    while(!bandInicio){

        system("cls");

        cout << ">>¡Veamos quien comienza<<" << endl;
        cout << "--------------------------" << endl;

        //jugador 1
        cout << nombre1 << "    >>>   Arroja tus dados" << endl;
        system("pause");


        srand(time(NULL));

        uno_dado1 = dibujos(tirar());
        uno_dado2 = dibujos(tirar());

        //jugador 2
        cout << nombre2 << "    >>>   Arroja tus dados" << endl;
        system("pause");


        dos_dado1 = dibujos(tirar());
        dos_dado2 = dibujos(tirar());

        system("pause");

        //Comienza
        if(uno_dado1 + uno_dado2 > dos_dado1 + dos_dado2){
            primero = nombre1;
            segundo = nombre2;
            bandInicio = true;
        }
        else if(uno_dado1 + uno_dado2 < dos_dado1 + dos_dado2){
            primero = nombre2;
            segundo = nombre1;
            bandInicio = true;
        }
        else{
            if(uno_dado1 + uno_dado2 == dos_dado1 + dos_dado2){

                maximo1 = uno_dado1;
                if(uno_dado2>maximo1){
                maximo1 = uno_dado2;
                }

                maximo2 = dos_dado1;
                if(dos_dado2>maximo2){
                maximo2 = dos_dado2;
                }


                if(maximo1>maximo2){
                    primero = nombre1;
                    segundo = nombre2;
                    bandInicio = true;
                }
                else if(maximo1<maximo2){
                    primero = nombre2;
                    segundo = nombre1;
                    bandInicio = true;

                }
                else{
                    cout << "¡TREMENDO EMPATE! ¡VUELVAN A TIRAR!" << endl;
                }
            }

        }
    }

    cout << endl;
    cout << "******************************************" << endl;
    cout << "COMENZARÁ POR MAYOR PUNTAJE: " << primero << endl;
    cout << "******************************************" << endl;
    Beep(600, 50);
    Beep(600, 50);
    Beep(800, 50);
    Beep(600, 500);
    system("pause");
}


///JUEGO ========================================
void juego(string player1, string player2, string &ganador, int &puntaje) //+ dos parametro enteros para estadisticas
{
    const int RONDAS = 5;
    int x, i;
    int trufas, acuTrufas = 0, totalTrufas1 = 0, totalTrufas2 = 0;
    int dado1, dado2, dado3=0;
    string participante;
    char continuar;
    int oink, codicioso, cantLanzamientos = 0;
    bool bandDado3 = false, bandBarro = false, bandOink;
    bool bandCincuenta1 = false, bandCincuenta2 = false;
    //PUNTOS DE VICTORIA
    int cantidad1 = 0, cantidad2 = 0, cont50_1, cont50_2;
    int restoTrufas1, restoTrufas2;
    int contOink1 = 0, contOink2 = 0;
    int lanz1 = 0, lanz2 = 0, puntosLanz1 = 0, puntosLanz2 = 0;
    bool bandLanz1 = false, bandLanz2 = false;
    string palabraFinal;
    int puntosOink1, puntosOink2;
    int totalPuntos1, totalPuntos2;
    //Examen
    int promedio, contadoLanz = 0, k, l;
    int vecLanz1[5] = {}, vecLanz2[5] = {};
    int puntosPro1, puntosPro2, acuPro1 = 0, acuPro2 = 0;


    system("cls");
    system("color 47");
    Beep(400, 100);
    system("color 57");
    Beep(600, 100);
    system("color 67");
    Beep(400, 100);
    system("color 87");
    Beep(600, 100);
    system("color 97");
    Beep(800, 300);
    system("color 07");



    Sleep(500);


    //INICIO 1er FOR
    for(x = 1; x <= RONDAS; x++){
        //INICIO 2do FOR
        for(i = 1; i <= 2; i++){
            if(i % 2 != 0)
                participante = player1;
            else
                participante = player2;

            continuar = 'S';
            cantLanzamientos = 0;

            //acumulacion
            if(bandBarro){
                bandBarro = false;
                if(i % 2 == 0){
                totalTrufas2 += acuTrufas;
                }
                else{
                totalTrufas1 += acuTrufas;
                }
            }
            else{
                if(i % 2 == 0){
                totalTrufas1 += acuTrufas;
                }
                else{
                totalTrufas2 += acuTrufas;
                }
            }
            //fin acumulacion

            acuTrufas = 0;

            //ACUALIZAR EL ULTIMO PUNTAJE GANADO DE LA ULTIMA RONDA, EL TEMA DE LOS TRES DADOS
            //totaltrufas += acuTrufas activa en la misma ronda!


            //INICIO WHILE
            while(continuar == 'S' || continuar == 'N'){
                bandOink = false;


                system("cls");
                cout << "EL GRAN CERDO" <<  endl;
                cout << "------------------------------------------------------------------------" << endl;
                cout << player1 << ": " << totalTrufas1 <<  " trufas acumuladas" << "            ";
                cout << player2 << ": " << totalTrufas2 <<" trufas acumuladas" << endl << endl;

                if(continuar == 'N'  ){

                    system("cls");
                    cout << "EL GRAN CERDO" << endl;
                    cout << "------------------------------------------------------------------------" << endl;
                    cout << player1 << ": " << totalTrufas1 <<  " trufas acumuladas" << "            ";
                    cout << player2 << ": " << totalTrufas2 <<" trufas acumuladas" << endl << endl;
                    cout << "TURNO DE " << participante << endl;
                    cout << "+-------------------------+" << endl;
                    cout << "RONDA #" << x << endl;
                    cout << "TRUFAS DE LA RONDA: " << acuTrufas << endl;
                    cout << endl;
                    cout << "+-------------------------+" << endl;

                    system("pause");
                    break;
                }

                contadoLanz++;

                cout << "TURNO DE " << participante << endl;
                cout << "+-------------------------+" << endl;
                cout << "RONDA #" << x << endl;
                cout << "TRUFAS DE LA RONDA: " << acuTrufas << endl;
                cout << "LANZAMIENTO #" << ++cantLanzamientos << endl;
                cout << "+-------------------------+" << endl;

                Sleep(1000);
                Beep(300, 100);
                Beep(300, 100);

                srand(time(NULL));
                dado1 = dibujos(tirar());
                dado2 = dibujos(tirar());
                if(bandDado3){
                    dado3 = dibujos(tirar());
                }



                //INICIO REGLAS


                if(dado1 != dado2 && dado1 != dado3 && dado3 != dado2 && dado1 != 1 && dado2 != 1 && dado3 != 1){
                    trufas = dado1 + dado2 + dado3;
                    cout << "¡Sumaste " << trufas << " trufas!" << endl << endl;
                    acuTrufas += trufas;
                }
                else if(((dado1 == dado2 && dado1 != dado3) || (dado1 == dado3 && dado1 != dado2) || (dado2 == dado3 && dado2 != dado1)) && (dado1 > 1 && dado2 > 1 && dado3 > 1)){
                    trufas = dado1 + dado2 + dado3;
                    cout << "¡Sumaste " << trufas << " trufas!" << endl << endl;
                    acuTrufas += trufas;

                }
                else if((dado1 == dado2) && (dado1 != 1 && dado2 !=1 && dado3 == 0)){
                    trufas = (dado1 + dado2) * 2;
                    cout << "-------BIEN HECHO-------" << endl;
                    cout << "-----Sacaste un Oink----" << endl << endl;
                    cout << "¡Sumaste " << trufas << " trufas!" << endl << endl;
                    acuTrufas += trufas;
                    bandOink = true;
                }
                else if((dado1 == dado2 && dado1 == dado3) && (dado1 != 1 && dado2 !=1 && dado3 != 1)){
                    trufas = (dado1 + dado2 + dado3) * 3;
                    cout << "-------BIEN HECHO-------" << endl;
                    cout << "-----Sacaste un Oink----" << endl << endl;
                    cout << "¡Sumaste " << trufas << " trufas!" << endl << endl;
                    acuTrufas += trufas;
                    bandOink = true;
                }

                else if((dado1 != dado2 && dado1 != dado2 && dado1 != dado3) && (dado1 == 1 || dado2 == 1 || dado3 == 1)){
                    cout << "******¡Vaya, no haz tenido suerte, sacaste un UNO!*****" << endl;
                    cout << endl << "Tu turno ha finalizado y tus trufas no serán acumuladas" << endl << endl << endl << endl;
                    acuTrufas = 0;
                    system("pause");
                    break;
                }
                else if(dado1 == dado2 && dado1 != dado3 && dado1 == 1 && dado3 == 0){
                    cout << "<<<<<<<<<<<<<<¡DOBLE UNO>>>>>>>>>>>>>!" << endl;
                    cout << "¡Parece que hoy no es tu día de suerte!" << endl;
                    cout << "      EL CERDO HA CAIDO EN BARRO       " << endl;
                    cout << "¡Perdiste todas las trufas acumuladas!" << endl;
                    cout << "   ¡serán aumuladas a tu oponente!" << endl << endl << endl << endl;
                    bandBarro = true;
                    bandDado3 = true;

                    system("pause");
                    break;
                }
                // dos dados con 1 y otro distinto || Un dado con 1 y dos distintos
                else if(((dado1 == dado2 && dado1 != dado3 && dado3 > 0) || (dado1 == dado3 && dado1 != dado2)) && (dado1 == 1 || dado2 == 1 || dado3 == 1)){
                    cout << endl << "******¡Vaya, no haz tenido suerte, sacaste un UNO!*****" << endl;
                    cout << "Tu turno ha finalizado y tus trufas no serán acumuladas" << endl << endl << endl << endl;
                    acuTrufas = 0;
                    system("pause");
                    break;
                }
                else if (dado1 == dado2 && dado1 == dado3 && dado1 == 1){
                    cout << "<<<<<<<<<<<<<<¡TRIPLE UNO>>>>>>>>>>>>>!" << endl;
                    cout << "¡Parece que hoy no es tu día de suerte!" << endl;
                    cout << "      EL CERDO HA CAIDO EN BARRO       " << endl;
                    cout << "¡Perdiste todas las trufas acumuladas!" << endl << endl << endl << endl;
                    bandBarro = true;
                    system("pause");
                    break;
                }
                //FIN REGLAS



                if(!bandOink){
                    do{
                    cout << "¿Desea continuar tirando? (S/N) " << endl;
                    cin >> continuar;
                    continuar = toupper(continuar);
                    }while(continuar != 'S' && continuar != 'N');

                }
                else{
                    if(i % 2 == 0)
                        contOink2++;
                    else
                        contOink1++;

                    system("pause");
                }


                if(i % 2 == 0){
                    if(!bandLanz2){
                        lanz2 = cantLanzamientos;
                        bandLanz2 = true;
                    }
                    else{
                        if(cantLanzamientos > lanz2){
                            lanz2 = cantLanzamientos;
                        }
                    }
                }
                else{
                    if(!bandLanz1){
                        lanz1 = cantLanzamientos;
                        bandLanz1 = true;
                    }
                    else{
                        if(cantLanzamientos > lanz1){
                            lanz1 = cantLanzamientos;
                        }
                    }
                }




                if(i % 2 == 0){
                    if(totalTrufas2 + acuTrufas > 50){
                        bandCincuenta2 = true;
                    }
                }
                else{
                    if(totalTrufas1 + acuTrufas > 50){
                        bandCincuenta1 = true;
                    }
                }

                if(bandCincuenta1 && bandCincuenta2){
                    bandDado3 = true;
                }

            }
            //FIN WHILE
        /*
                if(i % 2 == 0){
                    vecLanz2[x] = cantLanzamientos;
                }
                else{
                    vecLanz1[x] = cantLanzamientos;
                }
        */

        }
        //FIN 2do FOR
    }
    //FIN 1er FOR

    system("cls");
    cout << "EL GRAN CERDO" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "LOS PUNTAJES ACUMULADOS SON:" << endl;
    cout << player1 << ": " << totalTrufas1 <<  " trufas acumuladas" << "            ";
    totalTrufas2 += acuTrufas;
    cout << player2 << ": " << totalTrufas2 << " trufas acumuladas" << endl << endl;

    cout <<  endl;

    cout << "Pasemos a computar los puntos de victoría" << endl << endl;

    system("pause");

    system("cls");
    system("color 47");
    Beep(400, 100);
    system("color 57");
    Beep(600, 100);
    system("color 67");
    Beep(400, 100);
    system("color 87");
    Beep(600, 100);
    system("color 97");
    Beep(800, 300);
    system("color 07");

    // PUNTOS DE VICTORIA
    if(totalTrufas1 > totalTrufas2)
        cantidad1 = 5;
    else
        cantidad2 = 5;

    cont50_1 = totalTrufas1 / 50;
    cont50_2 = totalTrufas2 / 50;
    restoTrufas1 = totalTrufas1 - (totalTrufas1%50);
    restoTrufas2 = totalTrufas2 - (totalTrufas2%50);

    puntosOink1 = contOink1 * 2;
    puntosOink2 = contOink2 * 2;

    if(lanz1 > lanz2){
        puntosLanz1 = 3;
    }
    else{
        if(lanz1 < lanz2){
            puntosLanz2 = 3;
        }
        else{
            puntosLanz1 = 3;
            puntosLanz2 = 3;
        }
    }


    totalPuntos1 = cantidad1 + cont50_1 + puntosOink1 + puntosLanz1;
    totalPuntos2 = cantidad2 + cont50_2 + puntosOink2 + puntosLanz2;



    if(totalPuntos1 > totalPuntos2){
        ganador = player1;
        puntaje = totalPuntos1;
    }
    else{
        ganador = player2;
        puntaje = totalPuntos2;
    }
/*
    promedio = contadoLanz / 10;

    for(k=0; k<5; k++){
        if(vecLanz2[k]>promedio){
            puntosPro2 = vecLanz2[k] - promedio;
            acuPro2 += puntosPro2;
        }
    }

    for(l=0; l<5; l++){
        if(vecLanz1[l]>promedio){
            puntosPro1 = vecLanz1[l] - promedio;
            acuPro1 += puntosPro1;
        }

    }
*/

    cout << "EL GRAN CERDO  " <<endl;
    cout << "------------------------------------------------------------------------------" << endl;

    cout << "HITO                        " << player1 << "                                        " << endl;
    cout << "                                                       " << player2 << endl;
    cout <<"------------------------------------------------------------------------------" << endl;
    cout << "Más trufas en total         " << cantidad1 <<" PDV (" << totalTrufas1 << " trufas)            " << cantidad2 << " PDV (" << totalTrufas2 << " trufas)" << endl;
    cout << "Cada 50 trufas              " << cont50_1 <<" PDV (" << restoTrufas1 << " trufas)            " << cont50_2 << " PDV (" << restoTrufas2 << " trufas)" << endl;
    cout << "Oinks                       " << puntosOink1 <<" PDV (" << contOink1 <<" Oinks)              "<< puntosOink2 << " PDV (" << contOink2 <<" Oinks)" << endl;
    cout << "Cerdo codicioso             " << puntosLanz1 << " PDV (" << lanz1 << " lanzamientos)       " << puntosLanz2 << " PDV (" << lanz2 << " lanzamientos)" << endl;
    //cout << "Lanzamiento x sobre el promedio  " << acuPro1 <<" PDV (" << acuPro1 << " lanzamientos)            " << acuPro2 << " PDV (" << acuPro2 << " lanzamientos)" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "TOTAL                   " << totalPuntos1 << " PDV                        " << totalPuntos2 << " PDV" << endl << endl;
    cout << "GANADOR: " << ganador <<" con " << puntaje << " puntos de victoria. "<< endl;

    Beep(900, 100);
    Beep(1000, 100);
    Beep(1100, 100);
    Beep(1200, 100);

    cin.ignore();

    do{
    cout << endl << endl << "Ingrese Oink para continuar: ";

    getline(cin, palabraFinal);
    mayuscula(palabraFinal);
    }while(palabraFinal != "OINK");





    Sleep(100);
}



///Va a devolverme el puntaje total. de ambos participantes
///TIRAR ========================================
int tirar()
{
    return (rand() % 6) + 1;
}


///DIBUJOS ======================================
int dibujos(int numero)
{

    switch(numero){
    case 1:
        //posición

        cout << "+-------+" << endl;
        cout << "|       |" << endl;
        cout << "|   x   |" << endl;
        cout << "|       |" << endl;
        cout << "+-------+" << endl;
        break;
    case 2:
        cout << "+-------+" << endl;
        cout << "| x     |" << endl;
        cout << "|       |" << endl;
        cout << "|     x |" << endl;
        cout << "+-------+" << endl;
        break;
    case 3:
        cout << "+-------+" << endl;
        cout << "| x     |" << endl;
        cout << "|   x   |" << endl;
        cout << "|     x |" << endl;
        cout << "+-------+" << endl;
        break;
    case 4:
        cout << "+-------+" << endl;
        cout << "| x   x |" << endl;
        cout << "|       |" << endl;
        cout << "| x   x |" << endl;
        cout << "+-------+" << endl;
        break;
    case 5:
        cout << "+-------+" << endl;
        cout << "| x   x |" << endl;
        cout << "|   x   |" << endl;
        cout << "| x   x |" << endl;
        cout << "+-------+" << endl;
        break;
    case 6:
        cout << "+-------+" << endl;
        cout << "| x   x |" << endl;
        cout << "| x   x |" << endl;
        cout << "| x   x |" << endl;
        cout << "+-------+" << endl;
        break;
    }

    return numero;
}


///ESTADÍSTICAS ====================================

void estadisticas(string vecGanador[], int, int vecPuntaje[], int)
{
    int x;
    bool bandPuntaje = true;


    system("cls");
    system("color 47");

    cout << "**********ESTADÍSTICAS**********" << endl;


    for(x=0; x<10; x++){

        if(vecPuntaje[x] > 0){
            cout << vecGanador[x] << "               " << vecPuntaje[x] <<" PUNTOS" << endl << endl;
            bandPuntaje = false;
        }


    }

    if(bandPuntaje)
        cout << endl << "<<<No hay puntajes cargados>>>" << endl;

    cout << endl << endl << endl;
    Sleep(700);
}


///CRÉDITOS =======================================
void creditos()
{
    system("cls");
    system("color 61");
    cout << "*******************CRÉDITOS*******************" << endl << endl << endl << endl;

    cout << "Pablo Andrés Magnavachi           Legajo 25988" << endl;
    cout << "Marcos Luciano Labat              Legajo 25970" << endl;
    cout << "Paula Andrea Torres               Legajo 26330" << endl;
    cout << "Juan Facundo Tam                  Legajo 26812" << endl;

    cout << endl << endl << endl;

    Sleep(700);
}

///Reglas==========================================
void reglas()
{
    system("cls");
    system("color 07");
    cout << "*******************************REGLAS DEL JUEGO*******************************" << endl << endl << endl << endl;

    cout << "Gran Cerdo es un juego de dados de dos jugadores en el que intervienen el" << endl;
    cout << "azar y la codicia. El objetivo general del juego es sumar la mayor cantidad" << endl;
    cout << "de puntos de victoria en un total de 5 rondas. La suma de puntaje depende de" << endl;
    cout << "diferentes situaciones que se pueden dar en el juego y que más adelante se" << endl;
    cout << "explicarán." << endl << endl;

    cout << "Se juega con dos o tres dados de seis caras por cada jugador. Antes de" << endl;
    cout << "comenzar, se debe determinar cuál de los dos jugadores empieza. Para ello" << endl;
    cout << "se lanzan dos dados y el jugador que haya obtenido el mayor puntaje" << endl;
    cout << "comienza. Si empatan en el puntaje, comienza el jugador que haya obtenido" << endl;
    cout << "el dado más alto. Si empatan nuevamente vuelven a lanzar ambos dados" << endl;
    cout << "otra vez." << endl << endl;

    cout << "El juego está compuesto por cinco rondas por jugador y en cada ronda el" << endl;
    cout << "jugador dispone de ilimitados lanzamientos.En cada lanzamiento el jugador" << endl;
    cout << "tira los dados y se analiza los valores de las caras:" << endl << endl;

    cout << "* Si las caras son distintas entre sí y ninguna de ellas es un as. Entonces" << endl;
    cout << "  el cerdo acumula trufas según la suma de las caras al total de la ronda." << endl;
    cout << "  Por ejemplo: 5 y 3, acumula 8 trufas. Luego, puede decidir si volver a" << endl;
    cout << "  lanzar los dados o plantarse y ceder el turno al otro cerdo." << endl << endl;

    cout << "* Si las caras son iguales entre sí y no son ases. Entonces el cerdo hizo un" << endl;
    cout << "  Oink y acumula trufas por el doble de la suma de las caras al total de la" << endl;
    cout << "  ronda. Por ejemplo: 4 y 4, acumula 16 trufas. También, está obligado a" << endl;
    cout << "  lanzar los dados una vez más." << endl << endl;

    cout << "* Si las caras son distintas entre sí y hay un as entre ellas. Pierde todas" << endl;
    cout << "  las trufas que venía acumulando en la ronda actual y automáticamente" << endl;
    cout << "  le cede el turno al otro cerdo." << endl << endl;

    cout << "* Si dos de las caras son iguales entre sí y son ases. El cerdo se hunde en" << endl;
    cout << "  el barro y pierde todas las trufas que venía acumulando en las rondas" << endl;
    cout << "  anteriores y automáticamente le cede el turno al otro cerdo." << endl << endl;

    cout << "* Si se está lanzando con tres dados y tres de las caras son iguales entre sí" << endl;
    cout << "  y son ases. Aplica la misma quita de puntos que en el caso anterior pero" << endl;
    cout << "  dichos puntos se acumulan al otro cerdo en dicha ronda." << endl << endl;


    cout << "* El juego utiliza dos dados hasta que ambos cerdos superen (cada uno) las 50" << endl;
    cout << "  trufas o alguno de ellos se hunda en el barro. A partir de allí, el juego se" << endl;
    cout << "  desarrolla contres dados por lanzamiento (esto puede ocurrir incluso en el" << endl;
    cout << "  transcurso de una ronda)." << endl << endl;

    cout << "* Cuando finalizan las rondas, se determina el puntaje final a partir de los" << endl;
    cout << "  siguientes hitos en el juego." << endl << endl;

    cout << "Hito - Puntos de victoria" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "- Más trufas en total 5 PDV" << endl;
    cout << "- Cada 50 trufas 1 PDV" << endl;
    cout << "- Oink 2 PDV * Cantidad de Oinks" << endl;
    cout << "- Cerdo codicioso (ronda con mayor cantidad de lanzamientos) 3 PDV" << endl;


    cout << endl << endl << endl;

    system("pause");
}
///MAYUSCALAS =====================================
void mayuscula (string &texto){
 for(int i=0; i<texto.length(); i++){
  texto[i]= towupper(texto[i]);
 }
}

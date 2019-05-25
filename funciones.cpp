//
// Created by Cesar Paolo on 25/05/2019.
//
#include "funciones.h"
#include <iomanip>

void imprimir(tipo arr[][9]){
    cout << endl;
    for (int j = 0; j < 9; j++)
        cout << setw(4) << j + 1;
    cout << endl;

    for(int fila = 0; fila < 9 ; fila++) {
        int a = fila +1;
        cout << a <<setw(3);
        for (int columna = 0; columna < 9; columna++) {
            if(fila == 3 || fila == 4 || fila == 5) {
                if (columna > 0 && columna < 7)
                    cout << arr[fila][columna] << " - ";
                else
                    cout << arr[fila][columna] << "   ";
            }
            else
                if(fila > 0 && fila <8) {
                    if (columna > 2 && columna < 5)
                        cout << arr[fila][columna] << " - ";
                    else
                        cout << arr[fila][columna] << "   ";
                }
                else
                    cout << arr[fila][columna] << "   ";
        }
        cout << endl << endl;
    }
}
void menu_del_juego(){
    int a;
    tipo arr[9][9] = {};
    cout << "MENU - Juego Senku" << "\n" << "*******************" << endl;
    cout << "(1) ingles" << endl << "(2) frances" << endl << "(3) aleman" << endl;
    cout << "*******************" << endl;
    do {
        cout << "Elegir modo:";
        cin >> a;
    }while (a < 1 && a > 3);
    arr[9][9] = tableros(arr,a);
    imprimir(arr);

}

tipo tableros(tipo tab[][9],int opcion){
    tipo ingles [9][9] =   {{'x','x','x','x','x','x','x','x','x'},
                            {'x','x','x','O','O','O','x','x','x'},
                            {'x','x','x','O','O','O','x','x','x'},
                            {'x','O','O','O','O','O','O','O','x'},
                            {'x','O','O','O','+','O','O','O','x'},
                            {'x','O','O','O','O','O','O','O','x'},
                            {'x','x','x','O','O','O','x','x','x'},
                            {'x','x','x','O','O','O','x','x','x'},
                            {'x','x','x','x','x','x','x','x','x'}};

    tipo frances [9][9] = {{'x','x','x','x','x','x','x','x','x'},
                           {'x','x','x','x','x','x','x','x','x'},
                           {'x','x','x','x','x','x','x','x','x'},
                           {'x','x','x','x','x','x','x','x','x'},
                           {'x','x','x','x','x','x','x','x','x'},
                           {'x','x','x','x','x','x','x','x','x'},
                           {'x','x','x','x','x','x','x','x','x'},
                           {'x','x','x','x','x','x','x','x','x'},
                           {'x','x','x','x','x','x','x','x','x'},};

    for(int fila = 0; fila < 9 ; fila++){
        for(int columna = 0; columna < 9 ; columna++){
            if(opcion == 1)
                tab[fila][columna] = ingles[fila][columna];
            else{
                if(opcion == 2)
                    tab[fila][columna] = frances[fila][columna];
            }
        }
    }
    return tab[9][9];
}
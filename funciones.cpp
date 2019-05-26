//
// Created by Cesar Paolo on 25/05/2019.
//
#include "funciones.h"
#include <iomanip>

void imprimir(tipo arr2[][9]){
    cout << endl;
    for (int j = 0; j < 9; j++)
        cout << setw(4) << j + 1;
    cout << endl;

    for(int fila = 0; fila < 9 ; fila++) {
        int a = fila +1;
        cout << a <<setw(3);
        for (int columna = 0; columna < 9; columna++) {
            if(arr2[fila][columna]== 'O' || arr2[fila][columna]== '+') {
                if (arr2[fila][columna+1] == 'x')
                    cout << arr2[fila][columna] << "   ";
                else
                    cout << arr2[fila][columna] << " - ";
            }
            else
                cout << arr2[fila][columna] << "   ";
        }
        cout << endl;
        for(int i = 0; i<9 ;i++){
            if(arr2[fila][i] == 'O' || arr2[fila][i] == '+') {
                if (arr2[fila + 1][i] == 'x')
                    cout << setw(4) << ' ';
                else
                    cout << setw(4) << '|';
            }
            else
                cout << setw(4) << " ";
        }
        cout << endl;
    }
}

void menu_del_juego(tipo arr[][9]){
    int a;
    cout << "MENU - Juego Senku" << "\n" << "*******************" << endl;
    cout << "(1) ingles" << endl << "(2) frances" << endl << "(3) aleman" << endl;
    cout << "*******************" << endl;
    do {
        cout << "Elegir modo:";
        cin >> a;
    }while (a < 1 || a > 3);
    tableros(arr,a);
    imprimir(arr);
}

void tableros(tipo arr1[][9],int opcion){
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
}

void pedir(tipo arr5[][9]){
    int f1 , c1 , f2 , c2;
    do{
        cout << "ingresar la posicion de origen (fila , columna): ";
        cin >> f1 >> c1;
        cout << endl;
        cout << "ingresar la posicion de destino (fila , columna): ";
        cin >> f2 >> c2;
    }while (f1 > 9 || f1 < 1 || f2 > 9 || f2 < 1 || c1 > 9 || c1 < 1 || c2 > 9 || c2 < 1);
    f1 = f1 - 1;
    f2 = f2 - 1;
    c1 = c1 - 1;
    c2 = c2 - 1;
    verificar(arr5,f1,c1,f2,c2);
}

void verificar(tipo arr6[][9],int f1 ,int c1, int f2 , int c2) {
    int distanciaf = f2 -f1;
    int distanciac = c2 - c1;
    if(distanciac == 0 && distanciaf == 0)
        cout << "Movimiento erroneo.";
    else {
        if(distanciac == 1 ||  distanciaf == 1 || distanciac == -1 || distanciaf == -1)
            cout << "Movimiento erroneo.";
        else {
            if (distanciac > 2 || distanciac < -2 || distanciaf < -2 || distanciaf > 2)
                cout << "Movimiento erroneo.";
            else {
                if ( (distanciac == 2 || distanciac == -2) && (distanciaf == 2 || distanciaf == -2))
                    cout << "Movimiento erroneo.";
                else {
                    if (arr6[f1][c1] != 'O' || arr6[f2][c2] != '+')
                        cout << "Movimiento erroneo.";
                    else
                        cambio(arr6,f1,c1,f2,c2);
                }
            }
        }
    }
}

void cambio(tipo arr3[][9],int fil1,int col1 ,int fil2 ,int col2){
    int comodin;
    comodin = arr3[fil2][col2];
    arr3[fil2][col2] = arr3[fil1][col1];
    arr3[fil1][col1] = comodin;
    int a;
    int b;
    if(fil1 < fil2)
        a = fil2 -1;
    else {
        if (fil1 == fil2)
            a = fil2 + 0;
        else
            a = fil2 + 1;
    }
    if(col1 < col2)
        b = col2 -1;
    else {
        if (col1 == col2)
            b = col2 + 0;
        else
            b = col2 + 1;
    }
    arr3[a][b]= comodin;
    imprimir(arr3);
}

bool fin_del_juego(tipo arr4[][9]){
    int f=0;
    for(int i = 0; i < 9;i++){
        for(int j = 0; j < 9; j++){
            if(arr4[i][j] == 'O') {
                if ((arr4[i+2][j]=='+'&&arr4[i+1][j]=='O')||(arr4[i-2][j] =='+'&&arr4[i-1][j]=='O') ||(arr4[i][j+2]=='+'&&arr4[i][j+1]=='O') || (arr4[i][j-2]=='+'&&arr4[i][j-1]=='O'))
                    f = f+1;
                else
                    f = f + 0;
            }
        }
    }
    if(f > 0)
        return false;
    else
        return true;
}

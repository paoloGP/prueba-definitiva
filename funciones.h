//
// Created by Cesar Paolo on 25/05/2019.
//

#ifndef UNTITLED_FUNCIONES_H
#define UNTITLED_FUNCIONES_H

#include <iostream>
using namespace std;
typedef char tipo;

void menu_del_juego(tipo arr[][9]);
void tableros(tipo arr1[][9],int opcion);
void imprimir(tipo arr2[][9]);
void pedir(tipo arr5[][9]);
void cambio(tipo arr3[][9],int fil1,int col1 ,int fil2 ,int col2);
bool fin_del_juego(tipo arr4[][9]);
void verificar(tipo arr6[][9], int f1 ,int c1, int f2 , int c2);

#endif //UNTITLED_FUNCIONES_H

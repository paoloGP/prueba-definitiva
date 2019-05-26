#include <iostream>
#include <string>
#include "funciones.h"
using namespace std;

int main() {
    tipo tablero[9][9] = {};
    menu_del_juego(tablero);
    do{
        pedir(tablero);
        cout << endl;
    }while(!fin_del_juego(tablero));
    cout << "Fin del juego, !Lo lograste¡";
    return 0;
}

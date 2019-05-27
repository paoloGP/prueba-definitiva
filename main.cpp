#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    tipo tablero[9][9] = {};
    menu_del_juego(tablero);
    if(tablero[0][0] == 'x') {
        int salida =0;
        while(!fin_del_juego(tablero) && salida < 1)
            pedir(tablero , salida);

        if(salida < 1) {
            int i = 0;
            for (int a = 0; a < 9; a++) {
                for (int b = 0; b < 9; b++) {
                    if (tablero[a][b] == 'O')
                        i = i + 1;
                }
            }
            if (i > 1)
                cout << "FIN DEL JUEGO, te falto muy poco!!!";
            else
                cout << "Lo lograste !!!";
        }
        else
            cout << endl << "Gracias por jugar.";
    }
    else
        cout << endl << "Gracias por jugar.";
    return 0;
}

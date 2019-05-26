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
    int i =0;
    for(int a = 0; a<9;a++){
        for(int b = 0;b<9;b++){
            if(tablero[a][b] == 'O')
                i = i + 1;
        }
    }
    if(i > 1)
        cout << "FIN DEL JUEGO, te falto muy poco!!!";
    else
        cout << "Lo lograste !!!";
    return 0;
}

void menu_del_juego(tipo arr[][9]){
    int a;
    cout << "*************************************************************************" << endl;
    cout << "                            MENU - Juego Senku" << '\n' 
    cout << "*************************************************************************" << endl;
    cout << " Modos:"<<'\n',
    cout << "1.ingles" << endl << "2.aleman" << endl << "3.asimetrico" << endl;
    cout << "*************************************************************************" << endl;
    cout << "0.Salir del juego" << endl;
    cout << "-Si quiere salir durante el juego, ingresar una letra en fila o columna"<<'\n'<< " o ingresar 0 en las cuatro posiciones." << endl;
    cout << "*************************************************************************" << endl;

    do {
        cout << " Elegir modo:";
        cin >> a;
        if(!a)
            break;
    }while (a < 0 || a >= 4);
    if(a) {
        tableros(arr, a);
        imprimir(arr);
    }
}

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
                if ((arr2[fila][columna+1] == 'O' || arr2[fila][columna+1] == '+') && columna < 8)
                    cout << arr2[fila][columna] << " - ";
                else
                    cout << arr2[fila][columna] << "   ";
            }
            else
                cout << arr2[fila][columna] << "   ";
        }
        cout << endl;
        for(int i = 0; i<9 ;i++){
            if(arr2[fila][i] == 'O' || arr2[fila][i] == '+') {
                if (arr2[fila + 1][i] == 'O' || arr2[fila + 1][i] == '+')
                    cout << setw(4) << '|';
                else
                    cout << setw(4) << ' ';
            }
            else
                cout << setw(4) << " ";
        }
        cout << endl;
    }
}



void tableros(tipo arr1[][9],int opcion){
    tipo ingles [9][9] =   {{' ',' ',' ',' ',' ',' ',' ',' ',' '},
                            {' ',' ',' ','O','O','O',' ',' ',' '},
                            {' ',' ',' ','O','O','O',' ',' ',' '},
                            {' ','O','O','O','O','O','O','O',' '},
                            {' ','O','O','O','+','O','O','O',' '},
                            {' ','O','O','O','O','O','O','O',' '},
                            {' ',' ',' ','O','O','O',' ',' ',' '},
                            {' ',' ',' ','O','O','O',' ',' ',' '},
                            {' ',' ',' ',' ',' ',' ',' ',' ',' '}};

    tipo aleman [9][9] =  {{' ',' ',' ','O','O','O',' ',' ',' '},
                           {' ',' ',' ','O','O','O',' ',' ',' '},
                           {' ',' ',' ','O','O','O',' ',' ',' '},
                           {'O','O','O','O','O','O','O','O','O'},
                           {'O','O','O','O','+','O','O','O','O'},
                           {'O','O','O','O','O','O','O','O','O'},
                           {' ',' ',' ','O','O','O',' ',' ',' '},
                           {' ',' ',' ','O','O','O',' ',' ',' '},
                           {' ',' ',' ','O','O','O',' ',' ',' '}};

    tipo asimetrico [9][9] ={{' ',' ',' ','O','O','O',' ',' ',' '},
                             {' ',' ',' ','O','O','O',' ',' ',' '},
                             {' ',' ',' ','O','O','O',' ',' ',' '},
                             {' ','O','O','O','O','O','O','O','O'},
                             {' ','O','O','O','+','O','O','O','O'},
                             {' ','O','O','O','O','O','O','O','O'},
                             {' ',' ',' ','O','O','O',' ',' ',' '},
                             {' ',' ',' ','O','O','O',' ',' ',' '},
                             {' ',' ',' ',' ',' ',' ',' ',' ',' '}};

    tipo easy [9][9] =  {{' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ','+','O','+','O','O',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' '},
                         {' ',' ',' ',' ',' ',' ',' ',' ',' '}};

    for(int fila = 0; fila < 9 ; fila++){
        for(int columna = 0; columna < 9 ; columna++){
            if(opcion == 1)
                arr1[fila][columna] = ingles[fila][columna];
            else{
                if(opcion == 2)
                    arr1[fila][columna] = aleman[fila][columna];
                else if(opcion == 3)
                    arr1[fila][columna] = asimetrico[fila][columna];
                else if(opcion == 4)
                    arr1[fila][columna] = easy[fila][columna];
            }
        }
    }
}

void pedir(tipo arr5[][9], int &sa){
    int f1 , c1 , f2 , c2;
    cout << "ingresar la posicion de origen (fila , columna):";
    cin >> f1 >> c1;
    cout << "ingresar la posicion de destino (fila , columna):";
    cin >> f2 >> c2;
    if(!f1 || !c1 || !f2 || !c2 || (f1 == 0 && f2 == 0 && c1 == 0 && c2 == 0))
        sa = sa + 1;
    else {
        f1 = f1 - 1;
        f2 = f2 - 1;
        c1 = c1 - 1;
        c2 = c2 - 1;
        verificar(arr5, f1, c1, f2, c2);
    }
}

void verificar(tipo arr6[][9],int fi1 ,int co1, int fi2 , int co2) {
    int distanciaf = fi2 - fi1;
    int distanciac = co2 - co1;
    if (distanciac == 0 && distanciaf == 0)
        cout << "Movimiento erroneo." << endl;
    else {
        if (distanciac == 1 || distanciaf == 1 || distanciac == -1 || distanciaf == -1)
            cout << "Movimiento erroneo."<< endl;
        else {
            if (distanciac > 2 || distanciac < -2 || distanciaf < -2 || distanciaf > 2)
                cout << "Movimiento erroneo."<< endl;
            else {
                if ((distanciac == 2 || distanciac == -2) && (distanciaf == 2 || distanciaf == -2))
                    cout << "Movimiento erroneo."<< endl;
                else {
                    if (arr6[fi1][co1] != 'O' || arr6[fi2][co2] != '+')
                        cout << "Movimiento erroneo."<< endl;
                    else
                        cambio(arr6, fi1, co1, fi2, co2);
                }
            }
        }
    }
}

void cambio(tipo arr3[][9],int fil1,int col1 ,int fil2 ,int col2){
    tipo comodin;
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

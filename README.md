# Requisitos:
- Tener un copilador de lenguaje C++ (CLion).
- Cree un archivo funciones.h y un archivo funciones.cpp en su copilador
- Copie el codigo que se encuentra en este proyecto en cada archivo correspondiente (funciones.h, funciones.cpp, main.cpp)
- Asegúrese de que los tres archivos se encuentren en el ejecutable del programa (add_executable(Senku main.cpp funciones.cpp funciones.h))
- Ejecute el juego.

# Instrucciones de uso:
1. Seleccionar tablero
2. Ingresar la posición(Fila , columna) de la ficha que quiere mover.
3. Ingresar la posición(Fila , columna) de destino.
4. Repetir paso 2 y 3 hasta culminar el juego. 
# Reglas de juego:
mover los espacios ocupados hacia los espacios
vacíos, pero para moverlo es requisito obligatorio saltar sobre solo un espacio que este ocupado,
de otro modo el espacio ocupado no podrá moverse. Se gana el juego si al final se queda con
solo un espacio ocupado y se pierde si no se puede realizar más movimientos y se tiene más de
un espacio ocupado, los movimientos solo son verticales u horizontales, pero no diagonales.
# Integrantes:
- García Pérez César Paolo
- Luis Joaquín
- Salomón

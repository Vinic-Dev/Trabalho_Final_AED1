#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "menus.h"
#include "fila.h"
#include "gerador_dados.h"
#include <windows.h>


int main() {
    SetConsoleOutputCP(65001); // para corrigir os acentos no Windows
    SetConsoleCP(65001); // para corrigir os acentos no Windows
    srand(time(NULL));
    Fila fila;
    inicializarFila(&fila);
    Fila2 filaMudados;
    inicializarFila2(&filaMudados);

    int opcao;

    menu_principal();
    return 0;
}
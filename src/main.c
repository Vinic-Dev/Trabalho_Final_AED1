#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "menus.h"
#include "morador.h"
#include "dados.h"


int main() {   
    srand(time(NULL));
    Fila fila;
    inicializarFila(&fila);
    Fila2 filaMudados;
    inicializarFila2(&filaMudados);

    int opcao;

    menu_principal();
    return 0;
}
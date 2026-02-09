#include <stdio.h>
#include "menus.h"
#include "fila.h"

int main() 
{   
    Fila fila;
    inicializarFila(&fila);
    Fila2 filaMudados;
    inicializarFila2(&filaMudados);

    int opcao;
    menu_principal();
    return 0;
}
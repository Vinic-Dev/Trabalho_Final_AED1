#ifndef FILA_H
#define FILA_H
#define MAX 25 //nao necessariamente precisa ser 25, verificar isso depois
#include "morador.h"

typedef struct {

    Morador morador[MAX];
    int inicio;
    int fim;
    int qntd;

} Fila;

//funçoes essenciais de fila

void inicializarFila( Fila *fila);
int filaVazia( Fila *fila); // verificar nos casos de desenfileirar
int filaCheia(Fila *fila); //para desenfileirar
int enfileirar(Fila *fila, Morador morador); //no caso de colocar os moradores em fila, int para retornar 0 ou 1
int desenfileirar(Fila *fila, Morador *morador); //morador por parametroooo
void mostrarFila(Fila *fila); //apenas exibir a fila de moradores

//funçao para verificar a casa dos moradores


#endif

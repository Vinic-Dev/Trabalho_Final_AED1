#ifndef LISTA_DE_CASAS_H
#define LISTA_DE_CASAS_H
#include "tipos_de_dados.h"

typedef struct {
    Casa casa;
    No *proxima;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void mostrar_mapa(Lista *lista);





#endif
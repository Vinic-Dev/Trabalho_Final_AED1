#ifndef LISTA_DE_CASAS_H
#define LISTA_DE_CASAS_H
#include "tipos_de_dados.h"

typedef struct No {
    Casa casa;
    struct No *proxima;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void add_casa(Lista **No);

void mostrar_mapa();





#endif
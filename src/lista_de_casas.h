#ifndef LISTA_DE_CASAS_H
#define LISTA_DE_CASAS_H
#include "fila.h"

typedef struct No {
    Casa casa;
    struct No *proxima;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void inicializar_lista_casas(Lista *lista, Fila2 *fila_mudados);
void atualizar_situacao_casas(Lista *lista, Fila2 *filaMudados);


#endif
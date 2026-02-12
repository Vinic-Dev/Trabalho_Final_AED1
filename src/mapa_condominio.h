#ifndef MAPA_CONDOMINIO_H
#define MAPA_CONDOMINIO_H
#include "lista_de_casas.h"

void exibir_mapa_condominio(Lista *lista);

int atrib(int* M, int i, int b, int c, int f, int v);
int consul(int* M, int i, int b, int c, int f);

#endif
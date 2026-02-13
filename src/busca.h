#ifndef BUSCA_H
#define BUSCA_H

#include "busca.h"
#include "ordenacao.h"
#include "fila.h"


void procurarporIdade(Fila2 fila);
void procurarporNome(Fila2 fila);
int buscaBinaria(Morador m[], int n, char bloco, int apartamento);
void procurarPorBlocoEApartamento(Fila2 fila);


#endif
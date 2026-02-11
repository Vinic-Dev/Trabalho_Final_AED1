#ifndef BUSCA_H
#define BUSCA_H

#include "busca.h"
#include "ordenacao.h"
#include "morador.h"
#include "dados.h"

void procurarporIdade(Fila fila);
void procurarporNome(Fila fila);
int buscaBinaria(Morador m[], int n, char bloco, int apartamento);
void procurarPorBlocoEApartamento(Fila fila);


#endif

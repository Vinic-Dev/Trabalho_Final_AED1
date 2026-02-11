#ifndef DADOS_H
#define DADOS_H
#include "tipos_de_dados.h"

// recebe um tipo Interessado e o gera
void gerar_interessado(Interessado *interessado, int id);

//recebe uma string e gera um nome
void gerar_nome(char *nome);

//retorna um double de renda
double gerar_renda();

// retorna uma idade entre 18 e 99 anos
int gerar_idade();

#endif

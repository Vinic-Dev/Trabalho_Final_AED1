#ifndef DADOS_H
#define DADOS_H
#include "tipos_de_dados.h"

// Dados do morador
void gerar_interessado(Interessado *interessado, int id);

void listar_interessados(Interessado *interessados, int quantidade);

//recebe uma string e gera um nome
void gerar_nome(char *nome);

//retorna um double de renda
double gerar_renda();

// retorna uma idade entre 18 e 99 anos
int gerar_idade();

#endif

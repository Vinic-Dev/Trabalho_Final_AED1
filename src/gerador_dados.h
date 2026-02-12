#ifndef DADOS_H
#define DADOS_H
#include "tipos_de_dados.h"

// recebe um tipo Interessado e o gera
void gerar_interessado(Interessado *interessado, int id);

//recebe uma string e gera um nome
void gerar_nome(char *nome);

//retorna um double de renda
double gerar_renda();

// retorna uma idade entre 18 e 70 anos
int gerar_idade();

// recebe um tipo Morador e o gera
void gerar_morador(Morador *morador);

// recebe um tipo Casa e a gera aleatoriamente
void gerar_casa_aleatoria(Casa *casa);


#endif

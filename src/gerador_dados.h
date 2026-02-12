#ifndef DADOS_H
#define DADOS_H
#include "tipos_de_dados.h"
#include "lista_de_casas.h"
#include "fila.h"

// gera dados aleatorios para preencher a lista de casas e fila de mudados
void simular_ocupacao(Fila2 *filaMudados, Lista *lista, int quantidade);

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

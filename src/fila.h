#ifndef FILA_H
#define FILA_H
#define MAX 36
#include "tipos_de_dados.h"

typedef struct Node{
    Morador morador;
    struct Node *prox;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
    int qntd;
} Fila;

typedef struct {
    Node *inicio;
    Node *fim;
    int qntd;
} Fila2; //moradores que ja se mudaram

//Funções voltadas ao morador

Morador cadMorador(Fila *fila, Fila2 *filaMudados); //verificar o que precisa ser passado
void printMorador(Morador morador); //para mostrar a fila

//funçoes essenciais de fila

void inicializarFila( Fila *fila);
int enfileirar(Fila *fila, Morador morador); //no caso de colocar os moradores em fila, int para retornar 0 ou 1
int desenfileirar(Fila *fila, Morador *morador); //morador por parametroooo
void exibirFila(Fila *fila); //apenas exibir a fila de moradores

//funçao para verificar a casa dos moradores
int verificarCasa(Fila *fila, Fila2 *filaMudados, char bloco, int casa);

void exibirMoradoresMudados(Fila2 *filaMudados); //função para exibir os moradores que já se mudaram
int inserirMoradorMudado(Fila2 *filaMudados, Morador morador); //inserir moradores na fila de moradores mudados
void inicializarFila2( Fila2 *filaMudados); //inicializar a fila de moradores mudados
#endif

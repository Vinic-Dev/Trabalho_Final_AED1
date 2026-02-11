#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_de_casas.h"

void inicializar_lista_casas(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    char blocos[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J','K','L'};
    int num_casas = 6;

    for (int b = 0; b < 12; b++) {
        for (int n = 1; n <= num_casas; n++) {
            No *novo = (No*)malloc(sizeof(No));
            novo->casa.bloco = blocos[b];
            novo->casa.numero = n;
            novo->casa.esta_ocupada = false;
            novo->proxima = NULL;

            if (lista->inicio == NULL) {
                lista->inicio = novo;
                lista->fim = novo;
            } else {
                lista->fim->proxima = novo;
                lista->fim = novo;
            }
            lista->tamanho++;
        }
    }
}

bool verificar_ocupacao(Lista *lista, Fila2 *filaMudados, char bloco, int numero) {
    
    No *atual = lista->inicio;
    bool ocupada = false;
    while (atual != NULL) {
        if (atual->casa.bloco == bloco && atual->casa.numero == numero) {
            if (atual->casa.esta_ocupada) {
                ocupada = true;
            }
            break;
        }
        atual = atual->proxima;
    }

    if (ocupada) return true;

    Node *atualMorador = filaMudados->inicio;
    while (atualMorador != NULL) {
        if (atualMorador->morador.casa.bloco == bloco &&
            atualMorador->morador.casa.numero == numero) {
            return true;
        }
        atualMorador = atualMorador->prox;
    }
    return false;
}



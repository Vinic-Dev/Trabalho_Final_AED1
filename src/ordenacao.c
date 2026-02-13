#include <stdio.h>
#include <string.h>
#include "busca.h"
#include "ordenacao.h"
#include "fila.h"


int filaParaVetor(Fila2 fila, Morador vetor[]) {
    Node *aux = fila.inicio;
    int i = 0;
    //copia os moradores pra um vetor
    while (aux != NULL) {
        vetor[i] = aux->morador;
        aux = aux->prox;
        i++;
    }
    //retorna a quantidade moradores
    return i;
}
//organizar o vetor de morador em ordem bloco-apartamento
void insertionSort(Morador mor[], int n) {
    for (int i = 1; i < n; i++) {
        Morador atual = mor[i];
        int j = i - 1;

        while (j >= 0) {
            if(mor[j].casa.bloco > atual.casa.bloco) {
                mor[j + 1] = mor[j];
            } 
            else if(mor[j].casa.bloco == atual.casa.bloco && mor[j].casa.numero > atual.casa.numero) {
                mor[j + 1] = mor[j];
            } 
            else break;
            
            j--;
        }
        mor[j + 1] = atual;
    }
}
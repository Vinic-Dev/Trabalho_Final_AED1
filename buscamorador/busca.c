#include <stdio.h>
#include <string.h>
#include "busca.h"
#include "ordenacao.h"
#include "morador.h"
#include "dados.h"


void procurarporIdade(Fila fila){//fazer um int pra retornar sucesso ou n sucesso?
    int idade; 
    Node *aux = fila.inicio;
    printf("Digite a idade procurada:\n");
    scanf("%d", &idade);
    int existe = 0;
    printf("\tLista de moradores com a idade digitada: \n");
    //while que vai passando procurando pela fila ate chegar em null

    while(aux != NULL){
        if(aux->morador.idade == idade){
            printf("%s\n", aux->morador.nome);
            existe = 1;//flag que verifica se existem moradores dessa idade
        }
        aux = aux->prox;
    }
    if(!existe){
        printf("Não existem moradores com essa idade\n");
    }
}

void procurarporNome(Fila fila){//mudar pra int
    char name[50];
    Node *aux = fila.inicio;
    printf("Digite o nome que deseja procurar:\n");
    scanf(" %[^\n]*c", name);
    int existe = 0;
    while(aux != NULL){
        if(strcmp(aux->morador.nome, name) == 0){//
            existe = 1;
            printf("\tInformações sobre o morador:\n");
            printf("\tNome: ");
            printf("%s\n", aux->morador.nome);
            printf("\tBloco %c e apartamento %d\n", aux->morador.bloco, aux->morador.casa);
            printf("\tIdade: %d\n", aux->morador.idade);
        }
        aux = aux->prox;
    }
        if(!existe){
            printf("Morador inexistente\n");
        }
}
//no menu, fazer um printf pra escolher aa opção 
int buscaBinaria(Morador m[], int n, char bloco, int apartamento) {
    int inicio = 0, fim = n-1;

    while (inicio <= fim) {
        int meio = (inicio + fim)/2;

        if (m[meio].bloco == bloco && m[meio].casa == apartamento){
            return meio; //achou
        }
        if(m[meio].bloco < bloco || (m[meio].bloco == bloco && m[meio].casa < apartamento)){
            inicio = meio + 1;
        } 
        else fim = meio - 1;
    }
    return -1;
}

void procurarPorBlocoEApartamento(Fila fila) {
    Morador vetor[100];

    int n = filaParaVetor(fila, vetor);
    insertionSort(vetor, n);
    char bloco;
    int apt;

    printf("Digite o bloco: ");
    scanf(" %c", &bloco);
    printf("Digite o apartamento: ");
    scanf("%d", &apt);

    int pos = buscaBinaria(vetor, n, bloco, apt);

    if (pos != -1) {
        printf("\n\tMorador encontrado:\n");
        printf("\tNome: %s\n", vetor[pos].nome);
        printf("\tIdade: %d\n", vetor[pos].idade);
        printf("\tBloco %c - Apartamento %d\n",
               vetor[pos].bloco, vetor[pos].casa);
    } else {
        printf("\n\tMorador nao encontrado.\n");
    }
}


    /////////////////////////////////////////////////////////////////////
    //procurar o bloco e apartamento

    //while(aux =! NULL){
        
    //}
    //return 0;
//}




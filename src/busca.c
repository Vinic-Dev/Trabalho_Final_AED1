#include <stdio.h>
#include <string.h>
#include "busca.h"
#include "ordenacao.h"
#include "tipos_de_dados.h"


void procurarporIdade(Fila2 fila){
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
        printf("Nao existem moradores com essa idade\n");
    }
}

void procurarporNome(Fila2 fila){
    char name[50];
    Node *aux = fila.inicio;
    printf("Digite o nome que deseja procurar:\n");
    scanf(" %[^\n]*c", name);
    int existe = 0;
    while(aux != NULL){
        if(strcmp(aux->morador.nome, name) == 0){//verificando se os nomes sao os mesmos
            existe = 1;
            printf("\tInformações sobre o morador:\n");
            printf("\tNome: ");
            printf("%s\n", aux->morador.nome);
            printf("\tBloco %c e numero %d\n", aux->morador.casa.bloco, aux->morador.casa.numero);
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

        if (m[meio].casa.bloco == bloco && m[meio].casa.numero == apartamento){
            return meio; //achou
        }
        if(m[meio].casa.bloco < bloco || (m[meio].casa.bloco == bloco && m[meio].casa.numero < apartamento)){
            inicio = meio + 1;
        } 
        else fim = meio - 1;
    }
    return -1;
}

void procurarPorBlocoEApartamento(Fila2 fila) {
    Morador vetor[100];

    int n = filaParaVetor(fila, vetor);
    insertionSort(vetor, n);
    char bloco;
    int apt;

    printf("Digite o bloco: ");
    scanf(" %c", &bloco);
    printf("Digite o numero: ");
    scanf("%d", &apt);

    int pos = buscaBinaria(vetor, n, bloco, apt);

    if (pos != -1) {
        printf("\n\tMorador encontrado:\n");
        printf("\tNome: %s\n", vetor[pos].nome);
        printf("\tIdade: %d\n", vetor[pos].idade);
        printf("\tBloco %c - Apartamento %d\n",
               vetor[pos].casa.bloco, vetor[pos].casa.numero);
    } else {
        printf("\n\tMorador nao encontrado.\n");
    }
}

#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void menuMorador(){

    printf("\n----------MENU----------\n\n");
    printf("1-Cadastrar Morador\n");
    printf("2- Mostrar fila da mudanca\n");
    printf("3-Processar proxima mudanca\n");
    printf("4-Exibir moradores ja mudados\n");
    printf("0-Sair\n\n");
    printf("Qual opcao deseja escolher?\n");

}


void inicializarFila( Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qntd = 0;
}

void inicializarFila2( Fila2 *filaMudados){
    filaMudados->inicio = NULL;
    filaMudados->fim = NULL;
    filaMudados->qntd = 0;
}

Morador cadMorador(Fila *fila) {

   Morador morador;
   printf("Digite o nome do morador: ");
   scanf(" %[^\n]", morador.nome);
   printf("Digite a idade do morador: ");
   scanf("%d", &morador.idade);
   morador.status = 1; //1 pois ainda esta se mudando

   do{
            do {

                printf("Digite o bloco do morador: ");
                scanf(" %c", &morador.bloco);

                if (morador.bloco != 'A' && morador.bloco != 'B' &&
                morador.bloco != 'C' && morador.bloco != 'D' &&
                morador.bloco != 'E') {
                printf("Bloco inexistente. Tente novamente.\n");
                }

            }while ( morador.bloco != 'A' && morador.bloco != 'B' &&
            morador.bloco != 'C' && morador.bloco != 'D' &&
            morador.bloco != 'E');

            do {

                printf("Digite o numero da casa: ");
                scanf("%d", &morador.casa);

                if (morador.casa > 5 || morador.casa < 1) {
                printf("Casa inexistente. Tente novamente.\n");
                }

                if ( verificarCasa(fila, morador.bloco, morador.casa) == 1) {
                printf("Casa ja ocupada nesse bloco! Tente novamente.\n");
                }
        
            } while (morador.casa >5 || morador.casa < 1);

    } while (verificarCasa(fila, morador.bloco, morador.casa) == 1 
    || morador.casa > 5 || morador.casa < 1);

   return morador;
}


int enfileirar(Fila *fila, Morador morador){

    Node *newMorador = malloc (sizeof (Node));

    if (newMorador == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 0; // Falha na alocação
    }
    
    newMorador->morador = morador; //recebe as infos do morador
    newMorador->prox = NULL; //novo nó aponta para NULL pq é o último elemento da fila

    //verificar caso seja o 1 morador a ser inserado
    if (fila->inicio == NULL) {
        fila->inicio = newMorador;
        fila->fim = newMorador;
    } else {
        fila->fim->prox = newMorador;
        fila->fim = newMorador;
        //como nao é, fim da fila recebe o novo morador e o antigo fim aponta para o novo morador formando o nó
    }
    
    fila->qntd++; //para contar a quantidade de moradores na fila
    return 1; //sucesso
}


//parecido com exibir a fila
int verificarCasa(Fila *fila, char bloco, int casa){

    Node *atual = fila->inicio;

    for ( int i = 0; i < (fila->qntd); i++){
        if (atual->morador.bloco == bloco &&
        atual->morador.casa == casa)
        return 1;// casa e bloco ja ocupados

        atual= atual->prox;
    }
    
    return 0;// caso nao esteja ocupado
   
}


void exibirFila(Fila *fila){

    Node *atual = fila->inicio;

    if (atual == NULL) {
        printf("Fila vazia!.\n");
        return;
    }

    printf("\nFila de Mudança:\n\n");
    while (atual != NULL) {
        printf("-------------------------\n");
        printf("Nome: %s\n", atual->morador.nome);
        printf("Idade: %d\n", atual->morador.idade);
        printf("Bloco: %c\n", atual->morador.bloco);
        printf("Casa: %d\n", atual->morador.casa);
        atual = atual->prox; //avançar para o próximo nó

    }
}

int desenfileirar(Fila *fila, Morador *moradorRemovido){

    if (fila->inicio == NULL) {
        printf("Fila vazia!.\n");
        return 0; 
    }

    Node *temp = fila->inicio; //passar inicio para um no auxiliar
    *moradorRemovido = temp->morador; //nó temporario recebe as infos do morador a ser removido
    moradorRemovido->status = 0; //status do morador removido passa a ser 0 por conta da mudança concluida

    fila->inicio = fila->inicio->prox; //inicio passar a ser o elemento anterior do atual inicio

    free(temp); //libera a memória do nó removido, o que era o antigo inicio
    fila->qntd--; //decrementa a quantidade de moradores na fila

    return 1; //caso tenha dado certo
}

void printMorador(Morador morador) { // função para printar um morador especifico

    printf("--------------------------\n");
    printf("Nome: %s\n", morador.nome);
    printf("Idade: %d\n", morador.idade);
    printf("Bloco: %c\n", morador.bloco);
    printf("Casa: %d\n", morador.casa);
    printf("--------------------------\n");

}

int inserirMoradorMudado(Fila2 *filaMudados, Morador morador){
    Node *newMorador = malloc (sizeof (Node));

    if (newMorador == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 0; // Falha na alocação
    }
    
    newMorador->morador = morador; //recebe as infos do morador
    newMorador->prox = NULL;

    //verificar caso seja o 1 morador a ser inserado
    if (filaMudados->inicio == NULL) {
        filaMudados->inicio = newMorador;
        filaMudados->fim = newMorador;
    } else {
        filaMudados->fim->prox = newMorador;
        filaMudados->fim = newMorador;
        //como nao é, fim da fila recebe o novo morador e o antigo fim aponta para o novo morador formando o no
    }
    
    filaMudados->qntd++; //para contar a quantidade de moradores na fila
    return 1; // Sucesso
}

void exibirMoradoresMudados(Fila2 *filaMudados) {

    Node *atual = filaMudados->inicio;

    if (atual == NULL) {
        printf("Nenhum morador mudou ainda.\n");
        return;
    }

    printf("\nMoradores já mudados:\n\n");
    while (atual != NULL) {

        printf("-------------------------\n");
        printf("Nome: %s\n", atual->morador.nome);
        printf("Idade: %d\n", atual->morador.idade);
        printf("Bloco: %c\n", atual->morador.bloco);
        printf("Casa: %d\n", atual->morador.casa);
        atual = atual->prox; //avançar para o próximo nó

    }
}
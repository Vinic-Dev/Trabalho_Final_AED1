#include "menus.h"
#include <stdio.h>
#include "busca.h"
#include "ordenacao.h"
#define true 1
#include "fila.h"
#include "gerador_dados.h"
#include "lista_de_casas.h"
#include "mapa_condominio.h"
#define INTERESSADOS 10

 
void menu_interessados(Lista *lista) {
    
    Interessado interessados[INTERESSADOS];

    for(int i = 0; i < INTERESSADOS; i++){
        gerar_interessado(&interessados[i], i+1, lista);
    }
    for(int i = 0; i< INTERESSADOS; i++){
        printf("\nID: %d", interessados[i].id);
        printf("\nCasa de Interesse: Bloco:%c Número:%d", interessados[i].casa_interessada.bloco, interessados[i].casa_interessada.numero);
        printf("\nNome: %s", interessados[i].nome);
        printf("\nIdade: %d", interessados[i].idade);
        printf("\nRenda: R$%.2lf", interessados[i].renda);
        printf("\n");
    }
    printf("\n");
    char resposta;
    do {
        printf("\nDeseja sair do Menu de Interessados? s/n ");
        scanf(" %c", &resposta);
    } while(resposta != 's');
}

void pesquisar_informacoes(Fila *fila, Fila2 *filaMudados, Lista *listaCasas){

    int opcao;

    do {
        printf("\n--------- PESQUISAR MORADORES JA MUDADOS ---------\n");
        printf("1 - Buscar por idade\n");
        printf("2 - Buscar por nome\n");
        printf("3 - Buscar por bloco e apartamento\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                procurarporIdade(*filaMudados);
                break;

            case 2:
                procurarporNome(*filaMudados);
                break;

            case 3:
                procurarPorBlocoEApartamento(*filaMudados);
                break;

            case 0:
                return;

            default:
                printf("Opcao invalida!\n");
        }

    } while(1);
}


void mapa_do_comdominio(Lista *lista, Fila2 *filaMudados){
    atualizar_situacao_casas(lista, filaMudados);
    exibir_mapa_condominio(lista);
}

void menu_principal()
{
    Fila fila;
    inicializarFila(&fila);
    Fila2 filaMudados;
    inicializarFila2(&filaMudados);

    Lista listaCasas;
    inicializar_lista_casas(&listaCasas, &filaMudados);
    simular_ocupacao(&filaMudados, &listaCasas, 30);

    while (true) 
    {
        int op;

        printf("-----------------------------------------------\n");
        printf("|            GESTÃO DE CONDOMÍNIO             |\n");
        printf("-----------------------------------------------\n");
        printf("| 1. Interessados em Comprar                  |\n");
        printf("| 2. Cadastro de Moradores                    |\n");
        printf("| 3. Mudanças                                 |\n");
        printf("| 4. Mapa do Condomínio                       |\n");
        printf("| 5. Pesquisar Informações                    |\n");
        printf("| 0. Sair                                     |\n");
        printf("-----------------------------------------------\n");
        printf("Digite uma opcão: ");
        
        scanf("%d", &op);
        if (op == 0) break;
        if (op == 1) menu_interessados(&listaCasas);
        if (op == 2) cadastro_de_moradores(&fila, &filaMudados);
        if (op == 3) mudancas(&fila, &filaMudados);
        if (op == 4) mapa_do_comdominio(&listaCasas, &filaMudados);
        if (op == 5) pesquisar_informacoes(&fila, &filaMudados, &listaCasas);

        
    }
}


void menuMorador(){

    printf("\n----------MENU----------\n\n");
    printf("1- Mostrar fila da mudanca\n");
    printf("2-Processar proxima mudanca\n");
    printf("3-Exibir moradores ja mudados\n");
    printf("0-Sair\n\n");
    printf("Qual opcao deseja escolher?\n");

}

void cadastro_de_moradores(Fila* fila, Fila2* filaMudados) {
    Morador morador = cadMorador(fila, filaMudados);
    enfileirar(fila, morador);
}

void mudancas(Fila* fila, Fila2* filaMudados){
    int opcao;
     do {
        menuMorador();
        scanf("%d", &opcao);

        switch(opcao){
            case 1:

                exibirFila(fila);
                break;

            case 2: {

                Morador moradorRemovido; //dentro da função, moradorrRemovido recebe por parametro o primeiro morador da fila
                if (desenfileirar(fila, &moradorRemovido) == 1) {

                    printf("Morador removido da fila:\n");
                    printMorador(moradorRemovido);
                    inserirMoradorMudado(filaMudados, moradorRemovido); //inserir o morador removido na fila de moradores mudados
                } else {
                    printf("Fila vazia! Não ha morador para remover.\n");
                }
                break;
                
            }
            case 3:

                printf("Moradores já mudados:\n");
                exibirMoradoresMudados(filaMudados);
                break;

            case 0:

                printf("Finalizando o programa\n");
                break;
        }
    } while ( opcao != 0);
}
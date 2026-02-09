#include "menu.h"
#include <stdio.h>
#define true 1
#include "morador.h"
#include "fila.h"

void interessados_em_comprar();
void cadastro_de_moradores();
void mudancas();
void pesquisar_informacoes();
void mapa_do_comdominio();
void menu_principal()
{
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
        if (op == 1) interessados_em_comprar;
        if (op == 2) cadastro_de_moradores;
        if (op == 3) mudancas;
        if (op == 4) mapa_do_comdominio;
        if (op == 5) pesquisar_informacoes;
        
    }
}

/* 

void menuMorador(){

    printf("\n----------MENU----------\n\n");
    printf("1-Cadastrar Morador\n");
    printf("2- Mostrar fila da mudanca\n");
    printf("3-Processar proxima mudanca\n");
    printf("4-Exibir moradores ja mudados\n");
    printf("0-Sair\n\n");
    printf("Qual opcao deseja escolher?\n");

}

void menu_morador(){
    int opcao;
     do {

        menuMorador();
        scanf("%d", &opcao);

        switch(opcao){

            case 1: { //o uso de {} é por conta da declaração de variaveis dentro do case 
                
                Morador morador = cadMorador(&fila);
                enfileirar(&fila, morador);
                break;

            }
            case 2:

                exibirFila(&fila);
                break;

            case 3: {

                Morador moradorRemovido; //dentro da função, moradorrRemovido recebe por parametro o primeiro morador da fila
                if (desenfileirar(&fila, &moradorRemovido) == 1) {

                    printf("Morador removido da fila:\n");
                    printMorador(moradorRemovido);
                    inserirMoradorMudado(&filaMudados, moradorRemovido); //inserir o morador removido na fila de moradores mudados
                } else {
                    printf("Fila vazia! Não ha morador para remover.\n");
                }
                break;
                
            }
            case 4:

                printf("Moradores já mudados:\n");
                exibirMoradoresMudados(&filaMudados);
                break;

            case 0:

                printf("Finalizando o programa\n");
                break;
        }
    } while ( opcao != 0);



    return 0;
}

*/
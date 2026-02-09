#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
   
    Fila fila;
    inicializarFila(&fila);
    Fila2 filaMudados;
    inicializarFila2(&filaMudados);

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


#include <stdio.h>
#include "dados.h"

void mostrar_menu()
{
    while (1) 
    {
        char op;

        printf("-----------------------------------------------\n");
        printf("|            GESTÃO DE CONDOMÍNIO             |\n");
        printf("-----------------------------------------------\n");
        printf("| 1. Listar nomes aleatórios                  |\n");
        printf("| 2. Opcão 2                                  |\n");
        printf("| 3. Opcão 3                                  |\n");
        printf("| 0. Sair                                     |\n");
        printf("-----------------------------------------------\n");
        printf("Digite uma opcão: ");
        
        scanf(" %c", &op);
        if (op == '0') break;
        if (op == '1') 
        {
            int qtd;
            printf("\n\n\n\ndigite a quantidade de nomes: ");
            scanf("%d", &qtd);
            listar_moradores_aleatorios(qtd);
            printf("\n\n\n\n");
        }
    }
}

int main() 
{
    mostrar_menu();
    return 0;
}
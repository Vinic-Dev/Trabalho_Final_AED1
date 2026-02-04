#include <stdio.h>

void mostrar_menu()
{
    while (1) 
    {
        char op;

        printf("-----------------------------------------------\n");
        printf("|              GESTAO HOSPITALAR              |\n");
        printf("-----------------------------------------------\n");
        printf("| 1. Opcao 1                                  |\n");
        printf("| 2. Opcao 2                                  |\n");
        printf("| 3. Opcao 3                                  |\n");
        printf("| 0. Sair                                     |\n");
        printf("-----------------------------------------------\n");
        printf("Digite uma opcão: ");
        
        scanf(" %c", &op);
        if (op == '0') break;
    }
}

int main() 
{
    mostrar_menu();
    return 0;
}
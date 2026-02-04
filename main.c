#include <stdio.h>

void mostrar_menu()
{
    while (1) 
    {
        char op;

        printf("-----------------------------------------------\n");
        printf("|              GESTÃO HOSPITALAR              |\n");
        printf("-----------------------------------------------\n");
        printf("| 1. Opcão 1                                  |\n");
        printf("| 2. Opcão 2                                  |\n");
        printf("| 3. Opcão 3                                  |\n");
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
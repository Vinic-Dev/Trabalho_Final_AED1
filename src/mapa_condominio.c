#include "mapa_condominio.h"
#include <stdio.h>
#include "tipos_de_dados.h"
#include "lista_de_casas.h"


#include <stdlib.h>

// M é o nome da matriz, n é o numero de dimensões,
int atrib(int* M, int i, int b, int c, int f, int v) {
    if ((c <= i) && (i <= f)) {
        M[b + (i - c)] = v;
        return 1; 
    } else {
        printf("Indice %d invalido!!!\n", i);
        exit(EXIT_FAILURE);
    }
}

int consul(int* M, int i, int b, int c, int f) {
    if ((c <= i) && (i <= f)) {
        return M[b + (i - c)];
    } else {
        printf("Indice %d invalido!!!\n", i);
        exit(EXIT_FAILURE);
    }
}
void exibir_mapa_condominio(Lista *lista) {
    if (lista == NULL) {
        printf("Lista de casas nao inicializada.\n");
        return;
    }

    // Definicoes do mapa
    // Blocos A-L (0-11), Numeros 1-6 (0-5) -> 12 * 6 = 72 casas
    // Acesso baseado: indice linear i = (bloco_idx * 6) + (numero - 1)
    // Limites: c=0, f=71. Base b=0.

    int mapa[72]; // Matriz baseada

    for(int k=0; k<72; k++) {
        atrib(mapa, k, 0, 0, 71, 0);
    }

    // Preenche mapa a partir da lista
    No *atual = lista->inicio;
    while (atual != NULL) {
        int bloco_idx = atual->casa.bloco - 'A';
        int num_idx = atual->casa.numero - 1;
        
        if (bloco_idx >= 0 && bloco_idx < 12 && num_idx >= 0 && num_idx < 6) {
            int indice = (bloco_idx * 6) + num_idx;
            if (atual->casa.esta_ocupada) {
                atrib(mapa, indice, 0, 0, 71, 1); // 1 = Ocupada
            }
        }
        atual = atual->proxima;
    }

    printf("\nMapa do Condominio:\n");
    printf("[ ] Livre, [X] Ocupada\n\n");
    printf("    1   2   3   4   5   6\n");

    for (int b_idx = 0; b_idx < 12; b_idx++) {
        char bloco_char = 'A' + b_idx;
        printf("%c: ", bloco_char);
        
        for (int n = 1; n <= 6; n++) {
            int indice = (b_idx * 6) + (n - 1);
            int status = consul(mapa, indice, 0, 0, 71);
            
            if (status == 1) {
                printf("[X] ");
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
        if ((b_idx + 1) % 12 != 0 && (b_idx+1)%4==0) { 
        }
    }
    printf("\n");
}

#include <stdio.h>
#include "lista_de_casas.h"
#include "tipos_de_dados.h"
#define MAX 72

Casa casas[MAX];


void mostrar_mapa() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 14; j++) {
            if ((j % 2) != 0) {
                printf("");
            }
        }
    }
}

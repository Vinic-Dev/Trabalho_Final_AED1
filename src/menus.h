#ifndef MENU_H
#define MENU_H

#include "lista_de_casas.h"
#include "fila.h"

void menu_principal();

void menu_morador();

void cadastro_de_moradores(Fila* fila, Fila2* filaMudados);

void menu_interessados();

void mapa_do_comdominio(Lista *lista, Fila2 *filaMudados);

#endif
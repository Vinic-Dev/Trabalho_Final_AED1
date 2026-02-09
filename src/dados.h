#ifndef DADOS_H
#define DADOS_H
#include "morador.h"

/**
 * @brief função para criar dados aleatórios de moradores
 * 
 * @param quantidade quantos moradores adicionar
 * @param moradores[] um array de structs do tipo Morador
 */
void gerar_moradores(int quantidade, Morador *moradores);
void listar_moradores_aleatorios(int quantidade);
void quantos_nomes();
#endif

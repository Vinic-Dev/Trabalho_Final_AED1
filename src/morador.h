#ifndef MORADOR_H
#define MORADOR_H   

typedef struct {

    char nome[50];
    int idade;
    char bloco;
    int casa;
    int mudanca; //1 se nao mudou, 0 se mudou

} Morador;

Morador cadastrar_morador(); //verificar o que precisa ser passado

/**
 * @brief recebe um array de moradores e lista eles
 * 
 * @param moradores[] o array a ser passado
 */
void listar_moradores(Morador moradores[]);

#endif
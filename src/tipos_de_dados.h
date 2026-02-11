#ifndef TIPOS_DE_DADOS_H
#define TIPOS_DE_DADOS_H
#include <stdbool.h>

typedef struct {
    char bloco;
    int numero;
    bool esta_ocupada;
} Casa;

typedef struct {
    char nome[50];
    int idade;
    Casa casa;
    bool fez_mudanca;
} Morador;

typedef struct {
    int id;
    char nome[50];
    int idade;
    Casa casa_interessada;
    double renda;
} Interessado;



#endif
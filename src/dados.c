#include "dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char *nomes[] = {
    "Ana", "Maria", "João", "José", "Pedro", "Lucas", "Mateus", "Gabriel", "Rafael", "Daniel",
    "Bruno", "Carlos", "Marcos", "Paulo", "André", "Felipe", "Diego", "Thiago", "Leonardo", "Rodrigo",
    "Eduardo", "Fernando", "Gustavo", "Henrique", "Victor", "Igor", "Renato", "Alex", "Vinícius", "Caio",
    "Wesley", "Anderson", "Douglas", "Fábio", "Juliano", "Leandro", "Luciano", "Marcelo", "Maurício", "Nelson",
    "Otávio", "Patrick", "Ramon", "Sérgio", "Tiago", "Ulysses", "William", "Yuri", "Zeca", "Adriano",
    "Beatriz", "Camila", "Carolina", "Daniela", "Eduarda", "Fernanda", "Gabriela", "Helena", "Isabela", "Juliana",
    "Larissa", "Mariana", "Natália", "Olivia", "Patricia", "Rafaela", "Sabrina", "Tatiana", "Vanessa", "Yasmin",
    "Aline", "Bianca", "Cristiane", "Débora", "Elaine", "Flávia", "Giovana", "Heloisa", "Irene", "Jéssica",
    "Karina", "Luana", "Mirela", "Nicole", "Priscila", "Renata", "Silvana", "Teresa", "Ursula", "Vitória",
    "Ximena", "Zilda", "Arthur", "Bernardo", "Davi", "Enzo", "Heitor", "Miguel", "Noah", "Samuel"
};

const char *sobrenomes[] = {
    "Silva", "Santos", "Oliveira", "Pereira", "Costa", "Rodrigues", "Alves", "Lima", "Gomes", "Ribeiro",
    "Martins", "Araújo", "Melo", "Barbosa", "Rocha", "Dias", "Nogueira", "Teixeira", "Fernandes", "Azevedo",
    "Moreira", "Cavalcante", "Freitas", "Cardoso", "Ramos", "Tavares", "Farias", "Batista", "Pacheco", "Rezende",
    "Guimarães", "Macedo", "Torres", "Vieira", "Moura", "Leite", "Lopes", "Machado", "Monteiro", "Campos",
    "Borges", "Cunha", "Dantas", "Rangel", "Assis", "Peixoto", "Queiroz", "Amaral", "Coelho", "Figueiredo",
    "Pinheiro", "Fonseca", "Siqueira", "Menezes", "Souza", "Braga", "Valente", "Aguiar", "Barros", "Matos",
    "Neves", "Guerra", "Seabra", "Lacerda", "Pimentel", "Sá", "Rios", "Caldeira", "Moraes", "Moraes",
    "Prado", "Toledo", "Carvalho", "Drummond", "Paiva", "Vasconcelos", "Beltrão", "Bittencourt", "Cordeiro", "Frota",
    "Lins", "Magalhães", "Saldanha", "Trindade", "Falcão", "Porto", "Guedes", "Serra", "Xavier", "Zanetti"
};
void listar_moradores_aleatorios(int quantidade){
    srand(time(NULL));
    for (int i = 0; i < quantidade; i++) {
            int r = rand() % 101; // 0 a 100
            int s = rand() % 91;    // 0 a 90
            char nome[50];
            char sobrenome[50];
            strcpy(nome, nomes[r]);
            if (r > 90) r = r - 10;
            strcpy(sobrenome, sobrenomes[r]);
            strcat(nome, " ");
            strcat(nome, sobrenome);
            strcpy(sobrenome, sobrenomes[s]);
            strcat(nome, " ");
            strcat(nome, sobrenome);
            printf("nome: %s\n", nome);
        }
}

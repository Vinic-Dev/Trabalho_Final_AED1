#include "gerador_dados.h"
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
    "Cleunice", "Zilda", "Arthur", "Bernardo", "Davi", "Enzo", "Heitor", "Miguel", "Noah", "Samuel"
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

void gerar_nome(char *nome){
    int r = rand() % 98; // 0 a 97
    int s = rand() % 90;    // 0 a 89
    char sobrenome[50];
    
    if(nomes[r] != NULL) {
        strcpy(nome, nomes[r]);
    } else { 
        r -= 10;
        strcpy(nome, nomes[r]);
    }
    if (r > 90) {
        r = r - 10;
    }
    if (sobrenomes[r]!= NULL) {
        strcpy(sobrenome, sobrenomes[r]);
    } else { 
        r -= 10; 
        strcpy(sobrenome, sobrenomes[r]);
    }

    strcat(nome, " ");
    strcat(nome, sobrenome);
    strcpy(sobrenome, sobrenomes[s]);
    strcat(nome, " ");
    strcat(nome, sobrenome);
}

double gerar_renda(){
    int r = rand() % 1001; // 0 a 1000
    int s = rand() % 91;    // 0 a 90
    double renda = r * s;
    return renda;
}

int gerar_idade(){
    int r = rand() % 70;
    if(r < 18) r = 18;
    return r;
}

void gerar_casa_aleatoria(Casa *casa) {
    char blocos[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
    int indice_bloco = rand() % 12; // 0 a 11
    casa->bloco = blocos[indice_bloco];
    casa->numero = (rand() % 6) + 1; // 1 a 6
    casa->esta_ocupada = false;
}

void gerar_morador(Morador *morador) {
    gerar_nome(morador->nome);
    morador->idade = gerar_idade();
    gerar_casa_aleatoria(&morador->casa);
    morador->casa.esta_ocupada = true; 
    morador->fez_mudanca = false;
}

void gerar_interessado(Interessado *interessado, int id){
    char nome[50];
    gerar_nome(nome);
    interessado->id = id;
    strcpy(interessado->nome, nome); 
    interessado->idade = gerar_idade();
    interessado->renda = gerar_renda();
    gerar_casa_aleatoria(&interessado->casa_interessada);
}

void simular_ocupacao(Fila2 *filaMudados, Lista *lista, int quantidade) {
    if (filaMudados == NULL || lista == NULL) {
        printf("Erro: Ponteiros invalidos em simular_ocupacao.\n");
        return;
    }

    int gerados = 0;
    int tentativas = 0;
    int max_tentativas = quantidade * 10; // Evitar loop infinito

    while (gerados < quantidade && tentativas < max_tentativas) {
        Morador morador;
        gerar_morador(&morador);

        if (!verificar_ocupacao(lista, filaMudados, morador.casa.bloco, morador.casa.numero)) {
            if (inserirMoradorMudado(filaMudados, morador)) {
                gerados++;
            }
        }
        tentativas++;
    }

    if (gerados < quantidade) {
        printf("Aviso: Apenas %d moradores gerados de %d solicitados (muitas colisoes).\n", gerados, quantidade);
    } else {
        printf("Sucesso: %d moradores gerados e inseridos na fila de mudados.\n", gerados);
    }
    atualizar_situacao_casas(lista, filaMudados);
}
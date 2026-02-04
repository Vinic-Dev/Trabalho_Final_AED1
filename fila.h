#ifndef FILA_H
#define FILA_H
#define MAX 25
//nao necessariamente precisa ser 25, verificar isso depois

typedef struct {

    int ID; //um identificador unico para cada paciente
    int idade;
    char nome[50];
    char historico_paciente[200]; // o historico servirá para descrever a situação do paciente brevmente

} Paciente;

typedef struct {

    Paciente pacientes[MAX];
    int inicio; //indice primeiro da fila
    int fim; //indice ultimo da fila
    int total; // quantidade de pacientes

} Fila;

void criarFila( Fila *fila); //inicializa a fila com 0
int filaVazia ( Fila *fila); // verificar se a fila ta vazia, retorna 1 pra vazia e 0 para nao vazia
int filaCheia ( Fila *f); // verificar a fila de acordo com o limite, retorna 1 se cheia e 0 se tem espaço ainda
void inserirPaciente (Fila *fila, Paciente paciente); // pegar um paciente existente e colocá-lo no final da fila
Paciente removerPaciente (Fila *fila); //remover o paciente do inicio da fila
int tamFila(Fila *fila); //verificar quantos pacientes estao na fila atualmente

Paciente criarPaciente(); // aqui vamos inserir as informacoes do paciente, montando uma struct Paciente dentro da propria função
void exibirPaciente (Paciente paciente); //vai receber a struct e exibir

#endif

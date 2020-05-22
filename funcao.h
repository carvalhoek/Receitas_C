#ifndef FUNCAO_H_INCLUDE
#define FUNCAO_H_INCLUDE

typedef struct info{
    char* titulo;
    char* tempo;
    char* ingredientes;
    char* modo;
    char* criador;
    float nota;
    int vezes;
}*Info;

void menu(char* e, Lista l);

Lista utilizar(Lista l);

Lista modificar(Lista l);

Info coleta(Lista l);

void restaurar(FILE arq, Lista l);

void gravar(FILE arq, Lista l);

void copiarString(char** s1, char* s2, int qteL);

#endif
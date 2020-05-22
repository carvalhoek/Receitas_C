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
}Info;

void menu(char* e);

#endif
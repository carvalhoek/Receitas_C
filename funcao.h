#ifndef FUNCAO_H_INCLUDE
#define FUNCAO_H_INCLUDE

typedef struct lista* Lista;

typedef struct info* Info;

Lista criar(int v);

Lista insercao(Lista l);

Lista retira(Lista l);

void atualizaInfo(Lista l, Info id);

Info informacoes(Lista l);

void libera(Lista l);

void imprimeAtual(Lista l);

int tamLista(Lista l);

void menu(char* e, Lista l);

Lista utilizar(Lista l);

Lista modificar(Lista l);

Info coleta(Lista l);

void restaurar(FILE arq, Lista l);

void gravar(FILE arq, Lista l);

void copiarString(char** s1, char* s2, int qteL);

#endif
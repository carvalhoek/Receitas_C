#ifndef LISTA_H_INCLUDE
#define LISTA_H_INCLUDE

typedef struct lista* Lista;

Lista criar(int v);

Lista insercao(Lista l, int v);

Lista retira(Lista l);

void atualizaInfo(Lista l, Info id);

Info informacoes(Lista l);

void libera(Lista l);

void imprimeAtual(Lista l);

int tamLista(Lista l);

#endif
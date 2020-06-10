#ifndef FUNCAO_H_INCLUDE
#define FUNCAO_H_INCLUDE

#define TITULO 50
#define TEMPO 25
#define INGREDIENTES 2000
#define MODO 4000
#define CRIADOR 50

typedef struct lista Lista;

typedef struct info Info;

typedef struct posicao pos;

Lista* acessarP(pos* listas);

Lista* acessarU(pos* listas);

Lista* criar(char modo);

pos* insercao(pos* l);

Lista* retira(Lista* l, pos* p);

void libera(Lista* l);

Lista* altera(Lista* l, char modo);

void imprimeAtual(Lista* l);

int tamLista(Lista* l);

void menu(char* e, Lista* l);

void utilizar(Lista* l);

void modificar(Lista* l);

Info* coleta();

pos* restaurar(FILE* arq);

void gravar(FILE* arq, Lista* l);

#endif
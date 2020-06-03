#ifndef FUNCAO_H_INCLUDE
#define FUNCAO_H_INCLUDE

#define TITULO 50
#define TEMPO 25
#define INGREDIENTES 2000
#define MODO 4000
#define CRIADOR 50

typedef struct lista Lista;

typedef struct info Info;

Lista* criar(char modo);

Lista* insercao(Lista* l);

Lista* retira(Lista* l);

void atualizaInfo(Lista* l, Info* id);

Info* informacoes(Lista* l);

void libera(Lista* l);  //FEITO

Lista* altera(Lista* l, char modo); //FEITO

void imprimeAtual(Lista* l);

int tamLista(Lista* l);

void menu(char* e, Lista* l);

void utilizar(Lista* l);

void modificar(Lista* l);

Info* coleta();

Lista* restaurar(FILE* arq);

void gravar(FILE* arq, Lista* l);

#endif
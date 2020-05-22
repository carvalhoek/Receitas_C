#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"
#include "listaEnc.h"

struct lista{
    Info i;
    Lista anterior;
    Lista proximo;
    int teste;
};

Lista criar(int v){
    /**
     * alocar memoria
     * funcao para pegar informacoes
     * ligar ant e prox com ele mesmo
    **/
    Lista novo = malloc(sizeof(Lista));

    novo->anterior = novo;
    novo->proximo = novo;

    //int teste eh temporario
    //aqui ira info
    novo->teste = v;

    return novo;
}

Lista insercao(Lista l, int v){
    /**
     * funcao de criacao de elemento
     * verificar se eh o primeiro
     * colocar na posicao correta
     * ordem alfabetica
    **/

   Lista novo = criar(v);

   /*if(l != NULL){
       Lista ant = l;
       Lista prox = l->proximo;

       while(v > ant->teste &&){

       }

   }*/

   return novo;
}

Lista retira(/*endereco da lista*/){
    /**
     * remocao do endereco
     * prox->ant liga com ant
     * ant->prox liga com prox
    **/
}

void libera(/*endereco da lista*/){
    /**
     * loop para liberar toda a memoria
     * condicao de parada
    **/
}

void imprimeAtual(/*endereco do atual*/){
    /**
     * recebe info
     * imprime
    **/
}
#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"
#include "listaEnc.h"

struct lista{
    Info i;
    Lista anterior;
    Lista proximo;
    int teste;
    //LEMBRETE: REMOVER TESTE NA FINALIZACAO
};

Lista criar(int v){
    /**
     * alocar memoria
     * funcao para pegar informacoes (funcao)
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
     * ordem alfabetica em relacao ao titulo
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

Lista retira(Lista l){
    /**
     * prox->ant liga com ant
     * ant->prox liga com prox
     * cria auxiliar com o endereco de l->prox
     * retorna auxiliar
    **/
}

void atualizaInfo(Lista l, Info id){
    /**
     * iguala as informacoes da l->i com a info
     * nao sei se vai ser necessario
    **/
}

Info informacoes(Lista l){
    /**
     * retornar l->i
    **/
}

void libera(Lista l){
    /**
     * loop para liberar toda a memoria
     * condicao de parada
    **/
}

void imprimeAtual(Lista l){
    /**
     * recebe info
     * imprime
    **/
}

int tamLista(Lista l){
    /**
     * contador de todas os elementos
     * loop infinito
     * condicao de parada
    **/
}
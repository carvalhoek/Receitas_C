#include <stdio.h>
#include <stdlib.h>
#include "listaEnc.h"
#include "funcao.h"

void menu(char* e, Lista l){
    printf("\nLivro de Receitas\n\n");
    printf("<-a ou p->: Navegar\n");
    printf("u: Utilizada\n");
    printf("m: Modificar\n");
    printf("r: Remover\n");
    printf("i: Inserir nova\n");
    printf("s: Sair do livro\n");

    //funcao de imprimir a pagina atual (listaEnc)

    scanf("%c", e);
    fflush(stdin);
}

Lista utilizar(Lista l){
    /**
     * criar uma variavel para pegar informacoes do elemento da lista
     * funcao para pegar informacoes existentes do elemento (listaEnc)
     * perguntar a nota que o usuario da para a receita utilizada agora
     * adicionar em um a quantidade de vezes utilizada
     * fazer uma media com a nota ja existente, utiliizando a quantidade de vezes utilizada
     * colocar a nova info no elemento da lista (listaEnc)
     * retornar o elemento modificado da lista (ou nao, nao sei se precisa)
    **/
}

Lista modificar(Lista l){
    /**
     * criar uma variavel para pegar informacoes do elemento da lisra
     * funcao para pegar informacoes existentes do elemento (listaEnc)
     * podiamos fazer um loop infinito para saber o que quer ser alterado
     * colocar a nova info no elemento da lista (listaEnc)
     * retornar o elemento modificado da lista (ou nao, nao sei se precisa)
    **/
}

Info coleta(Lista l){
    /**
     * criar uma variavael (Info) auxiliar que pegara as informacoes
     * pegar todas as informacoes necessarias do usuario
     * utilizar variaveis auxiliares de string para otimizar espaco
     * utilizar funcao de colocar string em outra (vou criar vai estar em funcao)
     * igualar nota e vezes a 0, se necessario
     * retornar a variavel auxiliar
    **/
}

void restaurar(FILE arq, Lista l){
    /**
     * arquivo vai ser lida
     * pegar quantidade de elementos na Lista
     * loop com quantidade de elementos
     *      pegar info em ordem posta na struct
     *          char* titulo
     *          char* tempo
     *          char* ingredientes
     *          char* modo
     *          char* criador
     *          float nota
     *          int vezes
    **/
}

void gravar(FILE arq, Lista l){
    /**
     * arquivo vai ser escrito
     * funcao que le quantidade de elementos (listaEnc)
     * escreve a quantidade de elementos
     * loop quantidade de elementos
     *      escrever info em ordem posta na struct
     *          char* titulo
     *          char* tempo
     *          char* ingredientes
     *          char* modo
     *          char* criador
     *          float nota
     *          int vezes
     *      funcao de insercao (listaEnc)
    **/
}

void copiarString(char** s1, char* s2, int qteL){
    /**
     * s1 vai receber o texto de s2 referente a quantidade de letras de s2
     * como vai ser feito muito isso pra otimizacao de espaco vou criar uma funcao
     * assim deixa mais pratico de se vizualizar o codigo
    **/
}
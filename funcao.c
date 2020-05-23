#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"

struct lista{
    Info i;
    Lista anterior;
    Lista proximo;
    int teste;
    //LEMBRETE: REMOVER TESTE NA FINALIZACAO
};

struct info{
    char* titulo;
    char* tempo;
    char* ingredientes;
    char* modo;
    char* criador;
    float nota;
    int vezes;
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

Lista insercao(Lista l){

    /**
     * funcao de criacao de elemento
     * verificar se eh o primeiro
     * colocar na posicao correta
     * ordem alfabetica em relacao ao titulo
    **/
    char lixo;
    int v;
    printf("Digite o valor: ");
    scanf("%d", &v);
    scanf("%c", &lixo);

    Lista novo = criar(v);

    printf("novo criado\n");

    if(l != NULL){
        printf("entrei na condicao\n");
        Lista ant = l;
        Lista prox = l->proximo;

        while(v > prox->teste && prox != l){
           ant = ant->proximo;
           prox = ant->proximo;
        }

        novo->anterior = ant;
        novo->proximo = prox;
        ant->proximo = novo;
        prox->anterior = novo;

    }
    
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
    printf("imprimindo valores\n");
    Lista aux = l;
    do{
        printf("teste = %d\n", aux->teste);
        aux = aux->proximo;
    }while(aux != l);
}

int tamLista(Lista l){
    /**
     * contador de todas os elementos
     * loop infinito
     * condicao de parada
    **/
}

void menu(char* e, Lista l){
    printf("\nLivro de Receitas\n\n");
    printf("<-a ou p->: Navegar\n");
    printf("u: Utilizada\n");
    printf("m: Modificar\n");
    printf("r: Remover\n");
    printf("i: Inserir nova\n");
    printf("s: Sair do livro\n");

    //funcao de imprimir a pagina atual

    scanf("%c", e);
    fflush(stdin);
}

Lista utilizar(Lista l){
    /**
     * criar uma variavel para pegar informacoes do elemento da lista
     * funcao para pegar informacoes existentes do elemento
     * perguntar a nota que o usuario da para a receita utilizada agora
     * adicionar em um a quantidade de vezes utilizada
     * fazer uma media com a nota ja existente, utiliizando a quantidade de vezes utilizada
     * colocar a nova info no elemento da lista
     * retornar o elemento modificado da lista (ou nao, nao sei se precisa)
    **/
}

Lista modificar(Lista l){
    /**
     * criar uma variavel para pegar informacoes do elemento da lisra
     * funcao para pegar informacoes existentes do elemento
     * podiamos fazer um loop infinito para saber o que quer ser alterado
     * colocar a nova info no elemento da lista
     * retornar o elemento modificado da lista (ou nao, nao sei se precisa)
    **/
}

Info coleta(Lista l){
    /**
     * criar uma variavael (Info) auxiliar que pegara as informacoes
     * pegar todas as informacoes necessarias do usuario
     * utilizar variaveis auxiliares de string para otimizar espaco
     * utilizar funcao de colocar string em outra (vou criar)
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
     * funcao que le quantidade de elementos
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
     *      funcao de insercao
    **/
}

void copiarString(char** s1, char* s2, int qteL){
    /**
     * s1 vai receber o texto de s2 referente a quantidade de letras de s2
     * como vai ser feito muito isso pra otimizacao de espaco vou criar uma funcao
     * assim deixa mais pratico de se vizualizar o codigo
    **/
}
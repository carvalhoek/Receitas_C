#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"

struct lista{
    Info* i;
    Lista* anterior;
    Lista* proximo;
    int teste;
    //LEMBRETE: REMOVER TESTE NA FINALIZACAO
};

struct info{
    char titulo[TITULO];
    char tempo[TEMPO];
    char ingredientes[INGREDIENTES];
    char modo[MODO];
    char criador[CRIADOR];
    float nota;
    int vezes;
};

Lista* criar(int v){ //FEITO
    /**
     * alocar memoria
     * funcao para pegar info*rmacoes
     * ligar ant e prox com ele mesmo
    **/

    Lista* novo = (Lista*) malloc(sizeof(Lista));

    novo->teste = v;

    novo->proximo = novo;
    novo->anterior = novo;

    return novo;
}

Lista* insercao(Lista* l){ //FEITO
    /**
     * funcao de criacao de elemento
     * verificar se eh o primeiro
     * colocar na posicao correta
     * ordem alfabetica em relacao ao titulo
    **/

    int v;
    char lixo;
    printf("digite o valor: ");
    scanf("%d", &v);
    scanf("%c", &lixo);

    Lista* novo = criar(v);

    if(l == NULL)
        return novo;
    else if(l->teste > v){
        l->anterior->proximo = novo;
        novo->anterior = l->anterior;
        l->anterior = novo;
        novo->proximo = l;
        return novo;
    }
    else{
        Lista* aux = l->proximo;
        
        while(v > aux->teste && aux != l){
            aux = aux->proximo;
        }

        aux->anterior->proximo = novo;
        novo->anterior = aux->anterior;
        aux->anterior = novo;
        novo->proximo = aux;
        return l;
    }
}

Lista* retira(Lista* l){
    /**
     * prox->ant liga com ant
     * ant->prox liga com prox
     * cria auxiliar com o endereco de l->prox
     * retorna auxiliar
    **/
}

void atualizaInfo(Lista* l, Info* id){
    /**
     * iguala as informacoes da l->i com a info
     * nao sei se vai ser necessario
    **/
}

Info* informacoes(Lista* l){
    /**
     * retornar l->i
    **/
}

void libera(Lista* l){ //FEITO
    /**
     * loop para liberar toda a memoria
     * condicao de parada
    **/
   Lista* aux = l;
   do{
       aux = aux->proximo;
       free(aux->anterior);
   }while(aux != l);
}

Lista* altera(Lista* l, char modo){ //FEITO
    if(modo == 'a')
        return l->anterior;
    else if(modo == 'p')
        return l->proximo;
    else{ 
        printf("Modo invalido!\n");
        return l;
    }
}

void imprimeAtual(Lista* l){
    /**
     * recebe info
     * imprime
    **/
    printf("teste = %d\n\n", l->teste);
}

int tamLista(Lista* l){
    /**
     * contador de todas os elementos
     * loop infinito
     * condicao de parada
    **/
}

void menu(char* e, Lista* l){
    printf("\nLivro de Receitas\n\n");
    printf("<-a ou p->: Navegar\n");
    printf("u: Utilizada\n");
    printf("m: Modificar\n");
    printf("r: Remover\n");
    printf("i: Inserir nova\n");
    printf("s: Sair do livro\n\n");

    if(l != NULL)
        imprimeAtual(l);

    scanf("%c", e);
    fflush(stdin);
}

Lista* utilizar(Lista* l){
    /**
     * criar uma variavel para pegar info*rmacoes do elemento da lista*
     * funcao para pegar info*rmacoes existentes do elemento
     * perguntar a nota que o usuario da para a receita utilizada agora
     * adicionar em um a quantidade de vezes utilizada
     * fazer uma media com a nota ja existente, utiliizando a quantidade de vezes utilizada
     * colocar a nova info* no elemento da lista*
     * retornar o elemento modificado da lista* (ou nao, nao sei se precisa)
    **/
}

Lista* modificar(Lista* l){
    /**
     * criar uma variavel para pegar info*rmacoes do elemento da lisra
     * funcao para pegar info*rmacoes existentes do elemento
     * podiamos fazer um loop infinito para saber o que quer ser alterado
     * colocar a nova info* no elemento da lista*
     * retornar o elemento modificado da lista* (ou nao, nao sei se precisa)
    **/
}

Info* coleta(Lista* l){
    /**
     * criar uma variavael (Info*) auxiliar que pegara as info*rmacoes
     * pegar todas as info*rmacoes necessarias do usuario
     * utilizar variaveis auxiliares de string para otimizar espaco
     * utilizar funcao de colocar string em outra (vou criar)
     * igualar nota e vezes a 0, se necessario
     * retornar a variavel auxiliar
    **/
}

void restaurar(FILE arq, Lista* l){
    /**
     * arquivo vai ser lida
     * pegar quantidade de elementos na Lista*
     * loop com quantidade de elementos
     *      pegar info* em ordem posta na struct
     *          char* titulo
     *          char* tempo
     *          char* ingredientes
     *          char* modo
     *          char* criador
     *          float nota
     *          int vezes
    **/
}

void gravar(FILE arq, Lista* l){
    /**
     * arquivo vai ser escrito
     * funcao que le quantidade de elementos
     * escreve a quantidade de elementos
     * loop quantidade de elementos
     *      escrever info* em ordem posta na struct
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
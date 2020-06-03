#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"

struct lista{
    Info* i;
    Lista* anterior;
    Lista* proximo;
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

Lista* criar(){ //FEITO
    /**
     * alocar memoria
     * funcao para pegar informacoes
     * ligar ant e prox com ele mesmo
    **/

    Lista* novo = (Lista*) malloc(sizeof(Lista));

    novo->i = coleta();

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
    Lista* novo = criar();

    if(l == NULL)
        return novo;
    
    Info* infoNovo = novo->i;
    Info* infoL = l->i;
    int menor;

    if(strlen(infoL->titulo) < strlen(infoNovo->titulo))
        menor = strlen(infoL->titulo);
    else
        menor = strlen(infoNovo->titulo);
    
    if(strncmp(infoL->titulo, infoNovo->titulo, menor) > 0){
        l->anterior->proximo = novo;
        novo->anterior = l->anterior;
        l->anterior = novo;
        novo->proximo = l;
        return novo;
    }
    else{
        Lista* aux = l->proximo;
        Info* infoAux = aux->i;
        
        while(strncmp(infoAux->titulo, infoNovo->titulo, menor) < 0 && aux != l){
            aux = aux->proximo;
            infoAux = aux->i;
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
    if(l != NULL){
        char esc;
        printf("\nQuer remover a pagina atual? (S: caso sim): ");
        scanf("%c", &esc);
        fflush(stdin);

        if(esc == 's' || esc == 'S'){

            if(l->proximo == l){
                free(l);
                return NULL;
            }

            Lista* aux = l->proximo;
            Lista* temp = l;

            aux->anterior = temp->anterior;
            temp->anterior->proximo = aux;

            free(temp);

            return aux;
        }
    }
    return l;
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
    if(l == NULL)
        return;

    Lista* aux = l;
    do{
        aux = aux->proximo;
        free(aux->anterior);
    }while(aux != l);
}

Lista* altera(Lista* l, char modo){ //FEITO
    if(modo == '<')
        return l->anterior;
    else if(modo == '>')
        return l->proximo;
    else{ 
        printf("Modo invalido!\n");
        return l;
    }
}

void imprimeAtual(Lista* l){ //FEITO
    /**
     * recebe info
     * imprime
    **/
    Info* aux = l->i;
    printf("Receita: %s\n", aux->titulo);
    printf("Tempo de preparo: %s\n", aux->tempo);
    printf("Ingredientes: %s\n", aux->ingredientes);
    printf("Modo de preparo: %s\n", aux->modo);
    printf("Criador: %s\n", aux->criador);
    printf("Nota: %.2f/5\n", aux->nota);
    printf("Vezes utilizada: %d\n", aux->vezes);
}

int tamLista(Lista* l){
    /**
     * contador de todas os elementos
     * loop infinito
     * condicao de parada
    **/
}

void menu(char* e, Lista* l){
    printf("\n=====================================\n");
    printf("#                                   #\n");
    printf("#         Livro de Receitas         #\n");
    printf("#                                   #\n");
    printf("=====================================\n");
    printf("#                                   #\n");
    printf("#    <->: Navegar                   #\n");
    printf("#     u : Utilizada                 #\n");
    printf("#     m : Modificar                 #\n");
    printf("#     r : Remover                   #\n");
    printf("#     i : Inserir nova              #\n");
    printf("#                                   #\n");
    printf("#     s : Sair do livro             #\n");
    printf("#                                   #\n");
    printf("=====================================\n\n");

    if(l != NULL)
        imprimeAtual(l);
    else
        printf("Nenhuma Receita inserida (i: para uma nova)\n");
    
    printf("\nOpcao: ");

    scanf("%c", e);
    fflush(stdin);
}

void utilizar(Lista* l){
    /**
     * criar uma variavel para pegar informacoes do elemento da lista
     * funcao para pegar informacoes existentes do elemento
     * perguntar a nota que o usuario da para a receita utilizada agora
     * adicionar em um a quantidade de vezes utilizada
     * fazer uma media com a nota ja existente, utiliizando a quantidade de vezes utilizada
     * colocar a nova info no elemento da lista
     * retornar o elemento modificado da lista (ou nao, nao sei se precisa)
    **/

    Info* aux = l->i;
    char lixo;

    aux->nota *= aux->vezes;
    aux->vezes++;

    float notaMais;
    printf("\nDigite a nota que da para a receita utilizada (0-5): ");
    scanf("%f", &notaMais);
    scanf("%c", &lixo);

    aux->nota = (aux->nota+notaMais)/aux->vezes;
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

Info* coleta(){
    /**
     * criar uma variavael (Info*) auxiliar que pegara as informacoes
     * pegar todas as informacoes necessarias do usuario
     * utilizar variaveis auxiliares de string para otimizar espaco
     * igualar nota e vezes a 0, se necessario
     * retornar a variavel auxiliar
    **/

    Info* aux = (Info*) malloc(sizeof(Info));

    printf("\nDigite o nome da Receita\n");
    gets(aux->titulo);

    printf("\nDigite o tempo de preparo da receita\n");
    gets(aux->tempo);

    printf("\nDigite os ingredientes utilizados na receita\n");
    gets(aux->ingredientes);

    printf("\nDigite o modo de preparo da receita\n");
    gets(aux->modo);

    printf("\nDigite o criador da receita\n");
    gets(aux->criador);

    aux->vezes = 0;
    aux->nota = 0.00;

    return aux;
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
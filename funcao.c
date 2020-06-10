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

struct posicao{
    Lista* primeiro;
    Lista* ultimo;
};

Lista* acessarP(pos* listas){
    return listas->primeiro;
}

Lista* acessarU(pos* listas){
    return listas->ultimo;
}

Lista* criar(char modo){
    /**
     * parametro pra saber se eh feito durant a insercao ou ao restaurar
     * alocar memoria do elemento da lista
     * funcao para pegar informacoes
     * ligar anterior e proximo com ele mesmo
    **/
    Lista* novo = (Lista*) malloc(sizeof(Lista));

    if(modo == 'i')
        novo->i = coleta();
    if(modo == 'r')
        novo->i = malloc(sizeof(Info));
    
    novo->proximo = novo;
    novo->anterior = novo;

    return novo;
}

pos* insercao(pos* l){
    /**
     * funcao de criacao de elemento
     * verificar se eh o primeiro
     * colocar na posicao correta
     *      caso seja antes do primeiro vai modificar o primeiro
     *      caso seja o depois que o ultimo modificar o ultimo
     * ordem alfabetica em relacao ao titulo
    **/
    Lista* novo = criar('i');

    if(l == NULL){
        l = (pos*)malloc(sizeof(pos));
        l->primeiro = novo;
        l->ultimo = novo;

        return l;
    }

    Info* infoNovo = novo->i;
    Lista* primeiro = l->primeiro;
    Info* infoL = primeiro->i;
    int menor;

    if(strlen(infoL->titulo) < strlen(infoNovo->titulo))
        menor = strlen(infoL->titulo);
    else
        menor = strlen(infoNovo->titulo);
    
    if(strncmp(infoL->titulo, infoNovo->titulo, menor) > 0){
        primeiro->anterior->proximo = novo;
        novo->anterior = primeiro->anterior;
        primeiro->anterior = novo;
        novo->proximo = primeiro;
        l->primeiro = novo;

        return l;
    }
    else{
        Lista* aux = primeiro->proximo;
        Info* infoAux = aux->i;

        if(strlen(infoAux->titulo) < strlen(infoNovo->titulo))
            menor = strlen(infoAux->titulo);
        else
            menor = strlen(infoNovo->titulo);
        
        while(strncmp(infoAux->titulo, infoNovo->titulo, menor) < 0 && aux != primeiro){
            aux = aux->proximo;
            infoAux = aux->i;

            if(strlen(infoAux->titulo) < strlen(infoNovo->titulo))
                menor = strlen(infoAux->titulo);
            else
                menor = strlen(infoNovo->titulo);
        }

        if(aux == primeiro)
            l->ultimo = novo;

        aux->anterior->proximo = novo;
        novo->anterior = aux->anterior;
        aux->anterior = novo;
        novo->proximo = aux;

        return l;
    }
}

Lista* retira(Lista* l, pos* p){
    /**
     * verificar se o usuario quer remover a pagina atual
     *      caso nao retorna o mesmo elemento
     * verificar se a pagina atual eh a primeira ou a ultima
     *      caso primeira passa para a proxima
     *      caso ultima passa para a anterior
     * verifica se a pagina atual eh a unica existente
     *      retorna NULL
     * cria auxiliar com o endereco de l->prox
     * cria temporario com o endereco de l
     * prox->ant liga com ant
     * ant->prox liga com prox
     * retorna auxiliar
    **/
    if(l != NULL){
        char esc;
        printf("\nQuer remover a pagina atual? (S: caso sim): ");
        scanf("%c", &esc);
        fflush(stdin);

        if(esc == 's' || esc == 'S'){

            if(p->primeiro == l)
                p->primeiro = l->proximo;
            else if(p->ultimo == l)
                p->ultimo = l->anterior;

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

void libera(Lista* l){
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

Lista* altera(Lista* l, char modo){
    /**
     * verifica se existe elemento na lista
     *      caso retorna NULL
     * verifica qual modo
     *      navega pro proximo, ou para anterior
     * retorna o equivalente ao modo
    **/
    if(l == NULL)
        return NULL;

    if(modo == '<')
        return l->anterior;
    else if(modo == '>')
        return l->proximo;
    else{ 
        printf("Modo invalido!\n");
        return l;
    }
}

void imprimeAtual(Lista* l){
    /**
     * recebe info
     * imprime as info
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
     * retorna tamanho
    **/
    int i = 0;
    Lista* aux = l;

    do{
        i++;
        aux = aux->proximo;
    }while(aux != l);

    return i;
}

void menu(char* e, Lista* l){
    /**
     * menu
     * verifica se existe alguma receita pra ser impressa
     *      imprime atual se houver
     * coleta a opcao de escolha
    **/
    printf("\n=====================================\n");
    printf("||                                 ||\n");
    printf("||        Livro de Receitas        ||\n");
    printf("||                                 ||\n");
    printf("=====================================\n");
    printf("||                                 ||\n");
    printf("||    <->: Navegar                 ||\n");
    printf("||     u : Utilizada               ||\n");
    printf("||     m : Modificar               ||\n");
    printf("||     r : Remover                 ||\n");
    printf("||     i : Inserir nova            ||\n");
    printf("||                                 ||\n");
    printf("||     s : Sair do livro           ||\n");
    printf("||                                 ||\n");
    printf("=====================================\n\n");

    if(l != NULL)
        imprimeAtual(l);
    else
        printf("Nenhuma Receita inserida (i: para uma nova)\n");
    
    printf("\nOpcao: ");
    char lixo;
    scanf("%c", e);
    scanf("%c", &lixo);
    fflush(stdin);
}

void utilizar(Lista* l){
    /**
     * verifica se existe algum elemento na lista
     * criar uma variavel para pegar informacoes do elemento da lista
     * perguntar a nota que o usuario da para a receita utilizada agora
     *      qualquer nota maior que 5 sera equivalente a 5
     * adicionar em um a quantidade de vezes utilizada
     * fazer uma media com a nota ja existente, utilizando a quantidade de vezes utilizada
    **/
    if(l == NULL)
        return;

    Info* aux = l->i;
    char lixo;

    aux->nota *= aux->vezes;
    aux->vezes++;

    float notaMais;
    printf("\nDigite a nota que da para a receita utilizada (0-5): ");
    scanf("%f", &notaMais);
    scanf("%c", &lixo);

    if(notaMais > 5)
        notaMais = 5;

    aux->nota = (aux->nota+notaMais)/aux->vezes;
}

void modificar(Lista* l){
    /**
     * verifica se algum elemento esta sendo modificado
     * criar uma variavel para pegar informacoes do elemento da lista
     * print com opcoes que podem ser alterado
     * loop infinito para saber o que quer ser alterado
    **/
    if (l == NULL)
        return;

    Info* aux = l->i;
    char esc;

    do{
        printf("1 - Nome da receita: %s\n", aux->titulo);
        printf("2 - Tempo de preparo: %s\n", aux->tempo);
        printf("3 - Ingredientes: %s\n", aux->ingredientes);
        printf("4 - Modo de preparo: %s\n", aux->modo);
        printf("5 - Nome do criador: %s\n", aux->criador);

        printf("\nDigite a opcao da informacao sera modificada (0 para sair): ");
        scanf("%c", &esc);
        fflush(stdin);

        switch(esc){
            case '1':
                printf("\nNovo titulo: ");
                gets(aux->titulo);
                break;
            case '2':
                printf("\nNovo tempo de preparo: ");
                gets(aux->tempo);
                break;
            case '3':
                printf("\nNovos ingredientes: ");
                gets(aux->ingredientes);
                break;
            case '4':
                printf("\nNovo modo de preparo: ");
                gets(aux->modo);
                break;
            case '5':
                printf("\nNovo nome do criador: ");
                gets(aux->criador);
                break;
            case '0':
                break;
            default:
                printf("\nOperacao invalida!\n");
                break;
        }
    }while(esc != '0');
}

Info* coleta(){
    /**
     * criar uma variavael auxiliar que pegara as informacoes
     * pegar todas as informacoes necessarias do usuario
     * igualar nota e vezes a 0
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

pos* restaurar(FILE* arq){
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
     * definir a primeira e ultima posicao da lista
     * retornar a struct com as posicoes
    **/
    Lista* primeiro;
    Lista* ultimo;

    int tamS;
    int tamL;
    Info* auxI;

    fread(&tamL, sizeof(int), 1, arq);

    for (int cont = 0; cont < tamL; cont++){
        Lista* auxiliar = criar('r');

        auxI = auxiliar->i;

        fread(&tamS, sizeof(int), 1, arq);
        fread(auxI->titulo, sizeof(char), tamS, arq);
        auxI->titulo[tamS] = '\0';
        
        fread(&tamS, sizeof(int), 1, arq);
        fread(auxI->tempo, sizeof(char), tamS, arq);
        auxI->tempo[tamS] = '\0';
        
        fread(&tamS, sizeof(int), 1, arq);
        fread(auxI->ingredientes, sizeof(char), tamS, arq);
        auxI->ingredientes[tamS] = '\0';
        
        fread(&tamS, sizeof(int), 1, arq);
        fread(auxI->modo, sizeof(char), tamS, arq);
        auxI->modo[tamS] = '\0';
        
        fread(&tamS, sizeof(int), 1, arq);
        fread(auxI->criador, sizeof(char), tamS, arq);
        auxI->criador[tamS] = '\0';

        fread(&auxI->nota, sizeof(float), 1, arq);
        fread(&auxI->vezes, sizeof(int), 1, arq);

        if(cont != 0){
            ultimo->proximo = auxiliar;
            primeiro->anterior = auxiliar;
            auxiliar->anterior = ultimo;
            auxiliar->proximo = primeiro;
            ultimo = auxiliar;
        }
        else{
            primeiro = auxiliar;
            ultimo = auxiliar;
        }
	}
   
    pos* receita = (pos*)malloc(sizeof(pos));
    receita->primeiro = primeiro;
    receita->ultimo = ultimo;

    return receita;
}

void gravar(FILE* arq, Lista* l){
    /**
     * arquivo vai ser escrito
     * funcao que le quantidade de elementos
     * escreve a quantidade de elementos
     * loop com condica de parada
     *      escrever info em ordem posta na struct
     *          char* titulo
     *          char* tempo
     *          char* ingredientes
     *          char* modo
     *          char* criador
     *          float nota
     *          int vezes
    **/
    Lista* auxiliar = l;
    
    int tamL = tamLista(l);
    fwrite(&tamL, sizeof(int), 1, arq);
    
    do{
        Info* auxI =  auxiliar->i;

        int tam;

        tam = strlen(auxI->titulo);
        fwrite(&tam, sizeof(int), 1, arq);
        fwrite(auxI->titulo, sizeof(char), strlen(auxI->titulo), arq);

        tam = strlen(auxI->tempo);
        fwrite(&tam, sizeof(int), 1, arq);
        fwrite(auxI->tempo, sizeof(char), strlen(auxI->tempo), arq);

        tam = strlen(auxI->ingredientes);
        fwrite(&tam, sizeof(int), 1, arq);
        fwrite(auxI->ingredientes, sizeof(char), strlen(auxI->ingredientes), arq);

        tam = strlen(auxI->modo);
        fwrite(&tam, sizeof(int), 1, arq);
        fwrite(auxI->modo, sizeof(char), strlen(auxI->modo), arq);

        tam = strlen(auxI->criador);
        fwrite(&tam, sizeof(int), 1, arq);
        fwrite(auxI->criador, sizeof(char), strlen(auxI->criador), arq);

        fwrite(&auxI->nota, sizeof(float), 1, arq);

        fwrite(&auxI->vezes, sizeof(int), 1, arq);

        auxiliar = auxiliar->proximo;
    } while (auxiliar != l); 
}
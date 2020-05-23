#include <stdio.h>
#include "funcao.h"


int main(){
    Lista receitaAtual;
    char escolha;

    /**
     * verificacao da existencia de um arquivo
     * abrir arquivo
     * funcao para pegar informacoes do arquivo (funcao)
     * fechar arquivo, talvez apagar
    **/

    do{
        menu(&escolha, receitaAtual);
        switch(escolha){
            case 'a':
                printf("Indo pra pagina anterior\n");
                //funcao para ir pro elemento anterior da lista (listaEnc)
                break;
            case 'p':
                printf("Indo pra pagina posterior\n");
                //funcao para ir pro elemento posterior da lista da lista (listaEnc)
                break;
            case 'u':
                printf("Utilizando pra pagina atual\n");
                //funcao de utilizacao de receita (funcao)
                break;
            case 'm':
                printf("Modificando a pagina atual\n");
                //funcao de modificacao de info (funcao)
                break;
            case 'r':
                printf("removendo a pagina atual\n");
                //funcao de remocao de elemento da lista (listaEnc)
                break;
            case 'i':
                printf("inserindo uma nova pagina\n");
                //funcao de insercao de elemento da lista (listaEnc)
                receitaAtual = insercao(receitaAtual);
                imprimeAtual(receitaAtual);
                break;
            case 's':
                printf("Saindo do livro\n");
                break;
            default:
                printf("Operacao invalida!\n");
                break;
        }

    }while(escolha != 's');

    /**
     * criacao de arquivo de gravacao
     * funcao de gravacao de info no arquivo
     * fechar arquivo
     * liberacao de de variaveis
     * funcao de liberacao de lista (listaEnc)
    **/

    return 0;
}
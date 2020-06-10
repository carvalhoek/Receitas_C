#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"


int main(){
    Lista* receitaAtual = NULL;
    pos* receitas = NULL;
    char escolha;
    char a;

    /**
     * abrir arquivo
     * verificacao da existencia de um arquivo
     * funcao para pegar informacoes do arquivo
     * fechar arquivo
     * apagar o arquivo
    **/
    FILE* arq = fopen("datei.kr", "r+b");
    if(arq != NULL){
        receitas = restaurar(arq);
        receitaAtual = acessarP(receitas);
        fclose(arq);
        remove("datei.kr");
    }
    do{
        menu(&escolha, receitaAtual);
        switch(escolha){
            case '>':
            case '<':
                //funcao para ir pro elemento posterior da lista da lista
                receitaAtual = altera(receitaAtual, escolha);
                break;
            case 'u':
                //funcao de utilizacao de receita
                utilizar(receitaAtual);
                break;
            case 'm':
                //funcao de modificacao de info
                modificar(receitaAtual);
                break;
            case 'r':
                //funcao de remocao de elemento da lista
                receitaAtual = retira(receitaAtual, receitas);
                break;
            case 'i':
                //funcao de insercao de elemento da lista
                //verificacao se eh o primeiro elemento a ser inserido
                receitas = insercao(receitas);
                if(receitaAtual == NULL)
                    receitaAtual = acessarP(receitas);
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
     * verifica se tem algo pra gravar
     * criacao de arquivo de gravacao
     * funcao de gravacao de info no arquivo
     * fechar arquivo
     * funcao de liberacao de lista
    **/

    if(receitaAtual != NULL){
        arq = fopen("datei.kr", "w+b");
        gravar(arq, acessarP(receitas));
        fclose(arq);
        libera(receitaAtual);
        free(receitas);
    }

    return 0;
}
#include <stdio.h>
#include "funcao.h"


int main(){
    Lista* receitaPrimeira = NULL;
    Lista* receitaAtual = NULL;
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
                receitaAtual = retira(receitaAtual);
                break;
            case 'i':
                //funcao de insercao de elemento da lista
                receitaPrimeira = insercao(receitaPrimeira);
                if(receitaAtual == NULL)
                    receitaAtual = receitaPrimeira;
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

    libera(receitaAtual);

    return 0;
}
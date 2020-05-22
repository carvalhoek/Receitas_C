#include <stdio.h>
#include "funcao.h"
#include "listaEnc.h"


int main(){
    Lista receita;
    char escolha;

    do{
        menu(&escolha);
        switch(escolha){
            case 'a':
                printf("Indo pra pagina anterior\n");
                break;
            case 'p':
                printf("Indo pra pagina posterior\n");
                break;
            case 'u':
                printf("Utilizando pra pagina atual\n");
                break;
            case 'm':
                printf("Modificando a pagina atual\n");
                break;
            case 'r':
                printf("removendo a pagina atual\n");
                break;
            case 'i':
                printf("inserindo uma nova pagina\n");
                break;
            case 's':
                printf("Saindo do livro\n");
                break;
            default:
                printf("Operacao invalida!\n");
                break;
        }

    }while(escolha != 's');

    return 0;
}
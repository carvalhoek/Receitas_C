#include <stdio.h>
#include <stdlib.h>
#include "listaEnc.h"
#include "funcao.h"

void menu(char* e){
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

#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
#include <string.h>

int main()
{
    int num, v[10], str[20];
    printf("Associe as letras de A a J aos valores que desejar: ");
    for(int i = 0; i < 10; i++){
        scanf("%d", &v[i]);
    }
    printf("Selecione uma opcao: \n");
    printf("1: Forma pos-fixa\n");
    printf("2: Forma infixa com uso de parenteses\n");
    printf("3: Forma infixa com uso de parenteses eventuais\n");
    scanf("%d", &num);

    printf("Digite a expressao: ");
    scanf("%s",str);

    switch(num){
        case 1: pos_fixa(str,v); break;
        case 2: infixa_com_parentes(str,v); break;
        case 3: infixa_eventual(str,v); break;
        default: printf("Opcao invalida."); break;
    }


    return 0;
}

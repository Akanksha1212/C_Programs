#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
#include <string.h>
#include <math.h>

struct no{
    char info_char;
    int info;
    struct no *prox;
};

Pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(Pilha p){
    if(p == NULL)
        return 1;
    else
        return 0;
}

int push(Pilha *p, int elem) {
    Pilha N = (Pilha)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;

    N->info = elem;
    N->prox = *p;
    *p = N;
    return 1;
}

int pop(Pilha *p, int *elem){
    if(pilha_vazia(*p))
        return 0;

    Pilha aux = *p;
    *elem = aux->info;
    *p = aux->prox;
    free(aux);
    return 1;
}


int pushchar(Pilha *p, char elem) {
    Pilha N = (Pilha)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;

    N->info_char = elem;
    N->prox = *p;
    *p = N;
    return 1;
}

int popchar(Pilha *p, char *elem){
    if(pilha_vazia(*p))
        return 0;

    Pilha aux = *p;
    *elem = aux->info_char;
    *p = aux->prox;
    free(aux);
    return 1;
}

int le_topo(Pilha *p, int *elem){
    if(pilha_vazia(*p))
        return 0;
    *elem = (*p)->info;
    return 1;
}

int le_topo_char(Pilha *p, char *elem){
    if(pilha_vazia(*p))
        return 0;
    *elem = (*p)->info_char;
    return 1;
}

void pos_fixa(char str[20], int v[10]){
    Pilha p = cria_pilha();
    int num1, num2, result;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == 'A')
            push(&p,v[0]);
        else if(str[i] == 'B')
            push(&p, v[1]);
        else if(str[i] == 'C')
            push(&p, v[2]);
        else if(str[i] == 'D')
            push(&p, v[3]);
         else if(str[i] == 'E')
            push(&p, v[4]);
        else if(str[i] == 'F')
            push(&p, v[5]);
        else if(str[i] == 'G')
            push(&p, v[6]);
        else if(str[i] == 'H')
            push(&p, v[7]);
        else if(str[i] == 'I')
            push(&p, v[8]);
        else if(str[i] == 'J')
            push(&p, v[9]);
        else if(str[i] == '+'){
            pop(&p,&num1);
            pop(&p, &num2);
            result = num2 + num1;
            push(&p,result);
        }
            else if(str[i] == '-'){
            pop(&p,&num1);
            pop(&p, &num2);
            result = num2 - num1;
            push(&p,result);
        }

            else if(str[i] == '*'){
            pop(&p,&num1);
            pop(&p, &num2);
            result = num2 * num1;
            push(&p,result);
        }
               else if(str[i] == '/'){
            pop(&p,&num1);
            pop(&p, &num2);
            result = num2 / num1;
            push(&p,result);
        }

            else if(str[i] == '^'){
            pop(&p,&num1);
            pop(&p, &num2);
            result = pow(num2,num1);
            push(&p,result);
        }
    }

    pop(&p,&result);
    if(pilha_vazia(p) == 1){
        printf("Resultado: %d", result);
        }
    else
        return;
}

void infixa_com_parentes(char str[20], int u[10]){
    Pilha p = cria_pilha();
    int j=0;
    char v[10], c;

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
            pushchar(&p, str[i]);
        if(str[i] >= 'A' && str[i] <= 'J'){
            v[j] = str[i];
            j++;
            }
        if(str[i] == ')'){
            popchar(&p,&c);
            v[j] = c;
            j++;
        }
    }
    v[j] = '\0';
    printf("%s\n",v);
    if(pilha_vazia(p) == 1){
        pos_fixa(v,u);
    }
    else{
        return;
    }
}



int prioridade(char c){
    if(c == '(')
        return 0;
    else if(c == '+' || c == '-')
        return 1;
    else if(c == '/' || c == '*')
        return 2;
    else
        return 3;
}


void infixa_eventual(char str[20], int u[10]){
    Pilha p = cria_pilha();
    int j=0;
    char c, v[20];

    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 'A' && str[i] <= 'J'){
            v[j] = str[i];
            j++;
        }

        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
            while(pilha_vazia(p) == 0 && prioridade(str[i]) <= prioridade(p->info_char)){
                popchar(&p,&c);
                v[j] = c;
                j++;
            }
                pushchar(&p,str[i]);

        }
        else if(str[i] == '(')
            pushchar(&p, str[i]);
        else if(str[i] == ')'){
            while(p->info_char != '('){
                    popchar(&p,&c);
                    v[j] = c;
                    j++;
                  }
                  popchar(&p,&c); //para desempilhar e ignorar o abre parentese
        }
      }
      while(pilha_vazia(p) == 0){
            popchar(&p,&c);
            v[j] = c;
            j++;
        }
        v[j] = '\0';
        printf("%s\n",v);
      if(pilha_vazia(p) == 1)
         pos_fixa(v,u);
}


void imprime(Pilha p){
    Pilha aux = p;
    if(pilha_vazia(p)){
        printf("Vazia.");
        return;
        }

    while(aux != NULL){
        printf("%d", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

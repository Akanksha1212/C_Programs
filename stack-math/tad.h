typedef struct no *Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int push(Pilha *p, int elem);
int pushchar(Pilha *p, char elem);
int pop(Pilha *p, int *elem);
int popchar(Pilha *p, char *elem);
int le_topo(Pilha *p, int *elem);
int le_topo_char(Pilha *p, char *elem);
void pos_fixa(char str[20], int v[10]);
void infixa_com_parentes(char str[20], int u[10]);
int prioridade(char c);
void infixa_eventual(char str[20], int u[10]);

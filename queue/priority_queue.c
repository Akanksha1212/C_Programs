#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef long long int ll;
//FIFO
typedef struct qnode
{
    ll data;
    ll priority;
    struct qnode *next;
} qnode;

void initQ(qnode *first)
{
    first->data = 0;
    first->priority = 0;
    first->next = NULL;
}
void enqueue(qnode *p, ll a, ll b)
{
    qnode *temp = (qnode *)malloc(sizeof(qnode));
    assert(temp);
    temp->data = a;
    temp->priority = b;
    temp->next = NULL;
    qnode *t = p;
    while ((t->next != NULL) && ((t->next)->priority > b))
    {
        t = t->next;
    }
    temp->next = t->next;
    t->next = temp;
}
ll dequeue(qnode *p)
{

    qnode *temp = p->next;
    p->next = (p->next)->next;
    ll r = temp->data;
    free(temp);
    return r;
}
void qdisplay(qnode *first)
{
    qnode *temp = first->next;
    while (temp)
    {
        printf("%lld ", (temp->data));
        temp = temp->next;
    }

    printf("\n");
}
int main()
{
    ll A[10] = {5, 3, 6, 7, 8, 1, 2, 4, 9, 0};
    ll B[10] = {4, 6, 3, 2, 1, 8, 7, 5, 0, 9};
    qnode *Q = (qnode *)malloc(sizeof(qnode));
    initQ(Q);
    for (ll i = 0; i < 10; i++)
    {
        enqueue(Q, A[i], B[i]);
        //qdisplay(Q);
    }
    qdisplay(Q);
}

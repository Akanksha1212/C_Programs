#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
}
*start=NULL,*end=NULL;

// Create a single node
void createone(int n)
{
    struct node *temp;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new-> data = n;
    new->next = NULL;
    new->prev = NULL;
    if (start == NULL)
    {
        start = new;
        new->next = start;
        start->prev = end;
        end = new;
    }
    else
    {
        end->next = new;
        new->prev = end;
        new->next = start;
        end = new;
    }
}

// Printng the LinkList from Head
void printfo()
{
    struct node* t= start;
    do
    {
        printf("%d \n", t->data);
        t = t-> next;
    }
    while(t!= start);
}

// Printng the LinkList from Tail
void printbw()
{
    struct node* t= end;
    while(t!=start)
    {

        printf("%d \n", t->data);
        t = t-> prev;

    }
    printf("%d \n", t->data);


}

// Insertion of a new node after a node containing 'data' 
void insad(int data, int pos)
{
    int k =0;
    struct node* a = start;
    do
    {
        if(a->data == pos)
        {
            struct node* abc = (struct node*)malloc(sizeof(struct node));
            abc->next = a->next;
            abc->prev = a;
            abc->data = data;
            a->next = abc;
            abc->next->prev=abc;
            k++;
        }
        a = a-> next;

    }
    while(a->next!= start);
    if(a->data==pos)
    {
        int ss=0;
        insin(data,ss);
        k++;
    }
    if(k==0)
            printf("No such Data exist");
}

// Insertion of a new node before a node containing 'data' 
void insbd(int data, int pos)
{
    int k = 0;
    struct node* a = start;
    struct node* b = start ->next;
    if(a->data == pos)
    {
        int ss =1;
        insin(data, ss);
        k++;
    }
    else
    {
        do
        {
            if(a->data == pos)
            {
                struct node* abc = (struct node*)malloc(sizeof(struct node));
                abc->next = a;
                abc->prev = a->prev;
                abc->data = data;
                a->prev = abc;
                abc->prev->next=abc;
                k++;
            }
            a = a-> next;

        }
        while(a!= start);
    }

    if(k==0)
        printf("No such Data Exist");

}

// Inserting data at an index
void insin(int data,int pos)
{
    struct node* a = start;
    int d=0;
    struct node* t = start;
    do
    {
        d++;
        t = t-> next;
    }
    while(t!= start);
    int k = 1;
    if(pos>d+1)
        printf("Index out of bound\n");
    else if (pos==1)
    {
        struct node* abc = (struct node*)malloc(sizeof(struct node));

        abc->next = start;
        abc->prev = end;
        abc->data = data;
        start->prev = abc;
        start = abc;
        end->next=abc;
    }
    else if(pos == 0)
    {
        struct node* abc = (struct node*)malloc(sizeof(struct node));
        abc->next =start;
        abc->prev = end;
        abc->data = data;
        end->next = abc;
        end = abc;
    }
    else
    {
       k++;
    if(pos==d+1)
        {
            int ss=0;
            insin(data,ss);
        }
    else
    {

    do
    {

        if (k==pos)
        {
            struct node* abc = (struct node*)malloc(sizeof(struct node));
            abc->next = a->next;
            abc->prev = a;
            abc->data = data;
            a->next = abc;
            abc->next->prev= abc;
        }
        a = a->next;
        k++;
    }
    while(a->next!=start);
    }
    }

}

// Deleting node on the basis of data
void deld(int data)
{
    int k=0;
    struct node* a = start;
    if(a->data == data)
    {
        delin(1);
        k++;
    }
    else
    {
        struct node* b = a->next;
        do
        {

            if(b->data==data)
            {
                b->next->prev=a;
                a->next= b->next;
                k++;

            }
            a= a->next;
            b = b->next;
        }
        while(b!=start);
    }
    if (k==0)
        printf("Sorry Mate the number does not exist!!\n");

}

// Deleting a node on the basis of index
void delin(int pos)
{
    struct node* a = start;
    int k = 1;
    int d=0;
    struct node* t = start;
    do
    {
        d++;
        t = t-> next;
    }
    while(t!= start);

    if(pos>d)
        printf("Index out of bound\n");
    else if (pos==1)
    {
        start = start->next;
        start->prev= end;
        end->next = start;
    }
    else if(pos == 0)
    {

        end->prev->next = start;
        end=end->prev;
        start->prev=end;
    }
    else
    {
       k++;
    do
    {
        if (k==pos)
        {

            a->next->next->prev= a;
            a->next = a->next->next;

        }
        a = a->next;
        k++;
    }
    while(a!=start);
    }


}

// Searching a node
void search(int data)
{
    int s =1, v =0;
    struct node* t = start;
    do
    {
        if(t->data==data)
        {
            v++;
            printf("Number Found at position %d \n", s);
        }
        s++;
        t = t-> next;
    }
    while(t!=start);
    if(v==0)
        printf("Sorry Mate Number not found\n");
}

// To check weather the loop exist or not
void loop()
{
    struct node* t = start;

    int k =0;
    struct node* s = start;
    while(t!=NULL)
    {
        if(t->next == s)
        {
            k++;
            break;
        }
        t=t->next;
    }
    if (k==0)
        printf("No loop exist \n");
    else
        printf("Loop Exist\n");
}

// Sorting of elements of Linked List
void sort()
{
    struct node* t= start;
    do
    {
        struct node* s = t->next;
        do
        {
            if(s->data < t-> data)
            {
                int d = s->data;
                s->data = t->data;
                t->data = d;
            }
            s = s->next;
        }
         while(s!=start);
        t = t->next;
    }
    while(t->next!= start);
}

// Reverse a data in the linked list
void rev()
{
    struct node* t = start;
    struct node* tt = end;
    int temp = tt->data;
    tt->data= t->data;
    t->data = temp;

    while(tt->prev!= t && t->next!= tt && tt->prev!=t->next)
    {
        t= t->next;
        tt=tt->prev;
        int temp = tt->data;
        tt->data= t->data;
        t->data = temp;

    }
}

int main()
{
    int data,no,i,pos,ss;
    int n =1;
    while(n!=0)
    {
        // Select the option to perform operation on linked list created
        printf("Welcome to Double Linked List as ADT, Choose from the following: \n");
        printf(" 1. To create double link list \n 2. To print in forward \n 3. To search in double linked list\n ");
        printf("4. To insert data after a data \n 5. To insert data before a data\n ");
        printf("6. To insert data at beginning   \n 7. To insert data at end \n");
        printf(" 8. To delete values \n 9. To delete last node \n 10. To delete first node \n");
        printf(" 11. To sort \n 12. To reverse the nodes \n 13. To delete from a position\n");
        printf(" 14. To insert at a position \n 15. To check whether a loop exist or not \n 16. To print in backward \n");
        printf(" 0. To exit \n");
        printf("Choose from above? \n");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
            {
                printf("Enter the no of data in linked list \n");
                scanf("%d",&no);
                for(i=0; i<no; i++)
                    {
                        printf("Enter data %d  ", i);
                        scanf("%d",&data);
                        createone(data);
                    }
            }
            break;
            case 2:
            {
                printfo();
            }
            break;
            case 3:
            {
                printf("Enter the data to be searched \n");
                scanf("%d",&data);
                search(data);
            }
            break;
            case 4:
            {
                printf("Enter the data to be added \n");
                scanf("%d",&data);
                printf("Enter data after which to be inserted\n");
                scanf("%d",&pos);
                insad(data, pos);
            }
            break;
            case 5:
            {
                printf("Enter the data to be added \n");
                scanf("%d",&data);
                printf("Enter data before which to be inserted\n");
                scanf("%d",&pos);
                insbd(data, pos);
            }
            break;
            case 6:
            {
                printf("Enter the data to be added \n");
                scanf("%d",&data);
                ss =1;
                insin(data, ss);
            }
            break;
            case 7:
            {
                printf("Enter the data to be added \n");
                scanf("%d",&data);
                ss=0;
                insin(data, ss);
            }
            break;
            case 8:
            {
                printf("Enter data to be deleted \n");
                scanf("%d",&data);
                deld(data);
            }
            break;
            case 9:
            {
                ss=0;
                delin(ss);
            }
            break;
            case 10:
            {
                ss=1;
                delin(ss);
            }
            break;
            case 11:
            {
                sort();
            }
            break;
            case 12:
            {
                rev();
            }
            break;
            case 13:
            {
                printf("Enter position\n");
                scanf("%d",&pos);
                delin(pos);
            }
            break;
            case 14:
            {
                printf("Enter the data to be added \n");
                scanf("%d",&data);
                printf("Enter position\n");
                scanf("%d",&pos);
                insin(data, pos);
            }
            break;
            case 15:
            {
                loop();
            }
            break;
            case 16:
            {
                printbw();
            }
            break;
            case 0:
                printf("See you soon");
            break;
            default:
            {
                printf("Enter a valid option \n");
            }
            break;
        }
    }
    return(0);
}



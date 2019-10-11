#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
}
*start=NULL;

// Create a single node
void createone(int n)
{
    struct node *temp;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new-> data = n;
    new->next = NULL;
    if (start == NULL)
    {
        start = new;
        new->next = start;
    }
    else
    {
        temp = start;
        do
            temp = temp->next;
        while(temp->next!= start);
        temp-> next = new;
        new->next=start;
    }
}

// Printng the LinkList
void print()
{
    struct node* t= start;
    do
    {
        printf("%d \n", t->data);
        t = t-> next;
    }
    while(t!= start);
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
            abc->data = data;
            a->next = abc;
            k++;
        }
        a = a-> next;

    }
    while(a!= start);
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
        while(b!=start && b->data!=pos)
        {
        b = b->next;
        a = a-> next;

        }

            struct node* abc = (struct node*)malloc(sizeof(struct node));
            abc->next = b;
            abc->data = data;
            a->next = abc;
            k++;
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
        do
        {
            a=a->next;
        }
        while(a->next!=start);
        abc->next = start;
        abc->data = data;
        start = abc;
        a->next=abc;
    }
    else if(pos == 0)
    {
    do
    {
        a = a->next;
    }
    while(a->next!=start);
        struct node* abc = (struct node*)malloc(sizeof(struct node));
        abc->next =start;
        abc->data = data;
        a->next = abc;
    }
    else
    {
       k++;
    do
    {
        if (k==pos)
        {
            struct node* abc = (struct node*)malloc(sizeof(struct node));
            abc->next = a->next;
            abc->data = data;
            a->next = abc;
        }
        a = a->next;
        k++;
    }
    while(a->next!=start);
    }


}

// Deleting node on the basis of data
void deld(int data)
{
    struct node* a = start;
    if(a->data == data)
    {
        delin(1);
    }
    else
    {
        struct node* b = a->next;
        do
        {

            if(b->data==data)
            {
                a->next= b->next;
            }
            a= a->next;
            b = b->next;
        }
        while(b!=start);
    }

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
        do
        {
            t = t-> next;
        }
        while(t->next!= start);
        start = start->next;
        free(a);
        t->next = start;
    }
    else if(pos == 0)
    {
        while(a->next->next!=start)
    {
        a = a->next;
    }
        a->next = start;
    }
    else
    {
       k++;
    do
    {
        if (k==pos)
        {

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

int main()
{
    int data,no,i,pos,ss;
    int n =1;
    while(n!=0)
    {
        // Select the option to perform operation on linked list created
        printf("Welcome to Circular Linked List as ADT, Choose from the following: \n");
        printf(" 1. To create link list \n 2. To print the linked list \n 3. Search in linked list\n ");
        printf("4. To insert data into linked list after a data \n 5. To insert data into linked list before a data\n ");
        printf("6. To insert data into linked list at beginning   \n 7. To insert data into linked list at end \n");
        printf(" 8. To delete values from linked list \n 9. Delete last node \n 10. delete first node \n");
        printf(" 11. To sort the link list\n 12. To reverse the nodes of linked list \n 13. To delete from a position\n");
        printf(" 14. To insert at a position \n 15. To check whether a loop exist or not \n 0. To exit \n");
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
                print();
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
            default:
            {
                printf("Enter a valid option \n");
            }
            break;
        }
    }
    return(0);
}


#include<stdio.h>
#include<stdlib.h>

typedef struct list 
{
    int val;
    struct list * next;
}node;

node * insert_front(node *head)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    printf("\nEnter the value to enter \n");
    scanf("%d",&p->val);
    p->next=head;
    head=p;
    return head;
}

void insert_end(node * head )
{
    node *p,*temp;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;

    }
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the value to enter\n");
    scanf("%d",&temp->val);
    p->next=temp;
    temp->next=NULL;
       
    
}

void insert_pos(node * head,int pos )
{
    node * p,*temp ;
    p=head;
   
    {
        if(pos==0)
        {
            temp=(node* ) malloc(sizeof(node));
            printf("enter the value to enter \n");
            scanf("%d",&temp->val);
            temp->next=head;
            head=temp;
        }
        else
        {
            for(int i=1;i<pos;i++)
            {
                p=p->next;
                
            }
            temp=(node *)malloc(sizeof(node));
            printf("Enter the value to enter \n");
            scanf("%d",&temp->val);
            temp->next=p->next;
            p->next=temp;
            
        }           
    }    
}

node * delete_front(node *head)
{
    node*p;
    p=head;
    p=p->next;
    head=p;
    
    return head;
    //free(p);
}

void delete_end(node *head)
{
    node * p;
    p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p=NULL;    
    
}

void delete_pos(node * head,int pos)
{
    node *p;
    node * q;
    p=head;
    q=head->next;
    int k=1;
    while(p->next!=NULL && k<pos)
    
    {
        p=p->next;
        q=q->next;
        k++;

    }
    p->next=q->next;
    
}

void search(node*head,int data)
{
    node *p;
    p=head;
    int pos=0 ;

    while(p->next!=NULL&& p->val!=data)
    {
        pos++;
        p=p->next;
    }

    printf("the position of the data is : %d\n",pos);
    
}

void display(node*head)
{
    node *p;
    p=head;
   
    while(p!=NULL)
    {
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}


void main()
{

    node *head ,*p;
    int n;
    printf("Enter the total no of records you want to enter \n\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            head=(node*)malloc(sizeof(node));
            p=head;
        }
        else
        {
            p->next=(node*)malloc(sizeof(node));
            p=p->next;
        }
        printf("enter the value\n");
        scanf("%d",&p->val);
    }
    p->next=NULL;
    //free(p);

    while (1)
    {
        printf("1:insert\n2:delete\n3:search\n4:display\n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n1: at start \n2: at end \n3: at specified position\n");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                head=insert_front(head);
                break;

            case 2:
                insert_end(head);
                break;

            case 3:
                int pos;
                printf("Enter the position to enter \n");
                scanf("%d", &pos);
                insert_pos(head, pos);
                break;
            default:
                exit(0);
            }
            break;

        case 2:
            printf("1: at start\n2: at end\n3: at a position\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                head=delete_front(head);
                break;
                case 2:
                delete_end(head);
                break;

                case 3:
                int pos;
                printf("enter the position to delete\n");
                scanf("%d",&pos);
                delete_pos(head ,pos);
                break;

                default:
                exit(0);
            }
            break;

        case 3:
        int item;
        printf("enter the item to search\n");
        scanf("%d",&item);
        search(head,item);

        break;

        case 4:
            display(head);
            break;
        default:
        exit(0);

        
        
        }
    }
}

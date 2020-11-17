#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;


};
Node *f=NULL,*r=NULL;
void inserting(int x)
{
    Node* t;
    t->data=x;
    t->next=NULL;


    if(t==NULL)
        cout<<"Heap full:";
    else{
            if(f==NULL){f=r=t;}
            else{
                    r->next=t;
                    r=t;
            }

    }
}
void deleting()
{
    if(f==NULL)
        cout<<"Queue is empty";
    else
    {
        Node* p;
        p=f;
        int x=f->data;
        f=f->next;
        delete(p);
        cout<<x;
    }
}
void display()
{
    if(f==NULL)
        cout<<"Empty:";
    while(f)
    {
        cout<<f->data<<" ";
        f=f->next;
    }
}
int main()
{

    inserting(3);
    inserting(4);
    inserting(5);
    inserting(6);
    display();
    return 1;
}

/* Program to Represent and Evaluate a Polynomial */
#include<stdio.h>
#include<stdlib.h>	
#include<math.h>
struct node
{
int cf;
int px,py,pz;
struct node* link;
};
typedef struct node* NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc( sizeof(struct node));
if(x==NULL)
{
printf("Out of memeory");
exit(0);
}
return x;
}
NODE insert_rear(int cf,int px,int py,int pz, NODE head)
{
NODE temp,cur;
temp=getnode();
temp->cf=cf;
temp->px=px;
temp->py=py;
temp->pz=pz;
cur=head->link;
while(cur->link!=head)
{
cur=cur->link;
}
cur->link=temp;
temp->link=head;
return head;
}
NODE read_poly(NODE head)
{
int i,n;
int cf,px,py,pz;
printf("Enter the no. of terms in the polynomial");
scanf("%d", &n);
for(i=1; i<=n; i++)
{
printf("Enter term:%d\n",i);
printf("Cf Px, py, pz=");
scanf("%d %d %d %d",&cf,&px,&py,&pz);
head= insert_rear(cf,px,py,pz,head);
}
return head;
}
void display(NODE head)
{
NODE temp;
if(head->link==head)
{
printf("Polynomail does not exist");
return;
}
temp=head->link;
while(temp!=head)
{
if(temp->cf<0)
printf("%d",temp->cf);
else
printf("+%d",temp->cf);
if(temp->px!=0)
printf("x^%d",temp->px);
if(temp->py!=0)
printf("y^%d",temp->py);
if(temp->pz!=0)
printf("z^%d",temp->pz);
temp=temp->link;
}
printf("\n");
}
float evaluate(NODE head)
{
int x,y,z;float sum=0;
NODE p;
printf("Enter the value of x,y,z");
scanf("%d %d %d",&x,&y,&z);
p=head->link;
while(p!=head)
{
sum+=p->cf*pow(x,p->px)* pow(y,p->py)* pow(z,p->pz);
p=p->link;
}
return sum;
}
void main()
{
NODE head;
float res;
head=getnode();
head->link=head;
printf("Enter the polynomial\n");
head=read_poly(head);
res=evaluate(head);
printf("The given polynomial is\n");
display(head);
printf("The result=%f\n",res);
}

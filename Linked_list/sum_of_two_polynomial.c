/* Program to find the sum of two Polynomial */
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
scanf("%d",&n);
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
NODE search(NODE p1,NODE h2)
{
NODE p2;
int cf1,px1,py1,pz1, cf2,px2,py2,pz2;
px1=p1->px;
py1=p1->py;
pz1=p1->pz;
p2=h2->link;
while ( p2 != h2)
{
px2=p2->px;
py2=p2->py;
pz2=p2->pz;
if( px1==px2 && py1==py2 && pz1==pz2 ) break;
p2=p2->link; //Obtain the next term of poly2
}
return p2;
}
NODE copy_poly (NODE h2, NODE h3)
{
NODE p2;
int cf2,px2,py2,pz2;
p2=h2->link;
while( p2!=h2)
{
/*Add remaining terms of poly 2 into poly3); */
if( p2->cf != -999)
{
cf2=p2->cf;
px2=p2->px;
py2=p2->py;
pz2=p2->pz;
h3=insert_rear(cf2, px2, py2, pz2, h3);
}
p2 = p2->link; //Get the next term of poly2
}
return h3;
}
NODE add_poly(NODE h1, NODE h2, NODE h3)
{
NODE p1,p2;
int cf1,px1,py1,pz1, sum;
p1 = h1->link;
while(p1!=h1)
{
cf1=p1->cf;
px1=p1->px;
py1=p1->py;
pz1=p1->pz;
p2=search(p1,h2); //Search power of p1 in p2
if(p2!=h2) //Powers of poly1 found in poly2
{
sum=cf1+p2->cf; //Add coeff, insert to poly3
h3=insert_rear(sum,px1,py1,pz1,h3);
p2->cf=-999; //Delete the term of poly2
}
else //If not found, insert term of poly1 to poly 3
h3= insert_rear(cf1,px1,py1,pz1,h3);
p1=p1->link; //Get the next term of polynomial1
}
h3=copy_poly(h2,h3);//Copy remaining terms of poly2 into poly3
return h3; //return total terms in poly3
}
void main()
{
NODE h1,h2,h3;
h1= getnode();
h2=getnode();
h3= getnode();
h1->link=h1; h2->link=h2; h3->link=h3;
printf("Enter the first polynomial\n");
h1=read_poly(h1);
printf("Enter the second polynomial\n");
h2=read_poly(h2);
printf("Poly 1:");
display(h1);
printf("Poly2:");
display(h2);
printf("----------------------------------------------------------------\n");
h3= add_poly(h1,h2,h3);
printf("Poly 3:");
display(h3);
printf("----------------------------------------------------------------\n");
}

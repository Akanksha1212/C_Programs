#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void readpoly(int[],int*);
int addpoly(int[],int[],int[],int,int);
void displaypoly(int[],int);
void mult_term(int,int[],int[],int,int,int*);
void multpoly(int[],int[],int[],int,int,int*);
int main()
{
 int poly1[MAX],poly2[MAX],poly3[MAX],deg1,deg2,deg3;
 printf("Enter first polynomial:\n");
 readpoly(poly1,&deg1);
 displaypoly(poly1,deg1);
 printf("Enter second polynomial:\n");
 readpoly(poly2,&deg2);
 displaypoly(poly2,deg2);
 printf("Multiplied poly is :\n");
 multpoly(poly1,poly2,poly3,deg1,deg2,&deg3);
 displaypoly(poly3,deg3);
 return 0;
}
void readpoly(int poly1[],int *n)
{
    int i;
    printf("enter the degree of polynomial\n");
    scanf("%d",&(*n));
    printf("start entering coefficient in descending order of exponent\n");
    for(i=0;i<=*n;i++)
        scanf("%d",&poly1[i]);
}
int addpoly(int p1[],int p2[],int p3[],int d1,int d2)
{
	int i,j,diff;
	if(d1==0)
        for(i=0;i<=d2;i++)
        p3[i]=p2[i];
	else{
	    if(d1>d2)
	{
		for(i=0;i<(d1-d2);i++)
		p3[i]=p1[i];
		for(j=0;j<=d2;j++)
		p3[i+j]=p1[i+j]+p2[j];
		return d1;
	}
	if(d2>d1)
	{
		for(i=0;i<(d2-d1);i++)
		p3[i]=p2[i];
		for(j=0;j<=d1;j++)
		p3[i+j]=p2[i+j]+p1[j];
		return d2;
	}
	if(d1==d2)
	{
		for(i=0;i<=d1;i++)
		{
			p3[i]=p1[i]+p2[i];
		}
		for(i=0;i<=d1;i++)
		{
			if(p3[i]==0)
			   d2--;
			else
			   break;
		}
		diff=d1-d2;
		if(diff!=0)
		{
			for(i=diff;i<=d1;i++)
			{
				p3[i-diff]=p3[i];
			}

		}}
		return d2;
	}
}
void displaypoly(int p[],int d)
{
	int i,j,temp=0;
	for(i=0;i<=d;i++)
	{
		if(p[i]!=0)
		{
			temp=p[i];
			int count=0;
			while(temp>0)
			{
				temp/=10;
				count++;
			}
			for(j=0;j<=(count+1);j++)
			{
				printf(" ");
			}
			printf("%d",d-i);
		}
	}
	printf("\n");
	for(i=0;i<=d;i++)
	{
		if(p[i]!=0)
		{
			temp=d-i;
		for(j=0;temp>0;j++)
		{
		    printf(" ");
		    temp=temp/10;
		}
		if(p[i]>0 && i>0)
		    printf("+%dx",p[i]);
		else if(i==0 || p[i]<0)
		    printf("%dx",p[i]);
		}
	}
	printf("\n\n");
}
void multpoly(int poly1[],int poly2[],int poly3[],int deg1,int deg2,int *deg3)
{
    int i,deg,degterm,temp;
    deg=-1;
    int *temppoly;
    temppoly=(int *)malloc(MAX*sizeof(int));
    temp=deg1;
    for(i=0;i<=deg1;i++)
    {
        mult_term(poly1[i],poly2,temppoly,temp,deg2,&degterm);
        deg=addpoly(poly3,temppoly,poly3,deg,degterm);
        temp--;
    }
    free(temppoly);
    *deg3=deg;
}
void mult_term(int coeff,int poly2[],int temppoly[],int deg1,int deg2,int *degterm)
{
    int i;
    *degterm=(deg1+deg2);
    for(i=0;i<=*degterm;i++)
    {
        if(i<=deg2)
        temppoly[i]=coeff*poly2[i];
        else
            temppoly[i]=0;
    }
}

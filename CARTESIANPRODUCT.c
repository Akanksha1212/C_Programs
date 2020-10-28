#include<stdio.h>
#include<conio.h>
int main()
{
 int a[50],b[50],c[50],i,s1,s2,j,k;
 printf("Enter how many elements in set 1\n");
 scanf("%d",&s1);
 printf("Enter how many elements in set 2\n");
 scanf("%d",&s2); 
 printf("Enter elements of set 1\n");
 for(i=0;i<s1;i++)
 {
 scanf("%d",&a[i]);
 }
 printf("Enter elements of set 2\n");
 for(i=0;i<s2;i++)
 {
 scanf("%d",&b[i]);
 }
 printf("cartessian product=");
 printf("{");
 for(i=0;i<s1;i++)
 {
 for(j=0;j<s2;j++)
 {
 printf("(%d,%d)",a[i],b[j]);
 printf(",");
 }
 }
 printf("}");
}
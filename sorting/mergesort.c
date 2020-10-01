#include<stdio.h>
void algo_merge_sort(int val[],int counter1,int counter2);
void perfrom_merge(int val[],int counter11,int counter12,int counter22,int counter21);
int main()
{
int val[100],chk,counter1;
printf("Please enter the total count of the elements that you want to sort: \n");
scanf("%d",&chk);
printf("Please input the elements that has to be sorted:\n");
for(counter1=0;counter1<chk;counter1++)
scanf("%d",&val[counter1]);
algo_merge_sort(val,0,chk-1);
printf("\n Output generated after using quick sort \n");
for(counter1=0;counter1<chk;counter1++)
printf("%d ",val[counter1]);
return 0;
}
void algo_merge_sort(int val[],int counter1,int counter2)
{
int mid;
if(counter1<counter2)
{
mid=(counter1+counter2)/2;
algo_merge_sort(val,counter1,mid);
algo_merge_sort(val,mid+1,counter2);
perfrom_merge(val,counter1,mid,mid+1,counter2);
}
}
void perfrom_merge(int val[],int counter11,int counter12,int counter22,int counter21)
{
int temp_val[50];
int c1,c2,c3;
c1=counter11;
c2=counter22;
c3=0;
while(c1<=counter12 && c2<=counter21)
{
if(val[c1]<val[c2])
temp_val[c3++]=val[c1++];
else
temp_val[c3++]=val[c2++];
}
while(c1<=counter12)
temp_val[c3++]=val[c1++];
while(c2<=counter21)
temp_val[c3++]=val[c2++];
for(c1=counter11,c2=0;c1<=counter21;c1++,c2++)
val[c1]=temp_val[c2];
}

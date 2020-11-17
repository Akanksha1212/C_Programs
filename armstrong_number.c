#include <stdio.h>

int main() 
{
  int num,l,arms=0;
  scanf("%d",&num);
  int tmp=num;
  for(l=0;tmp>0;tmp/=10,l++);
    tmp=num;
  for(int c=0;c<l;c++,tmp/=10)
    arms+=pow(tmp%10,l);

  if(num==arms)
  printf("Armstrong Number");
  else
  printf("Not an armstrong number");
return 0;
}


#include <stdio.h>

int hanoi(int n){
  if(n==0)
    return 0;
  else if(n==1)
    return 1;
  else
    return 2*hanoi(n-1)+1;
}

int main(){
  int n,i=1;
  while(scanf("%d",&n))
    if(n!=0){
      printf("Teste %d\n%d\n",i,hanoi(n));
      i++;
    }
    else
      break;
  return 0;
}

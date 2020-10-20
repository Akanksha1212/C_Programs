#include <stdio.h>
#include <stdlib.h>


void soma(int *v, int tam, int max){
  int i,soma=0,count=0,x=0;
  for(i=0; i<tam; i++){
    soma+=v[i];
    if(soma>max){
      v[x] = v[i];
      x++;
      soma=0;
      count++;
    }
  }
  for(i=count-1; i>=0; i--)
    printf("%d\n",v[i]);
}

int main(){
  int x, *v, max, i=0;
  scanf("%d",&x);
  v = malloc(sizeof(int));
  v[0] = x;
  i++;
  do{
    v = realloc(v,(i+1)*sizeof(int));
    scanf("%d",&x);
    v[i] = x;
    i++;
  }while(x!=0);
  scanf("%d",&max);
  soma(v,i,max);
  return 0;
}

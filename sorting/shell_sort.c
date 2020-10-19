#include <stdio.h>
#include <stdlib.h>

#define key(a) (a)
#define less(x,y) (key(x)<key(y))
#define exch(x,y){ int t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

void insertionsortH(int *vetor, int l, int r, int h) {
	for(int i=l+h; i<=r;i++){
		int j=i, tmp=vetor[i];
		
		while(j>=l+h && less(tmp,vetor[j-h])){
			vetor[j]=vetor[j-h];
			j-=h;
		}
		
		vetor[j]=tmp;
	}
}

void shellsort(int *vetor, int l, int r) {
	int h;
	
	for(h=1;h<=(r-l)/9;h=3*h+1);
	for(;h>0;h/=3){
		insertionsortH(vetor,l,r,h);
	}
}

int main() {
	int *vetor, n,i;
	
	scanf(" %d",&n);
	
	vetor = (int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++){
		scanf(" %d", &vetor[i]);
	}
	
	shellsort(vetor,0,n-1);
	
  printf("%d", vetor[0]);

	for(i=1;i<n;i++){
		printf(" %d", vetor[i]);
	}
	
	printf("\n");

    return 0;
}

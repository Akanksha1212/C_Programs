//C program to compute upto 5000 factorial


#include <stdio.h>

int main(){
int a[16500];
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		for(int i=0; i<16500; i++)
			a[i]=0;
		a[0]=1;
		int m, c;
		for(int i=2; i<=n; i++){
			c=0;
			for(int j=0; j<16500; j++){
				 m= i*a[j];
				 m+= c;
				 a[j]=m%10;
				 c=m/10;
			}
		}
		int f=0, i=16500-1;
		while(a[i]==0 && i>=0){
			i--;
		}
		while(i>=0){
			printf("%d", a[i]);
			i--;
		}
		printf("\n");
	}
}


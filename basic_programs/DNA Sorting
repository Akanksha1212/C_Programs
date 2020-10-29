#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int x, i,j,k,l,a,b,cont[100],ze,vitor;
    char DNA[100][100];
    scanf("%d",&x);
    for(a=0;a<x;a++){
        scanf("%d %d", &k,&l);
        for(i=0;i<l;i++){
            scanf(" %s",DNA[i]);
        }
        for(i=0;i<l;i++){
            cont[i]=0;
            for(j=0;j<k;j++){
                for(b=j+1;b<k;b++){
                    if(DNA[i][b]<DNA[i][j]){
                        cont[i]++;
                    }
                }
            }
        }
        for(i=0;i<l;i++){
            ze=1000;
            for(j=0;j<l;j++){
                if(cont[j]<ze && cont[j]!=-1){
                    ze=cont[j];
                    vitor=j;
                }
            }
            printf("%s\n",DNA[vitor]);
            cont[vitor]=-1;
            vitor=0;
        }
        printf("\n");
    }
	return 0;
}

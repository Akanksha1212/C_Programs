#include<stdio.h>
#include<stdlib.h>
int main(){

	int length, i, k, num[1000], aux;
	char order;

	printf("What is the length of your sequence?\nType here: ");
	scanf("%d", &length);
	printf("Type the numbers that you want to order:\n");
	for(i=0; i<length; i++){
		scanf("%d", &num[i]);
	}
	printf("You want to put in which ordination: crescent(C) or decrescent(D)? ");
	scanf(" %c", &order);

	if(order=='C' || order=='c'){
		for(i=0; i<length; i++){
			for(k=0; k<length; k++){
				if(num[k]>num[k+1]){
					aux=num[k];
					num[k]=num[k+1];
					num[k+1]=aux;
				}
			}
		}
		printf("Your sequence in crescent ordination is: ");
		for(i=0; i<length; i++){
			printf("%d a ", num[i]);
		}
	}else if(order=='D' || order=='d'){
		for(i=0; i<length; i++){
			for(k=0; k<length-1; k++){
				if(num[k]<num[k+1]){
					aux=num[k];
					num[k]=num[k+1];
					num[k+1]=aux;
				}
			}
		}
		printf("Your sequence in decrescent ordination is: ");
		for(i=0; i<length; i++){
			printf("%d ", num[i]);
		}
	}

	return 0;
}

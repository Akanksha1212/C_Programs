
#include<stdio.h>

int main(){

	int row,col,N; float ratio;
    printf("No of equations to solve:\n");
    scanf("%d",&N);
    
    float arr2[1000][1000];
    
        for(row=0;row<N;row++){
            for(col=0;col<N+1;col++){
                scanf("%4f",&arr2[row][col]);
        }

  }
	for(col=0;col<N;col++){

		for(row=0;row<N;row++){

			if(row!=col){

               if(arr2[col][col]==0){
                    for(int c=0;c<N+1;c++){
                        int temp;
                        temp=arr2[col][c];
                        arr2[col][c]=arr2[col+1][c];    //Swaps rows if ratio=0.
                        arr2[col+1][c]=temp;
                    }
            }

			ratio=arr2[row][col]/arr2[col][col];
			
			for(int i=0;i<N+1;i++){
			arr2[row][i]=arr2[row][i]-arr2[col][i]*ratio;
				}
			}			
		}
			
	}
	
 
    for(int k=0;k<N;k++){
        	printf("%4f\n",arr2[k][N]/arr2[k][k]);
}
 
	return 0;
}

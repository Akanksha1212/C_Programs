#include <stdio.h>

int main(void) {
	long long int a1,a2,a5,a10,a20,a50,a100,a200,a500,a2000,n1,n2,n5,n10,n20,n50,n100,n200,n500,n2000,N,T,i=0;
	    
// input total amount
		printf("ENTER THE AMOUNT\n");
	    scanf("%lld", &N);
	    
	    n2000=N/2000;//number of 2000 rupee note
	    a2000=N%2000;
	    
	    n500=a2000/500;///number of 500 rupee note
	    a500=a2000%500;
	    
	    n200=a500/200;//number of 200 rupee note
	    a200=a500%200;
	    
	    n100=a200/100;//number of 100 rupee note
	    a100=a200%100;
	    
	    n50=a100/50;//number of 50 rupee note
	    a50=a100%50;
	    
	    n20=a50/20;//number of 20 rupee note
	    a20=a50%20;
	    
	    n10=a20/10;//number of 10 rupee note
	    a10=a20%10;

	    n5=a10/5;//number of 5 rupee note
	    a5=a10%5;
	    
	    n2=a5/2;//number of 2 rupee note
	    a2=a5%2;
	    
	    n1=a2;//number of 1 rupee note

	  
	    
	    a1=n2000+n500+n200+n100+n50+n20+n10+n5+n2+n1;//total number of notes


	    printf("MINIMUM AMOUNT OF NOTES REQUIRED ARE(IS) %lld\n", a1);
	    	printf( "2000 RUPEE NOTE(S)  : %lld\n",n2000 );
	    	printf( " 500 RUPEE NOTE(S)  : %lld\n",n500 );
		 	printf( " 200 RUPEE NOTE(S)  : %lld\n",n200 );
	 		printf( " 100 RUPEE NOTE(S)  : %lld\n",n100 );
	 		printf( "  50 RUPEE NOTE(S)  : %lld\n",n50 );
			printf( "  20 RUPEE NOTE(S)  : %lld\n",n20);
	 		printf( "  10 RUPEE NOTE(S)  : %lld\n",n10 );
	  		printf( "   5 RUPEE NOTE(S)  : %lld\n",n5 );
	 		printf( "   2 RUPEE NOTE(S)  : %lld\n",n2 );
	 		printf( "   1 RUPEE NOTE(S)  : %lld\n",n1 );
	
	
	
	    
	    
	   
	
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int main() {
	long long *a, i, n, count = 0, num, size = 1024, sum; 
	struct timeval tv1, tv2;
	time_t t1,t2,time_taken;
	int j ,temp = 0;
	a = (long long *)malloc(sizeof(long long) * size);
	/* Do "man scanf". Scanf returns -1 when there is "no input" 
	 * To tell scanf that there is no input, you can press "control-d" 
	 * in stdio.h EOF is #defined to be -1 */
	
	/*this code is for dynamic memry allocation*/
	while(scanf("%lld", &num) != EOF) {
		a[count] = num;
		count++;
		if(count == size) {
			size *= 2;
			a = (long long *)realloc(a, sizeof(long long) * size);
			if(a == NULL) {
				printf("Failed for %lld\n", size);
				exit(1);
			}
		}
	}
	tv1.tv_usec = gettimeofday(&tv1,NULL);	
	for(i = 0; i < count; i++) {
		for(j = 0; j < count-1;j++ ){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
		
	tv2.tv_usec = gettimeofday(&tv2,NULL);
	time_taken = ( ( tv2.tv_sec * 1000000 + tv2.tv_usec) - ( tv1.tv_sec * 1000000 + tv1.tv_usec) ) / 1000000;	
	printf("\nsorted nums :-\n");
	 for(i = 0; i < count; i++)
		printf("%lld  ",a[i]);
	printf("\n");
	printf("\ntime taken = %ld\n",time_taken);
	free(a);
	return 0;
}


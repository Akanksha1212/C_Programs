#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//The program uses the rand() function to compute the estimation of Pi using the Monte Carlo method. The underlying principle of the program is to randomly generate some points in a square, and to keep a count of the number of points that are inside a circle inscribed in the square. Using basic mathematical extrapolation, an estimate of Pi can be found.

int main(){

	int  n=100000,i,inside_circ=0;		//n is number of trials, inside_ circ is a boolean to check if the point is inside the circle

	float a=10.0, x,y;			//a, which is the side length of the square, can be changed

	srand(time(0));				//this generates a seed for the rand() function according to the time at which this program is executed

	for(i=0;i<n;i++){			//loop to generate n number of trials
	
		x = a*(float)rand()/(float)RAND_MAX - a/2;	//rand()/RAND_MAX results in a random float between 0 and 1

		y = a*(float)rand()/(float)RAND_MAX - a/2;
	
		if(x*x + y*y <= a*a/4){
			inside_circ++;			//condition to check if the point is inside or outside the circle
		}
	}

	printf("The value of pi is %f \n", 4.0*(float)inside_circ/(float)i);

	return 0;
}

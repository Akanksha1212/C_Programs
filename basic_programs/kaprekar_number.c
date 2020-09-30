/*// A kaprekar number is a number in base 10 whose square can be split such that the the sum of those numbers
add up to the original number for eg : (45)^2 = 2025 => 20+25=45 */

    # include <stdio.h>  
    # include <string.h>  
    # include <stdbool.h>  
    # include <math.h>  
    bool iskaprekarnum(int n)   
        {   
            if (n == 1)   // If the number passed is 1 then it is also considered to be a kaprekar number
               return true;   
            int square_number = n * n;   // Finding the square
            int count_digits = 0;   //This will be the counter variable for the number of digits in the number
            while (square_number != 0)   
            {   
                count_digits++;   
                square_number /= 10;   
            }   
            square_number = n*n;   // Recalculating square as it was changed in the above while loop
            for (int r_digits=1; r_digits<count_digits; r_digits++)   
            {   
                 int equal_parts = (int) pow(10, r_digits);   //Type casting to integer value 
                if (equal_parts == n)   
                    continue;   
                 int sum = square_number/equal_parts + square_number % equal_parts;   
                 if (sum == n)   
                   return true;   
            }   
            return false;   
        }    
      
      
    int main()  
    {   int num;
        printf("Enter the number till which you want to print the kaprekar numbers");
        scanf("%d",&num);
        for (int i=1; i<num; i++) {  
        if (iskaprekarnum(i)) //Checking if the number is a kaprekar number or not   
        printf("%d  ",i );   
        }  
    return 0;  
    }  
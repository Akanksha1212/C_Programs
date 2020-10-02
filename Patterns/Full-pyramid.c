//imports
#include <stdio.h>

//main function
int main()
{
    printf("Enter number of rows: ");
    scanf("%d",&rows);
    int px=rows; //left print control
    int py=rows; //right print control
    for(int i=1; i<=rows; ++i)
    {
        for( int j=1; j<rows*2; j++)
        {
            if(j>=px &&j<=py)
                printf("*")
            else
                printf(" ")
        }
        px--;
        py++;
        
        printf("\n");
    }
    
    return 0;
}

#include<stdio.h>
main()
{
    if('A' < 'a')
    {
        printf("Hii");
    }
    else
    {
        printf("Hello");
    }
}

//OPTIONS
//A. Hii
//B. Hello
//C. COMPILER ERROR


//CORRECT OPTION- Hii
//This is because ASCII value of A(65) and a(97) will be compared
//since 65<97 
//if condition will be executed
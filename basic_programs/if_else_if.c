#include <stdio.h>

int main()
{
	int age;
	printf("Enter age : ");
	scanf("%d", &age);
	if (age < 18)
		printf("You aren't even old enough to vote!!");
	else if (age >= 18 && age < 25)
		printf("Hope you are preparing well for a job!!");
	else if (age >= 25 && age < 32)
		printf("Are you searching for a job too??");
	else
		printf("Hope you are settled");

	return 0;
}

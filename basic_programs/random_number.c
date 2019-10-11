#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		/* gerando valores aleatórios entre zero e 100 */
		printf("%d ", rand() % 100);
	}
	printf("\n");
	return 0;
}

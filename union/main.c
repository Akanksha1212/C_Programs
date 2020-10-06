	#include"header.h"

	int main()
	{
		simpleUnion();
		//notSoSimpleUnion();
		
		return 0;
	}

	void simpleUnion()
	{
		union A unionA;
		unionA.a = 'a';
		printf("a = %c\n", unionA.a);
		unionA.b = 'b';
		printf("b = %c\n", unionA.b);
		unionA.c = 'c';
		printf("c = %c\n", unionA.c);
		unionA.d = 'd';
		printf("d = %c\n", unionA.d);
		printf("\n");
		printf("a = %c\n", unionA.a);
		printf("b = %c\n", unionA.b);
		printf("c = %c\n", unionA.c);
		printf("d = %c\n", unionA.d);
		printf("The size of 4 char union is %d bytes.\n", sizeof unionA);
	}

	void notSoSimpleUnion()
	{
		int i;
		union B unionB;
		unionB.symbol = 's';
		printf("symbol = %c\n", unionB.symbol);
		unionB.number = 5;
		printf("number = %d\n", unionB.number);
		for(i = 0; i < 3; ++i)
			unionB.numbers[i] = (float)i+1;
		for(i = 0; i < 3; ++i)
			printf("numbers[%d] = %.2f, ", i, unionB.numbers[i]);

		printf("\n");
		printf("\n");
		printf("symbol = %c\n", unionB.symbol);
		printf("number = %d\n", unionB.number);
		for(i = 0; i < 3; ++i)
			printf("numbers[%d] = %.2f, ", i, unionB.numbers[i]);
		printf("\n");
		printf("The size of union of 1 char, 1 int and array of 3 floats is %d bytes.\n", sizeof unionB);
	}
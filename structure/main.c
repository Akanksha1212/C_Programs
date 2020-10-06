#include"header.h";

int main()
{
	/*	Allocate memory for our structure.
		On some compilers you can skip this and the declaration will look like:
		    struct Employee* worker;
		Anyway, it is good to know how the memory is allocated and freed.
	*/
    struct Employee* worker = (struct Employee*)malloc(sizeof(struct Employee));
	printf("The size of struct A is %d\n", sizeof(struct A));
	printf("The size of struct B is %d\n", sizeof(struct B));
    inputEmployee(worker);
    outputEmployee(*worker);
	free(worker);	// release the memory from our structure, as we don't need it anymore
	worker = '\0';	// set the pointer to NULL to avoid misuse of freed memory

    return 0;
}

void inputEmployee(struct Employee* worker)
{
    char name[30];
    printf("==== Input Employee information ====\n");
    printf("Name = ");
    gets(name);
    strcpy(worker->name, name);
	inputAddress(&worker->address);
    printf("Age = ");
    scanf("%d", &worker->age);
    printf("..... End of input .....\n");
}

void inputAddress(struct Address* address)
{
    printf("Country = ");
	gets(address->country);
    printf("City = ");
	gets(address->city);
    printf("Street = ");
	gets(address->street);
    printf("additional address information: ");
	gets(address->addressField);
}

void outputEmployee(struct Employee worker)
{
    printf("==== Employee ====\n");
    printf("Name = %s\n", worker.name);
    printf("Age = %d\n", worker.age);
	outputAddress(worker.address);
    printf("..... End of Employee .....\n");
}

void outputAddress(struct Address address)
{
	printf("%s, %s, %s, %s\n", address.addressField, address.street, address.city, address.country);
}

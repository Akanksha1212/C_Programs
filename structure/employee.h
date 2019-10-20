struct Employee
{
	char address[100];
	char name[30];
	int age;
};
int main()
{
	struct Employee e;
	scanf("%d",&e.age);
	scanf("%s",&e.name);
	scanf("%s",&e.address);
	return 0;
}

struct Address
{
	char country[30];
	char city[30];
	char street[30];
	char addressField[30];
};
int main()
{
	struct Address a;
	scanf("%s%s%s%s",&a.country,&a.city,&a.street,&a.addressField);
	return 0;
}

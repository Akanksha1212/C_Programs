#include <iostream>

using namespace std;

int main()
{
    int c = 0;
    char input[101];
    cout << "Enter string to be mocked: ";
    cin.getline(input, 101);
    
    for (int i = 0; input[i] != '\0'; ++i)
    {
        c += (int) input[i];
        if (input[i] == ' '){}
        else if (c % 2 == 0)
            input[i] = input[i] ^= 32;  //flip character case
    }
    
    cout << "Your mocking string is: " << input;
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    char line[150];
    int vowel, consonant, digit, space;
    vowel =  consonant = digit = space = 0;
    cout << "Enter your string: ";
    cin.getline(line, 150);          //using getline to input string from user
    for(int i = 0; line[i]!='\0'; i++)
    {
        if(line[i]=='a' || line[i]=='e' || line[i]=='i' ||
           line[i]=='o' || line[i]=='u' || line[i]=='A' ||
           line[i]=='E' || line[i]=='I' || line[i]=='O' ||
           line[i]=='U')
        {
            vowel++;
        }
        else if((line[i]>='a'&& line[i]<='z') || (line[i]>='A'&& line[i]<='Z'))
        {
            consonant++;
        }
        else if(line[i]>='0' && line[i]<='9')
        {
            digit++;
        }
        else if (line[i]==' ')
        {
            space++;
        }
    }
    cout << "Number of Vowels: " << vowel << endl;
    cout << "Number of Consonants: " << consonant << endl;
    cout << "Number of Digits: " << digit << endl;
    cout << "Nuber of spaces: " << space << endl;
    return 0;
}

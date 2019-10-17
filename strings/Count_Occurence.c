/*input
*/

#include<bits/stdc++.h>
#define ll long long int
#define nl cout<<"\n"
using namespace std;


int main()
{
  // only for lower case alphabet
   string s = "aaabbcc";
   int occur[26] = {0};
   for (int i = 0; i < s.length(); i++) {
    occur[s[i] - 'a']++;
   }
   char c = 'a';
   for (int i = 0; i < 26; i++) {
    cout << c << " occurs " << occur[i] << " times\n";
    c++;
   }
   return 0;
}



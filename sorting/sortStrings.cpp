/*

Given a list of 'n' strings S0,S1,S2,……,Sn-1, each consisting of digits and spaces,
the number of spaces is the same for each entry, the goal is to implement a variation of a sort command.
None of the strings contains consecutive spaces. Also, no string starts with a space nor ends with it.
Spaces are used to divide string into columns, which can be used as keys in comparisons.

The program has to support the required parameters:

key: integer denoting the column used as a key in comparisons. The left-most column is denoted by 1.

reversed: boolean variable indicating whether to reverse the result of comparisons.

comparison-type: either lexicographic or numeric.
Lexicographic means that we use Lexicographical order where for example (122 < 13).
Numeric means that we compare the strings by their numerical values, so (13 < 122). 
If the comparison type is 'numeric' and numeric values of keys of Si and Sj are equal for i < j,
then Si is considered strictly smaller than Sj because it comes first.

Input Format
In the first line, there is a single integer 'n' denoting the number of strings to sort.
In the i-th of the following n lines there is a string Si. In the last line,
there are 3 space-separated values, denoting the values of variables 'key','reversed' , comparison-type.

Constraints
1 <= n <= 10^5
1 <= |Si| <= 50
1 <= key <= number of spaces in each string + 1

reversed = { true or false }

comparison-type = {lexicographical , numeric }

None of the strings contains consecutive spaces.

No string starts with a space nor ends with it.

All column values in all the strings are unique.

Output Format
Print exactly n lines. In the i-th of them, print the i-th string in the resulting order.

Sample Input
3
92 022
82 12
77 13
2 false numeric

Sample Output
82 12
77 13
92 022

Explanation
The key for ordering is 2, reversal is false and ordering is numeric.
Therefore, the keys 022, 12 and 13 should be ordered as 12, 13 and 022.
Therefore, the final output is 82 12, 77 13 and 92 022.

*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string extractStringAtKey(string str, int key){
    char *s = strtok((char *)str.c_str(), " ");
    while(key > 1){
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

int convertToInt(string s){
    int ans = 0;
    int p = 1;
    for(int i = s.length()-1; i >= 0; i--){
        ans = ans + ((s[i] - '0')*p);
        p = p * 10;
    }
    return ans;
}

bool numericCompare(pair<string,string> s1, pair<string,string> s2){
    string k1, k2;
    k1 = s1.second;
    k2 = s2.second;

    return convertToInt(k1) < convertToInt(k2);
}

bool lexicoCompare(pair<string,string> s1, pair<string,string> s2){
    string k1, k2;
    k1 = s1.second;
    k2 = s2.second;

    return k1 < k2;
}

int main(){
    int n;
    cin >> n;
    cin.get();

    string a[100];
    for(int i = 0; i < n; i++){
        getline(cin, a[i]);
    }

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    pair<string,string> strPair[100];

    for(int i = 0; i < n; i++){
        strPair[i].first = a[i];
        strPair[i].second = extractStringAtKey(a[i], key);
    }

    if(ordering == "numeric"){
        sort(strPair, strPair + n, numericCompare);
    } else {
        sort(strPair, strPair + n, lexicoCompare);
    }

    if(reversal == "true"){
        for(int i = 0; i < n/2; i++){
            swap(strPair[i], strPair[n - i - 1]);
        }
    }

    for(int i = 0; i < n; i++){
        cout << strPair[i].first << endl;
    }

    return 0;

}

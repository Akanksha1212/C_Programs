/*
 * run with at least c++11 version
 * g++ -std=c++11 check_anagram.cpp
 * ./a.out (and enter 2 strings for anagram checking)
 *
 * */
#include <bits/stdc++.h>
using namespace std;

bool check(string& s1, string& s2)
{
    if(s1.size() != s2.size())
    {
        return false;
    }

    map<char, int> char_map;
    for(auto x : s1)
    {
        char_map[tolower(x)]++;
    }

    for(auto x : s2)
    {
        char_map[tolower(x)]--;
        if(char_map[tolower(x)] == 0)
        {
            char_map.erase(tolower(x));
        }
    }

    return char_map.size() == 0;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s1, s2;
    cin >> s1 >> s2;
    cout << check(s1, s2);

    return 0;
}


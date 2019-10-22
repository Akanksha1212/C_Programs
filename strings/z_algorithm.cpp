/*
    Z Algorihtm: Linear Time Pattern Searching Algorithm
    This algorithm finds all occurences of a pattern in a text in linear time.

    Time Complexity: O(n + m)
    Space Complexity: O(n)
*/

#include <string.h>
#include <iostream>
#include <vector>

std::vector <int> z_function(std::string &str) {
    int n = str.size();
    int l = 0, r = 0;
    std::vector <int> z(n, 0);

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = std::min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int main()
{
    std::string str;
    std::cin >> str;
    std::vector <int> vec = z_function(str);
    for (auto it : vec) {
        std::cout << it << " ";
    }

    std::cout << std::endl;
    return 0;
}
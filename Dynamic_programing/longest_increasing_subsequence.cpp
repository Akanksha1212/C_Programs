#include <bits/stdc++.h>
using namespace std;

int lis(vector <int> &arr)
{
    int n = arr.size();

    int lis[n]; lis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;

        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
    }

    return *max_element(lis, lis + n);
}

int main()
{
    cout << "Array: ";

    vector <int> arr;
    int val;

    while (cin >> val)
        arr.push_back(val);

    cout << "Length: " << lis(arr) << "\n";

    return 0;
}
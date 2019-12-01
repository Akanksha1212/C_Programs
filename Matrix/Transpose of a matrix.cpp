
//imports
#include <iostream>
using namespace std;

//main function
int main()
{
    int arr[50][50], trans[50][50], r, c, i, j; //data memory allocation
    cout << "Enter rows and columns of matrix : ";
    cin >> r >> c;
    // Entering the elements in the matrix by user.
    cout << endl << "Enter elements of matrix: " << endl;
    for(i = 0; i < r; ++i)
    for(j = 0; j < c; ++j)
    {
        cout << "Enter elements for index- " << i + 1 << j + 1 << ": ";
        cin >> arr[i][j];
    }
    // Displaying the matrix.
    cout << endl << "Entered Matrix: " << endl;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout << " " << arr[i][j];
            if(j == c - 1)
                cout << endl;
        }
    // Finding transpose of matrix entered by user and then storing it in matrix trans[][].
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            trans[j][i]=arr[i][j];
        }
    // Displaying the transpose.
    cout << endl << "Transpose of the entered Matrix is : " << endl;
    for(i = 0; i < c; ++i)
        for(j = 0; j < r; ++j)
        {
            cout << " " << trans[i][j];
            if(j == r - 1)
                cout << endl;
        }
    return 0;
}

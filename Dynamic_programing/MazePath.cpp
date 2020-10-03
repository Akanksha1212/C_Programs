#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vs vector<string>
#define vvs vector<vs>
using namespace std;
//-----------------MAZE PATH ---------------------------------
int mazePath_memo(int sr, int sc, int er, int ec, vector<vector<int>> &dp) //move along vertical, horizontal and diagonal
{
    // function_call++;
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }
    int count = 0;
    // cout<<count;

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    if (sc + 1 <= ec)
    {
        count += mazePath_memo(sr, sc + 1, er, ec, dp);
    }
    if (sr + 1 <= er)
    {
        count += mazePath_memo(sr + 1, sc, er, ec, dp);
    }
    if (sr + 1 <= er && sc + 1 <= ec)
    {
        count += mazePath_memo(sr + 1, sc + 1, er, ec, dp);
    }
    dp[sr][sc] = count;

    return count;
}

int mazePath_tab(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    dp[er][ec] = 1;
    for (int i = er - 1; i >= 0; i--)
    {
        dp[i][ec] = dp[i + 1][ec];
    }
    for (int i = ec - 1; i >= 0; i--)
    {
        dp[er][i] = dp[er][i + 1];
    }

    for (int i = er - 1; i >= 0; i--)
    {
        for (int j = ec - 1; j >= 0; j--)
        {
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }
    return dp[0][0];
}
int main()
{
    vector<vector<int>> dp(5,vector<int>(5,-1));
    cout<<mazePath_memo(0,0,n-1,m-1,dp)<<endl;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<mazePath_tab(0,0,4,5,dp)<<endl;
    cout<<mazePath_memo(0,0,n-1,m-1,dp)<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int a[1000][1000];
int m,n;

void fill(int x,int y,int k, int prev){
    if(x>=n || x<0 || y>=m || y<0)
        return;
    if(a[x][y] != prev)
        return;
    if(a[x][y] == k){
        return;
    }

    a[x][y] = k;

    fill(x+1, y, k, prev);
    fill(x-1, y, k, prev);
    fill(x, y+1, k, prev);
    fill(x, y-1, k, prev);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t, i, j, k, p, q, r, x, y, u, v;
    cin>>t;
    while(t--){
      cin>>n>>m;
      for(i=0;i<n;i++){
        for(j=0;j<m;j++){
          cin>>a[i][j];
        }
      }
      cin>>x>>y>>k;
      fill(x, y, k, a[x][y]);
      for(i=0;i<n;i++){
        for(j=0;j<m;j++){
          cout<<a[i][j]<<" ";
        }
      }
      cout<<"\n";
    }
    return 0;
}
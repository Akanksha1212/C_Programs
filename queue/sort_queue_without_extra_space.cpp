#include<bits/stdc++.h>
using namespace std;
int minIndex(queue<int> &q,int sortedIndex){
    int minval=INT_MAX,min=-1;
    for(int i=0;i<q.size();i++){
        int top=q.front();
        q.pop();
        if(minval>top && i<=sortedIndex){
            min=i;
            minval=top;
        //     printf("\nin function loopmin element: %d min index= %d",minval,min);
        }
        q.push(top);
    }
  //  printf("\n in function min index: %d",min);
    return min;
}
void addMinToRear(queue<int> &q,int minIndex){
    int minElement,n=q.size();
     for(int i=0;i<n;i++){
            int top=q.front();
            q.pop();
        if (i != minIndex)
            q.push(top);
        else
            minElement =top;
     }
     q.push(minElement);
}
void sortQueue(queue<int> &q,int n){
    printf("sort queue function\n");
    for(int i=n-1;i>=0;i--){
        int minindex;
            // printf("print min index=%d",minindex);
        minindex=minIndex(q,i);
    //    printf("\nin  sorting print min index=%d\n",minindex);
        addMinToRear(q,minindex);
    }
}
int main(){
    int size;
    scanf("%d",&size);
    queue<int> q;
    while(--size>=0){
            int x;
        scanf("%d",&x);
    q.push(x);
    }
  //  printQueue(q,size);
    sortQueue(q,q.size());
  //  printQueue(q,size);
  while(!q.empty()){
        int top=q.front();
        printf(" %d ",top);
        q.pop();
     }
     return 0;
}

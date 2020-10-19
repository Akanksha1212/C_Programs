#include<stdio.h>
#include<stdlib.h>

#define key(a) (a)
#define less(x,y) (key(x)<key(y))
#define exch(x,y){ int t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

int part(int *v, int l, int r){
    int c = v[r];
    int j=l, k;
    for(k=l;k<r;k++){
        if(less(v[k],c)){
            exch(v[k],v[j]);
            j++;
        }
    }
    exch(v[k],v[j]);
    return j;
}

void quicksort(int *v, int l, int r){
    int j;

    if(r<=l)return;
    
    cmpexch(v[(l+r)/2],v[r]);
    cmpexch(v[l],v[(l+r)/2]);
    cmpexch(v[r],v[(l+r)/2]);

    j=part(v,l,r);
    quicksort(v,l,j-1);
    quicksort(v,j+1,r);
}
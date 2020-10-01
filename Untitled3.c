#include<stdio.h>
#include<conio.h>
int partition(int arr[],int start,int end){
    int pivot=arr[end],i,j=start-1,temp;
    for(i=start;i<=end-1;i++){
        if(arr[i]<=pivot){
            j++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    j++;
    temp=arr[j];
    arr[j]=pivot;
    arr[end]=temp;
    return j;
}
void quick_sort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int pi=partition(arr,start,end);
    quick_sort(arr,start,pi-1);
    quick_sort(arr,pi+1,end);

}
main(){
    int arr[100];
    int n,i;
    printf("Enter the size of the list\n");
    scanf("%d",&n);
    printf("Enter the elements of the list\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quick_sort(arr,0,n-1);
    printf("\n");
    for(i=0;i<n;i++){
       printf("%d ",arr[i]);
    }
    printf("\n");

}


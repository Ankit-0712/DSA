#include<stdio.h>
#include<stdlib.h>

int partition(int arr[], int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while(start< end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;
}

void QuickSort(int arr[], int lb, int ub){
    if(lb < ub){
        int loc = partition(arr,lb,ub);
        QuickSort(arr,lb,loc-1);
        QuickSort(arr,loc+1, ub);
    }
}

void dislpay(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[] = {7,4,10,8,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,n-1);
    dislpay(arr,n);

    return 0 ;
}
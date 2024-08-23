#include<stdio.h>
#include<stdlib.h>

void mergesort(int arr[], int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergesort(arr, lb, mid);
        mergesort(arr,mid+1, ub);
        merge(arr,lb,mid,ub)
    }
}

void merge(int arr[], int lb, int mid, int ub){
    int i=lb, j=mid+1,k = 0;
    int temp[ub-lb+1];
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++]
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]= arr[i++];
    }

    while(j<=ub){
        temp[k++] = arr[j++];
    }

    for(int i=lb, k=0;i<=ub;i++,k++){
        arr[i] = temp[k];
    }

}
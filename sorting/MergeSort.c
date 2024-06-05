#include<stdio.h>
#include<stdlib.h>
void MergeSort(int arr[], int lb, int ub);
void merge(int arr[], int mid, int lb, int ub);
void display(int arr[], int n);

void MergeSort(int arr[], int lb, int ub){
    if(lb < ub){
        int mid = (lb + ub)/2;
        MergeSort(arr,lb,mid);
        MergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void merge(int arr[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = 0;
    int temp[ub - lb + 1];

    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= ub) {
        temp[k++] = arr[j++];
    }

    for (i = lb, k = 0; i <= ub; i++, k++) {
        arr[i] = temp[k];
    }
} 

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {7,4,10,8,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,n-1);
    display(arr,n);

    return 0;
}
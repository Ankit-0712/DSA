#include<stdio.h>
#include<stdlib.h>

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]< arr[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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
    selectionSort(arr,n);
    display(arr,n);

    return 0;
}
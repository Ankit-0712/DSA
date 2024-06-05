#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[5] = {15,16,6,8,5};
    int n = sizeof(arr)/ sizeof(arr[0]);
    sort(arr,n);
    display(arr,n);

    return 0;
}
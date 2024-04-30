#include<stdio.h>
#include<stdlib.h>
void insert(int arr[], int val, int n);
void insert_at_pos(int arr[], int val, int pos, int n);
void delete(int arr[], int pos, int n);
void delete_at_end(int arr[], int n);
void insert(int arr[], int val, int n){
    int i;
    for(int i=0;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = val;
}
void insert_at_pos(int arr[],int val, int pos,int n){
    int i;
    for(int i=0;i<pos;i++){
        arr[i] = arr[i-1];
    }
    arr[i] = val;
}

void delete(int arr[],int pos,int n){
    for(int i=pos;i<n;i++){
        arr[i-1]=arr[i];

    }
    arr[n-1]= 0;
}

void delete_at_end(int arr[], int n){
    printf("The given element at end which is deleted is %d", arr[n-1]);
    arr[n-1]=0;

}
int main(){
    int arr[20], n,values,pos;
    printf("Enter the size of array");
    scanf("%d",&n);

    printf("Enter the values of array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i =0;i<n;i++){
        scanf("%d",arr[i]);
    }
    printf("Enter the position you want to insert in array");
    scanf("%d",&pos);

    printf("Enter the value you want to insert");
    scanf("%d", &values);

    insert_at_pos(arr,values,pos,n);
    delete_end(arr,n);

    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}
#include<stdio.h>
int main(){
    //1D
    int arr[10]={10,20,30,40,50};
    //printf("Array base address= %p",arr);
    //printf("\nfirst element address of an array= %p",&arr[0]);
    //printf("\nsecond element address of an array= %p",&arr[1]);
    //printf("\nsecond element  of an array= %d",*(&arr[0]+1));

    int(*ptr)[5];
    ptr = arr;
    printf("ptr = %u arr= %u",ptr,arr);
    
    
    printf("\nptr = %u arr = %u",ptr+1 , arr+1);

    

    return 0;
}
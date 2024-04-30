#include<stdio.h>
int main(){
int arr[3][4] ={
    {10,20,30,40},
    {50,60,70,80},
    {90,100,110,120},
};
int(*ptr)[4];
ptr = arr;
printf("%u",ptr);
printf("\n%d",*(*(ptr+1)+2));

    return 0;
}
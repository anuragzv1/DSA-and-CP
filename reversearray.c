#include<stdio.h>
int main(){
    int arr[]={2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i,j,temp;
    for(i=0,j=size-1;i<j;i++,j--){
        temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    for(i=0;i<size;i++){
        printf("%d,",arr[i]);
    }
}
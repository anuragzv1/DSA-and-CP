#include<stdio.h>

int main(){
    int a[]={1,2,3,4,5,7,8,9,10,12};
    int asize = sizeof(a) / sizeof(a[0]);
    int i,j;
    for(i=0;i<asize;i++){
        if(a[i]!=i+1){
            printf("%d \n",i+1);
            break;
        }
    }
}
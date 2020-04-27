#include<stdio.h>

int main(){
    int a[]={2,3,4,5,6};
    int b[]={5,0,9,2,4};
    int asize = sizeof(a) / sizeof(a[0]);
    int bsize = sizeof(b) / sizeof(b[0]);
    int i=0,j;
    for(i=0;i<asize;i++){
        for(j=0;j<bsize;j++){
            if(a[i]==b[j]){
                printf("%d,",a[i]);
            }
        }
    }
}
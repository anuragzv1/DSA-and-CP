#include<stdio.h>

int main(){
    int a[]={2,5,7,9,10};
    int b[]={3,4,6,8};
    int asize = sizeof(a) / sizeof(a[0]);
    int bsize = sizeof(b) / sizeof(b[0]);
    int c[asize+bsize];
    int i=0,j=0,k=0;
    while (i<asize && j<bsize)
    {
       if(a[i]<=b[j]){
           c[k++]=a[i++];
       }
       else if (a[i]>=b[j]){
           c[k++]=b[j++];
       }
    }
    for(;i<asize;i++){
        c[k++]=a[i];
    }
    for(;j<bsize;j++){
        c[k++]=b[j];
    }

    for(i=0;i<asize+bsize;i++){
        printf("%d,",c[i]);
    }
    
}
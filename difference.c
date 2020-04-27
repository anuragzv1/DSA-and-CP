#include<stdio.h>

int main(){
    int a[]={2,4,6,8,9};
    int b[]={4,6,8,1,3};
    int asize = sizeof(a) / sizeof(a[0]);
    int bsize = sizeof(b) / sizeof(b[0]);
    int c[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i,j,k=0,chk;
    for(i=0;i<asize;i++){
        chk=0;
        for(j=0;j<bsize;j++){
            if(a[i]==b[j]){
                chk=1;
            }
        }
        if(chk==0){
            printf("%d,",a[i]);
        }
    }

}
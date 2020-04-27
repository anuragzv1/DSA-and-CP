#include<stdio.h>

void main(){
    int n;
    scanf("%d",&n);
    int a=0;
    int b=1;
    printf("%d %d ",a,b);
    int c,i;
    
    for(i=2;i<n;i++){
        c=a+b;
        printf("%d ",c);
        a=b;
        b=c;
    }

}
#include<stdio.h>
static int p=1,f=1;
int taylor(int x, int n){
   if(n==0){
       return 1;
   }
   int r = taylor(x,n-1);
   p=p*x;
   f=f*n;
    return r + p/f;
}

void main(){
   printf("%d",taylor(5,5)) ;
    
}
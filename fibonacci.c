#include<stdio.h>

int main(){
int n;
scanf("%d",&n);
int arr[n],i;
arr[0]=0;
arr[1]=1;
printf("%d %d ",arr[0],arr[1]);
for(i=2;i<n;i++)
{
    arr[i]= arr[i-2]+arr[i-1];
    printf("%d ",arr[i]);
}
return 0;
}
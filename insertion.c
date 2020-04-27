#include<stdio.h>
void display(arr[],n){
int size = n;
printf("size = %d \n",size);
int i;
for(i=0;i<size;i++){
  printf("%d \n",arr[i]);
}
}
void insertionsort(int a[], int n){
  int i;
for(i=1;i<n;i++){
  int j = i-1;
  int x = a[i];
  while(j>-1 && a[j]>x){
    a[j+1]= a[j];
    j--;
  }
  a[j+1]=x;
}
display(a,n);
}
 int main(){
   int c[] = {5,6,7,5,4,3,6,6,7,5,3};
   insertionsort(c,11);
 }

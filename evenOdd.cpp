#include<iostream>
#define loop(var,start,end) for(int var=start;var<end;var++)
using namespace std;

void evenOdd(int arr[],int size){
    int i=0;
    int j= size-1;
    while(i<j){
        if(arr[i]%2==0){
            i++;
        }
        else if(arr[j]%2!=0){
            j--;
        }
        else{
            int temp =arr[i];
            arr[i]=arr[j];
            arr[j]= temp;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int * arr = new int[n];
    loop(i,0,n){
        cin>>arr[i];
    }
    
    evenOdd(arr,n);

    loop(i,0,n){
        cout<<arr[i]<<" ";
    }
    return 0;
}
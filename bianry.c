#include<stdio.h>

int binarySearch(int arr[], int l ,int h,int ele){
    
    if(l<=h){
        int mid =(l+h)/2;
        if(ele<arr[mid]){
           return binarySearch(arr,0,mid-1,ele);
        }
        else if (ele>arr[mid]){
            return binarySearch(arr,mid+1,h,ele);
        }
        else if (ele == arr[mid]){
            return(mid);
        }
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,6,7,8,11,34};
    int ele;
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Enter the element to be searched\n");
    scanf("%d",&ele);
    int val = binarySearch(arr,0,size-1,ele);
    if(val==-1){
        printf("Element not found\n");
    }
    else printf("Element found at %d \n",val+1);
    
}
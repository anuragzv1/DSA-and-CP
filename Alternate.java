import java.util.Scanner;

class Alternate{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr [] = new int[n];
        for(int i =0;i<n;i++){
            arr[i] = sc.nextInt();
        }

        rearrangeMyArray(arr);
        
        for(int i =0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    }

    private static void rotate(int [] arr,int startIndex , int endIndex){
        int ele = arr[endIndex];
        for(int i =endIndex;i>startIndex;i--){
            arr[i] = arr[i-1];
        }
        arr[startIndex] = ele;
    }

    private static void rearrangeMyArray(int[] arr) {
        int outOfPlaceIndex = -1;
        for(int i =0;i<arr.length;i++){
            if(outOfPlaceIndex >=0){
                if((arr[i]>=0 && arr[outOfPlaceIndex]<0) || (arr[i]<0 && arr[outOfPlaceIndex]>=0)){
                    rotate(arr , outOfPlaceIndex , i);
                    if (i - outOfPlaceIndex >= 2) 
                    outOfPlaceIndex+=2; 
                else
                    outOfPlaceIndex = -1; 
                }
            }

            if(outOfPlaceIndex ==-1){
                if(arr[i]>=0 && i%2==1) outOfPlaceIndex = i;
                if(arr[i]<0 && i%2==0)outOfPlaceIndex = i;
            }
        }
    }
}




/*abstract
#include<iostream>
using namespace std;

void rotate(int * arr,int startIndex , int endIndex){
        int ele = arr[endIndex];
        for(int i =endIndex;i>startIndex;i--){
            arr[i] = arr[i-1];
        }
        arr[startIndex] = ele;
    }

void rearrangeMyArray(int * arr , int n) {
        int outOfPlaceIndex = -1;
        for(int i =0;i<n;i++){
            if(outOfPlaceIndex >=0){
                if((arr[i]>=0 && arr[outOfPlaceIndex]<0) || (arr[i]<0 && arr[outOfPlaceIndex]>=0)){
                    rotate(arr , outOfPlaceIndex , i);
                    if (i - outOfPlaceIndex > 2) 
                    outOfPlaceIndex+=2; 
                else
                    outOfPlaceIndex = -1; 
                }
            }

            if(outOfPlaceIndex ==-1){
                if(arr[i]>=0 && i%2==1) outOfPlaceIndex = i;
                if(arr[i]<0 && i%2==0)outOfPlaceIndex = i;
            }
        }
    }


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i =0;i<n;i++)cin>>arr[i];
	    rearrangeMyArray(arr, n);
	    for(int i =0;i<n;i++)cout<<arr[i]<<" ";
	    cout<<endl;
	    
	}
	return 0;
}





*/
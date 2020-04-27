import java.util.Scanner;
public class HeapSort {

    private static void downHeapify(int arr[] , int parentIndex,int n){
        int leftChild = 2*parentIndex+1;
        int rightChild = 2*parentIndex+2;
        while(leftChild <n){
            int minValue = arr[parentIndex];
            int index = -1;
            if(arr[leftChild] < minValue){
                minValue = arr[leftChild];
                index = leftChild;
            }
            if(rightChild<n && arr[rightChild] <minValue){
                minValue = arr[rightChild];
                index = rightChild;
            }
            if(index ==-1)return;
            arr[index] = arr[parentIndex];
            arr[parentIndex]  = minValue;
        }
    }

    //by this process we design a heap using only downheapify operation and building heap takes O(n) time 
    // Overall complexity is Still O(log(n))

    public static void heapSort(int arr[]){
        int n = arr.length;
        for(int i =(n/2)-1; i>=0;i--){
            downHeapify(arr, i ,n);
        }

        for(int i =0;i<n;i++)System.out.print(arr[i]+" ");
        System.out.println();

        for(int i =1;i<n;i++){
            int temp = arr[0];
            arr[0] = arr[n-i];
            arr[n-i]  = temp;
            downHeapify( arr, 0,n-i);
        }
    }
   public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int arr [] = new int [n];
    for(int i  =0;i<n;i++){
        arr[i] = sc.nextInt();
    }
    heapSort(arr);
    for(int i = 0 ;i<n;i++){
        System.out.print(arr[i]+" ");
    }
   }
}
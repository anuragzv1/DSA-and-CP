import java.util.Scanner;
public class Solution {

    public static int partition(int [] arr , int low  , int high){
        int pivot = arr[high];
       // System.out.println("pivot element ="+pivot);
        int count=0;
        for(int i =low;i<high;i++){
            if(arr[i]<=pivot)count++;
        }
        int pos= low+count;
        //System.out.println("Position of pivot ="+pos);

        int temp = arr[pos];
        arr[pos]=arr[high];
        arr[high] = temp;

        // System.out.println("Element at pos ="+arr[pos]);
        // System.out.println("Array After Swapping");

        // for(int xx=low;xx<=high;xx++){
        //     System.out.print(arr[xx]+" ");
        // }

        int i = low;
        int j = high;
        while(i<pos  && j>pos){
            System.out.println("int loop");
            if(arr[i]>pivot && arr[j]<=pivot){
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
                j--;
            }
            else if(arr[i]<pivot)i++;
            else if(arr[j]>pivot)j--;
        }
        
        //System.out.println("Array after sorting right and left");
        // for(i=low;i<=high;i++){
        //     System.out.print(arr[i]+" ");
        // }
        
        return pos;



    }


    public static void myQuickSort(int [] arr , int low , int high){
        if(low< high){
            int pos = partition(arr , low ,high);
            myQuickSort(arr,low, pos-1);
            myQuickSort(arr,pos+1,high);
        }
    }


    public static void quickSort(int[] input) {
        myQuickSort(input , 0 , input.length-1);

    }
    static Scanner s = new Scanner(System.in);
	
	public static int[] takeInput(){
		int size = s.nextInt();
		int[] input = new int[size];
		for(int i = 0; i < size; i++){
			input[i] = s.nextInt();
		}
		return input;
	}
	
	public static void main(String[] args) {
		int[] input = takeInput();
		Solution.quickSort(input);
		for(int i = 0; i < input.length; i++) {
			System.out.print(input[i] + " ");
		}
	}

}
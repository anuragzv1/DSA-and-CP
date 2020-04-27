import java.util.Scanner;
class removeDupeLeet{


    public static void shift(int[] arr , int start , int x){
        for(int i =x;i<arr.length;i++){
            arr[start++] = arr[i];
        }
    }
    public static int removeDuplicates(int[] nums) {
        int i =0;
        while(i<nums.length){
            int ele = nums[i];
            int x = i+1;
            while(x<nums.length && nums[x]==ele){
                x++;
            }
            if(x==nums.length)return ++i;
            shift(nums , i+1 , x);
            i++;
            
        }
        return i;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int [n];
        for(int i =0;i<n;i++) arr[i]=sc.nextInt();
        sc.close();

        int newSize = removeDuplicates(arr);
        for(int i =0;i<newSize;i++){
            System.out.print(arr[i]+" ");
        }

    }
}
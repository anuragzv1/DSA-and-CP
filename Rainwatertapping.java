import java.util.Scanner;

public class Rainwatertapping {
    public static void main(String[] args) {
        Scanner sc = new  Scanner(System.in);
        int n  = sc.nextInt();
        int arr[] = new int [n];
        for(int i  = 0;i<n;i++){
            arr[i]= sc.nextInt();
        }
        int ans = calculateTrappedWater(arr , n);
        System.out.println(ans);
    }

    private static int calculateTrappedWater(int[] arr, int n) {
        int leftmax[] = new int [n];
        int rightmax[] = new int [n];

        rightmax[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--){
            rightmax[i] = Math.max(arr[i] , rightmax[i+1]);
        }

        leftmax[0] = arr[0];
        for(int i = 1;i<n;i++){
            leftmax[i] = Math.max(leftmax[i-1],arr[i]);
        }

        int level[] = new int [n];
        for(int i = 0 ;i<n;i++){
            level[i]  = Math.min(leftmax[i] , rightmax[i]);
        }

        int trappedWater = 0 ;
        for(int i  = 0;i<n;i++){
            trappedWater += Math.max(level[i]-arr[i], 0);
        }
        return trappedWater;
        
    }
}
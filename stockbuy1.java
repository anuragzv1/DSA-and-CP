
import java.util.*;

class stockbuy1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    int arr[] = new int[n];
    for(int i = 0;i<n;i++)arr[i] = sc.nextInt();

    System.out.println("MAX PROFIT : "+calMaxProfit(arr , 0 , arr.length-1));
    }

    private static int calMaxProfit(int[] arr, int start, int end) {
        if(start>=end){
            return 0;
        }

        int max_profit = 0;
        for(int i = start;i<end;i++){
            for(int j=i+1;j<=end;j++){
                if(arr[j]>arr[i]){
                    int current_profit = calMaxProfit(arr, start, i-1)+calMaxProfit(arr, j+1, end)+arr[j]-arr[i];
                    max_profit = Math.max(current_profit , max_profit);
                }
            }
        }
        return max_profit;
    }

}
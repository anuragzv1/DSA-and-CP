import java.util.Scanner;

class minCostDP {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int input[][] = new int [n][m];
        
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                input[i][j] = sc.nextInt();
            }
        }

        int dp[][] = new int[n][m];
        dp[n-1][m-1] = input[n-1][m-1];
        for(int i=n-2;i>=0;i--){
            dp[i][m-1] = input[i][m-1]+dp[i+1][m-1];
        }

        for(int i=m-2;i>=0;i--){
            dp[n-1][i] = input[n-1][i]+dp[n-1][i+1];
        }

        for(int i = n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j]= input[i][j]+Math.min(dp[i+1][j+1],Math.min(dp[i+1][j],dp[i][j+1]));
            }
        }

    
        System.out.print(dp[0][0]);
    }
}
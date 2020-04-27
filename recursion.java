import java.util.Scanner;

class recursion{



    public static int fibo(int n){
        if(n==1)return 1;
        if(n==0) return 1;


        int ans = fibo(n-1)+fibo(n-2);
     
     return ans;

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        System.out.println(fibo(n));
    }
}
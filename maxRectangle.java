import java.util.Scanner;
import java.util.Vector;


class maxRectangle{

    int ans  = Integer.MIN_VALUE;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int [n];
        String a ="";
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
            a+=arr[i];
        }
        int ans = 0;
        for(int i=0;i<a.length();i++){
            for(int j=i+1;j<=a.length();j++){
                ans = Math.max(ans , count(a.substring(i,j)));
            }
        }
        System.out.println(ans);
    }

    private static int count(String s) {
        int local_min = Integer.MAX_VALUE;
        for(int i =0;i<s.length();i++){
            local_min = Math.min(local_min , Integer.parseInt(""+s.charAt(i)));
        }
        return local_min*s.length();
    }
}
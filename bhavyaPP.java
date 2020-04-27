import java.util.*;

class bhavyaPP {

    public static int digSum(int n) {
        if (n == 0)
            return 0;
        return (n % 9 == 0) ? 9 : (n % 9);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int count = 0;
        int m = 1000000007;
        for (int i = 1; i <= Math.pow(10, n); i++) {
            if (digSum(i) == 7){
                count = (count%m + 1%m)%m;
                System.out.println(i);
            }
        }
        System.out.println(count);
    }
}
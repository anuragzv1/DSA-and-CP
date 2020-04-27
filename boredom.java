import java.util.*;

class boredom {
    public static int solve(int n, int arr[]) {
        if (n <= 0) {
            return 0;
        }

        int element = arr[0];

        Vector<Integer> v = new Vector<Integer>();

        for (int i = 1; i < n; i++) {
            if (arr[i] == element + 1 || arr[i] == element - 1) {
                continue;
            } else {
                v.add(arr[i]);
            }
        }
        int brr[] = new int[v.size()];
        for (int i = 0; i < v.size(); i++) {
            brr[i] = v.get(i);
        }

        int sum1 = element + solve(brr.length, brr);
        int crr[] = new int[arr.length - 1];
        for (int i = 1; i < arr.length; i++) {
            crr[i - 1] = arr[i];
        }
        int sum2 = solve(crr.length, crr);

        return Math.max(sum2, sum1);

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();
        System.out.println(solve(n, arr));
    }

}
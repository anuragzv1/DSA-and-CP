import java.lang.Math;

class GFG {
    public static void main(String[] args) {
        int arr[] = { 99,12,9,-1,-4,9,12,-90,88,55 };
        int b = 4, c = 0;
        int n = arr.length;
        int output[] = new int[n - (b - 1)];

        int i, j, max = Integer.MIN_VALUE;
        for (i = 0, j = 0; i <= n - b; j++) {
            if (j == i + b - 1) {
                output[c] = max;
                i++;
                j = i - 1;
                c++;
                max = Integer.MIN_VALUE;
            } else
                max = (int) Math.max(max, (Math.max(arr[j], arr[j + 1])));

        }
        for (int k = 0; k < output.length; k++) {
            System.out.print(output[k]+" ");
        }
    }
}

//1 3 -1 -3 5 3 6 7 3 10 -1 34 2 1 44 34 4
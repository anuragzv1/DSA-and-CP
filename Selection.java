import java.util.Scanner;

class Selection {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr [] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        for(int i =0;i<n;i++){
            int min = Integer.MAX_VALUE;
            int indexOfMin = -1;

            for(int j =i;j<n;j++){
                if(arr[j]<min){
                    min = arr[j];
                    indexOfMin = j;
                }
            }
            //swap
            int temp = arr[i];
            arr[i]  = min;
            arr[indexOfMin] = temp;
        }

        for(int i =0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
        sc.close();
    }
}
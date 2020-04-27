import java.util.Scanner;

class minmax{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int arr1[][] = new int [4][4];
        int arr2[][] = new int [4][4];
        System.out.println("Enter ele in 1st array");
        for(int i =0;i<4;i++){
            for(int j=0;j<4;j++){
                arr1[i][j] = sc.nextInt();
            }
        }

        System.out.println("enter ele in 2nd arary");
        for(int i =0;i<4;i++){
            for(int j=0;j<4;j++){
                arr2[i][j] = sc.nextInt();
            }
        }

        //processing step

        int newarr[][]= new int[4][4];

        for(int i =0;i<4;i++){
            for(int j=0;j<4;j++){
                newarr[i][j] = arr1[i][j]+arr2[i][j];
            }
        }

        System.out.println("New array = ");


        for(int i =0;i<4;i++){
            for(int j=0;j<4;j++){
                System.out.print(newarr[i][j]);
            }
            System.out.println();
        }
        sc.close();
    }
}

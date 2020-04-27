import java.util.Scanner;
import java.util.Vector;


class kToggle2{
    static Vector<String>combinations = new Vector<String>();

    static int amp(int mat[][] , int n , int m){
        int amp =0;
        for(int i=0;i<n;i++){
            boolean allOnes= true;
            for(int j=0;j<m;j++){
                if(mat[i][j]!=1){
                    allOnes = false;
                    break;
                }
            }
            if(allOnes)amp++;
        }
        return amp;
    }

    static void toggle(int arr[][] , int col){
        for(int i =0;i<arr.length;i++){
            if(arr[i][col]==1)arr[i][col]=0;
            else arr[i][col]=1;
        }
    }
    //for now you can consider as exes
    private static void myCombi(int k , int n,String s ){
        if(n==0 ){
            if(k==0){
            combinations.add(s);
            return;
        }
        else return;
    }

       for(int i=0;i<=k;i++){
           myCombi(k-i,n-1,s+i);
       }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();

        int arr[][] = new int [n][m];
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=sc.nextInt();
            }
        }
        myCombi(k , m, "");
        int brr[][] = new int[n][m];
        for(int i =0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                brr[i][j] = arr[i][j];
            }
        }

        int max_amp = 0;
        for(int i=0;i<combinations.size();i++){
            String c = combinations.get(i);
            for(int j=0;j<c.length();j++){
                if(c.charAt(j)=='1'){
                    toggle(brr,j);
                }
            }

            max_amp = Math.max(amp(brr,n,m),max_amp);
            for(int i1 =0;i1<n;i1++){
                for(int j1 = 0;j1<m;j1++){
                    brr[i1][j1] = arr[i1][j1];
                }
            }
        }
        sc.close();
        System.out.println(max_amp);
    }


}
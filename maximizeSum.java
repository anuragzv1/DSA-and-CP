import java.util.Scanner;

class maximizeSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        } 

        int m = sc.nextInt();
        int brr[] = new int[m];
        for (int i = 0; i < m; i++) {
            brr[i] = sc.nextInt();
        }

        int i =0,j=0;
        int commonIndex = -1;
        while(i<arr.length && j<brr.length){
            if(arr[i]==brr[j]){
                commonIndex = i;
                break;
            }
            else if(arr[i]<brr[j])i++;
            else j++;
        }
        if(commonIndex==-1){
            long sum1=0;
            for(int x =0;x<arr.length;x++){
                sum1+=arr[x];
            }

            long sum2=0;
            for(int x=0;x<brr.length;x++){
                sum2+=brr[x];
            }
            long ans = Math.max(sum1,sum2);
            System.out.println(ans);
            return;
        }
        
        int sum1common = 0,sum2common=0;

        for(i=0;i<=commonIndex;i++){
            sum1common+=arr[i];
            sum2common+=brr[i];
        }
        
        int ans = Math.max(sum1common,sum2common);

        i=j=commonIndex+1;
        while(i<arr.length && j<brr.length){
            if(arr[i]<brr[j]){
                sum1common=sum1common+arr[i++];
            }
            else if(brr[j]<arr[i]){
                sum2common+=brr[j++];
            }
            else if(brr[j]==arr[i]){
                ans +=Math.max(sum1common, sum2common)+brr[j];
                sum1common=0;
                sum2common=0;
                j++;
                i++;
            }
        }

        while(i<arr.length){
            sum1common+=arr[i++];
        }
        while(j<brr.length){
            sum2common+=brr[j++];
        }

        ans+=Math.max(sum1common,sum2common);
        sc.close();
        System.out.println(ans);


    }
}
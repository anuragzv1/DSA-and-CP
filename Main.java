import java.util.Scanner;
import java.util.HashMap; 
import java.util.Map; 
import java.util.Map.Entry; 

public class Main {


    static int mostFrequent(int arr[], int n) 
    { 
          
        // Insert all elements in hash 
        Map<Integer, Integer> hp = 
               new HashMap<Integer, Integer>(); 
          
        for(int i = 0; i < n; i++) 
        { 
            int key = arr[i]; 
            if(hp.containsKey(key)) 
            { 
                int freq = hp.get(key); 
                freq++; 
                hp.put(key, freq); 
            } 
            else
            { 
                hp.put(key, 1); 
            } 
        } 
          
        // find max frequency. 
        int max_count = 0, res = -1; 
          
        for(Entry<Integer, Integer> val : hp.entrySet()) 
        { 
            if (max_count < val.getValue()) 
            { 
                res = val.getKey(); 
                max_count = val.getValue(); 
            } 
        } 
          
        return res; 
    } 
      
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int arr[] = new int[n];
        int brr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        for (int j = 0; j < n; j++) {
            brr[j] = sc.nextInt();
        }
        int xrr [] = new int[n];

        int ans1 = 0;
        for(int i =0;i<n;i++){
            xrr[i] = arr[i]-brr[i];
        }
        ans1 = mostFrequent(xrr,xrr.length);

        int ans2 = 0;
        for(int i =0;i<n;i++){
            xrr[i] = brr[i]-arr[i];
        }
        ans2 = mostFrequent(xrr,xrr.length);
        
        int local_match1=0;
        for(int i =0;i<n;i++){
            if((arr[i]+ans1)==brr[i])local_match1++;
        }
        int local_match2=0;
        for(int j=0;j<n;j++){
            if((arr[j]+ans2)==brr[j])local_match2++;
        }
        
        int ans = Math.max(local_match1,local_match2);
        sc.close();
        System.out.println(ans);

    }

}

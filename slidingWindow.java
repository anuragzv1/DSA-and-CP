import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class slidingWindow {
    public static ArrayList<Integer> slidingMaximum(int[] A, int b) {
        Stack<Integer> stack = new Stack<>();
        ArrayList<Integer> ans = new ArrayList<>();

        int i = 0;
        while(i<b){
            if(stack.isEmpty()){
                stack.push(i++);
            }
            else{
                if(A[stack.peek()]<A[i]){
                    stack.pop();
                    stack.push(i);
                }
                i++;
            }
        }
        ans.add(A[stack.peek()]);
        int start = 1;
        while(start<=A.length-b){
            if(start<=stack.peek()){
                if(A[stack.peek()]<A[start+b-1]){
                    stack.pop();
                    stack.push(start+b-1);
                    ans.add(A[stack.peek()]);
                }
                else{
                    ans.add(A[stack.peek()]);
                }
                start++;
            }
            else{
                stack.pop();
                int x = start;
                while(x<start+b){
                    if(stack.isEmpty()){
                        stack.push(x++);
                    }
                    else{
                        if(A[stack.peek()]<A[x]){
                            stack.pop();
                            stack.push(x);
                        }
                        x++;
                    }
                }
                start++;
                ans.add(A[stack.peek()]);
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int b = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        ArrayList<Integer> brr = slidingMaximum(arr, b);

        for (int i = 0; i < brr.size(); i++) {
            System.out.print(brr.get(i) + " ");
        }

    }

   
}

import java.util.Scanner;

class removeDupes{


        public static String removeConsecutiveDuplicates(String s) {
            if(s.length()==1){
                return ""+s.charAt(0);
            }

            String ans = "";

            if(s.charAt(0)==s.charAt(1)){
                ans = removeConsecutiveDuplicates(s.substring(1));
            }
            else ans = ""+s.charAt(0)+removeConsecutiveDuplicates(s.substring(1));

            return ans;

        }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(removeConsecutiveDuplicates(s));
        sc.close();

    }
}
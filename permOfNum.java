import java.util.*;

class permOfNum{


    private static Vector<String> calPerm(String input){
        if(input.length()==1){
            Vector<String> v = new Vector<String>();
            String s = ""+input.charAt(0);
            v.add(s);
            return v;
        }

        Vector<String> x = calPerm(input.substring(1));
        Vector<String>x1 = new Vector<String>();
        for(int i =0;i<x.size();i++){
            String s = x.get(i);
            String newStr = "";
            for(int j=0;j<=s.length();j++){
                String s1 = s.substring(0,j);
                String s2 = s.substring(j,s.length());
                newStr = s1+input.charAt(0)+s2;
                x1.add(newStr);
            }
            
        }

        return x1;


    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = Integer.toString(n);
        sc.close();
       
       Vector<String> v =  calPerm(s);
       Vector<Integer> xx = new Vector<Integer>();
        Collections.sort(v);

        for(int i =0;i<v.size();i++){
            xx.add(Integer.parseInt(v.get(i)));
        }
        
        int pos = xx.indexOf(n);
        if(pos==v.size()-1)System.out.println(xx.get(0));
        else System.out.println(xx.get(pos+1));



    }
}
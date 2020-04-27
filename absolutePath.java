import java.util.Stack;
public class absolutePath {
    public String simplifyPath(String A) {
        Stack<String> stack = new Stack<>();

        for(int i =0;i<A.length();i++){
            if(A.charAt(i)=='/')continue;

            else if(A.charAt(i)=='.' ){
                if(i+1 < A.length() && A.charAt(i+1)=='.'){
                    if(!stack.isEmpty()){
                        stack.pop();
                    }
                    i++;
                }
            }
            else{
                String temp = "";
                for(;A.charAt(i)!='/';i++){
                    temp+=""+A.charAt(i);
                }
                stack.push(temp);
            }
            
        }
        String ans = "";
        while(!stack.isEmpty()){
            ans="/"+stack.pop()+ans;
        }
        return (ans=="")?"/":ans;
    }
}

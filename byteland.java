
import java.util.Scanner;
import java.util.HashMap;


public class byteland{
    
    static Scanner s = new Scanner(System.in);
    public static long bytelandian(long n){
        HashMap<Integer,Integer>map = new HashMap<>();
        map.put(0,0);
        map.put(1,1);
        for(int i = 2;i<=n;i++){
            if(map.containsKey((i/4)-1))map.remove((i/4)-1);
            map.put(i,i);
            int value = map.get(i/2)+map.get(i/3)+map.get(i/4);
            map.put(i , Math.max(i , value));
        }
        return  map.get((int)n);
	}
    public static void main(String[] args) {
       long n = s.nextLong();
       System.out.println(bytelandian(n));
   }

}



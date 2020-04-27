
import java.util.*;

class ListComparator implements Comparator<List<Long>> {

    public int compare(List<Long> o1, List<Long> o2) {
        if (o1.get(0) <= o2.get(0)) {
            return -1;
        } else
            return 1;
    }

}

class candies {

    static long GCD(long a, long b) {
        if(b>a)return GCD(b , a%b);
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long cost[] = new long[n];
        long energy[] = new long[n];
        int m = 1000000007;

        for (int i = 0; i < n; i++) {
            cost[i] = sc.nextLong();
        }

        for (int i1 = 0; i1 < n; i1++) {
            energy[i1] = sc.nextLong();
        }
        long totalMoney = sc.nextLong();

        List<List<Long>> list = new LinkedList<List<Long>>();
        for (int x = 0; x < n; x++) {
            List<Long> temp = new LinkedList<>();
            temp.add(cost[x]);
            temp.add(energy[x]);
            list.add(temp);
        }

        Collections.sort(list, new ListComparator());

        long totalEnergy = 0;
        for (int i = 0; i < n; i++) {
            if (list.get(i).get(0) <= totalMoney) {
                totalEnergy +=list.get(i).get(1);
                totalEnergy = totalEnergy%m;
                totalMoney -=list.get(i).get(0);
            } else {
                long x = list.get(i).get(1)*totalMoney;
                long y = list.get(i).get(0);
                long numerator = totalEnergy*y + x;
                long deno = y;
                long gcd = GCD(numerator,deno);
                numerator = numerator/gcd;
                deno = deno/gcd;
                totalEnergy = (numerator/deno)%m;
                totalMoney-=list.get(i).get(0);
                if(totalMoney==0)break;
            }
        }
        System.out.print(totalEnergy);

    }

}
import java.util.Scanner;
public class lol123 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Start Fah Value");
        int s = sc.nextInt();

        System.out.println("Enter End Fah Value");
        int e = sc.nextInt();

        System.out.println("Enter GAP Between Fah Value");
        int g = sc.nextInt();
        
        int cel;
        for (s = s; s <= e; s += g) {
            cel = (5 * (s - 32)) / 9;
            System.out.print(s);
            System.out.println(" " + cel);
        }

    }
}
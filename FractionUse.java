
class Fraction{
    private int numerator;
    private int denominator;

    Fraction(int numerator ,int denominator){
        this.numerator = numerator;
        this.denominator = denominator;
        simplify();
    }

    private int gcd(int a , int b){
        while(a!=b){
            if(a>b)a=a-b;
            else b=b-a;
        }
        return a;
    }
    private void simplify(){
        int gcd = gcd(this.numerator,this.denominator);
        this.denominator =this.denominator/gcd;
        this.numerator=this.numerator/gcd;
    }

    public void add(Fraction f2){
        int nume = this.numerator*f2.denominator + f2.numerator*this.denominator;
        int deno = this.denominator * f2.denominator;

        this.numerator = nume;
        this.denominator = deno;
        simplify();
    }
    public void print(){
        if(numerator==denominator)System.out.println(1);
        else System.out.println(this.numerator +"/"+this.denominator);
    }

}


class FractionUse{

    public static void main(String[] args) {
        Fraction f1 = new Fraction(2, 4);
        f1.print();
        Fraction f3 = new Fraction(4, 8);

        f3.add(f1);
        f3.print();
    }




}
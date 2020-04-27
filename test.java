class Divisors {

    public int exactly3Divisors(int N) {
        // Your code here
        int div = 0;
        for (int i = 2; i <= Math.sqrt(N); i++) {
            boolean v = isprime(i);
            if (v == true) {
                if (i * i <= N)
                    div++;
            }
        }
        return div;
    }

    public boolean isprime(int m) {
        for (int j = 2; j <= Math.sqrt(m); j++) {
            if (m % j == 0)
                return false;
        }
        return true;
    }

}
/**
 * quadraticPrimes
 */
public class xquadraticPrimes27 {

    public static void main(String[] args) {
        int maxPrimesTemp = 0,
                productTemp = 0,
                t;

        int a = -999;

        while (a != 1000) {
            int b = -1000;
            while (b != 1000) {
                if ((t = getConsecutiveNumberOfPrimes(a, b)) > maxPrimesTemp) {
                    maxPrimesTemp = t;
                    productTemp = a * b;
                }
                b++;
            }
            a++;
        }
        System.out.println(productTemp);
    }

    public static Integer getConsecutiveNumberOfPrimes(int a, int b) {
        int maxConsecutives = 0;
        for (int n = 0; n < Math.max(a, b); n++) {
            if (!isPrime(((int) Math.pow(n, 2)) + (a * n) + b)) {
                return maxConsecutives;
            }
            maxConsecutives++;
        }
        return maxConsecutives;
    }

    public static boolean isPrime(int n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
}
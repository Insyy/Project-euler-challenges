import java.util.AbstractMap;
import java.util.Map;

public class xdigitalRootClocks315 {
    private static Map<Integer, String> numberDigits = Map.ofEntries(
            new AbstractMap.SimpleEntry<Integer, String>(0, "1011111"),
            new AbstractMap.SimpleEntry<Integer, String>(1, "0000011"),
            new AbstractMap.SimpleEntry<Integer, String>(2, "1110110"),
            new AbstractMap.SimpleEntry<Integer, String>(3, "1110011"),
            new AbstractMap.SimpleEntry<Integer, String>(4, "0101011"),
            new AbstractMap.SimpleEntry<Integer, String>(5, "1111001"),
            new AbstractMap.SimpleEntry<Integer, String>(6, "1111101"),
            new AbstractMap.SimpleEntry<Integer, String>(7, "1001011"),
            new AbstractMap.SimpleEntry<Integer, String>(8, "1111111"),
            new AbstractMap.SimpleEntry<Integer, String>(9, "1111011"));

    public static long getPowerNeededForNumberSam(Integer number) {
        long powerNeeded = 0;
        while (number.toString().length() > 1) {
            powerNeeded += getSimpleTransitionsOfNumber(number);
            number = digitalRoot(number);
        }
        return 2 * (powerNeeded += getSimpleTransitionsOfNumber(number));
    }

    public static long getPowerNeededForNumberMax(Integer number) {
        long powerNeeded = 0;
        while (number.toString().length() > 1) {
            powerNeeded += getSimpleTransitionsOfNumber(number);
            powerNeeded -= getSavedTransitionsMax(number, digitalRoot(number));
            number = digitalRoot(number);
        }
        return 2 * (powerNeeded += getSimpleTransitionsOfNumber(number));
    }

    public static long getSavedTransitionsMax(Integer previous, Integer next) {
        long savedTransitions = 0;
        int minDigits = Math.min(previous.toString().length(), next.toString().length());

        for (int d = 0; d < minDigits; d++) {

            Integer prevCharInt = Character
                    .getNumericValue(previous.toString().charAt(previous.toString().length() - 1 - d));
            Integer nextCharInt = Character.getNumericValue(next.toString().charAt(next.toString().length() - 1 - d));

            int[] prevStream = numberDigits.get(prevCharInt).chars().toArray();
            int[] nextStream = numberDigits.get(nextCharInt).chars().toArray();

            for (int i = 0; i < 7; i++) {
                if (nextStream[i] == 49 &&
                        prevStream[i] == nextStream[i]) {
                    savedTransitions++;
                }
            }
        }
        return savedTransitions;
    }

    public static long getSimpleTransitionsOfDigit(Integer number) {
        return numberDigits.get(number).chars().filter(ch -> ch == '1').count();
    }

    public static long getSimpleTransitionsOfNumber(Integer number) {
        return number.toString().chars().reduce(0,
                (subtotal, ch) -> subtotal + (int) getSimpleTransitionsOfDigit(Character.getNumericValue(ch)));
    }

    public static int digitalRoot(Integer number) {
        return number.toString().chars().reduce(0, (subtotal, ch) -> subtotal + Character.getNumericValue(ch));
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

    public static void main(String[] args) {
        int tSam = 0,
                tMax = 0;
        int A = 10000000;
        int B = 20000000;

        for (int i = A; i <= B; i++) {
            if (isPrime(i)) {
                tSam += getPowerNeededForNumberSam(i);
                tMax += getPowerNeededForNumberMax(i);
            }
        }

        System.out.println("TOTAL DIFFERENCE RESULT: " + (tSam - tMax));

    }
}

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
/**
 * sumSquareCube348
 */
public class xsumSquareCube348 {

    public static Map<Integer, Integer> candidates = new HashMap<>();
    public static ArrayList<Integer> finalNumbers = new ArrayList<>();
    public static void main(String[] args) {
        for (int i = 2; i < 10000; i++) {
            for (int j = i; j < 100000; j++) {
                int sumSqCube = (int) ( Math.pow(i, 3) + Math.pow(j, 2));
                if (isPalindrome(sumSqCube)) {
                    if (sumSqCube == 5229225) {
                        System.out.println("found example with " + j + " and " + i + " ");
                    }
                    addToMap(sumSqCube);
                }
            }
        }
        System.out.println(candidates.toString());
        for (Entry<Integer, Integer> entry : candidates.entrySet()) {
            if (entry.getValue().equals(Integer.valueOf(4))) {
                finalNumbers.add(entry.getKey());
            }
        }
        Collections.sort(finalNumbers);
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += (int) finalNumbers.get(i);
        }
        System.out.println(sum);
    }
    
    private static boolean isPalindrome(int number) {
        String numberStr = Integer.toString(number);
        for (int i = 0; i < numberStr.length() / 2; i++) {
            if (numberStr.charAt(i) != numberStr.charAt(numberStr.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public static void addToMap(int number){
        if (candidates.containsKey(Integer.valueOf(number))) {
            candidates.replace(Integer.valueOf(number), candidates.get(Integer.valueOf(number)) + 1);
            return;
        }
        candidates.put(Integer.valueOf(number), 1);
    }

}

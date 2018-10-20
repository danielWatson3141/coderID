package r1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

/**
 * Created by jouke on 4/26/14.
 */
public class ChargingChaos {

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("input/1A/A-small-attempt1.in"));
            BufferedWriter outputWriter = new BufferedWriter(new FileWriter(new File("output/1A/ChargingChaosOutput")));

            int testCases = scanner.nextInt();

            for (int i = 0; i < testCases; i++) {
                String output = "Case #" + (i+1) + ": " + handleTestCase(scanner);
                System.out.println(output);
                outputWriter.write(output + "\n");
            }

            scanner.close();
            outputWriter.close();

        } catch (IOException e) {
            System.out.println("IOException !!!");
        }

    }

    public static String handleTestCase(Scanner scanner) {

        int N = scanner.nextInt();
        int L = scanner.nextInt();

        long[] outlets = new long[N];
        long[] devices = new long[N];

        for (int i = 0; i < N; i++) {
            outlets[i] = Long.parseLong(scanner.next(), 2);
        }

        for (int i = 0; i < N; i++) {
            devices[i] = Long.parseLong(scanner.next(), 2);
        }

        Map<Long, Set<Integer>> options = new HashMap<Long,Set<Integer>>();

        for (int i = 0; i < N; i++) {
            HashSet<Integer> set = new HashSet<Integer>();
            set.add(i);
            options.put(devices[0] ^ outlets[i], set);
        }

        boolean possible = true;

        for (int i = 1; i < N; i++) {

            //printOptions(options);

            boolean checkFurther = false;
            for (int j = 0; j < N; j++) {

                long key = devices[i] ^ outlets[j];
                if (options.containsKey(key) && !options.get(key).contains(j)) {
                    checkFurther = true;
                    options.get(key).add(j);
                }
            }

            //printOptions(options);

            if (!checkFurther) {
                possible = false;
                break;
            } else if (i == N-1) {
                break;
            }

            //remove non working options
            Iterator<Long> it = options.keySet().iterator();
            while (it.hasNext()) {
                long key = it.next();

                if (options.get(key).size() < i + 1) {
                    it.remove();
                }

            }
        }

         Set<Long> possibleSwitches = options.keySet();

        int minSwitches = Integer.MAX_VALUE;

        for (Long switchMoves : possibleSwitches) {
            if (Long.bitCount(switchMoves) < minSwitches) {
                minSwitches = Long.bitCount(switchMoves);
            }
        }

        if (possible) {
            return String.valueOf(minSwitches);
        } else {
            return "NOT POSSIBLE";
        }
    }

    public static void printOptions(Map<Long, Set<Integer>> options) {
        for (Long key : options.keySet()) {

            System.out.println("key: " + key + ", positions: " + Arrays.toString(options.get(key).toArray()));
        }
    }
}

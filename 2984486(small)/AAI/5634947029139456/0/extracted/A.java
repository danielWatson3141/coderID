package codejam;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A {

    static Map<String[], Integer> myMap = new HashMap<String[], Integer>();

    public static void main(String[] args) throws IOException {
        File input = new File("in");
        File out = new File("out");
        FileWriter writer = new FileWriter(out);
        Scanner scanner = new Scanner(input);

        int T = scanner.nextInt();
        for (int i = 0; i < T; i++) {

            int N = scanner.nextInt();
            int L = scanner.nextInt();

            String[] outlets = new String[N];
            String[] devices = new String[N];

            for (int j = 0; j < N; j++) {

                outlets[j] = scanner.next();
            }

            for (int j = 0; j < N; j++) {

                devices[j] = scanner.next();
            }

            int solve = solve(outlets, devices, 0, L);
            if (solve < 0 || solve >= (Integer.MAX_VALUE - 1000000)) {
                writer.write("Case #" + (i + 1) + ": NOT POSSIBLE");

            } else {

                writer.write("Case #" + (i + 1) + ": " + solve);
            }

            writer.write(System.getProperty("line.separator"));
        }
        writer.close();

    }

    private static int solve(String[] outlets, String[] devices, int i, int L) {

        if (match(outlets, devices)) {
            if (!myMap.containsKey(outlets)) {
                myMap.put(outlets, 0);
            }
            return myMap.get(outlets);
        }

        if (i >= L) {
            if (!myMap.containsKey(outlets)) {
                myMap.put(outlets, Integer.MAX_VALUE - 1000000);
            }
            return myMap.get(outlets);
        }

        String[] flipped = flip(i, Arrays.copyOf(outlets, outlets.length));

        if (!myMap.containsKey(outlets)) {
            myMap.put(outlets, solve(outlets, devices, i + 1, L));
        }

        if (!myMap.containsKey(flipped)) {
            myMap.put(flipped, 1 + solve(flipped, devices, i + 1, L));
        }

        return Math.min(Math.abs(myMap.get(outlets)), Math.abs(myMap.get(flipped)));

    }

    private static String[] flip(int i, String[] outlets) {
        for (int j = 0; j < outlets.length; j++) {
            StringBuilder b = new StringBuilder(outlets[j]);

            char charAt = b.charAt(i);
            if (charAt == '0')
                charAt = '1';
            else
                charAt = '0';
            b.setCharAt(i, charAt);
            outlets[j] = b.toString();

        }

        return outlets;
    }

    private static boolean match(String[] outlets, String[] devices) {

        int[] devicesInt = new int[devices.length];
        int[] outletsInt = new int[devices.length];

        for (int i = 0; i < outlets.length; i++) {
            outletsInt[i] = Integer.parseInt(outlets[i], 2);
            devicesInt[i] = Integer.parseInt(devices[i], 2);
        }

        Arrays.sort(outletsInt);
        Arrays.sort(devicesInt);

        for (int i = 0; i < outlets.length; i++) {
            if (outletsInt[i] != devicesInt[i])
                return false;
        }
        return true;
    }

}

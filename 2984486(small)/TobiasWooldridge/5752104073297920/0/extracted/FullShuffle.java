import java.util.*;

public class FullShuffle {
    static Scanner in;
    static double[] badFootprint;

    public static void main(String[] args) {
        in = new Scanner(System.in);

        badFootprint = new double[1000];

        for (int i = 0; i < 1000; i++) {
            int[] arr = createArr(1000);
            badShuffle(arr);

            for (int j = 0; j < arr.length; j++) {
                badFootprint[arr[j]] += j / 1000.0d;
            }
        }

        if (true) {
            final int testCases = in.nextInt();
            for (int testCase = 1; testCase <= testCases; testCase++) {
                Solution s = new Solution(testCase);
                boolean good = Solution.isGoodShuffle(s.numbers);
                System.out.println("Case #" + testCase + ": " + (good ? "GOOD" : "BAD"));
            }
        }
        else {
            // Test ze shuffling
            int correctForGood = 0;
            int correctForBad = 0;
            int[] arr;

            for (int i = 0; i < 100; i++) {
                arr = createArr(1000);
                goodShuffle(arr);

                if (Solution.isGoodShuffle(arr)) {
                    correctForGood++;
                    System.out.println(Solution.distanceFromBad(arr));
                }

                arr = createArr(1000);
                badShuffle(arr);

                if (!Solution.isGoodShuffle(arr)) {
                    correctForBad++;
                    System.out.println(Solution.distanceFromBad(arr));
                }
            }

            System.out.println(correctForGood);
            System.out.println(correctForBad);
        }
    }

    public static void swap(int[] arr, int k, int p) {
        int buffer = arr[k];
        arr[k] = arr[p];
        arr[p] = buffer;
    }

    public static void goodShuffle(int[] arr) {
        Random rand = new Random();
        for (int i = 0; i < arr.length; i++) {
            swap(arr, i, i + rand.nextInt(arr.length - i));
        }
    }

    public static void badShuffle(int[] arr) {
        Random rand = new Random();
        for (int i = 0; i < arr.length; i++) {
            swap(arr, i, rand.nextInt(arr.length));
        }
    }

    public static int[] createArr(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        return arr;
    }

    public static class Solution {
        public int testCase;
        public final int n;
        public final int[] numbers;

        Solution(int testCase) {
            this.testCase = testCase;
            n = in.nextInt();
            numbers = new int[n];

            for (int i = 0; i < n; i++) {
                numbers[i] = in.nextInt();
            }
        }

        static boolean isGoodShuffle(int[] arr) {
            return distanceFromBad(arr) > 249600;
        }

        static double distanceFromBad(int[] arr) {
            double distanceFromBadFootprint = 1;

            int n = arr.length;

            for (int i = 0; i < n; i++) {
                int value = arr[i];

                distanceFromBadFootprint += Math.abs((double)badFootprint[value] - i);
            }

            return distanceFromBadFootprint;
        }
    }
}

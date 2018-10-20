import java.util.*;

public class ChargingChaos {
    static Scanner in;

    public static class Solution {
        private final List<Long> outletFlows;
        private final List<Long> deviceFlows;
        private final Map<Long, Long> workingMasks;

        Solution(int testCase) {
            int devices = in.nextInt();
            int bits = in.nextInt();

            outletFlows = new ArrayList<Long>();
            for (int i = 0; i < devices; i++) {
                outletFlows.add(in.nextLong(2));
            }

            deviceFlows = new ArrayList<Long>();
            for (int i = 0; i < devices; i++) {
                deviceFlows.add(in.nextLong(2));
            }

            int minFlips = bits;
            boolean foundSolution = false;

            workingMasks  = new HashMap<Long, Long>();

            // O(n^2) #yolo
            for (long outlet : outletFlows) {
                for (long device : deviceFlows) {
                    long mask = outlet ^ device;

                    if (!workingMasks.containsKey(mask)) {
                        workingMasks.put(mask, 0l);
                    }

                    workingMasks.put(mask, workingMasks.get(mask) + 1);


                    if (workingMasks.get(mask) == devices) {
                        minFlips = Math.min(minFlips, Long.bitCount(mask));
                        foundSolution = true;
                    }
                }
            }

            if (foundSolution) {
                System.out.println("Case #" + testCase + ": " + minFlips);
            }
            else {
                System.out.println("Case #" + testCase + ": NOT POSSIBLE");
            }
        }
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);

        final int testCases = in.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            // Create a class level scope for each solution
            Solution s = new Solution(testCase);
        }
    }
}

import com.google.common.collect.Sets;

import java.util.Scanner;

/**
 * Created by bert on 4/26/14.
 */
public class GoogleC2A {

    //"Case #2: NOT POSSIBLE"

    public void solve(String input) {

        Scanner scan = new Scanner(input);

        int numberOfTestCases = scan.nextInt();

        for (int i = 0; i < numberOfTestCases; i++) {

            int devicesN = scan.nextInt();
            int switchesL = scan.nextInt();

            String[] initialFlow = scan(scan, devicesN, switchesL);
            String[] requiredFlow = scan(scan, devicesN, switchesL);


            int minimalSwitches = solveProblem(devicesN, switchesL, initialFlow, requiredFlow, 0, 0);
            if (minimalSwitches == Integer.MAX_VALUE) {
                System.out.println(String.format("Case #%s: NOT POSSIBLE", i + 1));
            } else {
                System.out.println(String.format("Case #%s: %s",i+1,minimalSwitches));
            }

        }

    }


    private String[] scan(Scanner scan, int devicesN, int switchesL) {

        String[] result = new String[devicesN];

        for (int i = 0; i < devicesN; i++) {
            result[i] = scan.next();
        }

        return result;
    }

    private int solveProblem(int devicesN, int switchesL, String[] currentFlow, String[] requiredFlow, int currentSwitchPosition, int timesSwitched) {

        if (currentSwitchPosition == switchesL) {
            if (isCompatible(currentFlow, requiredFlow)) {
                return timesSwitched;
            } else {
                return Integer.MAX_VALUE;
            }


        } else {
            int positionsWithoutSwitching = solveProblem(devicesN, switchesL, currentFlow, requiredFlow, currentSwitchPosition + 1, timesSwitched);
            int positionsWithSwitching = solveProblem(devicesN, switchesL, flipPosition(currentSwitchPosition, currentFlow), requiredFlow, currentSwitchPosition + 1, timesSwitched + 1);

            return Math.min(positionsWithoutSwitching, positionsWithSwitching);
        }



    }

    private String[] flipPosition(int position, String[] flow) {
        String [] result = new String[flow.length];

        for (int i = 0; i < flow.length; i++) {
            String s = flow[i];
            result[i] = s.substring(0,position) + (s.charAt(position) == '0'? '1' : '0') +s.substring(position + 1);
        }

        return result;
    }

    private boolean isCompatible(String[] currentFlow, String[] requiredFlow) {
        return Sets.newHashSet(currentFlow).equals(Sets.newHashSet(requiredFlow));
    }

}

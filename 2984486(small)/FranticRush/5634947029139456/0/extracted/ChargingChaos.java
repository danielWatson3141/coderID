import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;

public class ChargingChaos {

    public static void main(String[] args) throws IOException {
        FileOutputStream fop = null;
        PrintStream printStream = null;

        try {
            Scanner in = new Scanner(System.in);
            //Scanner in = new Scanner("C:\\Users\\jgilmore\\Downloads\\A-small-attempt0.in");

    //        File file = new File("C:\\Users\\jgilmore\\Downloads\\out1.txt");
    //        File file = new File("C:\\Users\\jgilmore\\Downloads\\out2.txt");
    //        File file = new File("C:\\Users\\jgilmore\\Downloads\\out3.txt");
    //        File file = new File("C:\\Users\\jgilmore\\Downloads\\out4.txt");
            File file = new File("C:\\Users\\jgilmore\\Downloads\\out.txt");
            if (file.exists()) {
                file.delete();
            }
            file.createNewFile();
            fop = new FileOutputStream(file);
            printStream = new PrintStream(fop);

            int numTests = in.nextInt();
            for (int t = 0; t < numTests; t++) {
                int deviceCount = in.nextInt();
                int switchCount = in.nextInt();
                int[] outlets = new int[deviceCount];
                int[] devices = new int[deviceCount];
                for (int d = 0; d < deviceCount; d++) {
                    String outletString = in.next();
                    outlets[d] = Integer.parseInt(outletString, 2);
                }
                for (int d = 0; d < deviceCount; d++) {
                    String deviceString = in.next();
                    devices[d] = Integer.parseInt(deviceString, 2);
                }
                Arrays.sort(outlets);
                Arrays.sort(devices);

                Integer switchFlipCount = findSwitches(switchCount, outlets, devices, 0);

                if (switchFlipCount == null) {
                    System.out.format("Case #%d: NOT POSSIBLE\n", t + 1);
                    printStream.format("Case #%d: NOT POSSIBLE\n", t + 1);
                } else {
                    System.out.format("Case #%d: %d\n", t + 1, switchFlipCount);
                    printStream.format("Case #%d: %d\n", t + 1, switchFlipCount);
                }
            }
        } finally {
            if (printStream != null) {
                try {
                    printStream.close();
                } catch (Exception e) {}
            }
            if (fop != null) {
                try {
                    fop.close();
                } catch (Exception e) {}
            }
        }
    }

    private static Integer findSwitches(int switchCount, int[] outlets, int[] devices, int switches) {
        boolean match = outletsMatchDevices(outlets, devices);
        if (match) {
            return 0;
        } else {
            int switchFlip = 0;
            Integer minResults = null;
            while (switchFlip < switchCount) {
                switchFlip++;
                int[] switchedOutlets = switchOutlets(outlets, switchCount, switchFlip);
                Integer results = findSwitches(switchCount-1, switchedOutlets, devices, switches);
                if (results != null) {
                    if (minResults == null || results < minResults) {
                        minResults = results;
                    }
                }
            }
            return minResults == null ? null : minResults + 1;
        }
    }

    private static int[] switchOutlets(int[] outlets, int numSwitches, int switchFlip) {
        int power = numSwitches - switchFlip;
        int[] switchedOutlets = new int[outlets.length];
        for (int i = 0; i < outlets.length; i++) {
            switchedOutlets[i] = outlets[i] ^ (1 << power);
        }
        Arrays.sort(switchedOutlets);
        return switchedOutlets;
    }

    private static boolean outletsMatchDevices(int[] outlets, int[] devices) {
        for (int i = 0; i < outlets.length; i++) {
            if (outlets[i] != devices[i]) {
                return false;
            }
        }
        return true;
    }
}

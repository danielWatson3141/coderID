import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemA {
    static String in = "src/a.in";
    static String out = "src/a.out";

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        String[] devices = new String[150];
        String[] flows = new String[150];
        boolean[] used = new boolean[150];
        int numlines = scan.nextInt();
        for(int x = 1; x <= numlines; x++) {
            int numDevices = scan.nextInt();
            int numBits = scan.nextInt();

            for(int y = 0; y < numDevices; y++) {
                flows[y] = scan.next();
                used[y] = false;
            }

            for(int y = 0; y < numDevices; y++) {
                devices[y] = scan.next();
            }

            int steps = -1;
            for(int y = 0; y < numDevices; y++) {
                String change = getChange(devices[0], flows[y]);
                int temps = 0;
                for(int z = 0; z < numBits; z++) {
                    if(change.charAt(z) == '1') {
                        temps++;
                    }
                }
                if(steps < 0 || temps < steps) {
                    used[y] = true;
                    if(solve(flows, devices, used, numDevices, change, 1)) {
                        steps = temps;
                    }
                    used[y] = false;
                }
            }


            if(steps >= 0) {
                write.write("Case #" + x + ": " + steps);
            }
            else {
                write.write("Case #" + x + ": NOT POSSIBLE");
            }
            write.write("\n");
        }

        scan.close();
        write.close();
    }

    private static boolean solve(String[] flows, String[] devices, boolean[] used, int numDevices, String change, int index) {
        if(index == numDevices) return true;
        for(int x = 0; x < numDevices; x++) {
            if(used[x]) {
                continue;
            }
            if(compatible(devices[index], flows[x], change)) {
                used[x] = true;
                boolean bool = solve(flows, devices, used, numDevices, change, index + 1);
                used[x] = false;
                if(bool) {
                    return true;
                }
            }
        }
        return false;
    }

    private static String getChange(String string, String string2) {
        String change = "";
        for(int x = 0; x < string.length(); x++) {
            if(string.charAt(x) == string2.charAt(x)) {
                change += '0';
            }
            else {
                change += '1';
            }
        }
        return change;
    }

    private static boolean compatible(String string, String string2, String change) {
        for(int x = 0; x < string.length(); x++) {
            if(string.charAt(x) == string2.charAt(x) && change.charAt(x) == '0') {

            }
            else if(string.charAt(x) != string2.charAt(x) && change.charAt(x) == '1') {

            }
            else {
                return false;
            }
        }
        return true;
    }
}

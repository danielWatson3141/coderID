import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

/**
 * Created by Rafal on 4/12/14.
 */
public class A {

    public static void main(String[] args) {
        try {

            InputStream in = new FileInputStream("c:/projekty/codejam/src/A.in");
            Scanner scanner = new Scanner(in);
            OutputStream out = new FileOutputStream("c:/projekty/codejam/src/A.out");
            PrintWriter writer = new PrintWriter(new OutputStreamWriter(out, "utf8"));
            int t = scanner.nextInt();
            for (int i = 0; i < t; i++) {
                solve(scanner, i+1, writer);
            }
            writer.close();
        } catch (Exception e) {
            System.out.println("Error: " + e);
            e.printStackTrace();
        }
    }


    public static void solve(Scanner scanner, int t, PrintWriter out) {
        int n = scanner.nextInt();
        int l = scanner.nextInt();
        scanner.nextLine();
        String line1 = scanner.nextLine();
        String line2 = scanner.nextLine();
        String []switches = line1.split(" ");
        String []deviced = line2.split(" ");

        List<String> resultsToCheck = s(switches, deviced, 0);
        int bestResult = -1;
        for (int i = 0; i < resultsToCheck.size(); i++) {
            String config = resultsToCheck.get(i);
            if (checkResult(switches, deviced, config, 0)) {
                int result = 0;
                for (int j = 0; j < config.length(); j++) {
                    if (config.charAt(j) == '1') {
                        result++;
                    }
                }
                if (bestResult == -1 || result < bestResult) {
                    bestResult = result;
                }
            }

        }

        String resultTxt = "";
        if (bestResult == -1) {
            resultTxt = "NOT POSSIBLE";
        } else {
            resultTxt = "" + bestResult;
        }
        System.out.println("Case #" + t + ": " + resultTxt);
        out.println("Case #" + t + ": " + resultTxt);
    }

    private static boolean checkResult(String[] switches, String[] devices, String config, int pos) {
        if (pos == config.length()) return true;
        List<String> s1, s0, d1, d0;
        s1 = new ArrayList<>();
        s0 = new ArrayList<>();
        d1 = new ArrayList<>();
        d0 = new ArrayList<>();
        char conf = config.charAt(pos);
        for (int i = 0; i < switches.length; i++) {
            char c = switches[i].charAt(pos);
            if (c == '1') {
                if (conf == '0') {
                    s1.add(switches[i]);
                } else {
                    s0.add(switches[i]);
                }
            } else {
                if (conf == '0') {
                    s0.add(switches[i]);
                } else {
                    s1.add(switches[i]);
                }
            }
            c = devices[i].charAt(pos);
            if (c == '1') {
                d1.add(devices[i]);
            } else {
                d0.add(devices[i]);
            }
        }
        if (s1.size() == d1.size()) {
            if (!checkResult(s1.toArray(new String[0]), d1.toArray(new String[0]), config, pos + 1)) {
                return false;
            }
            if (!checkResult(s0.toArray(new String[0]), d0.toArray(new String[0]), config, pos + 1)) {
                return false;
            }
            return true;
        }
        return false;

    }

    public static List<String> s(String []switches, String []devices, int pos) {
        List<String> result = new ArrayList<>();
        if (pos == switches[0].length()) {
            result.add("");
            return result;
        }

        List<String> s1, s0, d1, d0;
        s1 = new ArrayList<>();
        s0 = new ArrayList<>();
        d1 = new ArrayList<>();
        d0 = new ArrayList<>();
        for (int i = 0; i < switches.length; i++) {
            char c = switches[i].charAt(pos);
            if (c == '1') {
                s1.add(switches[i]);
            } else {
                s0.add(switches[i]);
            }
            c = devices[i].charAt(pos);
            if (c == '1') {
                d1.add(devices[i]);
            } else {
                d0.add(devices[i]);
            }
        }

        int bestResult = -1;
        if (s1.size() == d1.size()) {
            List<String> s = s(switches, devices, pos+1);
            for (String s2 : s) {
                result.add("0"+ s2);
            }
        }
        if (s0.size() == d1.size()) {
            List<String> s = s(switches, devices, pos+1);
            for (String s2 : s) {
                result.add("1"+ s2);
            }
        }
        return result;
    }

}

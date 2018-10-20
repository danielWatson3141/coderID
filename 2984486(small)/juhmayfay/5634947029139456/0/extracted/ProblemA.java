package com.boosh.round1;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by jcarter on 4/11/2014.
 */
public class ProblemA {

    private static BufferedReader br;
    private static BufferedWriter bw;
    private static int n = 0;
    private static int l = 0;
    private static int cases;

    public static void main(String[] args) throws IOException {

        loadInput("CodeJam/src/main/resources/A-small-attempt1.in");
        loadOutput("CodeJam/src/main/resources/A-small-attempt1.out");

        cases = Integer.valueOf(br.readLine());

        for (int i = 1; i <= cases; i++) {

            String[] headers = br.readLine().split(" ");
            n = Integer.valueOf(headers[0]);
            l = Integer.valueOf(headers[1]);

            String input = br.readLine();
            String result = br.readLine();

            String solution = solve(input, result);
            writeCase(i, solution);
        }
        cleanup();
    }

    private static String solve(String input, String result) {
        String solution = "";

        List<String> start = stringToList(input);
        List<String> end = stringToList(result);

        if (end.containsAll(start) && start.containsAll(end)) { return "0"; };
        int min = l + 1;
        List<String> perms = new ArrayList<String>();

        getPerms(perms, "", l);

        for (String perm : perms) {
            List<String> flipped = flip(start, perm);
            if (flipped.containsAll(end) && end.containsAll(flipped)) {
                int ans = countFlips(perm);
                if (ans < min) { min = ans; }
            }
        }

        if (min > l) {
            return "NOT POSSIBLE";
        } else {
            return String.valueOf(min);
        }
    }

    private static int countFlips(String perm) {
        int i = 0;
        for (char c : perm.toCharArray()) {
            if (c == '1') {
                i++;
            }
        }
        return i;
    }

    private static List<String> flip(List<String> input, String flip) {
        List<String> flipped = new ArrayList<String>();
        for (String s: input) {
            String f = "";
            for (int i = 0; i < s.length(); i ++) {
                if (flip.charAt(i) == '0') {
                    f += s.charAt(i);
                } else {
                    if (s.charAt(i) == '1') {
                        f+= '0';
                    } else {
                        f+= '1';
                    }
                }
            }
            flipped.add(f);
        }
        return flipped;
    }

    public static void getPerms(List<String> perms, String soFar, int iterations) {
        if(iterations == 0) {
            perms.add(soFar);
        }
        else {
            getPerms(perms, soFar + "0", iterations - 1);
            getPerms(perms, soFar + "1", iterations - 1);
        }
    }

    private static List<String> stringToList(String input) {
        String[] split = input.split(" ");
        List<String> output = new ArrayList<String>();

        for (String s : split) {
            output.add(s);
        }
        return output;
    }

    private static void writeCase(int caseNum, String output) {
        try {
            bw.write("Case #" + caseNum + ": " + output);
            bw.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void loadInput(String inFile) {
        try {
            br = new BufferedReader(new FileReader(inFile));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private static void loadOutput(String outFile) {
        try {
            bw = new BufferedWriter(new FileWriter(outFile));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void cleanup() {
        try {
            br.close();
            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


}

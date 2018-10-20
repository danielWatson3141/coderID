/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Chris
 */
public class CodeJam {

    public static PrintWriter writer;

    public static boolean compare(String state, ArrayList<String> codes, int n, int l) {
        for (int i = 0; i < codes.size(); i++) {
            boolean found = false;
            for (int j = 0; j < state.length(); j += l) {
                String c = state.substring(j, j + l);
                if (codes.get(i).equals(c)) {
                    found = true;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    public static String toggle(int i, String state, int n, int l) {

        for (int counter = i; counter < n * l; counter += l) {
            if (state.charAt(counter) == '0') {

                state = state.substring(0, counter) + '1' + state.substring(counter + 1);
            } else {

                state = state.substring(0, counter) + '0' + state.substring(counter + 1);
            }

        }
        return state;
    }

    public static void process(String input_file, String output_file) throws Exception {
        writer = new PrintWriter(output_file, "UTF-8");

        File file = new File(input_file);
        Scanner in = new Scanner(file);
        int test_cases = in.nextInt();
        System.out.println("test cases: " + test_cases);
        for (int i = 1; i <= test_cases; i++) {
            int n = in.nextInt();
            int l = in.nextInt();
            System.out.println("n: " + n);
            System.out.println("l: " + l);
            String initialState = "";
            String currentState = "";
            ArrayList<String> desiredCodes = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                String code = in.next();
                for (int k = 0; k < l; k++) {
                    initialState += code.charAt(k);
                }

            }
            for (int j = 0; j < n; j++) {
                String code = in.next();
                desiredCodes.add(code);
            }
            currentState = initialState;
            //System.out.println("initial state:");
            //System.out.println(initialState);
            //System.out.println("desired codes:");
            //for (int j = 0; j < desiredCodes.size(); j++) {
              //  System.out.println(desiredCodes.get(j));
            //}

            int minSwitches = -1;
            for (int j = 0; j < (int) Math.pow(2, l); j++) {
                currentState = initialState;
                String code = Integer.toBinaryString(j);
                while (code.length() < l) {
                    code = "0" + code;
                }

                //System.out.println("test case: " + code);
                for (int k = 0; k < l; k++) {
                    if (code.charAt(k) == '1') {
                        currentState = toggle(k, currentState, n, l);
                    }
                }
                //System.out.println("initial state " + initialState);
                //System.out.println("current state " + currentState);
                boolean result = compare(currentState, desiredCodes, n, l);

                if (result) {
                    // count 1s in code
                    int switches = 0;
                    for (int z = 0; z < code.length(); z++) {
                        if (code.charAt(z) == '1') {
                            switches++;
                        }
                    }
                    if (minSwitches == -1 || switches < minSwitches) {
                        minSwitches = switches;
                    }
                }
                //print(currentState, n, l);
            }
            if (minSwitches >= 0) {
                writer.println("Case #" + i + ": " + minSwitches);
            } else {
                writer.println("Case #" + i + ": NOT POSSIBLE");
            }
        }
        writer.close();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            process("input.txt", "output.txt");
        } catch (Exception ex) {
            System.out.println("error");
        }

    }

}

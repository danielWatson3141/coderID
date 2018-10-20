/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam2014.round1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 *
 * @author narok119
 */
public class Charger {

    public static void allBinary(int l, List<String> binaryList) {
        for (int i = 0; i < Math.pow(2, l); i++) {
            StringBuilder binary = new StringBuilder(Integer.toBinaryString(i));
            for (int j = binary.length(); j < l; j++) {
                binary.insert(0, '0');
            }
            binaryList.add(binary.toString());
        }
    }

    public static void main(String args[]) throws Exception {
        int caseCount = 1;
        BufferedReader reader = new BufferedReader(new FileReader(new File(
                "/Users/narok119/Desktop/A-small-attempt0.in")));
        String txt = reader.readLine();
        while ((txt = reader.readLine()) != null) {
            System.out.print(
                    "Case #" + (caseCount++) + ": ");
            int n = Integer.valueOf(txt.split(" ")[0]);
            int l = Integer.valueOf(txt.split(" ")[1]);
            String inputStrings[] = reader.readLine().split(" ");
            String desiredStrings[] = reader.readLine().split(" ");
            List<String> binaryList = new ArrayList<String>();
            allBinary(l, binaryList);
            Collections.sort(binaryList, new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {
                    Integer countO1 = o1.length() - o1.replace("1", "").length();
                    Integer countO2 = o2.length() - o2.replace("1", "").length();
                    return countO1.compareTo(countO2);
                }
            });
            List<String> inputs = Arrays.asList(inputStrings);
            List<String> desires = Arrays.asList(desiredStrings);
            Collections.sort(desires);
            boolean found = false;
            //System.out.print("Desire : ");
            //printList(desires);
            for (String binary : binaryList) {
                List<String> newInputs = new ArrayList<String>();
                for (String input : inputs) {
                    StringBuilder newInputBuilder = new StringBuilder();
                    for (int i = 0; i < binary.length(); i++) {
                        if (binary.charAt(i) == '1') {
                            newInputBuilder.append(input.charAt(i) == '1' ? '0' : '1');
                        } else {
                            newInputBuilder.append(input.charAt(i));
                        }
                    }
                    newInputs.add(newInputBuilder.toString());
                }
                Collections.sort(newInputs);
                //System.out.print("Input : ");
                //printList(newInputs);
                boolean match = true;
                for (int i = 0; i < n; i++) {
                    if (!desires.get(i).equals(newInputs.get(i))) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    found = true;
                    System.out.println(binary.length() - binary.replace("1", "").length());
                    break;
                }
            }
            if (!found) {
                System.out.println("NOT POSSIBLE");
            }
        }
    }

    private static void printList(List<String> ss) {
        for (String s : ss) {
            System.out.print(s + ",");
        }
        System.out.println();
    }
}

package com.google.code;

import com.google.common.collect.Lists;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main {
    static String notPossible = "NOT POSSIBLE";
    private static StringComparator comparator = new StringComparator();
    ;

    public static void main(String[] args) {
        int gameNumber = 1;
        int numberOfGames = 0;
        try {

            File f = new File("C:/IntelliJ/codejam2014/in.txt");
            BufferedReader fileReader;

            FileInputStream inputStream = new FileInputStream(f);
            DataInputStream dataInputStream = new DataInputStream(inputStream);

            fileReader = new BufferedReader(new InputStreamReader(dataInputStream));
            String line;
            int x = 0;
            double c = 0;
            double eff = 0;
            int n = 0;
            int l = 0;
            while ((line = fileReader.readLine()) != null) {
                if (numberOfGames == 0) {
                    numberOfGames = Integer.parseInt(line);
                } else {
                    x = 0;
                    String answer = notPossible;
                    String[] game = line.split(" ");
                    n = Integer.parseInt(game[0]);
                    l = Integer.parseInt(game[1]);
                    String[] currentFlow = fileReader.readLine().split(" ");
                    String[] requiredFlow = fileReader.readLine().split(" ");

                    List<String> nominations = nominate(requiredFlow[0], currentFlow);
                    Collections.sort(nominations, onesComparator);
                    for (String nomination : nominations) {
                        String[] canidate = applyNomination(nomination, currentFlow);
                        requiredFlow = sortFlow(requiredFlow);
                        canidate = sortFlow(canidate);
                        if (checkMatch(canidate, requiredFlow)) {
                            answer = countOnes(nomination);
                            break;
                        }

                    }
                    //                    System.out.println(Arrays.toString(currentFlow));
                    //                    System.out.println(Arrays.toString(requiredFlow));
//                    for (int i = 0; i < l; i++) {
//                        int bit = checkBit(i, currentFlow, requiredFlow);
//                        if (bit == 0) {
//
//                        }
//                        if (bit == 1) {
//                            x++;
//                            answer = "" + x;
//                        }
//                        if (bit == -1) {
//                            answer = notPossible;
//                        }
//                    }
//                    requiredFlow = sortFlow(requiredFlow);
//                    currentFlow = sortFlow(currentFlow);
//                    if (!checkMatch(currentFlow, requiredFlow)) {
//                        answer = notPossible;
//                    }
                    System.out.printf("Case #%d: %s\n", gameNumber++, answer);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static String countOnes(String nomination) {
        int out =0;
        char[] chars = nomination.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if(chars[i] == '1'){
                out++;
            }
        }
return ""+out;
    }

    private static String[] applyNomination(String nomination, String[] currentFlow) {
        ArrayList<String> strings = Lists.newArrayList(currentFlow);
        for (int i = 0; i < nomination.length(); i++) {
            if (nomination.charAt(i) == '1') {
                for (int i1 = 0; i1 < strings.size(); i1++) {
                    String string = strings.get(i1);
                    char[] chars = string.toCharArray();
                    if (chars[i] == '1') {
                        chars[i] = '0';
                    } else {
                        chars[i] = '1';
                    }
strings.set(i1,new String(chars));
                }
            }
        }
        return strings.toArray(new String[0]);
    }

    private static List<String> nominate(String s, String[] currentFlow) {
        List<String> out = Lists.newArrayList();
        for (int i = 0; i < currentFlow.length; i++) {
            out.add(xor(s, currentFlow[i]));
        }
        ;
        return out;
    }

    private static String xor(String s, String s1) {
        String out = "";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == s1.charAt(i)) {
                out += "0";
            } else {
                out += "1";
            }

        }
        return out;


    }

    private static int checkBit(int i, String[] currentFlow, String[] requiredFlow) {
        int onesCurrent = 0;
        int zerosCurrent = 0;
        int onesReq = 0;
        int zerosReq = 0;
        for (int j = 0; j < currentFlow.length; j++) {
            //are all the bits correct or incorrect for this slot
            if (currentFlow[j].charAt(i) == '1') {
                onesCurrent++;
            } else {
                zerosCurrent++;
            }

            if (requiredFlow[j].charAt(i) == '1') {
                onesReq++;
            } else {
                zerosReq++;
            }

        }

        if (onesCurrent == onesReq) {
            return 0;
        }

        if (onesCurrent == zerosReq) {
            for (int j = 0; j < currentFlow.length; j++) {
                //are all the bits correct or incorrect for this slot
                if (currentFlow[j].charAt(i) == '1') {
                    String pre = "";
                    if (i > 0) {
                        pre = currentFlow[j].substring(0, i);
                    }
                    String post = "";
                    if (i + 1 < currentFlow[j].length()) {
                        post = currentFlow[j].substring(i + 1);
                    }
                    currentFlow[j] = pre + "0" + post;

                } else {
                    String pre = "";
                    if (i > 0) {
                        pre = currentFlow[j].substring(0, i);
                    }
                    String post = "";
                    if (i + 1 < currentFlow[j].length()) {
                        post = currentFlow[j].substring(i + 1);
                    }
                    currentFlow[j] = pre + "1" + post;
                }
            }
            return 1;
        }
        return -1;
    }

    private static boolean checkMatch(String[] currentFlow, String[] requiredFlow) {
        for (int i = 0; i < currentFlow.length; i++) {
            if (!currentFlow[i].equals(requiredFlow[i])) {
                return false;

            }
        }
        return true;
    }

    private static String[] sortFlow(String[] flows) {
        ArrayList<String> flowList = Lists.newArrayList(flows);
        Collections.sort(flowList, comparator);
        return flowList.toArray(new String[0]);
    }

    static class StringComparator implements Comparator<String> {

        @Override
        public int compare(String o1, String o2) {
            for (int i = 0; i < o1.length(); i++) {
                char c = o1.charAt(i);
                char c1 = o2.charAt(i);
                if (c != c1) {
                    return c - c1;
                }
            }
            return 0;
        }
    }

    static OnesComparator onesComparator = new OnesComparator();

    static class OnesComparator implements Comparator<String> {

        @Override
        public int compare(String o1, String o2) {
            int out = 0;
            char[] chars = o1.toCharArray();
            for (int i = 0; i < chars.length; i++) {
                if (chars[i] == '1') {
                    out++;
                }
            }
            chars = o2.toCharArray();
            for (int i = 0; i < chars.length; i++) {
                if (chars[i] == '1') {
                    out--;
                }
            }

            return out;
        }
    }

}



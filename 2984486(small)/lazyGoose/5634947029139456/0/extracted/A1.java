package com.tjn.codejam.round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class A1 {
    static ArrayList<String> cc = new ArrayList<String>();
    public static void main(String[] args) {
        Scanner sc = null;
        try {
            sc = new Scanner(new File("input.txt"));
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        int len = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < len; i++) {
            int L_num = sc.nextInt();
            int L_bits = sc.nextInt();
            sc.nextLine();
            String[] L = sc.nextLine().split(" ");
            String[] L2 = sc.nextLine().split(" ");
            String comb = "";
            for (int w = 0; w < L[0].length(); w++) {
                comb += w;
            }
            cc = new ArrayList<String>();
            comb1(comb);
            String ret = getN(L, L2);
            System.out.println("Case #"+(i+1)+": " + ret);
        }
    }
    // print all subsets of the characters in s
    public static void comb1(String s) { comb1("", s); }

    // print all subsets of the remaining elements, with given prefix 
    private static void comb1(String prefix, String s) {
        if (s.length() > 0) {
            cc.add(prefix + s.charAt(0));
            comb1(prefix + s.charAt(0), s.substring(1));
            comb1(prefix,               s.substring(1));
        }
    } 
    public static String getN(String[] L, String[] L2) {
        int min = Integer.MAX_VALUE;
        int flip = 0;
        String[] dummy = L.clone();
        Arrays.sort(L2);
        Arrays.sort(L);
        for (int i = 0; i < L.length; i++) {
          if (!L[i].equals(L2[i])) break;
          if (i == L.length-1) {
              return String.valueOf(flip);
          }
        }


        for (int i = 0; i < cc.size(); i++) {
            L = dummy.clone();
            for (int j = 0; j < cc.get(i).length(); j++) {
                for (int k = 0; k < L.length; k++) {
                    StringBuilder tmp = new StringBuilder(L[k]);
                    int index = cc.get(i).charAt(j)-'0';
                    if( L[k].charAt(index) == '1' ) {
                        tmp.setCharAt(index, '0');
                    } else {
                        tmp.setCharAt(index, '1');
                    }
                    L[k] = tmp.toString();
                }
                Arrays.sort(L);
                for (int k = 0; k < L.length; k++) {
                    if (!L[k].equals(L2[k])) break;
                    if (k == L.length-1) {
                        if (min > cc.get(i).length()) min = cc.get(i).length();
                    }
                }
            }

        }
        
        if (min != Integer.MAX_VALUE) return String.valueOf(min);
        else return "NOT POSSIBLE";
    }

}

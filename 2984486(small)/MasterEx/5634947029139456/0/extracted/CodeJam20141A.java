/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam20141a;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author periklis
 */
public class CodeJam20141A {
    private static int testCases;
    static class Case{
        int N = 0;
        int L = 0;
        ArrayList<Integer> devices = new ArrayList<>();
        ArrayList<Integer> switches = new ArrayList<>();
    }
    static Case[] cases;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        // TODO code application logic here
        parse(args[0]);
//        printCases();
        checkAll();
    }
    
    public static void parse(String filename) throws FileNotFoundException {
        Scanner scan = new Scanner(new File(filename));
        testCases = scan.nextInt();
        scan.nextLine(); // skip
        cases = new Case[testCases];
        for(int i=0;i<testCases;i++) {
            Case tcase = new Case();
            Scanner line = new Scanner(scan.nextLine());
            tcase.N = line.nextInt();
            tcase.L = line.nextInt();
            line = new Scanner(scan.nextLine());
            for(int j=0;j<tcase.N;j++)
                tcase.devices.add(Integer.parseInt(line.next(),2));            
            line = new Scanner(scan.nextLine());
            for(int j=0;j<tcase.N;j++)
                tcase.switches.add(Integer.parseInt(line.next(),2));
            cases[i] = tcase;
        }
    }
    
    public static void printCases() {
        for(int i=0;i<testCases;i++) {
            Case tcase = cases[i];
            System.out.println("CASE #"+(i+1)+":");
            System.out.print(tcase.N+" "+tcase.L);
            System.out.println();
            System.out.println();
        }
    }
    
    public static void checkAll() {
        for(int i=0;i<cases.length;i++) {
            int flips = getScore(i);
            if(flips>=0)
                System.out.println("Case #"+(i+1)+": "+flips);
            else
                System.out.println("Case #"+(i+1)+": NOT POSSIBLE");
        }
    }
    
    public static int getScore(int i) {
        Case tcase = cases[i];
        for(int j=0; j<Math.pow(2, tcase.L);j++) {
            int[] arr = new int[tcase.switches.size()];
            int s = 0;
            for(int swit: tcase.switches) {
                arr[s++] = swit ^ j;
            }
            if(compAll(tcase, arr)) {
                return Integer.bitCount(j);
            }
        }
        return -1;
    }
    
    public static boolean compAll(Case tcase, int[] a) {
        int count = 0;
        for(int dev : tcase.devices)
            for(int i=0;i<a.length;i++)
                if(dev == a[i]) {
                    count ++ ;                 
                }
        return (count == a.length);
    }
}

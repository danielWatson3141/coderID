/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author test5
 */
public class Problem3 {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("src/round1a/C-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new File("src/round1a/out.txt"));
        int cutoff = 486;
        int T = sc.nextInt();
        for (int tc = 0; tc < T; tc++) {
            String out = "";
            
            int N = sc.nextInt();

            int[] a = new int[1000];
            for (int i = 0; i < 1000; i++) {
                a[i] = sc.nextInt();
            }

            int inplace = 0;

            for (int i = 0; i < 1000; i++) {
                if (a[i] <= i) {
                    inplace++;
                }
            }

            //System.out.println(inplace);

            if (inplace <= cutoff) // BAD! 
            {
                out = "BAD";
            } else {
                out = "GOOD";
            }

            System.out.println("Case #" + (tc + 1) + ": " + out);
            pw.println("Case #" + (tc + 1) + ": " + out);
        }
        pw.close();
    }
}

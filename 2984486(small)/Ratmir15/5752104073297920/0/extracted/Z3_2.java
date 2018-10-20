package c2014_c.c2014_r1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;

public class Z3_2 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z3.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\C-small-attempt2.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        long alldiff = 0;
        int cb = 0;
        for (int ti = 1; ti <= tn; ti++) {
            int n = scanner.nextInt();
            int [] a = new int[n];
            int diff = 0;
            for (int i=0;i<n-1;i++) {
                a[i] = scanner.nextInt();
                diff += Math.abs(i-a[i]);
            }
            System.out.println(diff);
            String s;
            if (diff<100000) {
                s = "Case #" + ti + ": BAD";
                cb++;

            } else {
                s = "Case #" + ti + ": GOOD";
            }
            alldiff += diff;
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
        System.out.println(alldiff/tn);
        System.out.println(cb);
    }

}

package c2014_c.c2014_r1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;

public class Z1_1 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z1.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-small-attempt1.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int n = scanner.nextInt();
            int l = scanner.nextInt();
            //String s1 = scanner.next();
            //String s2 = scanner.next();
            String[] l1 = new String[n];
            HashSet<String> set1 = new HashSet<String>();
            for (int i=0;i<n;i++) {
                l1[i] = scanner.next();
                set1.add(l1[i]);
            }
            String[] l2 = new String[n];
            for (int i=0;i<n;i++) {
                l2[i] = scanner.next();
            }
            //s1.split(" ");
            //String[] l2 = s2.split(" ");
            int min = Integer.MAX_VALUE;
            for (int mask=0;mask<2<<l;mask++) {
                int cnt = 0;
                //String[] cur = s2.split(" ");
                char [][] chars = new char[n][l];
                for (int j=0;j<n;j++) {
                    chars[j] = l2[j].toCharArray();
                }
                for (int i = 0; i < l; i++) {
                    if ((mask & 1 << i) != 0) {
                        cnt++;
                        for (int j=0;j<n;j++) {
                            if (chars[j][i] == '0') {
                                chars[j][i] = '1';
                            } else {
                                chars[j][i] = '0';
                            }
                        }
                    }
                }
                HashSet<String> set2 = new HashSet<String>();
                for (int i=0;i<n;i++) {
                    set2.add(new String(chars[i]));
                    //System.out.println(chars[i]);
                }
                if (set1.equals(set2)) {
                    if (cnt<min) {
                        //System.out.println(mask);
                        min = cnt;
                    }
                }
            }
            String s;
            if (min==Integer.MAX_VALUE) {
                s = "Case #" + ti + ": NOT POSSIBLE";
            } else {
                s = "Case #" + ti + ": "+min;
            }
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

}

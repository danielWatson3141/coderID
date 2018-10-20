package c2014_c.c2014_r1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;

public class Z2_1 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z2.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-small-attempt1.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int n = scanner.nextInt();
            int[][] matrix = new int[n][n];
            for (int i=0;i<n-1;i++) {
                int x = scanner.nextInt();
                int y = scanner.nextInt();
                matrix[x-1][y-1] = 1;
                matrix[y-1][x-1] = 1;
            }
            int max = -1;
            for (int mask=0;mask<2<<n;mask++) {
                int flag = 0;
                int flag2 = 0;
                int flag0 = 0;
                int c = 0;
                for (int i = 0; i < n; i++) {
                    int cnt = 0;
                    if ((mask & 1 << i) != 0) {
                        //System.out.println("use "+i );
                        c++;
                        for (int j=0;j<n;j++) {
                            if ((mask & 1 << j) != 0) {
                                if (matrix[i][j]==1) {
                                    cnt++;
                                }
                            }
                        }
                        if (cnt==0) {
                            c--;
                        }
                    }
                    if (cnt!=1 && cnt!=3 && cnt!=0) {
                        flag++;
                    }
                    if (cnt==2) {
                        flag2++;
                    }
                    //System.out.println("used "+i+cnt);
                }
                if (flag2==1 && flag==1) {
                    if (c>max) {
                        max = c;
                        //System.out.println(mask+" "+c+" "+max);
                    }
                }
            }
            String s;
            if (max==-1) {
                //throw new UnsupportedOperationException();
                //s = "PIZ";//"Case #" + ti + ": "+(n);
                s = "Case #" + ti + ": "+(n-1);
            } else {
                s = "Case #" + ti + ": "+(n-max);
            }
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

}

package cj141aa;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class CJ141AA {

    static BufferedReader inp;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException, IOException {
        inp = new BufferedReader(new FileReader("in.txt"));
        int t = Integer.parseInt(inp.readLine());
        String mi;
        String[] k = null;
        PrintWriter outp = new PrintWriter(new FileWriter("C:\\Users\\Faheem\\Desktop\\Output.txt"));

        for (int i = 0; i < t; i++) {
            outp.print("Case #" + (i + 1) + ": ");
            mi = inp.readLine();
            k = mi.split(" ");
            int n = Integer.parseInt(k[0]);
            int l = Integer.parseInt(k[1]);
            mi = inp.readLine();
            String[] outlets = new String[n];
            String[] devices = new String[n];
            outlets = mi.split(" ");
            mi = inp.readLine();
            devices = mi.split(" ");
            String[][] map = new String[n][n];
            for (int j = 0; j < n; j++) {
                for (int m = 0; m < n; m++) {
                    map[j][m] = "";
                }
            }
            for (int j = 0; j < n; j++) {
                for (int m = 0; m < n; m++) {
                    for (int o = 0; o < l; o++) {
                        if (outlets[j].charAt(o) != devices[m].charAt(o)) {
                            map[j][m] += "1";
                        } else {
                            map[j][m] += "0";
                        }
                    }
                }
            }
            int count = 1;
            int ans = 1000;
            String anss = "";
            for (int j = 0; j < n; j++) {
                count = 1;
                for (int m = 0; m < n; m++) {
                    for (int p = 0; p < n; p++) {
                        if (m == 0 && p == j) {

                            continue;
                        } else if (map[0][j].equals(map[m][p])) {
                            count++;
                        }
                    }
                }
                if (count == n) {
                    int tans = 0;
                    for (int y = 0; y < l; y++) {
                        if (map[0][j].charAt(y) == '1') {
                            tans++;
                        }
                    }
                    if(tans<ans){
                        ans=tans;
                    }
                }
            }

            if (ans == 1000) {
                outp.println("NOT POSSIBLE");
            } else {
                outp.println(ans);
            }
        }
        outp.close();
    }
}

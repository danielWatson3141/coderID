package cj141ac;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;

public class CJ141AC {

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
            int n = Integer.parseInt(inp.readLine());
            mi = inp.readLine();
            k = mi.split(" ");
            int[] nums = new int[n];
            for (int j = 0; j < n; j++) {
                nums[j] = Integer.parseInt(k[j]);
            }
            int[] good = new int[n];
            int[] bad = new int[n];
            for (int j = 0; j < n; j++) {
                good[j] = j;
            }
            for (int j = 0; j < n; j++) {
                Random r = new Random();
                int Low = j;
                int High = n;
                int p = r.nextInt(High - Low) + Low;
                good[j] = good[p];
            }
            for (int j = 0; j < n; j++) {
                Random r = new Random();
                int Low = 0;
                int High = n;
                int p = r.nextInt(High - Low) + Low;
                bad[j] = bad[p];
            }
            int ga = 0;
            int gb = 0;
            for (int j = 0; j < n; j++) {
                ga+=Math.abs(good[j]-nums[j]);
                gb+=Math.abs(bad[j]-nums[j]);
            }
            String ans = "";
            if(ga>=gb){
                ans="GOOD";                
            }
            else{
                ans = "BAD";
            }
            outp.println(ans);
        }

        outp.close();
    }
}

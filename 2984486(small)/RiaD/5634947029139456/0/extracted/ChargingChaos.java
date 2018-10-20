package main;

import name.admitriev.spsl.io.OutputWriter;
import name.admitriev.spsl.io.Reader;

import java.util.HashSet;

public class ChargingChaos {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int l = in.nextInt();

        String[] a = in.nextStringArray(n);
        String[] b = in.nextStringArray(n);



        int best = l + 1;
        for(int i = 0; i < n; ++i) {
            boolean[] change = new boolean[l];
            for(int j = 0; j < l; ++j) {
                change[j] = a[0].charAt(j) != b[i].charAt(j);
            }
            HashSet<String> have = new HashSet<String>();
            HashSet<String> need = new HashSet<String>();
            for (String s : b) {
                need.add(s);
            }
            for (String s : a) {
                StringBuffer sb = new StringBuffer(s);
                for(int j = 0; j < l; ++j) {
                    if(change[j])
                        sb.setCharAt(j, (char) ('0' + '1' - sb.charAt(j)));
                }
                have.add(sb.toString());
            }

            if(have.equals(need)) {
                int currentChange = 0;
                for (boolean bool : change) {
                    if(bool)
                        ++currentChange;
                }
                best = Math.min(best, currentChange);
            }
        }
        out.print("Case #" + testNumber + ": ");
        if(best > l) {
            out.println("NOT POSSIBLE");
        }
        else
            out.println(best);
    }
}

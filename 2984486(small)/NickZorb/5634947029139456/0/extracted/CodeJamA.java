package round1A;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;

public class CodeJamA {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        CodeJamA jam = new CodeJamA();
        jam.solve("round1A/A-small-attempt0.in");
    }

    public void solve(String file) throws FileNotFoundException, IOException {
        File f = new File(file);
        FileReader fin = new FileReader(f);
        BufferedReader in = new BufferedReader(fin);
        int cases = Integer.parseInt(in.readLine());
        File outF = new File("resultsA.txt");
        PrintStream out = new PrintStream(outF);
        for (int i = 1; i <= cases; i++) {
            String line = in.readLine();
            int o = Integer.parseInt(line.split(" ")[0]);
            int l = Integer.parseInt(line.split(" ")[1]);
            ArrayList<String> outs = new ArrayList();
            ArrayList<String> devs = new ArrayList();
            outs.addAll(Arrays.asList(in.readLine().split(" ")));
            devs.addAll(Arrays.asList(in.readLine().split(" ")));
            ArrayList<boolean[]> switched = new ArrayList();
            boolean[] cur = new boolean[l];
            for (int j = 0; j < l; j++) {
                cur[j] = false;
            }
            getCombinations(switched, 0, cur);
            int min = l + 1;
            for (boolean[] switchRotation : switched) {
                boolean valid = true;
                for (String s : devs) {
                    char[] curs = s.toCharArray();
                    for (int j = 0; j < l; j++) {
                        if(switchRotation[j]) {
                            curs[j] = curs[j] == '1' ? '0' : '1';
                        }
                    }
                    if (!outs.contains(new String(curs))) {
                        valid = false;
                    }
                }
                if (valid) {
                    int curl = 0;
                    for (boolean b : switchRotation) {
                        if (b) {
                            curl++;
                        }
                    }
                    if (curl < min) {
                        min = curl;
                    }
                }
            }
            out.print("Case #" + i + ": ");
            if (min == l + 1) {
                out.print("NOT POSSIBLE\n");
            } else {
                out.print(min + "\n");
            }
        }
    }

    public void getCombinations(ArrayList<boolean[]> combs, int depth, boolean[] cur) {
        boolean[] case1 = cur.clone();
        boolean[] case2 = cur.clone();
        case2[depth] = true;
        if (depth == cur.length - 1) {
            combs.add(case1);
            combs.add(case2);
        } else {
            getCombinations(combs, depth + 1, case1);
            getCombinations(combs, depth + 1, case2);
        }
    }
    
}

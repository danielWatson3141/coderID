package round1;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

public class ChargingChaos {
    static boolean[][] outlet;
    static boolean[][] device;
    static int L;
    static int N;
    static Boolean[] forcedSwitches;
    static int min;
    static int current;
    
    static boolean test(int index) {
        for (int n1=0; n1<N; n1++) {
            boolean found = false;
            for (int n2=0; n2<N; n2++) {
                boolean match = true;
                for (int l=0; l<=index; l++) {
                    if (outlet[n1][l] != device[n2][l]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
    
    static void check(int index) {
        if (current >= min) return;
        if (index == L) {
            if (test(L-1)) {
                min = current;
            }
            return;
        }
        if (forcedSwitches[index] != null) {
            check(index+1);
        } else {
            if (test(index)) {
                check(index+1);
            }
            for (int n=0; n<N; n++) {
                outlet[n][index] = !outlet[n][index];
            }
            current++;
            if (test(index)) {
                check(index+1);
            }
            current--;
            for (int n=0; n<N; n++) {
                outlet[n][index] = !outlet[n][index];
            }
        }
    }
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("A-small-attempt3.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            N = in.nextInt();
            L = in.nextInt();
            in.nextLine();
            outlet = new boolean[N][L];
            String s = in.nextLine();
            StringTokenizer st = new StringTokenizer(s);
            for (int n=0; n<N; n++) {
                s = st.nextToken();
                for (int l=0; l<L; l++) {
                    char c = s.charAt(l);
                    outlet[n][l] = (c == '1');
                }
            }
            device = new boolean[N][L];
            s = in.nextLine();
            st = new StringTokenizer(s);
            for (int n=0; n<N; n++) {
                s = st.nextToken();
                for (int l=0; l<L; l++) {
                    char c = s.charAt(l);
                    device[n][l] = (c == '1');
                }
            }
            forcedSwitches = new Boolean[L];
            int forced = 0;
            boolean impossible = false;
            for (int l=0; l<L; l++) {
                int deviceOnes = 0;
                int outletOnes = 0;
                for (int n=0; n<N; n++) {
                    if (outlet[n][l]) outletOnes++;
                    if (device[n][l]) deviceOnes++;
                }
                if (deviceOnes == outletOnes) {
                    if (N-deviceOnes == outletOnes) {
                        // not clear
                    } else {
                        forcedSwitches[l] = Boolean.FALSE;
                    }
                } else {
                    if (N-deviceOnes == outletOnes) {
                        forcedSwitches[l] = Boolean.TRUE;
                        forced++;
                        for (int n=0; n<N; n++) {
                            outlet[n][l] = !outlet[n][l];
                        }
                    } else {
                        impossible = true;
                        break;
                    }
                }
            }
            if (!impossible) {
                min = Integer.MAX_VALUE;
                current = forced;
                check(0);
            }
            if (min == Integer.MAX_VALUE) {
                impossible = true;
            }
            
            out.println("Case #"+(t+1)+": " + (impossible ? "NOT POSSIBLE" : min));
        }

        out.close();
    }
    
}

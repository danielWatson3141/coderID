import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

import java.util.ArrayList;
import java.util.TreeSet;

/**
 * PROBLEM: Charging Chaos
 * DATASET: large
 * BUILD:   1
 * @author logan.z
 */
public class ChargingChaos {
    public static final String PROBLEM = "ChargingChaos";
    public static final String DATASET = "A-large.in";
    public static Scanner in;
    public static PrintStream out;

    public static void setup() throws IOException {
    	in = new Scanner(new File(DATASET));
    	out = new PrintStream(new FileOutputStream(PROBLEM+".out", false));
    }

    public static void main(String[] args) throws Exception {
    	setup();
        System.out.println("Running "+PROBLEM);

        int cases = in.nextInt();
        in.nextLine();

        for (int i=0; i<cases; i++) {
            int N = in.nextInt(), L = in.nextInt();
            go(i+1,N,L);
        }
    }

    public static void go(int casen, int N, int L) {
			String[] outlets = new String[N];
            for (int j=0; j<N; j++) {
            	outlets[j] = in.next();
            }

            String[] devices = new String[N];
            for (int j=0; j<N; j++) {
            	devices[j] = in.next();
            }

            //find all bits that could be flipped
            ArrayList<ArrayList<String>> xors = new ArrayList<ArrayList<String>>();
            for (int i=0; i<N; i++) {
                xors.add(new ArrayList<String>());
                for (int j=0; j<N; j++) {
                    xors.get(i).add(xor(devices[i],outlets[j]));
                }
            }

            //only keep those that are common
            for (int i=1; i<N; i++) {
                    xors.get(0).retainAll(xors.get(i));
                }
            ArrayList<String> possible = xors.get(0);

            String outpt = "NOT POSSIBLE";
            if (possible.size()>0) {
                // //remove non-unique mappings
                // for (int i=0; i<possible.size(); i++) {
                //     TreeSet<String> mappings = new TreeSet<String>();
                //     for (int d=0; d<N; d++) {

                //     }
                // }

                //find lowest sum of xors
                int lsum = sumBits(possible.get(0));
                for (int i=1; i<possible.size(); i++) {
                    int s = sumBits(possible.get(i));
                    if (s<lsum) {lsum=s;}
                }

                outpt = ""+lsum;
            }

            out.println("Case #"+casen+": "+outpt);
    }

    public static String xor(String a, String b) {
        StringBuilder out = new StringBuilder();
        for (int i=0; i<a.length(); i++) {
            String bit = "1";
            if (a.charAt(i) == b.charAt(i)) {
                bit = "0";
            }
            out.append(bit);
        }
        return out.toString();
    }

    public static int sumBits(String input) {
        int sum = 0;
        for (int i=0; i<input.length(); i++) {
            if (input.charAt(i) == '1') {
                sum++;
            }
        }
        return sum;
    }

    // public static TreeSet<String> getGood(String[] outlets, String device, String switches) {
    //     TreeSet<String> out = new TreeSet<String>();
    //     for (int i=0; i<outlets.length; i++) {
    //         if (xor(device,flip(outlets[i],switches)).indexOf("1")<0) {
    //             out.add(outlets[i]);
    //         }
    //     }
    // }
}
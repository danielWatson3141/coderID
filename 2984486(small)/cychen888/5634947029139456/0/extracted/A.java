import java.util.*;
import java.io.*;


public class A {

    public static PrintWriter log;

    public static void main(String[] args) {
        String fileName = "A-small-attempt1";
        String inputFile = fileName+".in.txt";
        String outputFile = fileName+".out.txt";
        String logFile = fileName+".log.txt";

        File in = new File(inputFile);
        try {
            PrintWriter out = new PrintWriter(outputFile);
            log = new PrintWriter(logFile);
            Scanner scan = new Scanner(in);
            int numTest = scan.nextInt();
            for (int testCase = 1; testCase <= numTest; testCase++) {


                // for integer: scan.nextInt();     // -2147483648 ~ 2147483647 or -10^-9 ~ 10^9
                // for long: scan.nextLong();       // -18446744073709551616L ~ 18446744073709551615L or -10^19 ~ 10^19
                // for double: scan.nextDouble();
                // for string: scan.nextLine();
                // for string: scan.next(); // Finds and returns the next complete token from this scanner.

                // input variables are 3 scalars
                // read
                int N = scan.nextInt();
                int L = scan.nextInt();
                String[] init = new String[N];
                for (int i = 0; i < N; i++) {
                    init[i] = scan.next();
                }
                String[] dev = new String[N];
                for (int i = 0; i < N; i++) {
                    dev[i] = scan.next();
                }
                
                // print
                String logStr = "N = " + N + ", L = " + L + ", init = " + init.toString() + ", dev = " + dev.toString();
                System.out.format("Case #%d: %s\n", testCase, logStr);
                log.format("Case #%d: %s\n", testCase, logStr);

                // solve
                String result  = solve2(N, L, init, dev);
                out.format("Case #%d: %s\n", testCase, result);

                // input contains 2 2-D arrays
                /*
                // read
                int[][] first = new int[4][4];
                int[][] second = new int[4][4];
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        first[i][j] = scan.nextInt();
                    }
                }
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        second[i][j] = scan.nextInt();
                    }
                }

                // print
                System.out.format("Case #%d:\n", testCase);
                log.format("Case #%d:\n", testCase);
                for (int i = 0; i < first.length; i++) {
                    String logStr = Arrays.toString(first[i]);
                    System.out.format("%s\n", logStr);
                    log.format("%s\n", logStr);
                }
                for (int i = 0; i < second.length; i++) {
                    String logStr = Arrays.toString(second[i]);
                    System.out.format("%s\n", logStr);
                    log.format("%s\n", logStr);
                }

                // solve
                double result = solve(first, second);
                out.format("Case #%d: %.7f\n", testCase, result);
                */

            }
            out.close();
            log.close();
        }catch(FileNotFoundException e){
            e.printStackTrace();
        }
    }

    public static String solve2(int N, int L, String[] init, String[] dev) {
        // match the first dev with all init
        Arrays.sort(init);
        Arrays.sort(dev);
        int min = L+1;
        for (int i = 0; i < N; i++) {
            String[] state = new String[N];
            int num = 0;
            ArrayList<Integer> flip = new ArrayList<Integer>();
            for (int j = 0; j < L; j++) {
                if (dev[0].charAt(j) != init[i].charAt(j)){
                    flip.add(j);
                }
            }
            num = flip.size();
            //construct
            for (int k = 0; k < N; k++) {
                state[k] = "";
                for (int m = 0; m < L; m++) {
                    String s = "";
                    if (flip.contains(m)) {
                        s = (init[k].charAt(m) == '0')? "1":"0";
                    } else {
                        s = init[k].substring(m, m+1);
                    }
                    state[k] += s;
                }
            }
            Arrays.sort(state);
            // match the remaining dev
            for (int k = 0; k < N; k++) {
                System.out.println("i = " + i + ", k = " + k + ", Comparing " + dev[k] + " with " + state[k]);
                if (state[k].compareTo(dev[k]) != 0){
                    num = L+1;
                    break;
                }
            }
            min = Math.min(min, num);
        }
        return (min == L+1)? "NOT POSSIBLE":Integer.toString(min);
        
    }
    
    
    
    public static String solve(int N, int L, String[] init, String[] dev) {
    //public static double solve(int[][] first, int[][] second) {
        ArrayList<Integer> possFlip = new ArrayList<Integer>();
        int[] devSum = new int[L];
        int[] initSum = new int[L];
        int num = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < N; j++) {
                if (dev[j].charAt(i) == '1'){
                    devSum[i]++;
                }
                if (init[j].charAt(i) == '1'){
                    initSum[i]++;
                }
            }
            System.out.println("i = " + i + ", initSum = " + initSum[i] + ", devSum = " + devSum[i]);
            if (initSum[i] == devSum[i]) {
                if (initSum[i] == N-devSum[i]) {
                    possFlip.add(i); //may stil have to flip
                }
                // do nothing
            } else if (initSum[i] == N-devSum[i]){
                // flip init
                num++;
                for (int j = 0; j < N; j++) {
                    String newchar = "1";
                    if (dev[j].charAt(i) == '1'){
                        newchar = "0";
                    }
                    dev[j] = dev[j].substring(0,i) + newchar + dev[j].substring(i+1);
                    
                }
            } else {
                return "NOT POSSIBLE";
            }
            
                
        }
        
        System.out.println("NUMBERS MATCH!!!");


        for (int i = 0; i < N; i++) {
            System.out.println("Comparing " + init[i] + " with " + dev[i]);
            if (init[i].compareTo(dev[i]) != 0){
                return "NOT POSSIBLE";
            }
        }
        
        return Integer.toString(num);
    }

}

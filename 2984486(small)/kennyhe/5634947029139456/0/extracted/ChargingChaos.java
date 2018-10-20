

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class ChargingChaos {
    int N = 0;
    int L = 0;
    String[] strOutputs = null;
    String[] strTargets = null;
    int[] outputs = null;
    int[] targets = null;
    int[][] dist = null;
    long[][] diff = null;
    
    /**
     * @param args
     */
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Please add the file name as the first parameter");
        }
        
        try {
            ChargingChaos cc = new ChargingChaos();
            BufferedReader in = new BufferedReader(new FileReader(args[0]));
            int cases = Integer.parseInt(in.readLine());
            
            for (int caseNo = 1; caseNo <= cases; caseNo++) {
                // get test case data
                String[] vars = in.readLine().split("\\s");
                cc.N = Integer.parseInt(vars[0]);
                cc.L = Integer.parseInt(vars[1]);
                
                cc.strOutputs = in.readLine().split("\\s");
                cc.strTargets = in.readLine().split("\\s");
                
                System.out.format("Case #%d: ", caseNo);
                int result = cc.getSwitchSolution();
                if (result == -1) {
                    System.out.println("NOT POSSIBLE");
                } else {
                    System.out.println(result);
                }
            }
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    
    /**
     * Find a solution and print it out. Brute Force
     */
    public int getSwitchSolution() {
        /*
         * Enumerate all arrangements, and find the possibilities
         */
        if (N == 1) {
            return getHemingDist(strOutputs[0], strTargets[0]);
        }
        
        outputs = new int[N];
        targets = new int[N];
        
        for (int i = 0; i < N; i++) {
            outputs[i] = i;
            targets[i] = i;
        }
        
        dist = new int[N][N];
        diff = new long[N][N];
        
        getAllHemingDists();
        int minHemingDist = Integer.MAX_VALUE;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] < minHemingDist) {
                
                    int[] outputs1 = new int[N - 1];
                    int[] targets1 = new int[N - 1];
                    
                    // Copy and recursively call
                    int p = 0;
                    for (int m = 0; m < N; m++) {
                        if (m != i) {
                            outputs1[p++] = outputs[m];
                        }
                    }
                    p = 0;
                    for (int m = 0; m < N; m++) {
                        if (m != j) {
                            targets1[p++] = targets[m];
                        }
                    }
                    
                    if (tryNext(N - 1, outputs1, targets1, diff[i][j])) {
                        minHemingDist = dist[i][j];
                    }
                }
            }
        }
        
        if (minHemingDist == Integer.MAX_VALUE) {
            return -1;
        } else {
            return minHemingDist;
        }
    }

    private boolean tryNext(int N, int[] outputs, int[] targets, long aDiff) {
        if (N == 1) {
            return compDiff(outputs[0], targets[0], aDiff);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (compDiff(outputs[i], targets[j], aDiff)) {
                    int[] outputs1 = new int[N - 1];
                    int[] targets1 = new int[N - 1];
                    
                    // Copy and recursively call
                    int p = 0;
                    for (int m = 0; m < N; m++) {
                        if (m != i) {
                            outputs1[p++] = outputs[m];
                        }
                    }
                    p = 0;
                    for (int m = 0; m < N; m++) {
                        if (m != j) {
                            targets1[p++] = targets[m];
                        }
                    }
                    
                    if (tryNext(N - 1, outputs1, targets1, aDiff)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }


    private int getHemingDist(String s1, String s2) {
        int hemingDist = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                hemingDist++;
            }
        }
        return hemingDist;
    }

    private void getHemingDist(int s1, int s2) {
        int hemingDist = 0;
        long aDiff = 0;
        for (int i = 0; i < L; i++) {
            if (strOutputs[s1].charAt(i) != strTargets[s2].charAt(i)) {
                hemingDist++;
                aDiff++;
            }
            aDiff <<= 1;
        }
        dist[s1][s2] = hemingDist;
        diff[s1][s2] = aDiff;
    }


    private void getAllHemingDists() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                getHemingDist(i, j);
            }
        }    
    }


    private boolean compDiff(int s1, int s2, long given) {
        return (diff[s1][s2] == given);
    }
}

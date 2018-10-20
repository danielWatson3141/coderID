/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam.round_1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

/**
 *
 * @author Philip Lanaras <flanaras@csd.auth.gr>
 */
public class ChargingChaos {
    public static HashSet<String> wanted;
    public static int N;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        
        int cases;
        
        final String filename = "A-small-attempt2.in";
        final String outFile = "A-small-attempt2.out";
        
        String[] initialBits;
        String[] wantedBits;
        int minFlips, currentFlips;
        
        //int N;
        int L;
        //----------------------------Inits-Go-Here----------------------------\\
        
        //StringBuilder strRes;
        String temp;
        
        try (BufferedReader reader = new BufferedReader(new FileReader(filename));
                BufferedWriter writer = new BufferedWriter(new FileWriter(outFile))) {
            
            //Num of Cases
            temp = reader.readLine();
            cases = Integer.valueOf(temp);
            
            for (int i = 1; i <= cases; ++i) {
                temp = reader.readLine();
                initialBits = temp.split(" ");
                N = Integer.valueOf(initialBits[0]);
                L = Integer.valueOf(initialBits[1]);
                
                temp = reader.readLine();
                initialBits = temp.split(" ");
                
                temp = reader.readLine();
                wantedBits = temp.split(" ");
                //------------------------Inits-Go-Here------------------------\\
                char[][] arrayTemp = null;
                boolean ok = true;
                wanted = new HashSet<>();
                for (int j = 0; j < N; ++j) {
                    wanted.add(wantedBits[j]/*.toCharArray()*/);
                }
                
                minFlips = 45; //over max possible flips
                /*
                for (int j = 0; j < N; ++j) {
                    currentFlips = 0;
                    arrayTemp = new char [N][];
                    for (int k = 0; k < N; ++k) {
                        arrayTemp[k] = initialBits[k].toCharArray();
                    }
                    
                    for (int l = 0; l < N; ++l) {
                        if (!wanted.contains(String.valueOf(arrayTemp[l]))) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        minFlips = Math.min(currentFlips, minFlips);
                    }
                    
                    for (int k = j; k < L && currentFlips < minFlips; ++k) {
                        ok = true;
                        currentFlips++;
                        for (int l = 0; l < N; ++l) {
                            //swap
                            if (arrayTemp[l][k] == '1') {
                                arrayTemp[l][k] = '0';
                            } else {
                                if (arrayTemp[l][k] == '0') {
                                    arrayTemp[l][k] = '1';
                                } else {
                                    throw new IllegalArgumentException("waaaaaaa?");
                                }
                            }
                        }

                        //check
                        for (int l = 0; l < N; ++l) {
                            if (!wanted.contains(String.valueOf(arrayTemp[l]))) {
                                ok = false;
                            }
                        }
                        if (ok) {
                            minFlips = Math.min(currentFlips, minFlips);
                        }
                   }
                }
                */
                minFlips = check(0, minFlips, initialBits, 0);
                
                String output;
                if (minFlips < 45) {
                    output = String.valueOf(minFlips);
                } else {
                    output = "NOT POSSIBLE";
                }
                
                temp = "Case #" + i + ": " + output;
                // String.format("Case #%d: %.7f", i/*, cookie.fooBar()*/);
                System.out.println(temp);
                
                writer.write(temp);
                writer.newLine();
            }
        }

    }
    
    private static int check(int indexForZero, int minFlips, String[] str, int currentFlips) {
        
        char[][] arrayTemp = new char [N][];
        for (int k = 0; k < N; ++k) {
            arrayTemp[k] = str[k].toCharArray();
        }
        for (int l = 0; l < N; ++l) {
            //swap
            if (arrayTemp[l][indexForZero] == '1') {
                arrayTemp[l][indexForZero] = '0';
            } else {
                arrayTemp[l][indexForZero] = '1';
            }
        }
        
        boolean ok1 = true, ok2 = true;
        for (int l = 0; l < N; ++l) {
            if (!wanted.contains(str[l])) {
                ok1 = false;
            }
            if (!wanted.contains(String.valueOf(arrayTemp[l]))) {
                ok2 = false;
            }
        }
        if (ok1) {
            minFlips = Math.min(currentFlips, minFlips);
        }
        if (ok2) {
            minFlips = Math.min(currentFlips + 1, minFlips);
        }
        
        String[] str1 = new String[N];
        for (int k = 0; k < N; ++k) {
            str1[k] = String.valueOf(arrayTemp[k]);
        }
        
        ++indexForZero;
        if (indexForZero < str[0].length()) {
            //if (currentFlips < minFlips) {
                minFlips = Math.min(check(indexForZero, minFlips, str, currentFlips), minFlips);
                minFlips = Math.min(check(indexForZero, minFlips, str1, currentFlips + 1), minFlips);
            //}
        }
        
        return minFlips;
    }
    
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author AdamaMahefa
 */
public class Utils {
    public static String[] splitBySpace(String in){
        return in.split("\\s+");
    }
    
    public static int[] splitIntoIntegers(String in){
        String[] t = in.split("\\s+");
        int[] res = new int[t.length];
        for (int i = 0; i < res.length; i++) {
            res[i] = Integer.valueOf(t[i]);
        }
        return res;
    }
    
    public static double[] splitIntoDoubles(String in){
        String[] t = in.split("\\s+");
        double[] res = new double[t.length];
        for (int i = 0; i < res.length; i++) {
            res[i] = Double.valueOf(t[i]);
        }
        return res;
    }
    
    public static String[] readLines(int nLine, BufferedReader br){
        String[] res = new String[nLine];
        for (int i = 0; i < res.length; i++) {
            try {
                res[i] = br.readLine();
            } catch (IOException ex) {
                Logger.getLogger(Utils.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return res;
    }
    
    public static void writeLines(String[] lines, BufferedWriter bw){
        for(String line : lines){
            try {
                bw.write(line);
                bw.newLine();
            } catch (IOException ex) {
                Logger.getLogger(Utils.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
}
    

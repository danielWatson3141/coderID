/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam;

import java.util.*;

/**
 *
 * @author Study
 */
public class Case5 implements CodeJamProblem{

    int n, l;
    boolean[][] outlet, flow;
        
    public boolean check(){
        for (int i = 0; i < n; i++) {
            boolean none = true;
            for (int j = 0; j < n; j++){
                int k = 0;
                while (k < l && flow[i][k] == outlet[j][k]) k++;
                if (k == l) {
                    none = false;
                    break;
                }
            }
            if (none) return false;
        }
        return true;
    }
    
    public void sw(int pos){
        for (int i = 0; i < n; i++)
            outlet[i][pos] = !outlet[i][pos];
    }
    
    public int findMin(int pos){
        if (check()) return 0;
        if (pos == l) return 1000;
        else {
            int v1, v2;
            v1 = findMin(pos+1);
            sw(pos);
            v2 = 1+findMin(pos+1);
            sw(pos);
            if (v1 >= 1000 && v2 >= 1000) return 1000;
            if (v1 >= 1000) return v2;
            if (v2 >= 1000) return v1;
            return Math.min(v1, v2);
        }
    }
    
    @Override
    public String[] solve() {
        int res = findMin(0);
        if (res == 1000) return new String[]{"NOT POSSIBLE"};
        return new String[]{Integer.toString(res)};
    }

    @Override
    public int inputLineNumber() {
        return 3;
    }

    @Override
    public void collectData(String[] il) {
        int[] a = Utils.splitIntoIntegers(il[0]);
        n = a[0]; l = a[1];
        outlet = new boolean[n][l];
        flow = new boolean[n][l];
        int i = 0;
        for(String s : Utils.splitBySpace(il[1])){
            for (int j = 0; j < l; j++) {
                outlet[i][j] = s.charAt(j) == '1';
            }
            i++;
        }
        i = 0;
        for(String s : Utils.splitBySpace(il[2])){
            for (int j = 0; j < l; j++) {
                flow[i][j] = s.charAt(j) == '1';
            }
            i++;
        }
    }
    
}

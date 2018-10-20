/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam;

/**
 *
 * @author AdamaMahefa
 */
public interface CodeJamProblem {
    public String[] solve();  
    public int inputLineNumber();
    public void collectData(String[] il);
}

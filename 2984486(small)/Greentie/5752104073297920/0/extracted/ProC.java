/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/**
 *
 * @author admin
 */
public class ProC implements Problem {

    @Override
    public void solveSmall(Scanner in, PrintStream out) {
        int count = in.nextInt();
        int max=500*999;
        int th=259750;
        int counts=0;
        for (int i = 1; i <= count; i++) {
            String result = "";
            int length=in.nextInt();
            int[] p=new int[length];
            for(int j=0;j<length;j++)
                p[j]=in.nextInt();
            int r=check(p);
            if(r>th){result="GOOD";counts++;if(count>=109)System.out.println(th);}
            else result="BAD";
            out.printf("Case #%d: %s\n", i, result);

        }
    }

    
    public int check(int[] p){
        int n=0;
        for(int i=0;i<p.length-1;i++){
            int x=p[i]; 
            for(int j=i+1;j<p.length;j++){
                if(p[j]<x)n++;
            }
        }
        return n;
    }

    @Override
    public void solveLarge(Scanner in, PrintStream out) {
        int count = in.nextInt();
        for (int i = 1; i <= count; i++) {

            out.printf("Case #%d: %s\n", i, "result");
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Problem C = new ProC();
        String prepath = "C:\\Documents and Settings\\GreenTie\\My Documents\\NetBeansProjects\\GoogleCodeJam2014\\";
        String testname = "test-C";
        String smallname = "C-small-attempt1";
        String largename = "C-large";
        File tin = new File(prepath + testname + ".txt");
        File sin = new File(prepath + smallname + ".in");
        File lin = new File(prepath + largename + ".in");
        PrintStream testo = new PrintStream(prepath + testname + ".out");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
        C.solveSmall(new Scanner(tin), testo);
        C.solveSmall(new Scanner(sin), smallo);
        //System.out.println(prepath + smallname + ".out");
        // C.solveLarge(new Scanner(lin), largeo);
        //System.out.println(prepath + largename + ".out");
    }
}

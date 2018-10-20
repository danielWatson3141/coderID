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
public class ProA implements Problem {

    @Override
    public void solveSmall(Scanner in, PrintStream out) {
        int count = in.nextInt();
        for (int i = 1; i <= count; i++) {
            int Outlet=in.nextInt();
            int s=in.nextInt();
            int q=1<<s;
            int[] input=new int[Outlet];
            int[] require=new int[Outlet];
            
            for(int j=0;j<Outlet;j++)input[j]=in.nextInt(2);
            for(int j=0;j<Outlet;j++)require[j]=in.nextInt(2);  
//                        String[] input=new String[Outlet];
//            String[] require=new String[Outlet];
//            
//            for(int j=0;j<Outlet;j++){input[j]=in.next("[01]{"+s+"}");}
//            for(int j=0;j<Outlet;j++){require[j]=in.next("[01]{"+s+"}");}
            String result="NOT POSSIBLE";
            Arrays.sort(require);
            result=compute(input,require,q,s);
            
            
            out.printf("Case #%d: %s\n", i, result);
        }
    }
    
    
    public String compute(int[] input,int[] require,int q,int t){
       int min=t;
       boolean total=false;
        for(int k=0;k<q;k++){
           int[] temp=Arrays.copyOf(input, input.length);
         
           for(int i=0;i<input.length;i++){ 
             
                 
                  temp[i]^=k;               
                  //System.out.println(temp[i]);
           }
           
           Arrays.sort(temp);
           boolean test=true;
           for(int i=0;i<temp.length;i++){
               test&=temp[i]==require[i];
               if(test==false)break;
           }
           if(test==false)continue;
           
           if(test){
               total=true;
               int x=check(k);
              
               if(x<min)min=x;
           }
       }
       return ""+(total?min:"NOT POSSIBLE");
    }
    
    public int check(int k){
        char[] t=Integer.toBinaryString(k).toCharArray();
        int c=0;
        for(int i=0;i<t.length;i++)if(t[i]=='1')c++;
        return c;
    }

    @Override
    public void solveLarge(Scanner in, PrintStream out) {
        int count = in.nextInt();
        for (int i = 1; i <= count; i++) {
            //out.printf("Case #%d: %s\n",i,"result");
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Problem A = new ProA();
        String prepath = "C:\\Documents and Settings\\GreenTie\\My Documents\\NetBeansProjects\\GoogleCodeJam2014\\";
        //prepath = downpath;
        String testname = "test-A";
        String smallname = "A-small-attempt0";
        String largename = "A-large";
        File tin = new File(prepath + testname + ".txt");
        File sin = new File(prepath + smallname + ".in");
        File lin = new File(prepath + largename + ".in");
        PrintStream testo = new PrintStream(prepath + testname + ".out");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
        A.solveSmall(new Scanner(tin), testo);
        System.out.println(prepath + testname + ".out");
        A.solveSmall(new Scanner(sin), smallo);
        System.out.println(prepath + smallname + ".out");
        //A.solveLarge(new Scanner(lin), largeo);
        //System.out.println(prepath + largename + ".out");
    }
}

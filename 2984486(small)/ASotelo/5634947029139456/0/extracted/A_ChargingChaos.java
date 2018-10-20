// Author: Alejandro Sotelo Arevalo
package round1;

import java.io.*;
import java.util.*;

public class A_ChargingChaos {
  // --------------------------------------------------------------------------------
  private static String ID="A";
  private static String NAME="small-attempt0";
  private static String STAGE="round1";
  private static boolean STANDARD_OUTPUT=false;
  // --------------------------------------------------------------------------------
  private static BufferedReader reader=null;
  private static PrintStream output=null;
  // --------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    try (BufferedReader bufferedReader=reader=new BufferedReader(new FileReader(new File("data/"+STAGE+"/"+ID+"-"+NAME+".in")))) {
      try (PrintStream printStream=output=STANDARD_OUTPUT?System.out:new PrintStream(new File("data/"+STAGE+"/"+ID+"-"+NAME+".out"))) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static int N,L;
  private static void process() throws Throwable {
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String w[]=reader.readLine().split(" +");
      N=Integer.parseInt(w[0]);
      L=Integer.parseInt(w[1]);
      char matrix[][][]=new char[2][N][];
      for (int z=0; z<2; z++) {
        w=reader.readLine().split(" +");
        for (int i=0; i<N; i++) {
          matrix[z][i]=w[i].toCharArray();
        }
      }
      Arrays.sort(matrix[1],comparator);
      int min=process(matrix,0);
      output.println("Case #"+c+": "+(min>L?"NOT POSSIBLE":min));
    }
  }
  private static final Comparator<char[]> comparator=new Comparator<char[]>() {
    @Override
    public int compare(char[] array1, char[] array2) {
      for (int j=0; j<L; j++) {
        if (array1[j]!=array2[j]) return (array1[j]-'0')-(array2[j]-'0');
      }
      return 0;
    }
  };

  private static int process(char[][][] matrix, int j) {
    if (j==L) {
      return 0;
    }
    int min=1<<20;
    for (int v=0; v<2; v++) {
      Arrays.sort(matrix[0],comparator);
      boolean bad=false;
      for (int i=0; !bad&&i<N; i++) {
        for (int k=0; !bad&&k<=j; k++) {
          if (matrix[0][i][k]!=matrix[1][i][k]) bad=true;
        }
      }
      if (!bad) {
        int option=v+process(matrix,j+1);
        if (option<min) min=option;
      }
      for (int i=0; i<N; i++) {
        matrix[0][i][j]=matrix[0][i][j]=='0'?'1':'0';
      }
    }
    return min;
  }
}

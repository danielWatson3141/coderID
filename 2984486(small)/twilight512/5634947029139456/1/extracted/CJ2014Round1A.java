import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class CJ2014Round1A {

  public static int checkStats(int N, int L, String[] a, String[] b, int index) {
    if (index == L) return 0;
    boolean isDiff = false;
    int resultNonswitch = 1000;
    int resultSwitch = 1000;
    for (int i = 0; i < N; i++) {
      if(a[i].charAt(index) != b[i].charAt(index)) {
        isDiff = true;
        break;
      }
    }
    if (!isDiff) {
      resultNonswitch = checkStats(N, L, a, b, index+1);
    }
    isDiff = false;
    String[] nextA = new String[N];
    for (int i = 0; i < N; i++) {
      nextA[i] = a[i].substring(0, index) + (a[i].charAt(index) == '0' ? '1' : '0') + a[i].substring(index+1, L);
    }
    Arrays.sort(nextA);
    for (int i = 0; i < N; i++) {
      if(nextA[i].charAt(index) != b[i].charAt(index)) {
        isDiff = true;
        break;
      }
    }
    if (!isDiff) {
      resultSwitch = checkStats(N, L, nextA, b, index+1) + 1;
    }
    return Math.min(resultNonswitch, resultSwitch);
  }
  
  public static int getAnswer(int N, int L, String[] outlets, String[] devices) {
    Arrays.sort(outlets);
    Arrays.sort(devices);
    return checkStats(N, L, outlets, devices, 0);
  }
  
  public static boolean isTest = false;
  public static boolean isSmall = false;
  public static void main(String[] args) {
    try {
      BufferedReader br = null;
      BufferedWriter bw = null;
      if (isTest) {
        br = new BufferedReader(new FileReader("test.txt"));
        bw = new BufferedWriter(new FileWriter("output.txt"));
      } else if (isSmall) {
        br = new BufferedReader(new FileReader("A-small-attempt0.in.txt"));
        bw = new BufferedWriter(new FileWriter("A-small.out.txt"));
      } else {
        br = new BufferedReader(new FileReader("A-large.in.txt"));
        bw = new BufferedWriter(new FileWriter("A-large.out.txt"));
      }

      String line = br.readLine().trim();
      int numOfGames = Integer.parseInt(line);
      String[] inVals;
      for(int i = 1; i<=numOfGames; i++) {
        inVals = br.readLine().trim().split("\\s+");
        int N = Integer.parseInt(inVals[0]);
        int L = Integer.parseInt(inVals[1]);
        String[] outlets = br.readLine().trim().split("\\s+");
        String[] devices = br.readLine().trim().split("\\s+");
        int result = CJ2014Round1A.getAnswer(N, L, outlets, devices);
        if (result == 1000) {
          System.out.println("Case #"+i+": NOT POSSIBLE");
          bw.write("Case #"+i+": NOT POSSIBLE\n");
        } else {
          System.out.println("Case #"+i+": " + result);
          bw.write("Case #"+i+": " + result + "\n");
        }
      }
      br.close();
      bw.flush();
      bw.close();
    }
    catch (FileNotFoundException e) {
      System.out.println("ERROR: Cannot find file.");
      return;
    }
    catch (IOException e) {
    }
  }

}

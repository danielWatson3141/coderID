import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class CJ2014Round1C {

  public static boolean[] getAnswers(int N, int[][] p) {
    boolean[] answers = new boolean[120];
    int[] counts = new int[120];
    int[] delta = new int[120];
    for (int i = 0; i < 120; i++) {
      for (int j = 0; j < N/2; j++) {
        if (p[i][j] < N/2) {
          counts[i]++;
          delta[i]++;
        }
      }
    }
    Arrays.sort(delta);
    int divider = delta[59];
    for (int i = 0; i < 120; i++) {
      if (counts[i] > divider) {
        answers[i] = true;
      } else {
        answers[i] = false;
      }
    }
    return answers;
  }
  
  public static boolean isTest = false;
  public static boolean isSmall = true;
  public static void main(String[] args) {
    try {
      BufferedReader br = null;
      BufferedWriter bw = null;
      if (isTest) {
        br = new BufferedReader(new FileReader("test.txt"));
        bw = new BufferedWriter(new FileWriter("output.txt"));
      } else if (isSmall) {
        br = new BufferedReader(new FileReader("C-small-attempt2.in.txt"));
        bw = new BufferedWriter(new FileWriter("C-small.out.txt"));
      } else {
        br = new BufferedReader(new FileReader("C-large.in.txt"));
        bw = new BufferedWriter(new FileWriter("C-large.out.txt"));
      }

      String line = br.readLine().trim();
      int numOfGames = Integer.parseInt(line);
      String[] inVals;
      int[][] permutations = new int[numOfGames][];
      for(int i = 1; i<=numOfGames; i++) {
        inVals = br.readLine().trim().split("\\s+");
        int N = Integer.parseInt(inVals[0]);
        inVals = br.readLine().trim().split("\\s+");
        int[] permutation = new int[N];
        for (int j = 0; j < N; j++) {
          permutation[j] = Integer.parseInt(inVals[j]);
        }
        permutations[i-1] = permutation;
      }
      boolean[] answers = CJ2014Round1C.getAnswers(1000, permutations);
      for (int i = 1; i <= 120; i++) {
        if (answers[i-1]) {
          System.out.println("Case #"+i+": GOOD");
          bw.write("Case #"+i+": GOOD\n");
        } else {
          System.out.println("Case #"+i+": BAD");
          bw.write("Case #"+i+": BAD\n");
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

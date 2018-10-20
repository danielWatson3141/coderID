package codejam;

import java.io.FileInputStream;
import java.util.*;

public class A {
  
  private static int minFlips = Integer.MAX_VALUE;
  
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    
    int T = in.nextInt();
    
    for (int i = 0; i < T; i++) {
      int N = in.nextInt();
      int L = in.nextInt();
      
      char[][] board = new char[N][L];
      
      // String[] devices = new String[N];
      
      in.nextLine();
      String line = in.nextLine();
      String[] outlets = line.split(" ");
      
      for (int j = 0; j < N; j++) {
        board[j] = outlets[j].toCharArray();
      }
      line = in.nextLine();
      String[] devices = line.split(" ");
      
      Arrays.sort(devices);
      
      try {
        minFlips = Integer.MAX_VALUE;
        check(board, devices, 0, N, L, 0);
        System.out.println("Case #" + (i + 1) + ": " + minFlips);
      } catch (IllegalArgumentException e) {
        System.out.println("Case #" + (i + 1) + ": NOT POSSIBLE");
      }
    }
    
    
  }
  
  // k is the column that we are going to visit.
  public static void check(char[][] board, String[] devices, int flips, int N, int L, int k) throws IllegalArgumentException {
    // printBoard(board, N, L);
    if (k >= L) {
      // then verify
      List<String> x = new ArrayList<String>(N);
      for (int i = 0; i < N; i++) {
        x.add(new String(board[i]));
      }
      Collections.sort(x);
      boolean done = true;
      // now compare x with the devices
      for (int i = 0; i < N; i++) {
        if (!x.get(i).equals(devices[i])) {
          // then count
          done = false;
          break;
        }
      }
      
      if (done) {
        // then count
        if (flips < minFlips) {
          minFlips = flips;
        }
      }
      // count the number of flips
    } else {
      // try to extend if possible
      // check the column k
      // count the number of 0 and 1 in column k
      int X1 = 0;
      int X0 = 0;
      int Y1 = 0;
      int Y0 = 0;
      for (int i = 0; i < N; i++) {
        if (board[i][k] == '0') {
          X0++;
        } else {
          X1++;
        }
        if (devices[i].charAt(k) == '0') Y0++;
        else Y1++;
      }
      
      // now compare
      if (X1 == X0) {
        // then can flip
        // twice
        check(board, devices, flips, N, L, k + 1);
        // flips
        // flips[k] = true;
        flip(board, k, N);
        check(board, devices, flips + 1, N, L, k + 1);
        flip(board, k, N);
      } else {
        if (X1 == Y1) {
          if (X0 == Y0) {
            // no need to flip
            check(board, devices, flips, N, L, k + 1);
          } else {
            // Not possible
            throw new IllegalArgumentException();
          }
        } else if (X1 == Y0) {
          // then flip
          if (X0 == Y1) {
            flip(board, k, N);
            check(board, devices, flips + 1, N, L, k + 1);
            flip(board, k, N);
          } else {
            // Not possible
            throw new IllegalArgumentException();
          }
        } else {
          throw new IllegalArgumentException();
        }
      }
    }
  }

  private static void flip(char[][] board, int k, int N) {
    for (int i = 0; i < N; i++) {
      if (board[i][k] == '0') board[i][k] = '1';
      else board[i][k] = '0';
    }
  }
  
  private static void printBoard(char[][] board, int N, int L) {
    for (int i = 0; i < N; i++) {
      System.out.println(board[i]);
    }
  }
}

import java.io.*;
import java.util.*;

public class A {
  
  private static boolean[] makeItem(String str) {
    boolean[] output = new boolean[str.length()];
    for(int j = 0; j < output.length; j++) {
      output[j] = (str.charAt(j) == '1');
    }
    return output;
  }
  
  private static String runCase(Scanner s, int i) throws IOException {
    int n = s.nextInt();
    int l = s.nextInt();
    boolean[][] outlets = new boolean[n][];
    boolean[][] devices = new boolean[n][];
    
    int best = l + 1;
    
    for(int j = 0; j < n; j++) {
      outlets[j] = makeItem(s.next());
    }
    for(int j = 0; j < n; j++) {
      devices[j] = makeItem(s.next());
    }
    
    // For each outlet
    for(int j = 0; j < n; j++) {
      boolean[][] a = new boolean[n][l];
      for(int x = 0; x < n; x++) {
        for(int y = 0; y < l; y++) {
          a[x][y] = devices[x][y];
        }
      }
      int numSwaps = 0;
      // For each part of the outlet, swap if needed
      for(int k = 0; k < l; k++) {
        
        if(a[0][k] != outlets[j][k]) {
          // Flip the switch
          for(int x = 0; x < n; x++) {
            a[x][k] = !a[x][k];
          }
          numSwaps++;
        }
        
      }
      
      // Test to see if the others have an outlet
      boolean[] used = new boolean[n];
      used[0] = true;
      boolean broken = false;
      // For each outlet
      for(int y = 0; y < n; y++) {
        if(y != j) {
          // For each device
          boolean found = false;
          for(int x = 1; x < n; x++) {
            if(!used[x] && Arrays.equals(outlets[y], a[x])) {
              used[x] = true;
              found = true;
              break;
            }
          }
          if(!found) {
            broken = true;
            break;
          }
          
        }
      }
      if(!broken && numSwaps < best) {
        best = numSwaps;
      }
    }
    
    return "Case #" + i + ": " + (best <= l ? best : "NOT POSSIBLE");
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  public static void main(String[] args) {
    
    String filename;
    File file;
    Scanner scanner;
    PrintWriter writer;
    int numCases;
    boolean hadProblems = false;
    
    try {
      
      if(args.length > 0) {
        filename = args[0];
      }
      else {
        System.out.print("Enter the file name, minus extensions: ");
        Scanner kbd = new Scanner(System.in);
        filename = kbd.nextLine();
      }
      file = new File(filename + ".in");
      scanner = new Scanner(file);
      writer = new PrintWriter(filename + ".out", "UTF-8");
      numCases = Integer.parseInt(scanner.nextLine());
    }
    catch(Exception e) {
      System.err.println(e.getMessage());
      return;
    }
    
    System.out.println();
    
    for(int i = 1; i <= numCases; i++) {
      try {
        String output = runCase(scanner, i);
        writer.println(output);
        System.out.println(output);
      }
      catch(Exception e) {
        System.err.println(e.getMessage());
        hadProblems = true;
      }
    }
    
    writer.close();
    
    if(hadProblems) {
      System.out.println();
      System.err.println("ERRORS IN TEST CASES. PLEASE CHECK THE OUTPUT.");
    }
    
    System.out.println();
    
  }
  
  
}
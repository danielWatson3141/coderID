import java.io.*;
import java.util.*;

public class C {
  
  public static int heuristic(int[] a) {
    int x = 0;
    for(int i = 0; i < a.length; i++) {
      //x += (int)Math.pow(i - a.length / 2, 2) * a[i];
      if(a[i] < i) {
        x++;
      }
    }
    return x;
  }
  private static String runCase(Scanner s, int i) throws IOException {
    int n = s.nextInt();
    int[] a = new int[n];
    for(int x = 0; x < n; x++) {
      a[x] = s.nextInt();
    }
    return "Case #" + i + ": " + (heuristic(a) > 490 ? "GOOD" : "BAD");
      
    
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
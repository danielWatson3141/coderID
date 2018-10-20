import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class B {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = Integer.parseInt(sc.nextLine());
    for(int t=1; t<=T; t++) {
      int N = Integer.parseInt(sc.nextLine());
      
      int arr[] = new int[N];
      String tokens[] = sc.nextLine().split(" ");
      for(int i=0; i<tokens.length; i++)
        arr[i] = Integer.parseInt(tokens[i]);
      System.out.println("Case #"+t+": "+ans(N, arr));
      
    }
  }
  
  static String ans(int N, int arr[]) {
    long deg = 0;
    for(int i=0; i<arr.length; i++) {
      deg+=Math.abs(i-arr[i]);
    }
    
    long base = N*N/3;
    
    /*System.out.println(deg);
    System.out.println(base);*/
  //  System.out.println(Math.abs(base-deg)/(double)base);
    //System.out.println();
    if(Math.abs(base-deg)/(double)base <0.025)
      return "GOOD";
    return "BAD";
  }
}
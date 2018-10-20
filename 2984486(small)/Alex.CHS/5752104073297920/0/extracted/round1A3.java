import java.util.*;
import java.io.*;

public class round1A3 {
    static double[][] probs;
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("round1A3.in"));
        
        int a = Integer.parseInt(in.nextLine());
        parseData();
        
        for(int i = 0; i < a; i++) {
            in.nextLine();
            String[] arr = in.nextLine().split(" ");
            double numgood = 1;
            double numbad = 1;
            int[] nums = new int[arr.length];
            for(int j = 0; j < nums.length; j++) {
                nums[j] = Integer.parseInt(arr[j]);
            }
            for(int j = 0; j < nums.length; j++) {
                numbad *= probs[j][nums[j]];
            }
            System.out.println("Case #" + (i + 1) + ": " + ((numgood / (numgood + numbad)) >= 0.5 ? "GOOD" : "BAD"));
        }
    }
    
    public static void parseData() throws Exception {
        Scanner in2 = new Scanner(new File("round1A3.out"));
        probs = new double[1000][1000];
        for(int i = 0; i < probs.length; i++) {
            String[] str = in2.nextLine().split(" ");
            for(int j = 0; j < str.length; j++) {
                probs[i][j] = Double.parseDouble(str[j]);
            }
        }
    }
}
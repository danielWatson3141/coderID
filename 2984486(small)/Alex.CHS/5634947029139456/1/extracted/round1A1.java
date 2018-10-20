import java.util.*;
import java.io.*;

public class round1A1 {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("round1A1.in"));
        PrintStream out = new PrintStream(new File("round1A1.out"));
        
        int a = Integer.parseInt(in.nextLine());
        
        for(int i = 0; i < a; i++) {
            String str = in.nextLine();
            int minanswer = Integer.MAX_VALUE / 2;
            int N = Integer.parseInt(str.substring(0, str.indexOf(" ")));
            int L = Integer.parseInt(str.substring(str.indexOf(" ") + 1));
            String[] arr = in.nextLine().split(" ");//outlets
            
            String[] arr2 = in.nextLine().split(" ");//applicances
            Arrays.sort(arr2);
            
            boolean[] doswitch = new boolean[L];
            for(int j = 0; j < arr.length; j++) {//compares all arr with arr2[0], the first outlet thing
                int count = 0;
                for(int k = 0; k < arr[j].length(); k++) {
                    doswitch[k] = arr[j].charAt(k) != arr2[0].charAt(k);
                    if(arr[j].charAt(k) != arr2[0].charAt(k)) count++;
                }
                String[] arr3 = new String[arr.length];//switched version of arr
                for(int k = 0 ; k < arr3.length; k++) {
                    String string = "";
                    for(int l = 0; l < arr[k].length(); l++) {
                        if(doswitch[l]) {
                            string += arr[k].charAt(l) == '1' ? '0' : '1';
                        } else {
                            string += arr[k].charAt(l) == '1' ? '1' : '0';
                        }
                    }
                    arr3[k] = string;
                }
                Arrays.sort(arr3);
                
                if(Arrays.toString(arr3).equals(Arrays.toString(arr2))) {
                    minanswer = Math.min(minanswer, count);
                }
            }
            if(minanswer != Integer.MAX_VALUE / 2) {
                System.out.println("Case #" + (i + 1) + ": " + minanswer);
            } else {
                System.out.println("Case #" + (i + 1) + ": NOT POSSIBLE");
            }
        }
    }
}
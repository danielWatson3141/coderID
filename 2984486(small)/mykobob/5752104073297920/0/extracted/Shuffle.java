import java.util.*;
import java.io.*;

/*
ID: michael138
LANG: JAVA
TASK: Shuffle
*/
public class Shuffle {
    static BufferedReader in;
    static PrintWriter out;

    public static void main(String... bob) throws Exception {
        Scanner in = new Scanner(new File("C-small-attempt0.in"));
        out = new PrintWriter(new BufferedWriter(new FileWriter("Shuffle.out")));
        // Use StringTokenizer
        //StringTokenizer st = new StringTokenizer(in.readLine());
        int times = in.nextInt();
        for (int i = 0; i < times; i++) {
            int length = in.nextInt();
            int[] arr = new int[length];
            for (int j = 0; j < length; j++) {
                arr[j] = in.nextInt();
            }
            int[] sorted = Arrays.copyOf(arr, arr.length);
            Arrays.sort(sorted);
            int later = 0;
            for (int j = 0; j < length; j++) {
                for (int k = j + 1; k < length; k++) {
                    if (arr[k] == sorted[j])
                        later++;
                }
            }
            if(later == 0){
                System.out.println("Case #" + (i+1) + ": BAD");
                out.println("Case #" + (i+1) + ": BAD");
            }
            else if (later % 2 == 0)
            {
                System.out.println("Case #" + (i + 1) + ": GOOD");
                out.println("Case #" + (i + 1) + ": GOOD");
            }
            else
            {
                System.out.println("Case #" + (i+1) + ": BAD");
                out.println("Case #" + (i+1) + ": BAD");
            }
        }


        out.close();
        System.exit(0);
    }
}

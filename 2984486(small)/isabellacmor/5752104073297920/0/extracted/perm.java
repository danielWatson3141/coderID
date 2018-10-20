package round1;

import java.io.*;
import java.util.*;

/**
 * Created by isabella on 4/25/14.
 */
public class perm {
    public static void main(String [] args) throws IOException{
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();
        for(int nc = 1; nc <= numCases; nc++){
            int N = in.nextInt();
            int[] perm = new int[N];

            for(int i = 0; i < N; i++){
                perm[i] = in.nextInt();
            }

            int inOriginal = 0;
            for(int i = 0; i < N/2; i++){
                if(perm[i] > N/2) inOriginal++;
            }

            for(int i = N/2; i < N; i++)
                if(perm[i] < N/2) inOriginal++;

            System.out.println("Case #" + nc + ": " + (inOriginal > (N/2) ? "GOOD" : "BAD"));
        }
    }
}

/*

2
3
0 1 2
3
2 0 1

*/

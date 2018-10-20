package round1;

import java.io.*;
import java.util.*;

/**
 * Created by isabella on 4/25/14.
 */
public class chaos {
    public static int minScore;
    public static String[] bits, have;
    public static void main(String [] args) throws IOException{
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();
        for(int nc = 1; nc <= numCases; nc++){
            int numNeed = in.nextInt();
            int numBits = in.nextInt();
            in.nextLine();
            minScore = Integer.MAX_VALUE - 1;

            bits = in.nextLine().split(" ");
            have = in.nextLine().split(" ");

            //go through all the bits
            for(int i = 0; i < bits.length; i++){
                //try to match it to the first needed
                String[] test = Arrays.copyOf(bits, bits.length);
                flip(test, test[i], have[0]);
            }

            System.out.println("Case #" + nc + ": " + (minScore == Integer.MAX_VALUE - 1 ? "NOT POSSIBLE" : minScore));
        }
    }

    public static void flip(String[] test, String curState, String needState){
        int numFlips = 0;
        for(int i = 0; i < needState.length(); i++){
            if(curState.charAt(i) != needState.charAt(i)){
                numFlips++;
                for(int j = 0; j < test.length; j++){
                    char cur = test[j].charAt(i);
                    cur = cur == '1' ? '0' : '1';
                    test[j] = test[j].substring(0, i) + "" + cur + "" + test[j].substring(i+1);
                }
            }
        }

        if(allMatch(test)) minScore = Math.min(minScore, numFlips);
    }

    public static boolean allMatch(String[] test){
        boolean[] used = new boolean[test.length];

        for(int i = 0; i < test.length; i++){
            for(int j = 0; j < have.length; j++){
                if(test[i].equals(have[j]) && !used[i]){
                    used[i] = true;
                }
            }
        }

        for(int i = 0; i < used.length; i++){
            if(!used[i]) return false;
        }

        return true;
    }
}

/*

3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01

1
3 2
01 10 00
01 01 00

*/

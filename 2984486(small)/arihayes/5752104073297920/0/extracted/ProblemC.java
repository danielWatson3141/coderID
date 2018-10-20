import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemC {
    static String in = "src/c.in";
    static String out = "src/c.out";

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        int numgood = 0;
        int numlines = scan.nextInt();
        int totaltotal = 0;
        for(int x = 1; x <= numlines; x++) {
            int count = scan.nextInt();
            /*int expecteddist = count * count / 3;
            int totaldist = 0;
            for(int y = 0; y < count; y++) {
                int num = scan.nextInt();
                int badpos = num-1;
                int dist = (y - badpos);
                if(dist < 0) {
                    dist = 0-dist;
                }
                totaldist += dist;
                totaltotal += dist;
            }
            System.out.println(totaldist + "," + expecteddist);
            String answer;
            if(totaldist < expecteddist * 0.98) {
                answer = "BAD";
            }
            else {
                answer = "GOOD";
                numgood++;
            }*/

            int badness = 0;
            for(int y = 0; y < count; y++) {
                int num = scan.nextInt();
                if(y == num - 1) {
                    badness += 3;
                }
                else if(y <= num && num - y < (count/12)) {
                    badness += 2;
                }
                else if(y <= num && num - y < (count/6)) {
                    badness += 1;
                }
                //else if(y <= num && num - y > count/6) {
                //    badness -= 1;
                //}
                else if(y <= num && num - y > count/3) {
                    badness -= 1;
                }
            }
            System.out.println(badness);
            String answer;
            if(badness > (count/20)) {
                answer = "BAD";
            }
            else {
                answer = "GOOD";
                numgood++;
            }

            write.write("Case #" + x + ": " + answer);

            write.write("\n");
        }
        System.out.println(numgood);
        //System.out.println(((totaltotal/120.0)/500000));
        scan.close();
        write.close();
    }
}

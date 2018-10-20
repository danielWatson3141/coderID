import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import static java.util.Collections.copy;
import java.util.Scanner;

/**
 *
 * @author Chathura
 */
public class Solution {

    public static void main(String[] args) throws FileNotFoundException, IOException {

        //Scanner scnr = new Scanner(System.in);
        Scanner scnr = new Scanner(new File("D:\\Test\\cj\\A-small-attempt0(1).in"));
        int T = scnr.nextInt();
        System.out.println(T);

        ArrayList<String> answeres = new ArrayList<>();

        for (int i = 0; i < T; i++) {
            int N = scnr.nextInt();
            int L = scnr.nextInt();
            ArrayList<String> have = new ArrayList<>();
            ArrayList<String> haveCopy = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                have.add(scnr.next());
            }
            Collections.sort(have);

            ArrayList<String> required = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                required.add(scnr.next());
            }
            Collections.sort(required);

            if (required.equals(have)) {
                answeres.add(0 + "");
                continue;
            }

            int totlaiTimes = (int) Math.pow(2, L);
            int times = 1;
            int minFlips = L;
            boolean able = false;
            while (times <= totlaiTimes) {
                haveCopy = new ArrayList<>(have);
                //System.out.println(haveCopy);
                String toBinaryString = Integer.toBinaryString(times);
                if (toBinaryString.length() < L) {
                    int zeroCount = L - toBinaryString.length();
                    for (int j = 0; j < zeroCount; j++) {
                        toBinaryString = "0" + toBinaryString;
                    }
                }
                //System.out.println(toBinaryString);
                int flipings = 0;
                for (int j = 0; j < toBinaryString.length(); j++) {
                    if (toBinaryString.charAt(j) == '1') {
                        flipings++;
                    }
                }

                for (int j = 0; j < N; j++) {
                    String pattern = haveCopy.get(j);
                    
                    String afterFlip = "";
                    for (int k = 0; k < pattern.length(); k++) {
                        afterFlip += (Integer.parseInt(pattern.charAt(k) + "") ^ Integer.parseInt(toBinaryString.charAt(k) + ""));
                    }
                    haveCopy.set(j, afterFlip);
                }
                Collections.sort(haveCopy);
                if (haveCopy.equals(required)) {
                    able = true;
                    if (flipings < minFlips) {
                        minFlips = flipings;
                    }
                }

                times++;
            }
            if (able) {
                answeres.add(minFlips + "");
            } else {
                answeres.add("NOT POSSIBLE");
            }

        }
        String out = "";
        for (int i = 0; i < T; i++) {
            out += "Case #" + (i + 1) + ": ";
            out += answeres.get(i);
            out += "\r\n";
        }
        System.out.println(out);
        File outF = new File("D:\\Test\\cj\\out.out");
        FileWriter fw = new FileWriter(outF);
        fw.write(out);
        fw.flush();
    }

    public static char Flip(char bit) {
        if (bit == '0') {
            return 1;
        }
        return '0';
    }

}

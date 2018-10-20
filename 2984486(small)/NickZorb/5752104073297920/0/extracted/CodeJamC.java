package round1A;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.text.ParseException;


public class CodeJamC {
public static void main(String[] args) throws FileNotFoundException, IOException, ParseException {
        CodeJamC jam = new CodeJamC();
        jam.solve("round1A/C-small-attempt0.in");
    }
    
    public void solve(String file) throws FileNotFoundException, IOException, ParseException {
        File f = new File(file);
        FileReader fin = new FileReader(f);
        BufferedReader in = new BufferedReader(fin);
        int cases = Integer.parseInt(in.readLine());
        File outF = new File("round1A/resultsC.txt");
        PrintStream out = new PrintStream(outF);
        for (int i = 1; i <= cases; i++) {
            in.readLine();
            String number = in.readLine();
            String[] numbers = number.split(" ");
            int[] ints = new int[1000];
            for (int j = 0; j < 1000; j++) {
                ints[j] = Integer.parseInt(numbers[j]);
            }
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0; j < 500; j++) {
                sum1 += ints[j];
                sum2 += ints[j + 500];
            }
            if (sum1 < sum2) {
                out.println("Case #" + i + ": BAD");
            } else {
                out.println("Case #" + i + ": GOOD");
            }
        }
    }
}
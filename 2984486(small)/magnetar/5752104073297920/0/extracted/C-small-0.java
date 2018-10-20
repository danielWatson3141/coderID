import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Compiled with Oracle Java 8 (jdk1.8.0) on Mac OS X 10.9.2 (Intel).
 *
 * Problem statement:
 *
 *
 * @author magnetar <magnetar.fields@gmail.com>
 */
public class ProperShuffle {

    /** CONSTANTS ***********************************************************/
    public static final boolean DEBUG = true;
    public static final String FILENAME = "C-small-0";

    //region Class Members -----------------------------------------------------------/

    //endregion

    //region Boilerplate -------------------------------------------------------------/
    private File inputfile = new File("/Users/codejam/source/" + FILENAME + ".in");
    private File outfile = new File("/Users/codejam/source/" + FILENAME + ".out");
    private BufferedWriter writer = null;

    public static void main(String[] args) {
        new ProperShuffle();
    }

    public ProperShuffle() {
        System.out.println("Proper Shuffle entry by Magnetar <magnetar.fields@gmail.com>");
        try (Scanner scan = new Scanner(new BufferedReader(new FileReader(inputfile)))) {
            writer = new BufferedWriter(new FileWriter(outfile));
            process(scan);
        } catch (Exception ex) {
            ex.printStackTrace();
        } finally {
            try {
                if (writer != null)
                    writer.close();
            } catch (IOException ioex) {
                ioex.printStackTrace();
            }
        }
        System.out.println("Exit OK");
    }

    public void write() throws Exception {
        writer.newLine();
        if (!DEBUG) {
            System.out.println();
        }
    }

    public void write(String str) throws Exception {
        writer.write(str);
        writer.newLine();
        if (!DEBUG) {
            System.out.println(str);
        }
    }

    public void write(String str, boolean newline) throws Exception {
        if (newline) {
            writer.write(str);
            writer.newLine();
            if (!DEBUG) {
                System.out.println(str);
            }
        } else {
            writer.write(str);
            if (!DEBUG) {
                System.out.print(str);
            }
        }
    }

    public void print() {
        if (DEBUG) {
            System.out.println();
        }
    }

    public void print(int i) {
        print(Integer.toString(i));
    }

    public void print(int i, boolean newline) {
        print(Integer.toString(i), newline);
    }

    public void print(double i) {
        print(Double.toString(i));
    }

    public void print(double i, boolean newline) {
        print(Double.toString(i), newline);
    }

    public void print(String str) {
        if (DEBUG) {
            System.out.println(str);
        }
    }

    public void print(String str, boolean newline) {
        if (DEBUG) {
            if (newline)
                System.out.println(str);
            else
                System.out.print(str);
        }
    }
    //endregion

    /** process() ***********************************************************/
    public void process(Scanner scan) throws Exception {
        int T = scan.nextInt(); // number of test cases
        int goodcount = 0;
        int badcount = 0;
        for (int casen = 1; casen <= T; casen++) {
            print("Case #" + casen + ": ");
            //region Parse test case inputs ---------------------------------------------------/
            int N = scan.nextInt();
            int[] bin = new int [20];
            StringBuffer buf = new StringBuffer();
            for (int i = 0; i < N; i++) {
            	int num = scan.nextInt();
            	
            	if (num < 250) {
            		buf.append("1");
            	} else if (num < 500) {
            		buf.append("2");
            	} else if (num < 750) {
            		buf.append("3");
            	} else {
            		buf.append("4");
            	}
            }

            String str = buf.toString();
            String first = str.substring(0, 100);
            int fcount = countOccurrences(first, '4');
            String last = str.substring(900, str.length());
            int count = countOccurrences(last, '1');
            
            /*
            print(last +  "   -> " + count);
            if ((str.contains("111111") || str.contains("222222") || str.contains("333333") || str.contains("444444")) || 
                (str.contains("12341234") || str.contains("43214321"))) {
            	print("BAD");
            	write("Case #" + casen + ": " + "BAD");
            	badcount++;
            } else {
            	print("GOOD");
            	write("Case #" + casen + ": " + "GOOD");
            	goodcount++;
            }*/
            if ((fcount < 26 || fcount > 74) && (count < 26 || count > 74)) {
            	print("BAD");
            	write("Case #" + casen + ": " + "BAD");
            	badcount++;
            } else {
            	print("GOOD");
            	write("Case #" + casen + ": " + "GOOD");
            	goodcount++;
            }
            	
            /*
            if (low >= 10 || medium >= 10 || high >= 10 || zero >= 10) {
                print("            \t BAD");
                write("Case #" + casen + ": " + "BAD");
            } else {
            	print("            \t GOOD");
                write("Case #" + casen + ": " + "GOOD");
            }
            */
            
            //region Logic loop ------------------------------------------------------/


            //endregion End logic loop ---------------------------------------------/


        }
        print("good = " + goodcount + ", bad = " + badcount);
    }
    
    public static int countOccurrences(String haystack, char needle)
    {
        int count = 0;
        for (int i=0; i < haystack.length(); i++)
        {
            if (haystack.charAt(i) == needle)
            {
                 count++;
            }
        }
        return count;
    }
}

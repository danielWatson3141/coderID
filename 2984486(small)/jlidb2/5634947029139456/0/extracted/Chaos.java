import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

// to represent the input of a grid of numbers and the volunteer's inputs
class Chaos {
    int[][] outBits;
    int[][] devBits;
    int n;
    int l;
    int[] curKey;


    // CONSTRUCTOR
    Chaos(int n, int l, int[][] outBits, int[][] devBits) {
        this.n = n;
        this.l = l;
        this.outBits = outBits;
        this.devBits = devBits;
        curKey = new int[l];
        for (int i = 0; i < l; i++) {
            curKey[i] = 0;
        }
    }

    // METHODS FOR ALGORITHMS

    // parse the string into a bit array
    static int[] parseBit(String s) {
        int[] result = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if (s.substring(i, i + 1).equals("0")) {
                result[i] = 0;
            }
            else {
                result[i] = 1;
            }
        }
        return result;
    }

    // return the array of the two given arrays XORed
    int[] xor(int[] ar1, int[] ar2) {
        int[] result = new int[ar1.length];
        for (int i = 0; i < ar1.length; i++) {
            if (ar1[i] == ar2[i]) {
                result[i] = 0;
            }
            else {
                result[i] = 1;
            }

        }
        return result;
    }

    // are the two given bits the same?
    boolean sameBit(int[] b1, int[] b2) {
        for (int i = 0; i < b1.length; i++) {
            if (b1[i] != b2[i]) {
                return false;
            }
        }
        return true;
    }

    // is the given bit in the given array of bits
    boolean in(int[] bit, int[][] loBits) {
        for (int i = 0; i < loBits.length; i++) {
            if (sameBit(bit, loBits[i])) {
                return true;
            }
        }
        return false;
    }

    // how many 1's are in this array
    int switchNum(int[] bit) {
        int result = 0;
        for (int i = 0; i < bit.length; i++) {
            result = bit[i] + result;
        }
        return result;
    }

    // have we found a key that works
    boolean foundSol(int[] key) {
        for (int i = 0; i < outBits.length; i++) {
            if (!(in(xor(outBits[i], key), devBits))) {
                return false;
            }
        }
        return true;
    }

    // go through each key and see if there is a solution
    int getSol() {
        int min = -1;
        int curAns = -1;
        if (foundSol(curKey)) {
            curAns = switchNum(curKey);
            if ( curAns < min || min == -1) { 
                min = curAns;
            }
        }
        for (int i = 0; i < devBits.length; i++) {
            curKey = xor(outBits[0], devBits[i]);
            if (foundSol(curKey)) {
                curAns = switchNum(curKey);
                if ( curAns < min || min == -1) { 
                    min = curAns;
                }
            }
        }
        return min;
    }
}

/** algorithms */
class Outlet {

    // read the file named after the given String and return its contents
    // as a String
    public static String readFile(String filename) {
        String content = null;
        File file = new File(filename); //for ex foo.txt
        try {
            FileReader reader = new FileReader(file);
            char[] chars = new char[(int) file.length()];
            reader.read(chars);
            content = new String(chars);
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return content;
    }

    // input file contents as a string CHANGE NAME
    public static String s = readFile("A-small-attempt1.in.txt");

    // DECLARE VARIABLES/EXAMPLES
    static Outlet outlet = new Outlet();
    static Integer t = 0;
    static Integer n = 0;
    static Integer l = 0;
    static int[][] outBits = new int[n][l];
    static int[][] devBits = new int[n][l];
    static String output = "";
    static String tempStr = "";
    static int[] tempBit = new int[l];

    public static void main(String [] args) throws IOException {
        Scanner sc = new Scanner(s);
        t = sc.nextInt();
        for (int i = 0; i < t; i++) {

            // RUN METHODS ON INPUT
            n = sc.nextInt();
            l = sc.nextInt();
            outBits = new int[n][l];
            devBits = new int[n][l];
            for (int j = 0; j < n; j++) {
                tempStr = sc.next();
                tempBit = new int[l];
                tempBit = Chaos.parseBit(tempStr);
                outBits[j] = tempBit;
            }
            for (int j = 0; j < n; j++) {
                tempStr = sc.next();
                tempBit = new int[l];
                tempBit = Chaos.parseBit(tempStr);
                devBits[j] = tempBit;
            }

            Chaos chaos = new Chaos(n, l, outBits, devBits);
            int ans = chaos.getSol();
            String sol = "";
            if (ans == -1) {
                sol = "NOT POSSIBLE";
            }
            else {
                sol = ans + "";
            }
            output = output + "\nCase #" + (i + 1) + ": " + sol;
        }
        output = output.substring(1, output.length());
        File outFile = new File ("output.txt");
        FileWriter fWriter = new FileWriter (outFile);
        PrintWriter pWriter = new PrintWriter (fWriter);
        pWriter.println(output);
        pWriter.close();
        System.out.println(output);
    }

}
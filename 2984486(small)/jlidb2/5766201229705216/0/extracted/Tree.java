import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

// to represent the input of a grid of numbers and the volunteer's inputs
class Tree {
    // FIELDS
    int n;
    int[] degrees;
    int count;


    // CONSTRUCTOR
    Tree(int n, int[] degrees) {
        this.n = n;
        this.degrees = degrees;
        this.count = 0;
    }



    // METHODS FOR ALGORITHMS

    boolean has3() {
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 3) {
                return true;
            }
        }
        return false;
    }

    int minMore3() {
        int min = 3;
        for (int i = 0; i < n; i++) {
            if (degrees[i] > 2 && degrees[i] < min) {
                min = degrees[i];
            }
        }
        return min;
    }

    void assureRoot() {
        int num2s = 0;
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 2) {
                num2s = num2s + 1;
            }
        }
        if (num2s == 1) {
            return;
        }
        else if (num2s > 1) {
            boolean found = false;
            for (int i = 0; i < n; i++) {
                if (degrees[i] == 2 && found) {
                    degrees[i] = 1;
                    count = count + 1;
                }
                else if (degrees[i] == 2) {
                    found = true;
                }
            }
        }
        else {
            int target = minMore3();
            for (int i = 0; i < n; i++) {
                if (degrees[i] == target) {
                    degrees[i] = 2;
                    count = count + target - 2;
                    return;
                }
            }

        }
    }

    void bringTo3() {
        for (int i = 0; i < n; i++) {
            if (degrees[i] > 3) {
                count = count + degrees[i] - 3;
                degrees[i] = 3;

            }
        }
    }

    int solve() {
        if (n == 2) {
            return 1;
        }
        else {
            assureRoot();
            bringTo3();
            return count;
        }
    }
}

/** algorithms */
class Graph {

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
    public static String s = readFile("B-small-attempt2.in.txt");
    //public static String s = readFile("Input.txt");

    // DECLARE VARIABLES/EXAMPLES
    static Graph graph = new Graph();
    static Integer t = 0;
    static Integer n = 0;
    static int[] degrees = new int[n];
    static int count = 0;
    static String output = "";

    public static void main(String [] args) throws IOException {
        Scanner sc = new Scanner(s);
        t = sc.nextInt();
        for (int i = 0; i < t; i++) {

            // RUN METHODS ON INPUT
            n = sc.nextInt();
            degrees = new int[n];
            int tempDeg = 0;
            for (int j = 0; j < n; j++) {
                degrees[j] = 0;
            }
            for (int j = 0; j < 2 * n - 2; j++) {
                tempDeg = sc.nextInt();
                degrees[tempDeg - 1] = degrees[tempDeg - 1] + 1;
            }
            Tree tree = new Tree(n, degrees);
            int ans = tree.solve();
            String sol = ans + "";
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
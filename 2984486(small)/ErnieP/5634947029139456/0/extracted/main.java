import java.util.*;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.Writer.*;
import java.io.IOException;

public class main {

    public void swapBit(String[] array, int n, int count) {
        char[] temp;
        for (int i = 0; i<count;i++) {
            temp = array[i].toCharArray();
            if (array[i].charAt(n) == '0') {
                temp[n] = '1';
            } else {
                temp[n] = '0';
            }
            array[i] = String.valueOf(temp);
        }
    }

    public static void main(String[] args) {

        String[] currentFlow = new String[1000];
        String[] backupCurrentFlow = new String[1000];
        String[] devices = new String[1000];
        int[] plugFound = new int[1000];
        String tempString;
        String[] tempSplit = new String[2];
        String trash;
        int numCases = 0;
        int N;  //numPlugs
        int L;  //numBits
        int count = 1;
        int numSwapped = 0;
        int finalNumSwapped = 99999;


        Scanner inputFile;
        PrintWriter outFile;

        try {
            inputFile = new Scanner(new FileInputStream("data.in"));
            outFile = new PrintWriter(new FileWriter("outFile.out"));
        } catch (Exception e) {
            System.out.println("FAIL!");
            return;
        }

        numCases = inputFile.nextInt();
        trash = inputFile.nextLine();

        while (numCases-- != 0) {
            finalNumSwapped = 99999;

            for (int i = 0; i<1000; i++) plugFound[i]=0;    //clear plugs found

            N = inputFile.nextInt();    //num plugs
            L = inputFile.nextInt();    //num bits
            
            trash = inputFile.nextLine();

            tempString = inputFile.nextLine();
            System.out.println(tempString);
            currentFlow = tempString.split(" ");

            tempString = inputFile.nextLine();
            System.out.println(tempString);
            devices = tempString.split(" ");
            
            //new main().swapBit(devices,0,3);
            
            System.arraycopy(currentFlow, 0, backupCurrentFlow, 0, N);

            for (int i = 0; i<N ;i++) {     //match first plug to device i
                for (int q = 0; q<1000; q++) {plugFound[q]=0;}    //clear plugs found
                
                numSwapped = 0;
                System.arraycopy(backupCurrentFlow, 0, currentFlow, 0, N);
                
                for (int j = 0; j<L; j++) {
                    if (devices[i].charAt(j) != currentFlow[0].charAt(j)) {
                        new main().swapBit(currentFlow,j,N);
                        numSwapped++;
                    }
                }
                numSwapped = numSwapped +0;

                for (int j = 0; j<N ;j++) {
                    for (int k=0;k<N;k++) {
                        if (currentFlow[j].equals(devices[k])) {
                            plugFound[k] = 1;
                            break;
                        }
                    }
                }

                int totalSum = 0;

                for (int j = 0;j<N; j++) {
                    totalSum += plugFound[j];
                }

                if (totalSum == N) {
                    if (numSwapped < finalNumSwapped) finalNumSwapped = numSwapped;
                }

            }

            if (finalNumSwapped != 99999) {
                outFile.println("Case #" + count++ + ": " + finalNumSwapped);
                System.out.println("Found! " + finalNumSwapped);
            } else {
                outFile.println("Case #" + count++ + ": " + "NOT POSSIBLE");
                System.out.println("Not Found!");
            }


            //return;
        }

        outFile.close();
        return;
    }

}

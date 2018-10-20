import java.io.FileInputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {

    public static void main(String... args) throws Exception {
        System.setIn(new FileInputStream("inputA.txt"));
        Scanner scIn = new Scanner(System.in);

//        PrintStream streamOut = System.out;
        PrintWriter streamOut = new PrintWriter("outputA.txt", "UTF-8");

        int n = scIn.nextInt();
        String[] outputs;
        String[] editedOutputs;
        String[] devices;

        for (int i = 0; i < n; ++i) {
            int outputsCount = scIn.nextInt();
            int width = scIn.nextInt();
            scIn.nextLine();

            editedOutputs = new String[outputsCount];
            outputs = scIn.nextLine().split(" ");
            devices = scIn.nextLine().split(" ");
            Arrays.sort(devices);

            long iterationCount = Math.round(Math.pow(2, width));
            int bestAnswer = Integer.MAX_VALUE;
            for (int j = 0, switchIndicator = 0; j < iterationCount; ++j, ++switchIndicator) {
                String switchComb = Integer.toBinaryString(switchIndicator);

                // add lead zeros
                StringBuilder sb = new StringBuilder();
                for (int toPrepend = width - switchComb.length(); toPrepend > 0; toPrepend--) {
                    sb.append('0');
                }
                sb.append(switchComb);
                switchComb = sb.toString();

                int countOfSwitches = countOf1(switchComb);
                if (countOfSwitches >= bestAnswer) {
                    continue;
                }
                if (switchIndicator != 0) {
                    for (int k = 0; k < outputsCount; k++) {
                        StringBuilder editedOutput = new StringBuilder(outputs[k]);
                        for (int l = 0; l < width; l++) {
                            if (switchComb.charAt(l) == '1') {
                                editedOutput.setCharAt(l, flip(outputs[k].charAt(l)));
                            }
                        }
                        editedOutputs[k] = editedOutput.toString();
                    }
                } else {
                    editedOutputs = outputs.clone();
                }

                Arrays.sort(editedOutputs);
                boolean correct = true;
                for (int k = 0; k < outputsCount; ++k) {
                    if (!devices[k].equals(editedOutputs[k])) {
                        correct = false;
                    }
                }

                if (correct) {
                    if (bestAnswer > countOfSwitches) {
                        bestAnswer = countOfSwitches;
                    }
                }
            }
            streamOut.print("Case #" + (i + 1) + ": ");
            if (bestAnswer == Integer.MAX_VALUE) {
                streamOut.println("NOT POSSIBLE");
            } else {
                streamOut.println(bestAnswer);
            }
        }
        streamOut.close();
    }

    private static char flip(char ch) {
        if (ch == '1') {
            return '0';
        } else {
            return '1';
        }
    }

    private static int countOf1(String str) {

        int answer = 0;
        for (int k = 0; k < str.length(); ++k) {
            if (str.charAt(k) == '1') {
                answer++;
            }
        }
        return answer;
    }
}

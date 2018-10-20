import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {

    static int T = 1;
    static int N;
    static int L;

    public static void main(String args[]) throws Exception {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        scanner = new Scanner(new FileReader("inputA.txt"));
        FileWriter fileWriter = new FileWriter("outputA.out");
        BufferedWriter bw = new BufferedWriter(fileWriter);

        T = scanner.nextInt();
        for (int testNumber = 1; testNumber <= T; ++testNumber) {
            N = scanner.nextInt();
            L = scanner.nextInt();
            int[] first = new int[N];
            for (int i = 0; i < N; ++i) {
                String s1 = scanner.next();
                for (int j = 0; j < L; ++j) {
                    first[i] += Integer.parseInt(s1.substring(j, j + 1)) << L - j - 1;
                }
            }
            int[] second = new int[N];
            for (int i = 0; i < N; ++i) {
                String s1 = scanner.next();
                for (int j = 0; j < L; ++j) {
                    second[i] += Integer.parseInt(s1.substring(j, j + 1)) << L - j - 1;
                }
            }
            Arrays.sort(first);
            Arrays.sort(second);

            boolean good = true;
            for (int i = 0; i < N; ++i) {
                if (first[i] != second[i]) {
                    good = false;
                    break;
                }
            }

            if (good) {
                bw.write("Case #" + testNumber + ": " + 0);
            } else {
                boolean finish = false;
                for (int per = 1; per <= L; ++per) {
                    int[] mask = new int[L + 1];
                    for (int i = 0; i < per; ++i) {
                        mask[L - i] = 1;
                    }
                    //int[] firstMask = Arrays.copyOf(first, N);
                    while (mask[0] != 1) {
                        int[] firstMask = Arrays.copyOf(first, N);
                        for (int i = 1; i <= L; ++i) {
                            if (mask[i] == 1) {
                                for (int j = 0; j < N; ++j) {
                                    firstMask[j] = firstMask[j] ^ (1 << L - i);
                                }
                            }
                        }

                        Arrays.sort(firstMask);
                        good = true;
                        for (int i = 0; i < N; ++i) {
                            if (firstMask[i] != second[i]) {
                                good = false;
                                break;
                            }
                        }
                        if (good) {
                            finish = true;
                            bw.write("Case #" + testNumber + ": " + per);
                            break;
                        }

                        int count = 0;
                        int pos = L;
                        do {
                            for (int i = pos; i > 0; --i) {
                                if (mask[i] == 1) {
                                    if (mask[i - 1] == 0) {
                                        mask[i - 1] = 1;
                                        mask[i] = 0;
                                        count = L;
                                        break;
                                    } else {
                                        pos = i - 1;
                                        mask[i] = 0;
                                        mask[L - count] = 1;
                                        ++count;
                                    }
                                }
                            }
                        } while (count < L);
                    }
                    if (finish) {
                        break;
                    }
                }
                if (!finish) {
                    bw.write("Case #" + testNumber + ": NOT POSSIBLE");
                }
            }
            bw.newLine();
            //System.out.println("Case #" + testNumber + ": " + answer);
        }
        bw.close();
    }
}
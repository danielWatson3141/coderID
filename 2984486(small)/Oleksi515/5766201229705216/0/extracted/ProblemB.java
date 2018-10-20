import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProblemB {

    public static class Calc {
        int del;
        int all;
    }
    static int T = 1;
    static int N;
    static List<Integer>[] array;
    public static void main(String args[]) throws Exception {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        scanner = new Scanner(new FileReader("inputB.txt"));
        FileWriter fileWriter = new FileWriter("outputB.out");
        BufferedWriter bw = new BufferedWriter(fileWriter);

        T = scanner.nextInt();
        for (int testNumber = 1; testNumber <= T; ++testNumber) {
            N = scanner.nextInt();
            array = new ArrayList[N];
            for (int i = 0; i < N; ++i) {
                array[i] = new ArrayList<Integer>();
            }
            for (int i = 0; i < N - 1; ++i) {
                int first = scanner.nextInt() - 1;
                int second = scanner.nextInt() - 1;
                array[first].add(second);
                array[second].add(first);
            }
            int answer = N - 1;
            for (int i = 0; i < N; ++i) {
                if (array[i].size() == 1) {
                    break;
                } else if (array[i].size() == 2) {
                    Calc first = new Calc();
                    calculateToDelete(first, i, array[i].get(0), false);
                    Calc second = new Calc();
                    calculateToDelete(second, i, array[i].get(1), false);
                    if (answer > first.del + second.del) {
                        answer = first.del + second.del;
                    }
                } else {
                    Calc first = new Calc();
                    calculateToDelete(first, i, array[i].get(0), false);
                    Calc second = new Calc();
                    calculateToDelete(second, i, array[i].get(1), false);
                    Calc last = new Calc();
                    calculateToDelete(last, i, array[i].get(2), false);
                    int best = Math.min(first.del + second.del + last.all, first.del + second.all + last.del);
                    best = Math.min(best, first.all + second.del + last.del);

                    if (answer > best) {
                        answer = best;
                    }
                }
            }
            bw.write("Case #" + testNumber + ": " + answer);
            bw.newLine();
            //System.out.println("Case #" + testNumber + ": " + answer);
        }
        bw.close();
    }

    private static void calculateToDelete(Calc result, int parent, int child, boolean deleteAll) {
        result.all++;
        if (deleteAll) {
            result.del++;
        }
        if (array[child].size() == 2) {
            if (array[child].get(0) == parent) {
                calculateToDelete(result, child, array[child].get(1), true);
            } else {
                calculateToDelete(result, child, array[child].get(0), true);
            }
        } else if (array[child].size() != 1) {
            for (int i = 0; i < array[child].size(); ++i) {
                if (array[child].get(i) != parent) {
                    calculateToDelete(result, child, array[child].get(i), deleteAll);
                }
            }
        }
    }
}
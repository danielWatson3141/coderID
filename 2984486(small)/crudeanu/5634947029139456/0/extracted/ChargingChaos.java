import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.concurrent.Callable;

public class ChargingChaos {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new FileInputStream("A-small-attempt3.in"));
        PrintStream out = new PrintStream(new FileOutputStream("A-small-attempt3.out"));
        int nTests = scanner.nextInt();
        for (int test = 1; test <= nTests; test++) {
            final int n = scanner.nextInt();
            final int l = scanner.nextInt();
            final long[] outlet = new long[n];
            final long[] device = new long[n];
            for (int f = 0; f < n; f++) {
                outlet[f] = scanner.nextInt(2);
            }
            for (int f = 0; f < n; f++) {
                device[f] = scanner.nextInt(2);
            }
            int[] sumOutlet = new int[l];
            int[] sumDevice = new int[l];
            for (int f = 0; f < l; f++) {
                for (int g = 0; g < n; g++) {
                    sumOutlet[f] += (outlet[g] >>> f) & 1;
                    sumDevice[f] += (device[g] >>> f) & 1;
                }
            }
            int swapped = 0;
            long backTrack = 0;
            for (int f = 0; f < l; f++) {
                if (sumOutlet[f] == sumDevice[f]) {
                    if (sumOutlet[f] << 1L == n)
                        backTrack |= 1L << f;
                } else if (sumOutlet[f] == n - sumDevice[f]) {
                    // this bit should be swapped


                    swapped++;
                    for (int g = 0; g < n; g++) {
                        outlet[g] ^= 1L << f;
                        sumOutlet[f] = sumDevice[f];
                    }
//                    backTrack |= 1L << f;
                } else {
                    swapped = -1;
                    break;
                }
            }
            if (swapped != -1) {
                final long finalBackTrack = backTrack;
                int backResult = new Callable<Integer>() {
                    public int best = Integer.MAX_VALUE;

                    @Override
                    public Integer call() {
                        back(0, 0, 0L);
                        return best;
                    }

                    private void back(int bit, int swappedSoFar, long swapMask) {
                        if (bit == l) {
                            if (swappedSoFar < best) {
                                if (test(bit -1, 0, swapMask))
                                best = swappedSoFar;
                            }
                            return;
                        }
                        if ((finalBackTrack & (1L << bit)) == 0) {
                            back(bit + 1, swappedSoFar, swapMask);
                            return;
                        }
                        if (swappedSoFar < best) {
                            if (test(bit, 1, swapMask)) {
                                back(bit + 1, swappedSoFar + 1, swapMask | (1L << bit));
                            }
                            if (test(bit, 0, swapMask)) {
                                back(bit + 1, swappedSoFar, swapMask);
                            }
                        }
                    }

                    private boolean test(int bit, long isSwapped, long swapMask) {
                        HashSet<Long> outletSamples = new HashSet<Long>();
                        HashSet<Long> deviceSamples = new HashSet<Long>();
                        long mask = (1L << (bit + 1)) - 1L;
                        long swap = isSwapped << bit;
                        for (long out : outlet) {
                            outletSamples.add(((out & mask) ^ swap) ^ swapMask);
                        }
                        for (long dev : device) {
                            deviceSamples.add((dev & mask));
                        }
                        outletSamples.removeAll(deviceSamples);

                        return outletSamples.isEmpty();
                    }
                }.call();

                if (backResult != Integer.MAX_VALUE)
                    swapped += backResult;
                else
                    swapped = -1;
            }
            String answer = swapped == -1 ? "NOT POSSIBLE" : String.valueOf(swapped);
            out.printf("Case #%d: %s\n", test, answer);
        }
        out.close();
    }
}

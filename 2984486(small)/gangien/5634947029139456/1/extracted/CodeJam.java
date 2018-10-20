import java.io.*;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: gangien
 * Date: 4/11/14
 * Time: 11:46 PM
 * To change this template use File | Settings | File Templates.
 */
public class CodeJam {
    public static void main(String [] args) throws Exception {
        a();
//        b();
//        c();
    }

    static void findA(long [][] possible, int index, int N, Set<Integer> used, long value, Set<Long> found) {
        if(index == N) {
            found.add(value);
            return;
        }
        for(int x = 0; x < N; x++) {
            if(!used.contains(x)) {
                if(value == Long.MAX_VALUE || possible[index][x] == value) {
                    used.add(x);
                    long v = value;
                    if(value == Long.MAX_VALUE) {
                        v = possible[index][x];
                    }
                    findA(possible, index + 1, N, used, v, found);
                    used.remove(x);
                }
            }
        }

    }

    public static int countBits(long l) {
        int count = 0;
        for(long x = 0; x < 64; x++) {
            if((l & (1L << x)) != 0) {
                count ++;
            }
        }
        return count;
    }
    public static void a() throws Exception {
        String questionName = "A-large";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
            int [] tmp = readNumbers(r);
            int N = tmp[0];
            int L = tmp[1];
            long [] flows = readBinaryLongs(r);
            long [] devices = readBinaryLongs(r);
            long [][] possible = new long[N][N];
            for(int y = 0; y < N; y++) {
                for(int z = 0; z < N; z++) {
                    possible[y][z] = flows[y] ^ devices[z];
                }
            }

            Set<Long> found = new HashSet<Long>();
            findA(possible, 0, N, new HashSet<Integer>(), Long.MAX_VALUE, found);
            String result = "NOT POSSIBLE";
            if(found.size() > 0) {
                int min = Integer.MAX_VALUE;
                for(Long l : found) {
                    min = Math.min(min, countBits(l));

                }
                result = "" + min;
            }

            out.printf("Case #%d: ", x + 1);
            out.println(result);

        }
    }

    public static void b() throws Exception {
        String questionName = "B-small";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
//        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);
        for(int x = 0; x < count; x++) {
            Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
            int N = readNumber(r);
            for(int y = 0; y < N - 1; y++) {
                int [] link = readNumbers(r);
                List<Integer> l = map.get(link[0]);
                if(l == null) {
                    l = new ArrayList<Integer>();
                    map.put(link[0], l);
                }
                l.add(link[1]);

                l = map.get(link[1]);
                if(l == null) {
                    l = new ArrayList<Integer>();
                    map.put(link[1], l);
                }
                l.add(link[0]);
            }
            String result = map.toString();
            out.printf("Case #%d: ", x + 1);
            out.println(result);
        }
    }

    public static void c() throws Exception {
        String questionName = "C-small";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
        out = getPrintStream(questionName + ".out");
    }
    public static double sqrt(double n) {
        if(n >= 0 && n < 1) {
            double lower = n;
            double upper = 1.0d;
            while(lower <= upper) {
                double cur = (upper - lower) / 2 + lower;
                if(cur * cur == n) {
                    return cur;
                } else if(cur * cur < n) {
                    if(lower == cur) {
                        return lower;
                    }
                    lower = cur;

                } else {
                    if(upper == cur) {
                        return upper;
                    }
                    upper = cur;
                }
            }
            return upper;
        }
        return 0.0d;
    }

    public static BufferedReader getBufferedReader(String file) throws Exception {
        return new BufferedReader(new FileReader(file));
    }
    public static int readNumber(BufferedReader reader) throws Exception {
        return Integer.parseInt(reader.readLine());
    }

    public static int [] readNumbers(BufferedReader reader) throws Exception {
        String [] nums = reader.readLine().split(" ");
        int [] ret = new int[nums.length];
        for(int x = 0; x < nums.length; x++) {
            ret[x] = Integer.parseInt(nums[x]);
        }
        return ret;
    }
    public static double [] readDoubles(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        String [] nums = line.split(" ");
        double [] ret = new double[nums.length];
        for(int x = 0; x < nums.length; x++) {
            ret[x] = Double.parseDouble(nums[x]);
        }
        return ret;
    }

    public static String [] readStrings(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        String [] nums = line.split(" ");
        return nums;
    }

    public static long [] readBinaryLongs(BufferedReader reader) throws Exception {
        String [] line = readStrings(reader);
        long [] nums = new long[line.length];
        for(int x = 0; x < line.length; x++) {
            nums[x] = Long.parseLong(line[x], 2);
        }
        return nums;
    }

    public static void  quala() throws Exception {
        BufferedReader reader = getBufferedReader("A-small-attempt0.in");
        int amt = readNumber(reader);
        for(int x = 0; x < amt; x++) {
            int a1 = readNumber(reader);
            int [][] rows1 = new int[4][];
            for(int y = 0; y < 4; y++) {
                rows1[y] = readNumbers(reader);
            }

            int a2 = readNumber(reader);
            int [][] rows2 = new int[4][];
            for(int y = 0; y < 4; y++) {
                rows2[y] = readNumbers(reader);
            }
            Set<Integer> ans1 = new HashSet<Integer>();
            for(int y = 0; y < rows1[a1-1].length; y++) {
                ans1.add(rows1[a1 - 1][y]);
            }

            Set<Integer> ans2 = new HashSet<Integer>();
            for(int y = 0; y < rows2[a2-1].length; y++) {
                ans2.add(rows2[a2 - 1][y]);
            }

            ans2.retainAll(ans1);
            if(ans2.size() == 1) {
                System.out.printf("Case #%d: %d\n", x + 1,ans2.iterator().next().intValue());
            } else if(ans2.size() < 1) {
                System.out.printf("Case #%d: Volunteer cheated!\n", x + 1);
            } else {
                System.out.printf("Case #%d: Bad magician!\n", x + 1);
            }
        }
    }

    public static PrintStream getPrintStream(String file) throws Exception {
        if(new File(file).exists()) {
            throw new RuntimeException(new File(file).getAbsolutePath() + " Already exists");
        }

        FileOutputStream fos = new FileOutputStream(new File(file), true);
        PrintStream printStream = new PrintStream(fos);
        return printStream;
    }

    public static void  qualb() throws Exception {
        BufferedReader r = getBufferedReader("B-large.in");
        PrintStream out = System.out;
        out = getPrintStream("B.out");
        int amt = readNumber(r);
        for(int x = 0; x < amt; x++) {
            double [] nums = readDoubles(r);

            double C = nums[0];
            double F = nums[1];
            double X = nums[2];
            double rate = 2.0d;
            double timeSpent = 0.0d;
            double cookies = 0.0d;
            double answer = Double.MAX_VALUE;

            do {
                if(timeSpent > answer) {
                    break;
                }
                answer = Math.min(answer, timeSpent + (X / rate));
                timeSpent = timeSpent + (C / rate);
                rate += F;
            } while(true);

            out.printf("Case #%d: ", x + 1);
            out.print(answer);
            out.println();
        }
    }

    public static void quald() throws Exception {
        BufferedReader r = getBufferedReader("D-large.in");
        PrintStream out = System.out;
        out = getPrintStream("D-large.out");
        int amt = readNumber(r);
        for(int x = 0; x < amt; x++) {
            int count = readNumber(r);
            double [] naomi = readDoubles(r);
            double [] ken = readDoubles(r);
            boolean [] naomiUsed = new boolean[ken.length];
            Arrays.fill(naomiUsed, false);
            int scoreDec = 0;
            for(int y = 0; y < count; y++) {
                double cur = ken[y];
                int min = -1;
                int max = -1;
                for(int z = 0; z < count; z++) {
                    if(!naomiUsed[z]) {
                        if(min == -1) {
                            min = z;
                            if(cur < naomi[z]) {
                                max = z;
                            }
                        } else {
                            if(naomi[min] > naomi[z]) {
                                min = z;
                            }
                            if(naomi[z] > cur) {
                                if(max == -1 || naomi[max] > naomi[z]) {
                                    max = z;
                                }
                            }
                        }
                    }
                }
                if(max == -1) {
                    naomiUsed[min] = true;
                } else {
                    scoreDec++;
                    naomiUsed[max] = true;
                }
            }

            boolean [] kenUsed = new boolean[ken.length];
            Arrays.fill(kenUsed, false);
            int scoreOpt = 0;
            for(int y = 0; y < count; y++) {
                double cur = naomi[y];
                int min = -1;
                int max = -1;
                for(int z = 0; z < count; z++) {
                    if(!kenUsed[z]) {
                        if(min == -1) {
                            min = z;
                            if(cur < ken[z]) {
                                max = z;
                            }
                        } else {
                            if(ken[min] > ken[z]) {
                                min = z;
                            }
                            if(ken[z] > cur) {
                                if(max == -1 || ken[max] > ken[z]) {
                                    max = z;
                                }
                            }
                        }
                    }
                }
                if(max == -1) {
                    scoreOpt++;
                    kenUsed[min] = true;
                } else {
                    kenUsed[max] = true;
                }

            }
            out.printf("Case #%d: ", x + 1);
            out.print(scoreDec);
            out.print(" ");
            out.println(scoreOpt);
        }
    }


}

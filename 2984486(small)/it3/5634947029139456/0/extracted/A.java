import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.reverse;
import static java.lang.Integer.*;
import static java.lang.Long.parseLong;
import java.util.*;
import java.util.concurrent.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.awt.geom.*;
import java.io.*;

//// Apache Jakarta Common Lang : http://commons.apache.org/lang/
//import org.apache.commons.lang.builder.*;

// java -Xmx1024m -Xss5m
@SuppressWarnings("unchecked")
public class A {
    private static final String NO = "NOT POSSIBLE";
    public static final long MAX = Long.MAX_VALUE;
    public static final int INF = 1000000000;
    public static final int MOD = 9901; 
    public static final int UNDEF = -3;

    /*
     * problem
     * 
     * Decide if it is possible for Shota to charge all of his devices
     * at the same time, and if it is possible, figure out the minimum
     * number of switches that needs to be flipped
     */
    /*
     * solution
     * 
Limits
1 ≤ T ≤ 100.
No two outlets will begin by producing the same electric flow.
No two devices will require the same electric flow.

Small dataset
1 ≤ N ≤ 10.
2 ≤ L ≤ 10.

Large dataset
1 ≤ N ≤ 150.
10 ≤ L ≤ 40. 
     */
    private void run(int caseNumber) throws Exception {
        int N = INT();
        int L = INT();
        String[] init = new String[N];
//        char[][] init = new char[N][];
        for (int i = 0; i < init.length; i++) {
//            init[i] = STR().toCharArray();
            init[i] = STR();
        }
        String[] want = new String[N];
//        char[][] want = new char[N][];
        for (int i = 0; i < want.length; i++) {
//            want[i] = STR().toCharArray();
            want[i] = STR();
        }
        
        /// reading input done
        if(caseNumber<caseStart||caseNumber>caseEnd) {
            System.out.println("### skip case "+caseNumber);
            return;
        }

        
        /// start solving problem
        sort(init);
        sort(want);
//        char[][] a0=cvt(init);
//        char[][] a1=cvt(want);
        int ret = INF;
        for (int msk = 0; msk < 1<<L; msk++) {
//            if (ok(msk,init,want)) {
//            if (ok(msk,a0,a1)) {
            if (ok(msk,cvt(init),cvt(want))) {
                ret = Math.min(ret, bitCount(msk));
            }
        }
//        System.out.println("  want[" + want.length + "]=" + Arrays.toString(want));
        out.printf("Case #%d: %s\n", caseNumber, ret<INF?(ret+""):NO);
//        out.printf("Case #%d:", caseNumber);
//        out.println();
    }

    private char[][] cvt(String[] a) {
        char[][] r = new char[a.length][];
        for (int i = 0; i < a.length; i++) {
            r[i]=a[i].toCharArray();
        }
        return r;
    }

//    boolean ok(int msk, String[] init, String[] want) {
    boolean ok(int msk, char[][] init, char[][] want) {
        int len = init[0].length;
        for (int i = 0; i < len; i++) {
            if (has(msk,i)) {
                for (int j = 0; j < init.length; j++) {
                    init[j][i] = init[j][i]=='0'?'1':'0'; 
                }
            }
        }
        sort(init, new Comparator<char[]>() {
            @Override
            public int compare(char[] o1, char[] o2) {
                return compareArr(o1,o2);
            }
        });
//        System.out.println("### init");
//        for (int i = 0; i < init.length; i++) {
//            System.out.printf("%2d: ", i);
//            System.out.println(Arrays.toString(init[i]));
//        }
        for (int i = 0; i < want.length; i++) {
            if (!Arrays.equals(init[i],want[i])) {
                return false;
            }
        }
        return true;
    }

    static int compareArr(char[] a1, char[] a2) {
        int n=Math.min(a1.length,a2.length);
        for (int i = 0; i < n; i++) {
            if(a1[i]<a2[i]) {
                return -1;
            }
            if(a1[i]>a2[i]) {
                return 1;
            }
        }
        return a1.length-a2.length;
    }
    
    // keep only the lowest bit
    static int lowest(int mask) {
        return (mask & -mask);
    }

    // i-th bit is set
    static boolean has(int mask, int i) {
        return (mask & (1 << i)) != 0;
    }

    // set i-th bit to v
    static int set(int mask, int i, boolean v) {
        return v ? set(mask, i) : unset(mask, i);
    }

    // set i-th bit
    static int set(int mask, int i) {
        return mask | (1 << i);
    }

    // unset i-th bit
    static int unset(int mask, int i) {
        return mask & ~(1 << i);
    }

    // mask set contains subset
    static boolean contain(int set, int subset) {
        return (set & subset) == subset;
    }

    static boolean printInput=false;
//    static boolean printInput=true; // print input case
    
    static boolean printDoubleCheck=true;
//    static boolean printDoubleCheck=false;
    
    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
    static boolean writeToFile=true;
//    static boolean writeToFile=false;
    
//    static String testFilename=null;
//    static String testFilename="A-test.in";
//    static String testFilename="A-small-attempt0.in";
    static String testFilename="A-small-attempt1.in";
//    static String testFilename="A-small.in";
//    static String testFilename="A-small-practice.in";
//    static String testFilename="A-large.in";
//    static String testFilename="A-large-practice.in";
    
    static int THREAD=1;
//    static int THREAD=3;
    
    static BufferedReader in;
    static StringTokenizer inTok = new StringTokenizer("");

//    static Scanner in;
    static PrintWriter out;

    //control the cases to run : [caseStart..csaeEnd]
    static int caseStart=1;
//    static int caseStart=1;
    static int caseEnd=Integer.MAX_VALUE;
//    static int caseEnd=caseStart+0;
    
    public static void main(String[] args) throws Exception {
        String resultFilename=testFilename+"-res.txt";
        long start = System.currentTimeMillis();

//        myTest();        
        
        // $0 inputFile caseStart caseEnd
        if(args.length>0) {
            testFilename = args[0];
        }
        if(args.length>1) {
            caseStart=parseInt(args[0]);
        }
        if(args.length>2) {
            caseEnd=parseInt(args[1]);
        }
        
        // redirect sys out
        if(redirectStdoutToFile) {            
            String filename = "output.txt";
            System.out.println("NOTE: redirect stdout to file "+filename);
            FileOutputStream fos = new FileOutputStream(filename);
            PrintStream ps = new PrintStream(fos,true);
            System.setOut(ps);
        }
        
        if(testFilename==null) {
            myTest();
        } else {
            
//          in = new BufferedReader(new InputStreamReader(System.in));
            in = new BufferedReader(new FileReader(testFilename));
            int NN=INT();
//            in = new Scanner(System.in);
//            in = new Scanner(new File(testFilename));
//            int NN=in.nextInt();
            out = writeToFile ? new PrintWriter(new FileWriter(resultFilename),true) 
                              : new PrintWriter(System.out, true);
            if (THREAD>1) {                
                parallelSolve(NN);            
            } else {                
                for (int i = 1; i <= NN; i++) {
//                    out.printf("Case #%d: ", i);
                    if (printInput) System.out.println("\n### Case "+i);                
                    new A().run(i);
                }
            }
            in.close();
            
            if(writeToFile) {
                out.close();
            }
        }
        
        System.out.println("\nTime taken: "+((System.currentTimeMillis()-start)/1000.0)+" sec");
        
        if(writeToFile) {
            File ans=new File(testFilename+"-ans.txt");
            if(ans.exists()&&ans.length()>0) {
                boolean same=sameFileContent(ans, new File(resultFilename), true);
                if(same) {
                    System.out.println("Answer correct :)");
                    System.out.println("Answer match file "+ans);
                } else {
                    System.out.println("ERROR : Answer not matched");
                    
                    // check other possible answer file
                    for (int i = 1; i < 9; i++) {
                        ans=new File(testFilename+"-ans"+i+".txt");
                        if (ans.exists() && ans.length()>0) {                            
                            same=sameFileContent(ans, new File(resultFilename), false);
                            if (same) {
                                System.out.println("\nAnswer correct :)");
                                System.out.println("Answer match file "+ans);
                                break;
                            }
                        }
                    }
                }
            }            
        }
    }
    static void parallelSolve(int totalCase) throws Exception {
        int th = Math.min(THREAD, Runtime.getRuntime().availableProcessors());
        System.out.println("thread = "+th);
        ExecutorService executor = Executors.newFixedThreadPool(th);
        List<Solver> solvers = new ArrayList<Solver>();
        for (int i = 1; i <= totalCase; i++) {
            if (printInput) System.out.println("\n### Case "+i);

            solvers.add(new Solver());
        }

        List <Future<Object>> results = executor.invokeAll(solvers);
            
        int caseNumber=1;
        for (Future<Object> result : results) {
            out.printf("Case #%d: %s\n", caseNumber, result.get());
            caseNumber++;
        }
        executor.shutdown();
    }
    static class Solver implements Callable<Object> {
        final int n;

        // Do all input reading here!!
        public Solver() throws IOException {
            n = INT();
            throw new RuntimeException("TODO: do reading/solving in Solver()");
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public Object call() throws Exception {
            return n;
        }
    }
    
    private static boolean sameFileContent(File ansFile, File resFile, boolean showInfo) throws IOException {
        if (showInfo) {
            System.out.println();
        }
        
        BufferedReader ans = new BufferedReader(new FileReader(ansFile));
        BufferedReader res = new BufferedReader(new FileReader(resFile));
        boolean ok=true;
        List<Integer> wrong = new ArrayList<Integer>();
        int ln=1;
        while(true) {
            String sAns=ans.readLine(); 
            String sRes=res.readLine();
            if(sAns==null) {
                if(sRes!=null) {
                    if (showInfo) {                        
                        System.out.println("### result has more lines than answer");
                        do {
                            System.out.println(sRes);
                        } while ((sRes=res.readLine())!=null);
                        System.out.println();
                    }
                    ok=false;
                }
                break;
            }
            if(sRes==null) {
                if(sAns!=null && !sAns.isEmpty()) {
                    if (showInfo) {                        
                        System.out.println("### answer has more lines than result");
                        do {
                            System.out.println(sAns);
                        } while ((sAns=ans.readLine())!=null);
                        System.out.println();
                    }
                    ok=false;
                }
                break;
            }
            String tAns = sAns.trim();
            String tRes = sRes.trim();
            if(!tAns.equals(tRes)) {
                if (matchDouble(tAns,tRes, showInfo && printDoubleCheck)) {
                    if (showInfo && printDoubleCheck) {                            
                        System.out.println("### line "+ln+" pass double check:");
                        System.out.println("ans = "+sAns);
                        System.out.println("res = "+sRes);
                        System.out.println();
                    }                    
                } else {
                    if (showInfo) {                        
                        System.out.println("### line "+ln+" not match:");
                        System.out.println("ans = "+sAns);
                        System.out.println("res = "+sRes);
                        System.out.println();
                    }
                    ok=false;
                    wrong.add(ln);
                }
            }
            ln++;
        }
        if(!ok && showInfo) {
            System.out.println("wrong : "+wrong.size()+" lines, lines start from 1: "+wrong);
            System.out.println("total : "+ln+" lines");
        }
        ans.close();
        res.close();
        return ok;
    }    
    private static boolean matchDouble(String tAns, String tRes, boolean showInfo) {
        final double tol = 1e-6;
        
        if (!tAns.matches(".*[0-9]+\\.[0-9]+.*") || !tRes.matches(".*[0-9]+\\.[0-9]+.*")) {
            // no 123.456 pattern
            return false;
        }
        
        String[] sa= tAns.split(" ");
        String[] sr= tRes.split(" ");
        if (sa.length!=sr.length) {
            return false;
        }
        for (int i = 0; i < sr.length; i++) {
            if (sa[i].equals(sr[i])) continue; 
            
            try {                    
                double a = Double.parseDouble(sa[i]);
                double r = Double.parseDouble(sr[i]);
                if (abs(a-r)>tol) {
                    if (showInfo) {                        
                        System.out.println(i+"-th ans!=res: "+sa[i]+" != "+sr[i]);
                    }
                    return false;
                }
            } catch (NumberFormatException e) {
                return false;
            }
        }
        return true;
    }
    

    private static void myTest() throws Exception {
//        int num=-1000;
        int num=1000;
        for (int i = 1; i <= num; ++i) {
//            System.out.println(i+" : "+new A().small(Rn.i(0,50)));
//            for (int j = 1; j <= i; ++j) {
//                System.out.println(i+","+j+" : "+i);
//            }
        }
    }

    static String LINE() throws IOException {
        String s=in.readLine();
        if (printInput) System.out.println(s);
        return s;
    }
    static String STR() throws IOException {
        while (!inTok.hasMoreTokens()) {
            String line = LINE();
            if (line == null) {
                return null;
            }
            inTok = new StringTokenizer(line);
        }
        return inTok.nextToken();
    }

    static int INT() throws IOException { return Integer.parseInt(STR()); }
    static long LONG() throws IOException { return Long.parseLong(STR()); }
    static double DOUBLE() throws IOException { return Double.parseDouble(STR()); }
    
    static int INT(String s) { return Integer.parseInt(s); }
    static double DOUBLE(String s) { return Double.parseDouble(s); }
    static long LONG(String s) { return Long.parseLong(s); }
}


import java.util.*;
import java.io.*;

class Main {
    private Stdin stdin = new Stdin();
    private java.util.logging.Logger logger = null;
    private static String logger_name = "XXX";

    /**
     * Init class data here
     */
    private void init() {
	
    }

    /**
     * Handle the input here.
     * This method will call solve() method inside to solve the problem.
     * The return value indicates if there are more input data need to 
     * be handled. If it doesn't return 0, means this function have to be
     * called again to solve next data.
     * @return 0: end. 1: need to call input() again for next data.
     */
    private int input() {
	int ret=0;
	String com1;
	int T;

	com1 = stdin.get1();
	if (com1==null) {
	    return ret;
	}
	T = Integer.parseInt(com1);

	for (int t=0; t<T; t++) {
	    int N;
	    int L;
	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    N = Integer.parseInt(com1);
	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    L = Integer.parseInt(com1);

	    int[][] outlets = new int[N][L];
	    int[][] devices = new int[N][L];

	    for (int i=0; i<N; i++) {
		com1 = stdin.get1();
		if (com1==null) {
		    return ret;
		}
		for (int j=0; j<L && j<com1.length(); j++) {
		    if (com1.charAt(j)=='0') {
			outlets[i][j]=0;
		    } else {
			outlets[i][j]=1;
		    }
		}
	    }
	    
	    for (int i=0; i<N; i++) {
		com1 = stdin.get1();
		if (com1==null) {
		    return ret;
		}
		for (int j=0; j<L && j<com1.length(); j++) {
		    if (com1.charAt(j)=='0') {
			devices[i][j]=0;
		    } else {
			devices[i][j]=1;
		    }
		}
	    }
	    solve(outlets, devices);
	}

	ret=0;
    	return ret;
    }

    private boolean check1(int[][] outlets, int[][] devices, int L) {
	HashSet<String> map1 = new HashSet<String>(outlets.length);

	for (int i=0; i<outlets.length; i++) {
	    StringBuffer sb1 = new StringBuffer(L);
	    for (int j=0; j<L; j++) {
		if (outlets[i][j]==0) {
		    sb1.append("0");
		} else {
		    sb1.append("1");
		}
	    }
	    map1.add(sb1.toString());
	}

	for (int i=0; i<devices.length; i++) {
	    StringBuffer sb1 = new StringBuffer(L);
	    for (int j=0; j<L; j++) {
		if (devices[i][j]==0) {
		    sb1.append("0");
		} else {
		    sb1.append("1");
		}
	    }
	    String s = sb1.toString();
	    if (!map1.contains(s)) {
		return false;
	    }
	}
	return true;
    }

    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(int[][] outlets, int[][] devices) {
	int N = outlets.length;
	int L = outlets[0].length;

	int[] o1 = new int[L];
	int[] d1 = new int[L];

	Arrays.fill(o1,0);
	Arrays.fill(d1,0);

	for (int i=0; i<L; i++) {
	    for (int j=0; j<N; j++) {
		o1[i] += outlets[j][i];
		d1[i] += devices[j][i];
	    }
	}

	/* backtrackng */
	int[] switch1 = new int[L];
	Arrays.fill(switch1, -1);

	for (int i=0; i<L; ) {
	    if (i<0) {
		break;
	    }
	    if (switch1[i] == -1) {
		switch1[i]=0;
		if (o1[i] != d1[i]) {
		    continue;
		}
		if (!check1(outlets, devices, i+1)) {
		    continue;
		}
		i++;
	    } else if (switch1[i] == 0) {
		switch1[i]=1;
		for (int j=0; j<N; j++) {
		    outlets[j][i] = 1 - outlets[j][i];
		}
		o1[i]=N-o1[i];
		if (o1[i] != d1[i]) {
		    continue;
		}
		if (!check1(outlets, devices, i)) {
		    continue;
		}
		i++;
	    } else {
		for (int j=0; j<N; j++) {
		    outlets[j][i] = 1 - outlets[j][i];
		}
		o1[i]=N-o1[i];
		switch1[i]=-1;
		i--;
	    }
	}

	output(switch1);
    }

    int output_N=0;
    /**
     * Output the results
     */
    private void output(int[] switch1) {
	output_N++;
	int result=-1;
	if (switch1[0]<0) {
	    result=-1;
	} else {
	    result=0;
	    for (int i=0; i<switch1.length; i++) {
		result += switch1[i];
	    }
	}
	if (result<0) {
	    System.out.format("Case #%1$d: NOT POSSIBLE%n", output_N);
	} else {
	    System.out.format("Case #%1$d: %2$d%n", output_N, result);
	}
    }


    /**
     * log information for debugging.
     */
    public void logInfo(String a, Object... args) {
	if (logger != null) {
	    logger.info(String.format(a,args));
	}
    }

    public void begin() {
	this.logger = java.util.logging.Logger.getLogger(Main.logger_name);
	if (this.logger.getLevel() != java.util.logging.Level.INFO) {
	    this.logger = null;
	}
	init();
	while (input()==1) {
	}
    }

    public void unittest() {
	this.logger = java.util.logging.Logger.getLogger(Main.logger_name);
    }

    public static void main (String args[]) {
	Main myMain = new Main();
	if (args.length >= 1 && args[0].compareTo("unittest")==0) {
	    myMain.unittest();
	    return;
	}
	java.util.logging.Logger.getLogger(Main.logger_name).setLevel(java.util.logging.Level.SEVERE);
	for (int i=0; args!=null && i<args.length; i++) {
	    if (args[i].compareTo("debug")==0) {
		java.util.logging.Logger.getLogger(Main.logger_name).setLevel(java.util.logging.Level.INFO);
	    }
	}
	myMain.begin();
    }
}

class Stdin
{
    private java.io.InputStream cin;
    private java.io.BufferedReader cin_br;
    private java.io.StreamTokenizer cin_st;

    public static java.lang.String endl = System.getProperty("line.separator");

    public Stdin() {
	this(java.lang.System.in);
    }

    public Stdin(java.io.InputStream cin) {
	this.cin = cin;
 	cin_br = new java.io.BufferedReader(new java.io.InputStreamReader(this.cin));
	cin_st = new java.io.StreamTokenizer(cin_br);
	cin_st.resetSyntax();
	cin_st.wordChars('\u0021','\u007E');
	cin_st.wordChars('\u00A0','\u00FF');
	cin_st.whitespaceChars('\u0000', '\u0020');
    }

    public java.io.InputStream getInputStream() {
	return cin;
    }

    public java.io.BufferedReader getBufferedReader() {
	return cin_br;
    }

    public java.io.StreamTokenizer getStreamTokenizer() {
	return cin_st;
    }

    public java.lang.String gets() {
	java.lang.String str=null;
	try {
	    str = this.cin_br.readLine();
	} catch (java.lang.Exception e) {
	    str = null;
	}
	return str;
    }

    public java.lang.String get1() {
	java.lang.String str=null;
	try {
	    if (cin_st.nextToken() != java.io.StreamTokenizer.TT_EOF) {
		str = cin_st.sval;
	    }
	} catch (java.lang.Exception e) {
	    str = null;
	}
	return str;
    }
}

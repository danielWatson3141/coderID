package Y2014.Round1A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class ChargingChaos {

    private static final String newLine = System.getProperty("line.separator");
    int T;
    int copy;
    BufferedWriter bw;
    {
	try {
	    bw = new BufferedWriter(new FileWriter(new File("E:\\out"
		    + System.currentTimeMillis() + ".t")));
	} catch (IOException e) {
	    // TODO Auto-generated catch block
	    e.printStackTrace();
	}
    }

    public static void main(String[] args) throws IOException {
	long b = System.currentTimeMillis();
	ChargingChaos f = new ChargingChaos();
	f.do1();
	long a = System.currentTimeMillis();
	System.out.println(a - b);

    }

    private void do1() throws IOException {
	Scanner sc = new Scanner(new File("E:\\A-small-attempt0.in"));
	copy = sc.nextInt();
	int N = 1;
	T = copy;
	while (T-- > 0) {
	    int n = sc.nextInt();
	    int l = sc.nextInt();
	    int[] source = new int[n];
	    int[] target = new int[n];
	    for (int i = 0; i < n; i++) {
		String s = sc.next();
		source[i] = Integer.parseInt(s, 2);
	    }
	    for (int i = 0; i < n; i++) {
		String s = sc.next();
		target[i] = Integer.parseInt(s, 2);
	    }
	    solve(N, source, target, l);
	    N++;
	}
	// TODO Auto-generated method stub
	sc.close();
	bw.close();

    }

    private void solve(int N, int[] source, int[] target, int l)
	    throws IOException {
	Arrays.sort(target);
	for (int i = 0; i < 1 << l; i++) {
	    int[] tmp = copy(source);
	    int cnt = 0;
	    for (int j = 0; j < l; j++) {
		if ((i & 1 << j) > 0) {
		    changeBit(tmp, j);
		    cnt++;
		}
	    }
	    if (compare(tmp, target)) {
		resultPrint(N, cnt);
		return;
	    }
	}
	resultPrint(N, "NOT POSSIBLE");
    }

    private boolean compare(int[] tmp, int[] target) {
	Arrays.sort(tmp);
	for (int i = 0; i < tmp.length; i++)
	    if (tmp[i] != target[i])
		return false;
	return true;
    }

    private void changeBit(int[] tmp, int j) {
	for (int i = 0; i < tmp.length; i++) {
	    if ((tmp[i] & 1 << j) > 0)
		tmp[i] -= 1 << j;
	    else
		tmp[i] += 1 << j;
	}
    }

    private int[] copy(int[] source) {
	int[] copied = new int[source.length];
	for (int i = 0; i < source.length; i++)
	    copied[i] = source[i];
	return copied;
    }

    public void resultPrint(int n, Object res) throws IOException {
	// System.out.print("Case #" + n + ": " + res + newLine);

	/*
	 * if (n == copy) // for last output ,we don't need newLine.
	 * bw.write("Case #" + n + ": " + res); else
	 */
	bw.write("Case #" + n + ": " + res + newLine);

    }

}

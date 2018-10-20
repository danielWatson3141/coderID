package Y14.round1A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("Y14.round1A\\A-small-attempt1.in"));
		FileWriter fstream = new FileWriter("Y14.round1A\\A-small-attempt1.out");
		BufferedWriter out = new BufferedWriter(fstream);
		int T = Integer.valueOf(in.nextLine());
		for (int i = 0; i < T; i++) {
			String[] array = in.nextLine().split(" ");
			int N = Integer.valueOf(array[0]), L = Integer.valueOf(array[1]);
			String[] from = in.nextLine().split(" ");
			long[] f = new long[N], t = new long[N];
			for (int j = 0; j < N; j++) {
				f[j] = Long.parseLong(from[j], 2);
			}
			String[] to = in.nextLine().split(" ");
			for (int j = 0; j < N; j++) {
				t[j] = Long.parseLong(to[j], 2);
			}
			int result = getResult(f, t, L);
			if (result != -1) {
				out.write("Case #" + (i + 1) + ": " + result);
			} else {
				out.write("Case #" + (i + 1) + ": NOT POSSIBLE");
			}
			out.newLine(); 
		}
		in.close();
		out.close();
	}
	
	public static int getResult(long[] from, long[] to, int L) {
		Arrays.sort(to);
		int N = from.length;
		for (int i = 0; i < L; i++) {
			ArrayList<ArrayList<Integer>> sets = combine(L, i);
			
			for (ArrayList<Integer> list :sets) {
				char[] chs = new char[L];
				Arrays.fill(chs, '0');
				for (int kk : list) {
					chs[kk - 1] = '1';
				}
				long num = Long.parseLong(new String(chs), 2);
				long[] newFrom = new long[N];
				newFrom = from.clone();
				for (int j = 0; j < N; j++) {
					newFrom[j] ^= num;
				}
				Arrays.sort(newFrom);
				if (Arrays.equals(newFrom, to)) {
					return i;
				}
			}
		}
		return -1;
	}
	
	public static ArrayList<ArrayList<Integer>> combine(int n, int k) {
		// Start typing your Java solution below
		// DO NOT write main() function
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>> ();
        ArrayList<Integer> path = new ArrayList<Integer> ();
        if (k == 0) {
            result.add(path);
            return result;
        } else if (n == 0) {
            return result;
        } 
        ArrayList<ArrayList<Integer>> preRes1 = combine(n - 1, k);
        ArrayList<ArrayList<Integer>> preRes2 = combine(n - 1, k - 1);
        for (ArrayList<Integer> list : preRes2) {
            list.add(n);
        }
        result.addAll(preRes1);
        result.addAll(preRes2);
        return result;
	}
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package speedprogramming;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.print.Printer;

/**
 *
 * @author User
 */
public class SpeedProgramming {

	public static boolean equ(long[] a, long[] b) {
		int cou = 0;
		for (int i = 0; i < a.length; i++) {
			for (long qwe : b) {
				if (qwe == a[i]) {
					cou++;
					break;
				}
			}
		}
		if (cou == a.length) {
			return true;
		} else {
			return false;
		}
	}

	public static long val(long v, int bit) {
		if ((v & bin[bit]) == 0) {
			v = v + bin[bit];
		} else {
			v = v - bin[bit];
		}
		return v;
	}

	public static long[] bin = new long[41];

	public static List getDiff(long a, long b, int len) {
		List<Integer> bit;
		bit = new LinkedList<>();
		for (int i = 0; i < len; i++) {
			if ((a & bin[i]) != (b & bin[i])) {
				bit.add(i);
			}
		}
		return bit;
	}

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) throws FileNotFoundException {

		for (int i = 0; i < 41; i++) {
			bin[i] = (long) Math.pow(2, i);
		}

		Scanner fin = new Scanner(new File("input.txt"));
		long n, m;
		long[] init;
		long[] finala;
		long[] inter;
		List<Integer> un;
		int testCase = fin.nextInt();
		List<Integer> ans = new LinkedList<>();
		//System.out.println(testCase);
		for (int z = 0; z < testCase; z++) {
			ans.clear();
			System.out.print(String.format("Case #%d: ", z + 1));
			m = fin.nextLong();
			n = fin.nextLong();

			init = new long[(int) m];
			finala = new long[(int) m];
			inter = new long[(int) m];

			for (int i = 0; i < m; i++) {
				init[i] = fin.nextLong(2);
				//System.out.println(init[i]);
			}
			for (int i = 0; i < m; i++) {
				finala[i] = fin.nextLong(2);
				//System.out.println(finala[i]);
			}

			boolean qwe = false;

			for (int i = 0; i < m && !qwe; i++) {
				un = getDiff(init[i], finala[0], (int) n);
				//System.out.println(un);
				for (int j = 0; j < m; j++) {
					inter[j] = init[j];
					for (Integer q : un) {
						inter[j] = val(inter[j], q);
					}
				}
				if (equ(finala, inter)) {
					//System.out.println(un.size());
					ans.add(un.size());//qwe = true;
				}
				/*System.out.println(init);
				 System.out.println(inter);
				 System.out.println(finala);*/
			}
			if (ans.size() == 0) {
				System.out.println("NOT POSSIBLE");
			} else {
				System.out.println(Collections.min(ans));
			}
		}

	}

}

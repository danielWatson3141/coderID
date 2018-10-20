package core.compitition;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import core.helper.IntSort;

public class Charging {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			FileReader fr = new FileReader(
					"src/core/io/input.txt");
			FileWriter fw = new FileWriter(
					"src/core/io/output.txt");
			BufferedReader br = new BufferedReader(fr);
			BufferedWriter bw = new BufferedWriter(fw);
			int n = Integer.parseInt(br.readLine());
			for (int i = 0; i < n; i++) {
				String out = execute(br);
				bw.write("Case #" + (i+1) + ": " + out + "\n");
			}
			bw.close();
			br.close();
		} catch (Exception e) {
			e.printStackTrace(System.out);
		}
	}
	
	public static String execute(BufferedReader br) {
		String result = "NOT POSSIBLE";
		String a;
		int finalcount =  99999999 ;
		try {
			a = br.readLine();
			String arr[] = a.split(" ");
			int n = Integer.parseInt(arr[0]);
			int l = Integer.parseInt(arr[1]);
			String ss[] = br.readLine().split(" ");
			int src[] = getArray(ss);
			String ds[] = br.readLine().split(" ");
			int dest[] = getArray(ds);
			int max = (int) Math.pow(2, l);
			for (int i = 0; i < max; i++) {
				if(applyAndTest(src, dest, i)){
					int selectedNumber = i;
					String tmp = Integer.toBinaryString(selectedNumber);
					int count = 0;
					for (int j = 0; j < tmp.length(); j++) {
						if(tmp.charAt(j) == '1') {
							count++;
						}
					}
					if(count < finalcount) {
						finalcount = count;
					}
				}
			}
			if(finalcount != 99999999) {
				result = String.valueOf(finalcount);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return result;
	}

	private static boolean applyAndTest(int[] src, int[] dest, int i) {
		// TODO Auto-generated method stub
		boolean test = false;
		IntSort s = new IntSort();
		int nsrc[] = s.sort(apply(src, i));
		int ndest[] = s.sort(dest);
		test = compare(nsrc, ndest);
		return test;
	}

	private static boolean compare(int[] nsrc, int[] ndest) {
		// TODO Auto-generated method stub
		boolean test = true;
		if(nsrc.length == ndest.length) {
			for(int i = 0; i < nsrc.length && test; i++) {
				test = nsrc[i] == ndest[i];
			}			
		}
		return test;
	}

	private static int[] apply(int[] src, int i) {
		// TODO Auto-generated method stub
		int[] nsrc = new int[src.length];
		for (int j = 0; j < src.length; j++) {
			int a = src[j];
			nsrc[j] =  (a&(~i))|((~a)&i);
		}
		return nsrc;
	}

	private static int[] getArray(String[] ds) {
		// TODO Auto-generated method stub
		int[] arr = new int[ds.length];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = Integer.parseInt(ds[i],2);
		}
		return arr;
	}
	
	
}

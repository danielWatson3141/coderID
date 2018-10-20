import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Charge {
	private final int N;
	private final int len;
	private final ArrayList<String> ini = new ArrayList<String>();
	private final ArrayList<String> tar = new ArrayList<String>();
	private Queue<ArrayList<String>> q = new LinkedList<ArrayList<String>>();
	private ArrayList<ArrayList<String>> set = new ArrayList<ArrayList<String>>();
	
	
	public Charge(int N, int len, String[] start, String[] end) {
		this.N = N;
		this.len = len;
		for (int i = 0; i < N; i++) {
			ini.add(start[i]);
		}
		for (int j = 0; j < N; j++) {
			tar.add(end[j]);
		}
	}
	
	public ArrayList<String> alter(ArrayList<String> s, int idx) {
		ArrayList<String> res = new ArrayList<String>();
		for (String sub: s) {
			char[] copy = sub.toCharArray();
			if (sub.charAt(idx) == '0') {
				copy[idx] = '1';
			}
			else {
				copy[idx] = '0';
			}
			res.add(String.valueOf(copy));
		}
		return res;
	}
	
	public boolean equals(ArrayList<String> a, ArrayList<String> b) {
		for (String s : a) {
			if (!b.contains(s)) return false;
		}
		return true;
	}
	
	public boolean contains(ArrayList<String> s) {
		for (ArrayList<String> sub : set) {
			if (equals(sub, s)) return true;
		}
		return false;
	}
	
	public int solve() {
		LinkedList<Integer> d = new LinkedList<Integer>();
		q.add(ini);
		set.add(ini);
		d.add(0);
		while(!q.isEmpty()) {
			ArrayList<String> s = q.remove();
			int lev = d.remove();
			if (equals(s, tar)) return lev;
			for (int i = 0; i < len; i++) {
				ArrayList<String> next = alter(s, i);
				if (!contains(next)) {
					d.add(lev+1);
					q.add(next);
					set.add(next);
				}

			}
		}
		return -1;
	}
	
	public static void main(String[] args) {
		File file = new File(args[0]);
		Scanner in = null;
		try {
			in = new Scanner(file);
		} 
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		BufferedWriter fw = null;
		File file2 = new File("C:/Users/wang/Desktop/result.txt");
		try {
			fw = new BufferedWriter(new FileWriter(file2));			
		} 
		catch (IOException e) {
			e.printStackTrace();
		}
		int T = 0;
		if (in.hasNext()) {
			T = in.nextInt();
		}
		for (int i = 0; i < T; i++) {
			int N = in.nextInt();
			int L = in.nextInt();
			String[] start = new String[N];
			String[] end = new String[N];
			for (int j = 0; j < N; j++) {
				start[j] = in.next();
			}
			for (int k = 0; k < N; k++) {
				end[k] = in.next();
			}
			Charge c = new Charge(N, L, start, end);
			int res = c.solve();
/*			System.out.print("Case #"+Integer.toString(i+1)+": ");
			if (res == -1) {
				System.out.println("NOT POSSIBLE");
			}
			else {
				System.out.println(res);
			}*/
			try {
				fw.append("Case #"+Integer.toString(i+1)+": ");
				if (res == -1) {
					fw.append("NOT POSSIBLE");
					
				}
				else {
					fw.append(Integer.toString(res));
				}
				fw.newLine();
			}
			catch (IOException e){
				e.printStackTrace();
			}
			
		}
		try {
			fw.close();
		}
		catch (IOException e) {
			
		}
		in.close();
	}
	

}

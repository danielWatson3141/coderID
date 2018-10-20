

import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.Integer.*;

public class B {
	static Scanner sc = null;
	static BufferedReader br = null;
	static PrintWriter out = null;
	static PrintStream sysout = System.out;
	static Random rnd = new Random();
	
	int INF = Integer.MAX_VALUE / 10;
	double DF = 0.0000000001;
	
	long b = 1;
	int N = 0;
	int M = 0;
	
	List<List<Integer>> g = null;
	
	int[][] cdp = null;
	public void solve() throws Exception{
		String s = br.readLine();
		N = parseInt(s);
		g = new ArrayList<List<Integer>>();
		for(int i = 0; i < N; i++){
			List<Integer> l = new ArrayList<Integer>();
			g.add(l);
		}
		for(int i = 0; i < N-1; i++){
			s = br.readLine();
			String[] sp = s.split(" ");
			int f = parseInt(sp[0])-1;
			int t = parseInt(sp[1])-1;
			g.get(f).add(t);
			g.get(t).add(f);
		}
		cdp = new int[N][N];
		
		int ans = N-1;
		for(int I = 0; I < N; I++){
			if(g.get(I).size() == 1){
				ans = min(ans, N-1);
			}
			else if(g.get(I).size() == 2){
				ans = min(ans, calc(I, g.get(I).get(0)) + calc(I, g.get(I).get(1)));
			}
			else{
				for(int i = 0; i < g.get(I).size(); i++){
					
					for(int j = i+1; j <  g.get(I).size(); j++){
					
						int NUM = 0;
						for(int k = 0; k < g.get(I).size(); k++){
							if(k != i && k != j ){
								NUM += getNum(I, g.get(I).get(k));
							}
						}
						NUM += calc(I,g.get(I).get(i));
						NUM += calc(I, g.get(I).get(j));
						ans = min(ans, NUM);
					}
				}
			}
		}
		println(ans);
	}
	
	int calc(int p, int n){
		int num = Integer.MAX_VALUE;
		if(g.get(n).size() == 1){
			return 0;
		}
		else if(g.get(n).size() == 2){
			int next = g.get(n).get(0);
			if(next == p){
				next = g.get(n).get(1);
			}
			num = getNum(n, next);
		}
		else if(g.get(n).size() >= 3){
			for(int i = 0; i < g.get(n).size(); i++){
				if(g.get(n).get(i) == p) continue;
				for(int j = i+1; j < g.get(n).size(); j++){
					if(g.get(n).get(j) == p) continue;
					int NUM = 0;
					for(int k = 0; k < g.get(n).size(); k++){
						if(k != i && k != j && g.get(n).get(k) != p){
							NUM += getNum(n, g.get(n).get(k));
						}
					}
					NUM += calc(n,g.get(n).get(i));
					NUM += calc(n, g.get(n).get(j));
					num = min(num, NUM);
				}
			}
		}
		return num;
		
	}
	
	int getNum(int p, int n){
		int num = 1;
		for(int i = 0; i < g.get(n).size(); i++){
			int next = g.get(n).get(i);
			if(next == p){
				continue;
			}
			num += getNum(n, next);
		}
		return num;
	}
	
	boolean isp(int p, int n){
		boolean f = true;
		if(g.get(n).size() == 1){
			return true;
		}
		else if(g.get(n).size() == 3){
			for(int i = 0; i < g.get(n).size(); i++){
				int next = g.get(n).get(i);
				if(next == p) continue;
				f = f & isp(n, next);
			}
			return f;
		}
		else{
			return false;
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		File file = new File("B-small-attempt0.in");
		if(file.exists()){
			System.setIn(new BufferedInputStream(new FileInputStream(file)));
		}
		//sc =  new Scanner(System.in);
		br = new BufferedReader(new InputStreamReader(System.in));
		FileWriter fw = new FileWriter(new File("output.txt"));
		out = new PrintWriter(fw);
		
		B b = new B();
		int T = 0;
		if(sc != null){
			T = sc.nextInt();
		}
		else{
			T = parseInt(br.readLine());
		}
		int t = 1;
		while(t <= T){
			out.print("Case #" + t + ": ");
			System.out.print("Case #" + t + ": ");
			b.solve();
			t++;
		}
		out.close();
		fw.close();
	}
	
	void print(int i){
		out.print(i + "");
		System.out.print(i);
	}
	void println(int i){
		out.println(i + "");
		System.out.println(i);
	}
	void print(String s){
		out.print(s);
		System.out.print(s);
	}
	void println(String s){
		out.println(s);
		System.out.println(s);
	}
	void print(long i){
		out.print(i + "");
		System.out.print(i);
	}
	void println(long i){
		out.println(i + "");
		System.out.println(i);
	}
}

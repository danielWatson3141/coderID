

import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.Integer.*;

public class A {
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
	
	String NP =  "NOT POSSIBLE";
	
	public void solve() throws Exception{
		String s = br.readLine();
		String[] sp = s.split(" ");
		N = parseInt(sp[0]);
		int L = parseInt(sp[1]);
		int[] E = new int[N];
		s = br.readLine();
		sp = s.split(" ");
		for(int i = 0; i < N; i++){
			E[i] = Integer.parseInt(sp[i], 2);
		}
		int[] d = new int[N];
		s = br.readLine();
		sp = s.split(" ");
		for(int i = 0; i < N; i++){
			d[i] = Integer.parseInt(sp[i], 2);
		}
		int[] e = new int[N];
		Arrays.sort(d);
		int ans = INF;
		for(int i = 0; i < (1 << L) ; i++){
			e = Arrays.copyOf(E, N);
			for(int j = 0; j < L; j++){
				int b = 1 << j;
				if( (i & b ) > 0){
					for(int k = 0; k < N; k++){
						int tmp = e[k];
						tmp = tmp ^ b;
						e[k] = tmp;
					}
				}
			}
			
			Arrays.sort(e);
			
			boolean flag = true;
			for(int j = 0; j < N; j++){
				if(e[j] != d[j]){
					flag = false;
					break;
				}
			}
			if(flag){
				int b = i;
				int cnt = 0;
				while(b > 0){
					int tmp = Integer.highestOneBit(b);
					b ^= tmp;
					cnt++;
				}
				ans = min(ans, cnt);
			}
		}
		if(ans == INF){
			println(NP);
		}
		else{
			println(ans);
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		File file = new File("A-small-attempt0.in");
		if(file.exists()){
			System.setIn(new BufferedInputStream(new FileInputStream(file)));
		}
		//sc =  new Scanner(System.in);
		br = new BufferedReader(new InputStreamReader(System.in));
		FileWriter fw = new FileWriter(new File("output.txt"));
		out = new PrintWriter(fw);
		
		A b = new A();
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



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
	
	int N = 0;
	int M = 0;
	
	String NP =  "NOT POSSIBLE";
	
	public void solve() throws Exception{
		String s = br.readLine();
		String[] sp = s.split(" ");
		N = parseInt(sp[0]);
		int L = parseInt(sp[1]);
		String[] E = new String[N];
		s = br.readLine();
		sp = s.split(" ");
		for(int i = 0; i < N; i++){
			E[i] =sp[i];
		}
		String[] d = new String[N];
		s = br.readLine();
		sp = s.split(" ");
		for(int i = 0; i < N; i++){
			d[i] = sp[i];
		}
		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				boolean[] b = new boolean[L];
				int cnt = 0;
				for(int k = 0; k < L; k++){
					if(E[i].charAt(k) != d[j].charAt(k)){
						b[k] = true;
						cnt++;
					}
				}
				boolean[] used = new boolean[N];
				used[i] = true;
				boolean flag = true;
				for(int k = 0; k < N; k++){
					if(k == j) continue;
					char[] cs = new char[L];
					for(int a = 0; a < L; a++){
						if(b[a]){
							if(d[k].charAt(a) == '1'){
								cs[a] = '0';
							}
							else{
								cs[a] = '1';
							}
						}
						else{
							cs[a] = d[k].charAt(a);
						}
					}
					boolean found = false;
					for(int a = 0; a < N; a++){
						if(used[a]) continue;
						String ck = E[a];
						boolean f = true;
						for(int h = 0; h < L; h++){
							if(cs[h] != ck.charAt(h)){
								f = false;
								break;
							}
						}
						if(f){
							found = true;
							used[a] = true;
						}
					}
					if(!found){
						flag = false;
						break;
					}
				}
				if(flag){
					ans = min(ans, cnt);
				}
			}
		}
		if(ans == Integer.MAX_VALUE){
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
		File file = new File("A-large.in");
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


import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeMap;


public class Main {
	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("e:\\A-small-attempt0.in"));
		//System.setIn(new FileInputStream("input3"));

		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for(int i = 1; i<=T;i++){
			int N = in.nextInt();
			int L = in.nextInt();
			
			int[] m = new int[N];
			int[] p = new int[N];
			
			for(int j = 0;j<N;j++){
			    String s = in.next();
				for(int k = 0; k<s.length(); k++){
					m[j] = (s.charAt(k) - '0') + (m[j] << 1);
				}
			}
			
			HashSet<Integer> pp = new HashSet<Integer>();
			for(int j = 0;j<N;j++){
				String s = in.next();
				for(int k = 0; k<s.length(); k++){
					p[j] = (s.charAt(k) - '0') + (p[j] << 1);
				}

				pp.add(p[j]);
			}
			
			int r = -1;
			HashSet<Integer> mm = new HashSet<Integer>();
			for(int j = 0; j <= Math.pow(2, L)-1; j++){
				mm.clear();
				for(int k = 0; k<N; k++){
					mm.add(m[k] ^ j);
				}
				if(mm.equals(pp)){
					int c = countbit(j);
					if(c<r || r==-1) r = c;
				}
			}
			
			System.out.print("Case #"+i+": ");
			if(r==-1){
				System.out.println("NOT POSSIBLE");
			}else{
				System.out.println(r);
			}
		}
	}
	
	static int countbit(int n){
		int c = 0;
		while(n > 0){
			if((n & 1) == 1) c++;
			n = n >> 1;
		}
		return c;
	}
}

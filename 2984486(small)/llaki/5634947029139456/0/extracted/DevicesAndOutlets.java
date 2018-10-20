import java.util.*;
import java.io.*;

public class DevicesAndOutlets {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int T = sc.nextInt();
		for(int t=1; t<=T; t++){
			n = sc.nextInt();
			L = sc.nextInt();
			out = new long[n];
			dev = new long[n];
			for(int i=0; i<n; i++){
				String str = sc.next();
				out[i] = 0;
				for(int j=0; j<L; j++){
					outlets[i][j] = (str.charAt(j)=='0' ? 0 : 1);
					if(outlets[i][j]>0){
						out[i] ^= (1L<<j);
					}
				}
			}
			for(int i=0; i<n; i++){
				String str = sc.next();
				dev[i] = 0;
				for(int j=0; j<L; j++){
					devices[i][j] = (str.charAt(j)=='0' ? 0 : 1);
					if(devices[i][j]>0){
						dev[i] ^= (1L<<j); 
					}
				}
			}
			Arrays.sort(dev);
			int ans = getAnswer();
			String resp = (ans!=-1 ? ""+ans : ("NOT POSSIBLE"));
			pw.println("Case #"+t+": "+resp);
		}
		pw.flush();
		pw.close();
	}
	
	
	static int getAnswer(){
		int best = 10000;
		OUT = new long[n];
		for(int i=0; i<L; i++){
			for(int j=0; j<L; j++){
				long mask = getBitmaskOfChanges(i, j);
				applyChanges(mask, out, OUT);
				Arrays.sort(OUT);
				if(sameArray()){
					best = Math.min(best, Long.bitCount(mask));
				}
			}
		}
		return best<10000 ? best : -1;
	}
	
	static boolean sameArray(){
		for(int i=0; i<n; i++){
			if(OUT[i]!=dev[i]) return false;
		}
		return true;
	}
	
	static void applyChanges(long bitmask, long[] src, long[] dest){
		for(int i=0; i<n; i++){
			OUT[i] = (out[i] ^ bitmask);
		}
	}
	
	static long getBitmaskOfChanges(int a, int b){
		long mask = 0;
		int[] X = outlets[a], Y = devices[b];
		for(int i=0; i<L; i++){
			if(X[i]==Y[i]) continue;
			else{
				mask ^= (1L<<i);
			}
		}
		return mask;
		
	}
	
	
	static int L, n;
	
	static long[] out = new long[1000], dev = new long[1000];
	
	static int[][] outlets = new int[1000][41], devices = new int[1000][41];

	static long[] OUT = new long[1000], DEV = new long[1000];
	
}

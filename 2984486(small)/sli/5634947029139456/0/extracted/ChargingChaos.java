import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;



public class ChargingChaos {
	public static void main(String[] args) throws FileNotFoundException{
		System.setIn(new FileInputStream("src\\A-small-attempt0.in"));
		System.setOut(new PrintStream("A-small.out"));
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		
		for(int t = 0; t < tests; t++){
			int n = sc.nextInt();
			int l = sc.nextInt();
			sc.nextLine();
			String[] init = new String[n];
			String[] want = new String[n];
			for(int i = 0; i < n; i++){
				init[i] = sc.next();
			}
			for(int i = 0; i < n; i++){
				want[i] = sc.next();
			}
			long[] initl = toLong(init);
			long[] wantl = toLong(want);
			long[] possible = new long[initl.length];
			for(int i = 0; i < initl.length; i++){
				possible[i] = initl[i]^wantl[0];
			}
			int best = Integer.MAX_VALUE;
			boolean pos = false;
			for(int i = 0; i < possible.length; i++){
				//System.out.println(possible[i]);
				boolean works = true;
				for(int j = 0; j < wantl.length; j++){
					boolean feasible = false;
					for(int k = 0; k < initl.length; k++){
						if((possible[i]^initl[k]) == wantl[j]){
							feasible = true;
						}
					}
					if(!feasible){
						works = false;
					}
				}
				if(works){
					best = Math.min(best, countOnes(possible[i]));
				}
			}
			if(best < 100){
				System.out.println("Case #" + (t+1) + ": " + best);
			}
			else{
				System.out.println("Case #" + (t+1) + ": " + "NOT POSSIBLE");
			}
		}
	}

	private static int countOnes(long l) {
		int count = 0;
		while(l > 0){
			if(l%2 == 1){
				count++;
			}
			l/=2;
		}
		return count;
	}

	private static long[] toLong(String[] in) {
		long[] out = new long[in.length];
		for(int i = 0; i < in.length; i++){
			for(int j = 0; j < in[i].length(); j++){
				out[i]*=2;
				if(in[i].charAt(j) == '1'){
					out[i] += 1;
				}
			}
		}
		return out;
	}
}

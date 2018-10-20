import java.io.*;
import java.util.*;

public class A{
	public static void main(String[] args) throws Exception {
		PrintWriter pw = new PrintWriter (new File("./output.txt"));

		//Scanner sc = new Scanner(System.in);
		//Scanner sc = new Scanner(new File("./sample.txt"));
		//Scanner sc = new Scanner(new File("./small.txt"));
		Scanner sc = new Scanner(new File("./large.txt"));
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++ ){
			pw.print("Case #"+ i + ": ");
			int N = sc.nextInt();
			int L = sc.nextInt();
			long [] devices = new long[N];
			long [] oulets = new long[N];
 			Set<Long> devicesSet = new TreeSet<Long>();
			
			for(int j = 0; j < N; j++){
				oulets[j] = input( sc.next() );
				System.out.println("oulets[j] : " + oulets[j]);
			}

			for(int j = 0; j < N; j++){
				devices[j] = input(sc.next());
				devicesSet.add(new Long(devices[j]) );
				System.out.println("devices[j] : " + devices[j]);
			}

			int bestAnswer = Integer.MAX_VALUE;

			for(int j = 0; j < N; j++){
				long mask = ( oulets[0] ^ devices[j] );
				System.out.println("mask " + mask);
				boolean valid = true;
				for(int k = 0; k < N; k++){
					if( !devicesSet.contains( oulets[k] ^ mask )){
						valid = false;
						break;
					}
				}
				if(valid){
					bestAnswer = Math.min(bestAnswer, count(mask));
				}
			}

			if(bestAnswer == Integer.MAX_VALUE){
				pw.println("NOT POSSIBLE");
			}else{
				pw.println(bestAnswer);
			}
		}
		pw.flush();
		pw.close();	
	}

	private static int count(long value){
		//System.out.println(value);
		int count = 0;
		while (value > 0){
			if( (value & 1) == 1){
				count++;
			}
			value >>= 1;
		}
		return count;
	}

	private static long input(String str){
		return Long.parseLong(str, 2);
	}
}
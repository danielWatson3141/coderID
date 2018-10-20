import java.util.Random;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException {
		int T;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T=Integer.parseInt(br.readLine());
		for(int z=1;z<=T;z++) {
			int N=Integer.parseInt(br.readLine());
			String[] nums=br.readLine().split(" ");
			int[] p = new int[N];
			for(int i=0;i<N;i++)
				p[i]=Integer.parseInt(nums[i]);
			int ic=0;
			for(int i=0;i<N;i++)
				for(int j=i+1;j<N;j++)
					if(p[i]>p[j]) ic++;
			System.out.print("Case #" + z + ": ");
			if(ic<240000) System.out.println("BAD");
			else if(ic<250000) {
				Random rand = new Random(System.nanoTime());
				int r=rand.nextInt(10000);
				int diff=ic-240000;
				if(r<=diff) System.out.println("BAD");
				else System.out.println("GOOD");
			}
			else System.out.println("GOOD");
		}
	}
}
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemAChargingChaos {
	public static void main(String[] args) throws Exception {
		//BufferedReader k = new BufferedReader(new InputStreamReader(System.in));
		 Scanner k = new Scanner(new File("AA.txt"));

		 PrintWriter out = new PrintWriter(new FileWriter("resAA.out"));
		 int t = k.nextInt();
		 
		for (int i = 1; i <= t; i++) {
			
			int n=k.nextInt();
			int l=k.nextInt();
			String[] outlet=new String[n];
			for (int j = 0; j < n; j++) {
				outlet[j]=k.next();
			}
			
			String[] devices=new String[n];
			for (int j = 0; j < n; j++) {
				devices[j]=k.next();
			}
			
			table=new int[n][n];
			vst=new boolean[n];
			for (int j = 0; j < n; j++) {
				String a=outlet[j];
				for (int j2 = 0; j2 < n; j2++) {
					String b=devices[j2];
					for (int m = 1; m <= l; m++) {
						if(a.charAt(m-1)!=b.charAt(m-1))
							table[j][j2]+=(1+m*1000);
					}
				}
			}
			
			
			int Min=1000;
			for (int j = 0; j < n; j++) {
				vst[j]=true;
				Min=Math.min(Min, solve(1, table[0][j]));
				vst[j]=false;
			}
			
			if(Min==1000){
				out.printf("Case #%d: NOT POSSIBLE\n",i);
			}else{
				out.printf("Case #%d: %d\n",i,Min);
			}
		}
		out.close();
		k.close();
	}
	
	static int[][] table;
	static boolean[] vst;
	private static int solve(int i, int prev){
		if(i==table.length){
			return prev%100;
		}
		
		int Min=1000;
		for (int j = 0; j < table.length; j++) {
			if(!vst[j]&&table[i][j]==prev){
				vst[j]=true;
				Min=Math.min(Min, solve(i+1, prev));
				vst[j]=false;
			}
		}
		
		return Min;
	}
}

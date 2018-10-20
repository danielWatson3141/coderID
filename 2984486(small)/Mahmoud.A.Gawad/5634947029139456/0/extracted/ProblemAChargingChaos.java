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
			char[][] outlet=new char[n][l];
			for (int j = 0; j < n; j++) {
				outlet[j]=k.next().toCharArray();
			}
			
			String[] devices=new String[n];
			for (int j = 0; j < n; j++) {
				devices[j]=k.next();
			}
			Arrays.sort(devices);
			String[] cur=new String[n];
			int Min=1000,cnt;
			
			for (int j = 0; j < (1<<l); j++) {
				char[][] temp=new char[n][l];
				for (int row = 0; row < n; row++) {
					for (int col = 0; col < l; col++) {
						temp[row][col]=outlet[row][col];
					}
				}
				cnt=0;
				for (int j2 = 0; j2 < l; j2++) {
					if(((1<<j2)&j)!=0){
						cnt++;
						for (int m = 0; m < n; m++) {// for every outlet
							temp[m][j2]=(char)('1'-outlet[m][j2]+'0');
						}
						
					}
				}
				
				
				for (int row = 0; row < n; row++) {
					cur[row]="";
					for (int m = 0; m < l; m++) {
						cur[row]+=temp[row][m];
					}
				}
				Arrays.sort(cur);
				boolean f=true;
				for (int m = 0; m < n; m++) {
					if(!devices[m].equals(cur[m])){
						f=false;
						break;
					}
				}
				if(f){
					Min=Math.min(Min, cnt);
				}
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
}

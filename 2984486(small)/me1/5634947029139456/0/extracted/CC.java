import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class CC {

	public static void main(String[] args) throws FileNotFoundException {
		PrintStream out = new PrintStream("output.txt");
//		PrintStream out = System.out;

		Scanner scanner = new Scanner(new File("A-small-attempt0.in"));

		int cases = scanner.nextInt();
		for (int casen = 1; casen <= cases; casen++) {
			out.print("Case #" + casen + ": ");

			int  N, L;
			
			N = scanner.nextInt();
			L = scanner.nextInt();
			scanner.nextLine();
			
			String[] A = new String[N];
			String[] B = new String[N];
			String[] A2 = new String[N];
			String[] B2 = new String[N];
			
			A=scanner.nextLine().split(" ");
			B=scanner.nextLine().split(" ");
			
			int best = L+1;

			boolean[] diff= new boolean[L];
			StringBuilder bu;
			
			for (int ii=0;ii<N;ii++)
				for (int jj=0;jj<N;jj++) {
					String aa=A[ii];
					String bb=B[jj];
					for (int i=0;i<L;i++) 
						diff[i] = (aa.charAt(i) == bb.charAt(i));
					int score = 0;
					
//					out.println("###########");
//					out.print(ii+" "+jj+" ");
//					for (int i=0;i<L;i++) {
//						if (diff[i]) out.print("1");
//						else out.print("0");
//					} out.println();
					
					for (int i=0;i<L;i++)
						if (!diff[i]) score++;
					
					for (int i=0;i<N;i++) {
						bu = new StringBuilder();
						for (int j=0;j<L;j++) {
							if (diff[j]) bu.append(A[i].charAt(j));
							else {
								if (A[i].charAt(j) == '0') bu.append('1');
								else bu.append('0');
							}
						}
						A2[i]=bu.toString();
//						out.println(A2[i]);
					}
					for (int i=0;i<N;i++) {
//						bu = new StringBuilder();
//						for (int j=0;j<L;j++) {
//							if (diff[j]) bu.append(B[i].charAt(j));
//							else {
//								if (B[i].charAt(j) == '0') bu.append('1');
//								else bu.append('0');
//							}
//						}
						B2[i]=B[i];//bu.toString();
//						out.println(B2[i]);
					}
					
					Arrays.sort(A2);
//					out.println(Arrays.toString(A2));
					Arrays.sort(B2);
//					out.println(Arrays.toString(B2));
					boolean thesame=true;
					for (int i=0;i<N;i++) {
						if (! A2[i].equals(B2[i]))
							thesame=false;
					}
					if (thesame) {
						best = Math.min(best,score);
					}
				}
			
			if (best <=L) out.println(best);
			else out.println("NOT POSSIBLE");
			
			
			//for (int i=0;i<N;i++) out.println(A[i]+" " +B[i]);
		}
		scanner.close();
	}

}

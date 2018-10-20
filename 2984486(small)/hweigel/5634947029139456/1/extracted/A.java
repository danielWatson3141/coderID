import java.util.Scanner;


public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int kase=1;kase<=T;kase++) {
			int N = in.nextInt();
			int L = in.nextInt();
			boolean [][] board = new boolean [N][L];
			for(int i=0;i<N;i++) {
				String s = in.next();
				for(int j=0;j<L;j++) {
					board[i][j]=(s.charAt(j)=='1');
				}
			}
			boolean [][] need = new boolean [N][L];
			for(int i=0;i<N;i++) {
				String s = in.next();
				for(int j=0;j<L;j++) {
					need[i][j]=(s.charAt(j)=='1');
				}
			}

			int min=Integer.MAX_VALUE;
			for(int i=0;i<N;i++) {
				int acc=0;
				boolean [] switc = new boolean[L];
				for(int j=0;j<L;j++) {
					switc[j]= (need[0][j] != board[i][j]);
					if(switc[j])
						acc++;
				}
				boolean [][] modboard = new boolean[N][L];
				boolean fail=false;
				outer: for(int j=0;j<N;j++) {
					for(int k=0;k<L;k++) {
						modboard[j][k]= (switc[k]?!board[j][k]:board[j][k]);
					}
					boolean matched = false;
					it: for(int k=0;k<N;k++) {						
						for(int l=0;l<L;l++) {
							if(modboard[j][l] != need[k][l])
								continue it;
						}
						matched=true;
						break;
					}
					if(!matched) {
						fail=true;
						break outer;
					}
				}
				if(!fail && (acc<min))
					min=acc;				
			}
			System.out.print("Case #"+kase+": ");
			if(min==Integer.MAX_VALUE) {
				System.out.println("NOT POSSIBLE");
			}
			else
				System.out.println(min);
		}
	}

}

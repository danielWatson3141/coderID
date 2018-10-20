import java.io.*;
import java.util.*;

public class Tree{

	private static int [][] keep;
	private static int [][] edges;
	private static int [] edgeCount;

	private static int find(int i, int j){
		if(i != -1 && keep[i][j] != -1){
			return keep[i][j];
		}
		int max1 = 0, max2 = 0;

		for(int k = 0; k < edgeCount[j]; k++){
			if(edges[j][k] == i) continue;
			int ans =  find(j, edges[j][k]);
			if( ans > max1){
				max2 = max1;
				max1 = ans;
			}else if(ans > max2){
				max2 = ans;
			}
		}
		int ans = Integer.MAX_VALUE;

		if(max1 == 0 || max2 == 0){
			ans = 1;
		}else{
			ans = max1 + max2 + 1;
		}
		if(i != -1){
			keep[i][j] = ans;
		}

		return ans;
	}

	public static void main(String[] args) throws Exception {
		PrintWriter pw = new PrintWriter (new File("./output.txt"));

		//Scanner sc = new Scanner(System.in);
		//Scanner sc = new Scanner(new File("./sample.txt"));
		//Scanner sc = new Scanner(new File("./small.txt"));
		Scanner sc = new Scanner(new File("./large.txt"));
		int T = sc.nextInt();
		for (int cas = 1; cas <= T; cas++ ){
			pw.print("Case #"+ cas + ": ");
			int N = sc.nextInt();

			edges = new int [N][N];
			keep = new int [N][N];
			edgeCount = new int [N];
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					keep[i][j] = -1;
				}
				edgeCount[i] = 0;
			}

			for(int i = 1; i < N; i++){
				int x = sc.nextInt() - 1;
				int y = sc.nextInt() - 1;
				edges[x][edgeCount[x]++] = y;
				edges[y][edgeCount[y]++] = x;
			}

			/*
			for(int i = 0; i < N; i++){
				for(int j = 0; j < edgeCount[i]; j++){
					System.out.print(edges[i][j]+" ");
				}
				System.out.println();
			}
			System.out.println();
			*/
			int bestAnswer = Integer.MIN_VALUE;
			for(int i = 0; i < N; i++){
				bestAnswer = Math.max( bestAnswer, find(-1, i) );
			}
			pw.println( N - bestAnswer);

		}
		pw.flush();
		pw.close();	
	}

}
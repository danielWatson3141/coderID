import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;


public class FullBinaryTree {

	public static void main(String[] args) throws IOException {
		new FullBinaryTree().go();
	}
	
//	String IN = "B.in";
//	String OUT = "B.out";
	String IN = "B-small-attempt0.in";
	String OUT = "B-small-attempt0.out";
	
	void go() throws IOException{
		Scanner scan = new Scanner(new File(IN));
		scan.useLocale(Locale.US);
		FileWriter wr = new FileWriter(OUT);
		int T = scan.nextInt();		
		System.out.println("T = " + T);		
		for(int t=1;t<=T;t++){
			int N = scan.nextInt();
			int edges[][] = new int[N-1][2];
			for (int i = 0; i < N - 1; i++) {
				edges[i] = new int[]{scan.nextInt(),scan.nextInt()};
			}
			
			int max = 0;
			
			for (int r = 1; r <= N; r++) {
				boolean used[] = new boolean[N+1];
				used[r] = true;
				Queue<Integer> q = new LinkedList<Integer>();
				q.add(r);
				int count = 1;
				
				while(!q.isEmpty()){
					int v = q.poll();
					int cnt = 0;
					for(int edge[] : edges){
						if(edge[0] == v && !used[edge[1]]){
							cnt++;
						}else if(edge[1] == v && !used[edge[0]]){
							cnt++;
						}
					}
					if(cnt == 2){
						for(int edge[] : edges){
							if(edge[0] == v && !used[edge[1]]){
								used[edge[1]] = true;
								q.add(edge[1]);
								count++;
							}else if(edge[1] == v && !used[edge[0]]){
								used[edge[0]] = true;
								q.add(edge[0]);
								count++;
							}
						}
					}
				}
				
				max = Math.max(max, count);
				
			}
			
			int ans = N - max;
			debug("max = " + max);
			debug("ans = " + ans);
			wr.append("Case #" + t + ": " + ans + "\n");
			
		}
		scan.close();
		wr.close();
		
	}
	
	
	String trans(String str,int index){
		char[] arr = str.toCharArray();
		arr[index] = arr[index] == '0' ? '1' : '0'; 	
		return new String(arr);
	}
	
	
	static void debug(Object... objs) {
		System.err.println(Arrays.deepToString(objs));
	}

}

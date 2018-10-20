import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class FBT {

	static int best = 0;
	static ArrayList[] tree;
	
	public static void main(String[] args) throws FileNotFoundException {
		PrintStream out = new PrintStream("output.txt");
//		PrintStream out = System.out;

		Scanner scanner = new Scanner(new File("B-small-attempt0.in"));

		int cases = scanner.nextInt();
		for (int casen = 1; casen <= cases; casen++) {
			out.print("Case #" + casen + ": ");

			int  N;
			N = scanner.nextInt();
			tree = new ArrayList[N];
            for (int i=0;i<N;i++)
				tree[i]= new ArrayList<Integer>();
			
			int x,y;
			for (int i=0;i<N-1;i++) {
				x = scanner.nextInt();
				y = scanner.nextInt();
				tree[x-1].add(y-1);
				tree[y-1].add(x-1);
			}

			best = 0;
			
			for (int i=0;i<N;i++) {
				rec(i,-1);
			}
			
			out.println(N-best);			
		}
		scanner.close();
	}

	private static int rec(int x, int parent) {
//		System.out.println(x+1);
		//int[] paths = new int[tree[x].size()];
		ArrayList<Integer> paths = new ArrayList<Integer>();
		
		for (int i=0;i<tree[x].size();i++) {
//			System.out.println(x+1 +" -> "+ (((int) tree[x].get(i)) + 1));
			if (parent != (int) tree[x].get(i))
				paths.add(rec((int) tree[x].get(i),x));
			//else paths[i] = 0;
		}
		
		int current = 1;
		
		if (paths.size() > 1) {
			Collections.sort(paths);
			current += paths.get(paths.size()-1) + paths.get(paths.size()-2);
		}

        best = Math.max(best,current);
		return current;
	}

}

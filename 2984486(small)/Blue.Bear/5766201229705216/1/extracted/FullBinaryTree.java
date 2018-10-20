import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;


public class FullBinaryTree {

	
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner cin = new Scanner(new File("B-small-attempt1.in"));
		PrintStream cout = new PrintStream("B-small-attempt1.out");
//		Scanner cin = new Scanner(new File("A-large.in"));
//		PrintStream cout = new PrintStream("A-large.out");
//		Scanner cin = new Scanner(System.in);
//		PrintStream cout = System.out;
		
		int _case = 0;

		
		for (int T=cin.nextInt(); T>0; T--) {
			_case++;
			
			int n = cin.nextInt();
			
			@SuppressWarnings("unchecked")
			HashSet<Integer> e[] = new HashSet[n];
			for (int i=0; i<n; i++)
				e[i] = new HashSet<Integer>();
			
			for (int i=0; i<n-1; i++) {
				int u = cin.nextInt();
				int v = cin.nextInt();
				u--; v--;
				
				e[u].add(v);
				e[v].add(u);
			}
			
			int ans = 0;
			int numOfDegreeOne = 0;
			for (int i=0; i<n; i++)
				if (e[i].size() == 1) numOfDegreeOne++;
			
			while(numOfDegreeOne * 2 - 1 != n - ans) {
				ans++;
				int which = -1;
				int min = 1 << 29;
				for (int i=0; i<n; i++)
					if (e[i].size() == 1) {
						int cb = e[i].iterator().next();
						if (e[cb].size() < min) {
							min = e[cb].size();
							which = i;
						}
					}

//				if (_case == 2) 
//					for (int i=0; i<n; i++)
//						System.out.println(i + " " + e[i]);
//				System.out.println();
				
				
				int u = which;
				int v = e[u].iterator().next();
				e[u].remove(v);
				e[v].remove(u);
				
				numOfDegreeOne = 0;
				for (int i=0; i<n; i++)
					if (e[i].size() == 1) numOfDegreeOne++;
				if (numOfDegreeOne == 0) break;
				
//				if (_case == 83) {
//					System.out.println(numOfDegreeOne + " " + (n - ans));
//				}
					
			}
			
			cout.printf("Case #%d: %d%n", _case, ans);
			
		}
			
		
		cin.close();
		cout.close();
	}
	
}

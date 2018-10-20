import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Tree {

	public static void main( String[] args ) throws IOException{
		(new Tree()).tree();
	}

	int n;
	int[][] edges;
	boolean[][] visit;
	int root;
	
	public int check( int node ){
		int ans = 1;
		int max1 = -1;
		int max2 = -1;
		for ( int i = 1 ; i <= edges[node][0] ; i++ )
			if ( !visit[node][edges[node][i]] ){
				visit[node][edges[node][i]] = visit[edges[node][i]][node] = true;
				int t = check(edges[node][i]);
				if ( t > max1 ){
					max2 = max1;
					max1 = t;
				}
				else if ( t > max2 )
					max2 = t;
			}
		if ( max1 != -1 && max2 != -1 ){
			ans += max1 + max2;
		}
			
		return ans;
	}
	
	public void tree() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			n = sc.nextInt();
			int i;
			edges = new int[n+1][n];
			for ( i = 0 ; i < n-1 ; i++ ){
				int x,y;
				x = sc.nextInt();
				y = sc.nextInt();
				edges[x][0]++;
				edges[x][edges[x][0]] = y;
				edges[y][0]++;
				edges[y][edges[y][0]] = x;
			}
			int ans = n;
			for ( i = 1 ; i <= n ; i++ ){
				visit = new boolean[n+1][n+1];
				root = i;
				int t = n - check(i);
				if ( t < ans )
					ans = t;
			}
			bw.write("Case #" + z + ": " + ans + "\n");
		}
		bw.close();
		sc.close();
	}
	
}

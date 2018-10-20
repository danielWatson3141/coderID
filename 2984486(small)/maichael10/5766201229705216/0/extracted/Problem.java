/**
 * 
 */
package problem;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/**
 * @author michael
 *
 */
public class Problem {

	static int N;

	static byte[][] adj ;

	/**
	 * Metodo main que corre el programa.
	 * @param args Argumentos con los que es llamado el programa.
	 * @throws Exception Si hubo excepcion.
	 */
	public static void main(String args[]) throws Exception {

		String file = "B-small-attempt0";
		//String file = "test";

		Object[] pairIO = openIO(file);
		BufferedReader red = (BufferedReader) pairIO[0];
		PrintWriter wr = (PrintWriter) pairIO[1];


		int problemas = Integer.parseInt(red.readLine());
		outer: for (int w = 0 ; w < problemas ; w++) {
			N = Integer.parseInt(red.readLine());

			adj = new byte[N][N];
			int min = Integer.MAX_VALUE;

			for (int i = 1 ; i < N; i++) {
				String[] p1 = red.readLine().split(" ");
				int n1 = Integer.parseInt(p1[0]);
				int n2 = Integer.parseInt(p1[1]);
				adj[n1-1][n2-1] = 1;
				adj[n2-1][n1-1] = 1;
			}

			for (int i = 0 ; i < N; i++) {
				min = Math.min(min, root(i));
			}

			if (min == Integer.MAX_VALUE) {
				wr.println("Case #" + (w+1) + ": NOT POSSIBLE" );
			}
			else {
				wr.println("Case #" + (w+1) + ": " + min);
			}
		}
	}

	private static int root(int root) {
		int adjroot = 0;
		for (int i = 0 ; i < N ; i++) {
			if (adj[root][i] == 1) adjroot++;
		}

		if (adjroot == 1) {
			for (int j = 0 ; j < N ; j++) {
				if (adj[root][j] != 1) continue;
				
				return 1 + sons(j, root);
			}
		}
		else if (adjroot > 2) {
			int min = Integer.MAX_VALUE;
			for (int j = 0 ; j < N ; j++) {
				if (adj[root][j] != 1) continue;
				for (int k = j+1 ; k < N ; k++) {
					if (adj[root][k] != 1) continue;

					int thisCase = 0;
					byte adjsroot[] = new byte[N];
					for (int i = 0 ; i < N ; i++) {
						if (i!=j && i!= k && adj[root][i]==1) {
							adjsroot[i] = 1;
							adj[root][i] = 0;
							adj[i][root] = 0;
							thisCase+=1+sons(i,root);
						}
					}
					adj[root][j] = 0;
					adj[j][root] = 0;
					adj[root][k] = 0;
					adj[k][root] = 0;

					thisCase+=root(j) + root(k);
					min = Math.min(thisCase, min);

					for (int i = 0 ; i < N ; i++) {
						if (adjsroot[i]==1) {
							adj[root][i] = 1;
							adj[i][root] = 1;
						}
					}

					adj[root][j] = 1;
					adj[j][root] = 1;
					adj[root][k] = 1;
					adj[k][root] = 1;
				}
			}
			return min;
		} else if (adjroot == 2)  {
			int k = N;
			for (int j = 0 ; j < N ; j++) {
				if (adj[root][j] != 1) continue;

				if (k == N) {
					k = j;
					continue;
				}
				adj[root][j] = 0;
				adj[j][root] = 0;
				adj[root][k] = 0;
				adj[k][root] = 0;
				int min = root(j) + root(k);
				adj[root][j] = 1;
				adj[j][root] = 1;
				adj[root][k] = 1;
				adj[k][root] = 1;
				return min;
			}
		}
		return 0;
	}

	private static int sons(int i, int root) {
		int sons = 0;
		for (int j = 0 ; j < N ; j++) {
			if (adj[i][j]==1 && j!= root) {
				sons += 1 + sons(j,i);
			}
		}
		return sons;
	}

	/////////////////////////////////////////////
	//// Methods for IO operations
	/////////////////////////////////////////////

	public static BufferedReader loadFile(String fileName) throws FileNotFoundException {
		File file = new File("./data/" + fileName + ".in");
		FileInputStream fis = new FileInputStream(file);
		BufferedReader red = new BufferedReader(new InputStreamReader(fis));
		return red;
	}

	public static PrintWriter openFile(String fileName) throws FileNotFoundException {
		File file = new File("./data/" + fileName + ".out");
		if (file.exists()) file.delete();
		FileOutputStream fos = new FileOutputStream(file);
		PrintWriter wr = new PrintWriter(fos, true);
		return wr;
	}

	public static Object[] openIO(String fileName) throws IOException {
		return new Object[] { loadFile(fileName) , openFile(fileName)};
	}
}


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

	/**
	 * Metodo main que corre el programa.
	 * @param args Argumentos con los que es llamado el programa.
	 * @throws Exception Si hubo excepcion.
	 */
	public static void main(String args[]) throws Exception {

		String file = "A-large";
		//String file = "test";

		Object[] pairIO = openIO(file);
		BufferedReader red = (BufferedReader) pairIO[0];
		PrintWriter wr = (PrintWriter) pairIO[1];


		int problemas = Integer.parseInt(red.readLine());
		outer: for (int w = 0 ; w < problemas ; w++) {
			String p1 [] = red.readLine().split(" ");
			int N = Integer.parseInt(p1[0]);
			int L = Integer.parseInt(p1[1]);

			long[] init = new long[N];
			long[] need = new long[N];
			int min = Integer.MAX_VALUE;

			String[] temp = red.readLine().split(" ");
			for (int i = 0 ; i < N; i++) {
				init[i] = Long.parseLong(temp[i], 2);
			}
			temp = red.readLine().split(" ");
			for (int i = 0 ; i < N; i++) {
				need[i] = Long.parseLong(temp[i], 2);
			}

			otherConf: for (int i = 0 ; i < N; i++) {
				// Tratar de casar el switch i al primer equipo
				long switches = init[i]^need[0];
				otherDev: for (int j = 1 ; j < N ; j++) {
					for (int k = 0 ; k < N ; k++) {
						if ((init[k]^need[j]) == switches) {
							continue otherDev;
						}
					}
					continue otherConf;
				}

				int thisCase = 0;
				for (int j = 0 ; j < L ; j++) {
					if ((switches&1) == 1)
						thisCase++;
					switches = switches>>1;
				}

				min = Math.min(min, thisCase);
			}

			if (min == Integer.MAX_VALUE) {
				wr.println("Case #" + (w+1) + ": NOT POSSIBLE" );
			}
			else {
				wr.println("Case #" + (w+1) + ": " + min);
			}
		}
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


/**
 * 
 */
package googleJam.Round1A2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

/**
 * @author Kisna
 *
 */
public class ProperShuffle {
	public static void main(String[] args) {
		BufferedReader br = null;
		HashSet<String> map = new HashSet<String>();
		try {
			
			FileWriter fstream = new FileWriter("output.out");
			BufferedWriter out = new BufferedWriter(fstream);
			String sCurrentLine;

			br = new BufferedReader(new FileReader("C-small-attempt2.in"));
			sCurrentLine = br.readLine();
			int i = 1;
			
			while ((sCurrentLine = br.readLine()) != null) {
				int N = Integer.parseInt(sCurrentLine);
				String[] temp = br.readLine().split(" ");
				for (int j = 0; j < temp.length; j++) {
					map.add(temp[j]);	
				}
				
				String ans = "GOOD";
				if(map.size() <= 600 )
					ans = "BAD";
					
				
				out.write("Case #" + i++ + ": " + ans);
				System.out.println("Case #" + i + ": " + ans);
				out.write("\n");
			}
			
			out.close();

		} catch (IOException e) {
		} finally {
			try {
				if (br != null)
					br.close();
			} catch (IOException ex) {
			}
		}
	}
}

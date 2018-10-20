import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class A {
	static String file = "A-large";	
	
	public static void main(String[] args) throws IOException {	
				
		FileInputStream fis = new FileInputStream(file+ ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 0;
		for (int i = 0; i < problemCount; i++) {
			
			int n;
			int l;
			String[] vals = lines.get(++currentIndex).split(" ");
			n = Integer.parseInt(vals[0]);
			l = Integer.parseInt(vals[1]);
			String[] p1 = lines.get(++currentIndex).split(" ");
			String[] p2 = lines.get(++currentIndex).split(" ");
						
			int switches = solve(p1, p2, l,n);
			String r = "a";
			if (switches == Integer.MAX_VALUE)
				r = "Case #" + (i+1) + ": NOT POSSIBLE";
			else 
				r = "Case #" + (i+1) + ": " + switches;
			
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();		
	}
	
	static int solve(String[] p1, String[] p2, int l, int n)
	{
		int switches = Integer.MAX_VALUE;
		
		for (int i = 0; i < p2.length; i++) {			
			int sw = 0;
			// get required switches
			List<Integer> requiredSwitches = new ArrayList<Integer>();
			for (int j = 0; j < l; j++) {
				if (p1[0].charAt(j) != p2[i].charAt(j))
				{
					requiredSwitches.add(j);
					sw++;
				}
			}			
			
			// switch others
			List<String> p1R = new ArrayList<String>();
			List<String> p2R = new ArrayList<String>();
			
			for (int j = 0; j < p2.length; j++) {
				if (j>0)
					p1R.add(p1[j]);
				
				if (j!=i)
				{
					StringBuilder newP2 = new StringBuilder(p2[j]);
					for (int k = 0; k < requiredSwitches.size(); k++) {
						int ind = requiredSwitches.get(k);
						if (newP2.charAt(ind) == '0')
							newP2.setCharAt(ind, '1');
						else
							newP2.setCharAt(ind, '0');
					}
					
					p2R.add(newP2.toString());					
				}							
			}
			
			// sort others
			Collections.sort(p1R);
			Collections.sort(p2R);

			// compare others
			boolean ok = true;
			for (int j = 0; j < p1R.size(); j++) {
				if (p1R.get(j).compareTo(p2R.get(j)) != 0)
				{
					ok = false;
					break;
				}
			}
			
			if (ok)
				switches = Math.min(switches, sw);
		}
		return switches;
		
	}
	
}



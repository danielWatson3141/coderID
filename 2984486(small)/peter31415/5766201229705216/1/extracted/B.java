import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class B {
	static String file = "B-large(1)";	
	
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
			int n = Integer.parseInt(lines.get(++currentIndex));
			List<List<Integer>> g = new ArrayList<List<Integer>>();
			for (int j = 0; j < n; j++) {
				g.add(new ArrayList<Integer>());
			}
			
			for (int j = 0; j < n - 1; j++) {
				String[] vals = lines.get(++currentIndex).split(" ");
				int v1 = Integer.parseInt(vals[0]);
				int v2 = Integer.parseInt(vals[1]);
				
				g.get(v1-1).add(v2-1);
				g.get(v2-1).add(v1-1);
			}
			
			int ans = solve(g);
			
			String r = "Case #" + (i+1) + ": " + ans;
						
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();		
	}
	
	static int solve(List<List<Integer>> g)
	{
		int min = Integer.MAX_VALUE;
				
		for (int i = 0; i < g.size(); i++) {
			// i is now a root
			int tmp = Integer.MAX_VALUE;			
			tmp = incorrectInTree(g, i, -1);
						
			min = Math.min(min, tmp);
		}
		
		return min;
	}
		
	static int incorrectInTree(List<List<Integer>> g, int current, int parent)
	{
		
		List<Integer> incorrect = new ArrayList<Integer>();
		List<Integer> size = new ArrayList<Integer>();
		for (int i = 0; i < g.get(current).size(); i++) {
			if (g.get(current).get(i) != parent)
			{
				incorrect.add(incorrectInTree(g, g.get(current).get(i), current));
				size.add(nodesInTree(g, g.get(current).get(i), current));
			}
		}
		
		if(incorrect.size() == 1)
			return size.get(0);
		if(incorrect.size() == 0)
			return 0;
		
		int totalsum = 0;
		for (int i = 0; i < size.size(); i++) {
			totalsum += size.get(i);
		}
		
		int ans = Integer.MAX_VALUE;		
		for (int i = 0; i < size.size(); i++) {
			for (int j = i + 1; j < size.size(); j++) {							
				int tmp = totalsum;
				tmp -= size.get(i);
				tmp -= size.get(j);
				tmp += incorrect.get(i);
				tmp += incorrect.get(j);
				
				ans = Math.min(ans, tmp);
			}
		}
		
		return ans;
	}
	
	static int nodesInTree(List<List<Integer>> g, int current, int parent)	
	{
		int ans = 0; 
		
		for (int i = 0; i < g.get(current).size(); i++) {
			if (g.get(current).get(i) != parent)
				ans += nodesInTree(g, g.get(current).get(i), current); 
		}
				
		return ans + 1;
	}
}



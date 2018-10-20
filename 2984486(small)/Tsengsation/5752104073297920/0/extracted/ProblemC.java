import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class ProblemC {
	File f; 
	Scanner s; 
	File out;
	FileWriter writer;
	
	public void init() throws IOException {
		f = new File("CSmall.txt");
		s = new Scanner(f);
		out = new File("CSmallOut.txt");
		writer = new FileWriter(out);
	}
	
	public void finish() throws IOException {
		writer.close();
	}
	
	
	public void go() throws IOException {
		init();
		int numCases = s.nextInt();
		for (int c = 0; c < numCases; c ++) {
			int n = s.nextInt();
			int count = 0;
			for (int i = 0; i < n; i ++) {
				int j = s.nextInt();
				if (j == i) count++;
			}
			System.out.println(count);
			String ans; 
			if (count > 0) ans = "GOOD";
			else ans = "BAD";
			writer.write("Case #" + (c+1) + ": " + ans + "\n");
			System.out.println("Case #" + (c+1) + ": " + ans);
		}
		finish();
	}	
	public static void main(String[] args) {
		ProblemC c = new ProblemC();
		try {
			c.go();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}

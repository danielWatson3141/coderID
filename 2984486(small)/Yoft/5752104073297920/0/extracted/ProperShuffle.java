import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;


public class ProperShuffle {
	private static Queue<String> lines = new LinkedList<String>();

	public static void main(String[] args) throws Exception {
		FileInputStream fis = new FileInputStream(new File(args[0]));
		BufferedReader br = new BufferedReader(new InputStreamReader(fis));
		
		Random rnd = new Random();
		
		String fileLine = null;
		while ((fileLine = br.readLine()) != null) {
			lines.add(fileLine);
		}
		br.close();
		
		int times = Integer.parseInt(lines.poll());
		PrintWriter writer = new PrintWriter("C:\\Users\\Shaun\\Desktop\\Code_Jam_1A_C-output.txt");
		
		
		for (int time=1;time<=times;time++) {
			int N = Integer.parseInt(lines.poll());
			String[] nums = lines.poll().split(" ");
			int goodScore = 0;
			int badScore = 0;
			
			String[] good = nums.clone();
			for (int k=N-1; k>=0; k--) {
				int p = Integer.parseInt(good[k]);
				if ((Integer.parseInt(good[k])<k) && (Integer.parseInt(good[p])>p)) {
					goodScore++;
				}else{
					badScore++;
				}
				good[k] = good[p];
				good[p] = String.valueOf(p);
			}
			badScore /= Math.PI;
			writer.print("Case #"+time+": "+(badScore>goodScore?"BAD":"GOOD"));
			if (time!=times) {
				writer.println();
			}
			System.out.println("Good: "+goodScore+" Bad: "+badScore+" "+(badScore>goodScore?"BAD":"GOOD"));
		}
		writer.close();
	}

}

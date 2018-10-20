import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) throws Exception {
		if (args.length != 1) {
			System.out.println("Wrong Usage.");
			return;
		}

		FileInputStream in = new FileInputStream(args[0]);
		String outStr = args[0].substring(0, args[0].lastIndexOf('.')) + ".out";
		FileOutputStream out = new FileOutputStream(outStr);
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(out));

		int T = Integer.parseInt(br.readLine());
		for (int i = 1; i < T+1; ++i) {
			int N = Integer.parseInt(br.readLine());
			String[] input = br.readLine().split(" ");
			
			boolean found = false;
			for (int j = 0; j < N && !found; j++) {
				String chance[] = BAD(N);
				//for (int k = 0; k < N; k++) System.out.print(chance[k]+" ");
				//System.out.println();
				
				if (chance[1].equals( input[0] )) {
					bw.write("Case #"+i+": BAD\n");
					found = true;
				}
			}
			
			if (!found)
				bw.write("Case #"+i+": GOOD\n");
			
			//System.out.println();
		}
		bw.close();
		br.close();

	}
	
	public static String[] BAD(int N) {
		Random rG = new Random();
		String[] output = new String[N];
		
		for (int i = 0; i < N; i++) {
			output[i] = ""+i;
		}
		for (int i = 0; i < N; i++) {
			int p = rG.nextInt(N-1);
			String tmp = output[i];
			output[i] = output[p];
			output[p] = tmp;
		}
		return output;
	}

}

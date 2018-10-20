import java.io.*;
import java.util.*;

public class A {

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
			String params[] = br.readLine().split(" ");
			int N = Integer.parseInt(params[0]);
			int L = Integer.parseInt(params[1]);
			
			String nLine[] = br.readLine().split(" ");
			String lLine[] = br.readLine().split(" ");
			
			int ans = goes(lLine,nLine,0,L,N);
			if (ans < L+1)
				bw.write("Case #"+i+": "+ans+"\n");
			else
				bw.write("Case #"+i+": NOT POSSIBLE\n");
		}
		bw.close();
		br.close();

	}
	
	public static int goes(String[] req, String[] has, int x, int L, int N) {
		//for (int i = 0; i < has.length; i++) System.out.println(has[i]);
		//System.out.println();
		
		if (matches(req,has)) return 0;
		if (x > L) return L+1;
		int depth = L+1;
		String tmp[] = has;
		for (int i = x; i < L; i++) {
			for (int j = 0; j < N; j++) {
				if (has[j].charAt(i) == '0') 
					tmp[j] = has[j].substring(0, i) + '1' + has[j].substring(i+1);
				else
					tmp[j] = has[j].substring(0, i) + '0' + has[j].substring(i+1);
			}
			int att = goes(req,tmp,i+1,L,N) + 1;
			if (depth > att) depth = att;
			for (int j = 0; j < N; j++) {
				if (has[j].charAt(i) == '0') 
					tmp[j] = has[j].substring(0, i) + '1' + has[j].substring(i+1);
				else
					tmp[j] = has[j].substring(0, i) + '0' + has[j].substring(i+1);
			}
		}
		return depth;
	}
	
	public static boolean matches(String[] req, String[] has) {
		boolean used[] = new boolean[has.length];
		for (int i = 0; i < has.length; i++) used[i] = false;
		int correct = 0;
		for (int i = 0; i < req.length; i++) {
			boolean found = false;
			for (int j = 0; j < has.length; j++)
				if (!used[j] && req[i].equals(has[j])) {
					used[j] = true;
					correct++;
					found = true;
				}
			if (!found) return false;
		}
		
		if (correct == req.length) return true; 
		else return false;
	}

}

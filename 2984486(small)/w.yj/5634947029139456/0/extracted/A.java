package round1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.security.InvalidParameterException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class A {

	private static File inputF = new File("A-small-attempt0.in");
	private static File outputF = new File("a_small.out");

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(inputF);
		BufferedWriter out = new BufferedWriter(new FileWriter(outputF));
		int numCase = sc.nextInt();
		for (int testNum = 0; testNum < numCase; testNum++) {
			int n = sc.nextInt();
			int l = sc.nextInt();
			sc.nextLine();
			String[] outletSs = sc.nextLine().split(" ");
			String[] needSs = sc.nextLine().split(" ");
			out.write("Case #"+(testNum+1)+": ");
			ArrayList<Long> outlets = new ArrayList<Long>();
			HashSet<Long> needSet = new HashSet<Long>();
			ArrayList<Long> needs = new ArrayList<Long>();
			for (String ol : outletSs) {
				outlets.add(Long.parseLong(ol, 2));
			}
			for (String nd : needSs) {
				needs.add(Long.parseLong(nd, 2));
				needSet.add(Long.parseLong(nd, 2));
			}

			int ans = l + 1;
			for (int pr = 0; pr < n; pr++) {
				long chg = needs.get(0).longValue()
						^ outlets.get(pr).longValue();
				HashSet<Long> tmpSet = new HashSet<Long>();
				for(long outlet : outlets){
					tmpSet.add(outlet ^ chg);
				}
				if(!tmpSet.equals(needSet)) continue;
				int count = 0;
				while(chg > 0) {
					if((chg & 1) == 1) count++;
					chg = chg >> 1;
				}
				if(ans > count) ans = count;
			}
			if(ans > l) {
				out.write("NOT POSSIBLE");
			} else {
				out.write(Integer.toString(ans));
			}
			out.newLine();

		}

		sc.close();
		out.flush();
		out.close();
	}

}

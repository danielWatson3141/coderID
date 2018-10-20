import java.io.*;
import java.util.*;

public class A {
	public static void main(String args[]) {
		try {
			InputStreamReader isr = null;
			try {
				isr = new InputStreamReader(System.in, "UTF-8");
				BufferedReader br = null;
				try {
					br = new BufferedReader(isr);
					new A().go(br);
				} finally {
					if (br != null) br.close();
				}
			} finally {
				if (isr != null) isr.close();
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	public void go(BufferedReader br) throws Exception {
		int num = Integer.parseInt(br.readLine());
		for (int n = 1; n <= num; n++)
			solve(n, br);
	}

	public void solve(int num, BufferedReader br) throws Exception {
		String lines[] = br.readLine().split(" ");
		int N = Integer.parseInt(lines[0]);
		int L = Integer.parseInt(lines[1]);

		String CONS[] = br.readLine().split(" ");
		String DEVS[] = br.readLine().split(" ");

		String DEVS_DONS[][] = new String[N][N];

/*
		ArrayList<String>[] changes =
			(ArrayList<String>[])new ArrayList<String>[N];
*/
		ArrayList<ArrayList<String>> changes =
			new ArrayList<ArrayList<String>>();
		String startDev[] = new String[L];
		for (int i = 0; i < N; i++) {
			changes.add(new ArrayList<String>());
			for (int j = 0; j < N; j++) {
				StringBuffer sb = new StringBuffer();
				for (int k = 0; k < L; k++) {
					if (DEVS[i].charAt(k) != CONS[j].charAt(k))
						sb.append('1');
					else
						sb.append('0');
				}
				changes.get(i).add(sb.toString());
// System.out.println(sb.toString());
			}
// System.out.println("-----");
		}

// System.out.println(changes);

		ArrayList<String> pats = new ArrayList<String>();
		for (int i = 0; i < N; i++) {
			String pat = changes.get(0).get(i);
			boolean cont = true;
			for (int j = 1; j < N; j++) {
				if (!changes.get(j).contains(pat)) {
					cont = false;
					break;
				}
			}
			if (cont) {
				pats.add(pat);
//System.out.println("pat=" + pat);
			}
		}

//System.out.println("num=" + pats.size());

		if (pats.size() == 0) {
			System.out.println("Case #" + num + ": NOT POSSIBLE");
			return;
		}

		int patm = L;
		for (int i = 0; i < pats.size(); i++) {
			int patn = 0;
			String pat = pats.get(i);
			for (int j = 0; j < pat.length(); j++) {
				if (pat.charAt(j) == '1')
					patn++;
			}
			if (patn < patm)
				patm = patn;
		}

		System.out.println("Case #" + num + ": " + patm);
	}
}

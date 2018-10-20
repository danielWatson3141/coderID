
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class Solve2014R1AAS {
	private static String filePath = "A-small-attempt1.in"; //"2014R1AA-ChargingChaos.in";

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		long startDatetime = System.currentTimeMillis();

		StringBuffer answer = new StringBuffer();
		try {
			BufferedReader br = null;
			String line = null;
			if (filePath == null) br = new BufferedReader(new InputStreamReader(System.in));
			else br = new BufferedReader(new InputStreamReader(new FileInputStream(filePath)));

			int T = Integer.parseInt(br.readLine());
			//System.out.println(T);

			for (int x = 1; x <= T; x++) {
				if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + x); }
				answer.append("Case #" + x + ": ");

				String[] sts = line.split(" ");
				int N = Integer.parseInt(sts[0]);
				int L = Integer.parseInt(sts[1]);
				int[][] Ni = new int[N][L];
				int[][] Ci = new int[N][L];
				if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + x); }
				sts = line.split(" ");
				for (int i = 0; i < N; i++) {
					String str = sts[i];
					for (int j = 0; j < L; j++)
						Ni[i][j] = str.charAt(j) - 48;
				}
				if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + x); }
				sts = line.split(" ");
				for (int i = 0; i < N; i++) {
					String str = sts[i];
					for (int j = 0; j < L; j++)
						Ci[i][j] = str.charAt(j) - 48;
				}

				int y = 0;
				int[] Ns = new int[L];
				int[] Cs = new int[L];
				boolean notPossible = false;
				List<Integer> chgs = new ArrayList<Integer>();
				for (int i = 0;i < L; i++) {
					Ns[i] = 0;
					Cs[i] = 0;
					for (int j = 0; j < N; j++) {
						Ns[i] += Ni[j][i];
						Cs[i] += Ci[j][i];
					}
					if (Ns[i] != Cs[i]) {
						if (Ns[i] + Cs[i] != N) {
							notPossible = true;
							break;
						} else {
							for (int j = 0; j < N; j++) {
								Ci[j][i] = 1 - Ci[j][i];
							}
							y++;
						}
					} else if (Ns[i] * 2 == N) chgs.add(i);
				}
				if (!notPossible) {
					String[] Nstr = new String[N];
					for (int i = 0; i < N; i++) {
						Nstr[i] = "";
						for (int j = 0; j < L; j++) {
							Nstr[i] += Ni[i][j];
						}
					}

					if (!isOk(N, L, Nstr, Ci)) {
						notPossible = true;
						int size = chgs.size();
						int ymin = y + size;
						for (int i = 1; i < (1 << size); i++) {
							int[][] Citmp = new int[N][L];
							int ytmp = y;
							//System.arraycopy(Ci, 0, Citmp, 0, Ci.length);
							for (int ii = 0; ii < N; ii++)
								for (int jj = 0; jj < L; jj++)
									Citmp[ii][jj] = Ci[ii][jj];
							for (int j = 0; j < size; j++) {
								if ((i & (1 << j)) > 0) {
									ytmp++;
									int idx = chgs.get(j);
									for (int k = 0; k < N; k++) {
										Citmp[k][idx] = 1 - Citmp[k][idx];
									}
								}
							}
							if (isOk(N, L, Nstr, Citmp)) {
								notPossible = false;
								if (ymin > ytmp) ymin = ytmp;
								if (ymin == y + 1) break;
							}
						}
						if (!notPossible) y = ymin;
					}
				}

				if (notPossible) answer.append("NOT POSSIBLE").append("\n");
				else answer.append(y).append("\n");
			}
			br.close();
			br = null;
			output(answer);
		} catch (Exception e) {
			e.printStackTrace();
		}
		long tm = System.currentTimeMillis() - startDatetime;
		long tms = tm / 1000;
		System.out.println("The process time: " + tms + "s " + (tm%1000) + "ms");
	}

	private static boolean isOk(int N, int L, String[] Nstr, int[][] Ci) {
		List<String> Cstr = new ArrayList<String>();
		for (int i = 0; i < N; i++) {
			String strc = "";
			for (int j = 0; j < L; j++) {
				strc += Ci[i][j];
			}
			Cstr.add(strc);
		}
		boolean find = true;
		for (int i = 0; i < N; i++) {
			int idx = Cstr.indexOf(Nstr[i]);
			if (idx < 0) {
				find = false;
				break;
			} else Cstr.remove(idx);
		}
		return find;
	}

	private static void output(StringBuffer answer) throws Exception {
		String outPath = "answer.out";
		if (filePath != null) outPath = filePath.substring(0, filePath.length()-2) + "out";
		FileOutputStream fos = new FileOutputStream(outPath, false);
		fos.write(answer.toString().getBytes());
		fos.close();
		fos = null;
	}
}

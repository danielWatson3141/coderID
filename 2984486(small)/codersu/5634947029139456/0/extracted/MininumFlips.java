import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class MininumFlips {

	public static void main(String[] args) {
		solution();
		// test();
	}

	public static void test() {
		int L = 3;
		char[] ch = { 'A', 'B', 'C' };
		for (int i = 0; i < (1 << L); i++) {
			for (int j = 0; j < L; j++) {
				if ((i & (1 << j)) > 0) {
					System.out.print(ch[j]);
				}
			}
			System.out.println();
		}
	}

	public static void solution() {
		BufferedReader br = null;

		try {
			br = new BufferedReader(new FileReader("A-small-attempt0.in"));
			int noOfTestCases = Integer.parseInt(br.readLine());
			File file = new File("out.txt");
			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			for (int i = 1; i <= noOfTestCases; i++) {
				String[] input = br.readLine().split(" ");
				int N = Integer.parseInt(input[0]);
				int L = Integer.parseInt(input[1]);
				int min = Integer.MAX_VALUE;
				String[] words = br.readLine().split(" ");
				
				String[] requiredWords = br.readLine().split(" ");
				// Map<String,Integer> org = new HashMap<String,Integer>();
				Map<String, Integer> req = new HashMap<String, Integer>();
				for (String word : requiredWords) {
					if (req.get(word) == null)
						req.put(word, 1);
					else {
						int cnt = req.get(word);
						req.put(word, cnt + 1);
					}
				}

				for (int k = 0; k < (1 << L); k++) {
					Map<String, Integer> cpy = new HashMap<String, Integer>(req);
					String[] cpyWords = Arrays.copyOf(words, words.length);
					int x = 0;
					for (int j = 0; j < L; j++) {
						if ((k & (1 << j)) > 0) {
							x++;
							for (int l = 0; l < cpyWords.length; l++) {
								char[] ch = cpyWords[l].toCharArray();
								int len = ch.length;
								if (ch[len - j - 1] == '1')
									ch[len - j - 1] = '0';
								else
									ch[len - j - 1] = '1';

								String temp = new String(ch);
								cpyWords[l] = temp;
							}
						}
					}
					for (String temp : cpyWords) {
						if (cpy.get(temp) != null) {
							int cnt = cpy.get(temp);
							cpy.put(temp, cnt - 1);
						}
					}
					int cnt = 0;
					for (String word : cpy.keySet()) {

						if (cpy.get(word) == 0) {
							cnt++;
						}

					}
					if (cnt == cpy.size()) {
						min = Math.min(min, x);
					}

				}
				String result = "Case #" + i + ": ";
				if (min == Integer.MAX_VALUE)
					result = result + "NOT POSSIBLE";
				else
					result = result + min;
				if (i == noOfTestCases) {
					bw.write(result);
				} else {
					bw.write(result);
					bw.newLine();
				}
			}
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}
}

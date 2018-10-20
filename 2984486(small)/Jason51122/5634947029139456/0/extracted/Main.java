import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		//Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new File("A-small-attempt2.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("small.out"));

		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = in.nextInt();
			int L = in.nextInt();
			int result = -1;

			in.nextLine();
			String[] str1 = in.nextLine().split(" ");
			String[] str2 = in.nextLine().split(" ");
			
			HashSet<String> set0 = new HashSet<String>();
			for (String s : str1) {
				set0.add(s);
			}
			boolean flag = true;
			for (String s : str2) {
				if (set0.contains(s) == false) {
					flag = false;
					break;
				}
			}

			if (flag == true) {
				result = 0;
			}
			else {
				for (int i = 1; i <= L; i++) {
					ArrayList<ArrayList<Integer>> list = combine(L, i);
					for (ArrayList<Integer> key1 : list) {
						HashSet<String> set1 = new HashSet<String>(set0);
						for (Integer key2 : key1) {
							set1 = change(key2, set1);
						}

						flag = true;
						for (String s : str2) {
							if (set1.contains(s) == false) {
								flag = false;
								break;
							}
						}

						if (flag == true) {
							result = key1.size();
							break;
						}
					}

					if (flag == true) {
						break;
					}
				}
			}

			if (result == -1) {
				bw.write("Case #" + t + ": NOT POSSIBLE");
			} else {
				bw.write("Case #" + t + ": " + result);
			}
			bw.newLine();
		}

		in.close();
		bw.close();
	}

	public static HashSet<String> change(int l, HashSet<String> set1) {
		HashSet<String> set = new HashSet<String>();
		for (String s : set1) {
			StringBuilder sb = new StringBuilder(s);
			if (sb.charAt(l) == '0') {
				sb.setCharAt(l, '1');
			} else {
				sb.setCharAt(l, '0');
			}
			set.add(sb.toString());
		}
		return set;
	}
	
    private static ArrayList<ArrayList<Integer>> combine(int n, int k) {
        if (n < 1 || k < 1) {
            return new ArrayList<ArrayList<Integer>>();
        }
        
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        helper(new ArrayList<Integer>(), k, 0, n, result);
        
        return result;
    }
    
    private static void helper(ArrayList<Integer> cur, int k, int index, int n, ArrayList<ArrayList<Integer>> result) {
        if (cur.size() == k) {
            result.add(new ArrayList<Integer>(cur));
            return;
        }
        
        for (int i = index; i < n; i++) {
            cur.add(i);
            helper(cur, k, i + 1, n, result);
            cur.remove(cur.size() - 1);
        }
    }
}
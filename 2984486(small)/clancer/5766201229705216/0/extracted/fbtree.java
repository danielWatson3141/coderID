import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class fbtree {
	static HashMap<Integer,ArrayList<Integer>> edges;
	
	public static void main (String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("B-small-attempt0.in")));
		Integer n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			
			edges = new HashMap<Integer,ArrayList<Integer>>();
			
			int s = Integer.parseInt(br.readLine());
			for (int j = 0; j < s-1; j++) {
				String[] sedge = br.readLine().split(" ");
				Integer sv1 = Integer.parseInt(sedge[0]);
				Integer sv2 = Integer.parseInt(sedge[1]);
				ArrayList<Integer> temp = new ArrayList<Integer>();
				if (edges.containsKey(sv1)) {
					temp = edges.get(sv1);
				}
				temp.add(sv2);
				edges.put(sv1, temp);
				temp = new ArrayList<Integer>();
				if (edges.containsKey(sv2)) {
					temp = edges.get(sv2);
				}
				temp.add(sv1);
				edges.put(sv2, temp);
			}
			
			int min_output = -1;
			for (Integer root : edges.keySet()) {
				ArrayList<Integer> black = new ArrayList<Integer>();
				black.add(root);
				int deleted = 0;
				if (edges.get(root).size() > 2) {
					ArrayList<Integer> grey = new ArrayList<Integer>();
					for (int di = 0; di < edges.get(root).size()-2; di++) {
						int mini = 0;
						int min = -1;//count(edges.get(root).get(0), black);
						for (Integer b : edges.get(root)) {
							if (!grey.contains(b)) {
								int todelete = count(b, black);
								if ( todelete < min || min == -1) {
									min = todelete;
									mini = b;
								}
							}
						}
						deleted += min;
						grey.add(mini);
					}
					for (Integer b : edges.get(root)) {
						if (!grey.contains(b)) {
							black.add(b);
							deleted += trim(b, black);
						}
					}
				} else if ( edges.get(root).size() == 1) {
					deleted += count(edges.get(root).get(0), black);
					
				} else {
					black.add(edges.get(root).get(0));
					black.add(edges.get(root).get(1));
					deleted += trim(edges.get(root).get(0), black);
					deleted += trim(edges.get(root).get(1), black);
				}
				if (min_output == -1 || deleted < min_output) {
					min_output = deleted;
				}
			}
			//for (ArrayList<Integer> t : edges.values()) {
			//	for (Integer d : t) {
			//		System.out.print(d + " ");
			//	}
			System.out.println("Case #"+(i+1)+": "+min_output);
			//}
			//break;
			
		}
	}
	public static int count(Integer root, ArrayList<Integer> black) {
		ArrayList<Integer> thisblack = (ArrayList<Integer>) black.clone();
		thisblack.add(root);
		return 1+counth(root,thisblack);
	}
	public static int counth(Integer root, ArrayList<Integer> black) {
		int thisc = 0;
		for (Integer b : edges.get(root)) {
			if (!black.contains(b)) {
				black.add(b);
				thisc += 1 + counth(b,black);
			}
		}
		return thisc;
	}
	public static int trim(Integer root, ArrayList<Integer> black) {
		int deleted = 0;
		if (edges.get(root).size() > 3) {
			ArrayList<Integer> grey = new ArrayList<Integer>();
			for (int di = 0; di < edges.get(root).size()-2; di++) {
				int mini = 0;
				int min = -1;//count(edges.get(root).get(0), black);
				for (Integer b : edges.get(root)) {
					if (!grey.contains(b) && !black.contains(b)) {
						int todelete = count(b, black);
						if ( todelete < min || min == -1) {
							min = todelete;
							mini = b;
						}
					}
				}
				deleted += min;
				grey.add(mini);
			}
			for (Integer b : edges.get(root)) {
				if (!grey.contains(b) && !black.contains(b)) {
					black.add(b);
					deleted += trim(b, black);
				}
			}
		} else if ( edges.get(root).size() == 2) {
			for (Integer b : edges.get(root)) {
				if (!black.contains(b)) {
					deleted += count(b, black);
				}
			}
		} else if (edges.get(root).size() == 3) {
			for (Integer b : edges.get(root)) {
				if (!black.contains(b)) {
					black.add(b);
					deleted += trim(b, black);
				}
			}
		}
		return deleted;
	}
}

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;

public class Main {
	static PrintWriter writer;

	public static void main(String[] args) {
		try {
			writer = new PrintWriter("out.txt", "UTF-8");
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		} catch (UnsupportedEncodingException e1) {
			e1.printStackTrace();
		}
		Scanner sc = null;
		try {
			sc = new Scanner(new File("in.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int T = sc.nextInt();
		top: for (int t = 0; t < T; t++) {
			// ----------------------------------------------------------
			int N = sc.nextInt();
			int L = sc.nextInt();
			// String[] n=new String[N];
			// String[] l=new String[L];
			sc.nextLine();
			String[] a = sc.nextLine().split(" ");
			String[] b = sc.nextLine().split(" ");
			Arrays.sort(a);
			Arrays.sort(b);
//			System.out.println(Arrays.toString(a));
//			System.out.println(Arrays.toString(b));
			PriorityQueue<Node> pq = new PriorityQueue<Node>();
			Node n = new Node(0,0, a);
			pq.add(n);
			while (pq.size() > 0) {
				n = pq.poll();
//				System.out.println(n.length);
				Arrays.sort(n.a);
				boolean flag = true;
				for (int i = 0; i < N; i++) {
					if (!n.a[i].equals(b[i])) {
						flag = false;
						break;
					}
				}
				if (flag) {
					out(t,n.changed+"");
					continue top;
				}
//				for (int i = n.length; i < L; i++) {
				if ((n.length)>=L)continue;
					Node p = new Node(n.length + 1,n.changed+1, n.a);
					Node p1 = new Node(n.length+1, n.changed, n.a);
					pq.add(p1);
//					System.out.println(p.length);
					for (int j = 0; j < N; j++) {
						String h = p.a[j];
						boolean bb = (h.charAt(n.length) == '1');
						if (bb) {
							h = p.a[j].substring(0, n.length) + '0' + p.a[j].substring(n.length + 1);
						}
						else h = p.a[j].substring(0, n.length) + '1' + p.a[j].substring(n.length + 1);
						p.a[j] = h;
					}
					pq.add(p);
					
				}
//			}
			out(t,"NOT POSSIBLE");
		}
		writer.close();
	}
	public static void out(int t, String s) {
		String g = "Case #" + (t + 1) + ": " + s;
		System.out.println(g);
		writer.write(g + "\n");

	}
}

class Node implements Comparable<Node> {

	int length = 0;
	int changed=0;
	String[] a;

	public Node(int length, int changed,String[] a) {
		this.length = length;
		this.a = new String[a.length];
		this.changed=changed;
		System.arraycopy(a, 0, this.a, 0, a.length);
	}

	@Override
	public int compareTo(Node arg0) {
		return Integer.compare(changed, arg0.changed);
	}

}

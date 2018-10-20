package main;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FullTree {
	private TNode [] tree;
	private Scanner sc;
	int N;
	int min;
	
	public FullTree(Scanner sc) {
		this.sc = sc;
		N = sc.nextInt();
		tree = new TNode[N + 1];
		min = N - 1;
		
		for (int i = 1; i <= N; i++) {
			tree[i] = new TNode();
		}
		
		for (int i = 0; i < N - 1; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			tree[x].neib.add(y);
			tree[x].deg++;
			tree[y].neib.add(x);
			tree[y].deg++;
		}
	}
	
	public int countNode(int root, int par) {
		int count = 1;
		TNode cnode = tree[root];
		
		for (int i = 0; i < cnode.deg; i++) {
			int next = cnode.neib.get(i);
			if (next != par) {
				count += countNode(next, root);
			}
		}
		
		return count;
	}
	
	public int getCut(int root, int par) {
		int cut = 0;
		TNode cnode = tree[root];
		if (cnode.deg == 2) {
			if (par == 0) {
				for (int i = 0; i < 2; i++) {
					int next = cnode.neib.get(i);
					if (next != par) {
						cut += getCut(next, root);
					}
				}
			} else {
				for (int i = 0; i < 2; i++) {
					int next = cnode.neib.get(i);
					if (next != par) {
						cut += countNode(next, root);
					}
				}
			}
		} else if (cnode.deg == 1){
			if (par != 0)
				cut = 0;
			else
				cut = N - 1;
		} else {
			// deg == 3
			for (int i = 0; i < 3; i++) {
				int next = cnode.neib.get(i);
				if (next != par) {
					cut += getCut(next, root);
				}
			}
		}
		
		return cut;
	}
	
	public int getRes() {
		min = N - 1;
		
		// ÂÖÁ÷×öroot
		for (int root = 1; root <= N; root++) {
			if (tree[root].deg == 3)
				continue;
			
			int tmp = getCut(root, 0);
			if (tmp < min)
				min = tmp;
		}

		return min;
	}

	public static void main(String[] args) throws IOException {
		FileInputStream fis = new FileInputStream("input.txt");
		FileOutputStream fos = new FileOutputStream("output.txt");
		
		Scanner sc = new Scanner(fis);
		
		int T = sc.nextInt();
		int cnt = 0;
		
	
		while (cnt < T) {
			
			FullTree ft = new FullTree(sc);
		
			String res = "Case #" + (cnt + 1) + ": " +  ft.getRes() + "\n";
			System.out.print(res);
			fos.write(res.getBytes());
			
			cnt++;
		}
		
		sc.close();
		fos.close();
	}
	
	class TNode {
		public int self;
		public List<Integer> neib;
		public int deg;
		
		public TNode() {
			neib = new ArrayList<Integer>(3);
			deg = 0;
		}
	}

}

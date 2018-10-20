/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlejam;

import java.io.*;
import java.util.*;

/**
 *
 * @author a.bogdanov
 */
public class GoogleJam_FullBinaryTree {
	
	
    public static final String problemLetter = "B";
	private static int N;
	
	private static TreeSet<Integer>[] edges;
	
	private static int checkSubTree(int root, int parent){
		int childs=0;
		for(int next:edges[root]){
			if(next != parent){
				childs++;
			}
		}
		int[] sizes = new int[childs];
		int[] trees = new int[childs];
		int[] diffs = new int[childs];
		int total = 0;
		int i = 0;
		for(int next:edges[root]){
			if(next != parent){
				sizes[i] = sizeSubTree(next, root);
				trees[i] = checkSubTree(next, root);
				diffs[i] = sizes[i] - trees[i];
				total+=sizes[i];
				i++;
			}
		}
		if(childs==0){
			return 0;
		}else if(childs==1){
			return sizes[0];
		}else if(childs==2){
			return trees[0] + trees[1];
		}else{
			Arrays.sort(diffs);
			return total - diffs[childs-1] - diffs[childs-2];
		}
	}
    
	private static int sizeSubTree(int root, int parent){
		int childs=1;
		for(int next:edges[root]){
			if(next != parent){
				childs += sizeSubTree(next, root);
			}
		}
		return childs;
	}

	public static void solve(BufferedReader reader, PrintWriter writer) throws IOException{
        int caseCount = Integer.parseInt(reader.readLine());
        for(int caseNum=1; caseNum<=caseCount; caseNum++){
        	N = Integer.parseInt(reader.readLine());
        	edges = new TreeSet[N+1];
        	for(int i=1; i < N+1; i++){
        		edges[i] = new TreeSet<Integer>();
        	}
        	for(int i=0; i < N-1; i++){
        		String[] str = reader.readLine().split(" ");
        		int from = Integer.parseInt(str[0]);
        		int to = Integer.parseInt(str[1]);
        		edges[from].add(to);
        		edges[to].add(from);
        	}
        	int min = N;
        	for(int i=1; i < N+1; i++){
        		int need = checkSubTree(i, 0);
        		if(need < min){
        			min = need;
        		}
        	}
            System.out.println("Case #" + caseNum + ": " + min);
            writer.println("Case #" + caseNum + ": " + min);
            writer.flush();
        }
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File folder = new File(".");
        for(final File entry:folder.listFiles()){
            if(entry.getName().endsWith(".in") && entry.getName().startsWith(problemLetter)){
                BufferedReader reader = new BufferedReader(new FileReader(entry));
                String fileOut = entry.getName().substring(0, entry.getName().length()-3) + ".out";
                System.out.println(entry.getName() + " -> " + fileOut);
                PrintWriter writer = new PrintWriter(fileOut);
                solve(reader, writer);
                reader.close();
                writer.close();
            }
        }
    }
    
}

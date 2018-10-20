/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;
import java.util.*;
import java.lang.*;
/**
 *
 * @author Tom
 */
public class FullBinaryTree {
    private int nodes;
    private ArrayList<int[]>[] edges;
    public static FullBinaryTree[] readFile(Scanner input) {
        FullBinaryTree[] puzzles = new FullBinaryTree[input.nextInt()];
        
        for(int i = 0; i < puzzles.length; ++i) {
            int nodes = input.nextInt();
            int[][] edges = new int[nodes - 1][2];
            for(int j = 0; j < edges.length; ++j) {
                edges[j][0] = input.nextInt();
                edges[j][1] = input.nextInt();
            }
            puzzles[i] = new FullBinaryTree(nodes, edges);
        }
        
        return puzzles;
    }
    
    private FullBinaryTree(int nodes, int[][] edgesArg) {
        this.nodes = nodes;
        //this.edges = edges;
        this.edges = new ArrayList[nodes + 1];
        for(int i = 0; i < edges.length; ++i) {
            edges[i] = new ArrayList<int[]>();
        }
        
        for(int i = 0; i < edgesArg.length; ++i) {
            edges[edgesArg[i][0]].add(edgesArg[i]);
            edges[edgesArg[i][1]].add(edgesArg[i]);
        }
    }
    boolean[] used;
    public String solve() {
        //System.out.println("===========");
        int min = Integer.MAX_VALUE;
        
        for(int i = 1; i <= nodes; ++i) {
            //System.out.println("--------------");
            used = new boolean[nodes + 1];
            int[] result = solve(i);
            min = Math.min(min, result[0]);
        }
        return "" + min;
    }
    
    private int[] solve(int node) {
        used[node] = true;
        int count = 0;
        int score = 0;
        ArrayList<int []> results = new ArrayList<int []>();
        for(int i = 0; i < edges[node].size(); ++i) {
            int[] edge = edges[node].get(i);
            if(edge[0] == node && !used[edge[1]]) {
                int[] tempResult = solve(edge[1]);
                count += tempResult[1];
                results.add(tempResult);
            } else if(edge[1] == node && !used[edge[0]]){
                int[] tempResult = solve(edge[0]);
                count += tempResult[1];
                results.add(tempResult);
            }
        }
        
        if(results.size() == 1) {
            score = count;
        } else if(results.size() == 2) {
            for(int i = 0; i < results.size(); ++i) {
                score += results.get(i)[0];
            }
        } else if(2 < results.size()) {
            int min = Integer.MAX_VALUE;
            for(int i = 0; i < results.size(); ++i) {
                for(int j = i + 1; j < results.size(); ++j) {
                    int result = count - results.get(i)[1] - results.get(j)[1] + results.get(i)[0] + results.get(j)[0];
                    min = Math.min(min, result);
                }
            }
            score = min;
        }
        ++count;
        //System.out.println(node + " " + score + " " + count + " " + results.size());
        return new int[] {score, count};
    }
}

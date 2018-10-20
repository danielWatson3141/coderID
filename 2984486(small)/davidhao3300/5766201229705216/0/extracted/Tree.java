
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author David
 */
public class Tree {
    static ArrayList<Integer>[] map;
    static int nodes;
    public static void main (String[] args) throws IOException
    {
        Scanner in = new Scanner(new BufferedReader(new FileReader("input.in")));
        PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
        int cases = in.nextInt();
        for(int i = 1; i <= cases; i++)
        {
            nodes = in.nextInt();
            map = new ArrayList[nodes];
            
            for(int j = 0; j < nodes; j++)
            {
                map[j] = new ArrayList<Integer>();
            }
            for(int j = 0; j < nodes-1; j++)
            {
                int first = in.nextInt()-1;
                int second = in.nextInt()-1;
                map[first].add(second);
                map[second].add(first);
            }
            for (ArrayList<Integer> row : map)
            {
                //System.out.println(row);
            }
            done = new boolean[nodes];
            int min = nodes +1;
            for(int j = 0; j < nodes; j++)
            {
                done[j] = true;
                
                int res = recurse(j, -1, 0);
                if(res < min) 
                {
                    min = res;
                    //System.out.println(j);
                }
            }
            
            out.printf("Case #%d: %d\n", i, min);
            //System.out.println();
        }
        out.close();
    }
    static int under = 0;
    static boolean[] done;
    static int recurse(int node, int parent, int current)
    {
        //System.out.println(node+" "+parent+" "+current);
        ArrayList<Integer> choices = map[node];
        //System.out.println(choices);
        int diff = 0;
        if (parent == -1) diff = -1;
        
        if(choices.size() == 1 + diff) return current;
        else if(choices.size() == 2+diff ) 
        {
            for(int choice : choices)
            {
                if(choice != parent) return current +under(choice, node);
            }
        }
        else if(choices.size() == 3 + diff)
        {
            for(int choice : choices)
            {
                if(choice != parent)
                {
                    current = recurse(choice, node, current);
                }
            }
            return current;
        }
        else
        {
            int[][] test = new int[choices.size()-1-diff][2];
            int index = 0;
            for(int choice : choices)
            {
                if(choice!= parent)
                {
                    test[index] = new int[] {choice, under(choice, node)};
                    index++;
                }
            }
            Arrays.sort(test, new Comparator<int[]>()
            {
                @Override
                public int compare(int[] o1, int[] o2) {
                    return o1[1]-o2[1];               
                }
                
            });
            for(int[] row : test)
            {
              //  System.out.println(Arrays.toString(row));
            }
            for(int i = 0; i < test.length-2; i++)
            {
                current+=test[i][1];
            }
            for(int i = test.length-2; i < test.length; i++)
            {
                current = recurse(test[i][0], node, current);
            }
            return current;
        }
        System.out.println("wut");
        return current;
    }
    static int under(int node, int parent)
    {
        ArrayList<Integer> choices = map[node];
        int count = 1;
        for(int choice : choices)
        {
            if (choice != parent)
            {
                count += under(choice, node);
            }
        }
        return count;
    }
}

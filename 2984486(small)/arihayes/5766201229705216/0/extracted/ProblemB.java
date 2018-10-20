import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemB {
    static String in = "src/b.in";
    static String out = "src/b.out";

    public static node[] nodes = new node[1000];

    public static int best(int id, int parent) {
        node n = nodes[id];

        int nei = n.connect.size();
        int realnei = nei;
        if(parent >= 0) {
            nei--;
        }

        //System.out.println(parent + ":" + id + "; " + nei);

        if(nei < 2) {
            return 1;
        }
        else if(nei == 2) {
            int ret = 1;
            for(int x = 0; x < realnei; x++) {
                int nextid = n.connect.get(x);
                node next = nodes[n.connect.get(x)];
                if(nextid != parent) {
                    ret += best(nextid, id);
                }
            }
            return ret;
        }
        else {
            int best = 1;
            int best2 = 1;
            for(int x = 0; x < realnei; x++) {
                int nextid = n.connect.get(x);
                node next = nodes[n.connect.get(x)];
                if(nextid != parent) {
                    int temp = best(nextid, id);
                    if(temp > best) {
                        best = temp;
                    }
                    else if (temp > best2) {
                        best2 = temp;
                    }
                }
            }

            return best + best2 + 1;
        }
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));

        for(int x = 0; x < 1000; x++) {
            nodes[x] = new node();
        }

        int numlines = scan.nextInt();
        for(int x = 1; x <= numlines; x++) {
            int numnodes = scan.nextInt();
            for(int y = 0; y < numnodes; y++) {
                nodes[y].connect.clear();
            }

            for(int y = 1; y < numnodes; y++) {
                int a = scan.nextInt();
                int b = scan.nextInt();
                nodes[a-1].connect.add(b-1);
                nodes[b-1].connect.add(a-1);
            }

            int maxgood = 1;
            int nodesleft = numnodes;
            /*boolean deletednode = true;
            while(deletednode) {
                deletednode = false;
                for(int y = 0; y < nodesleft && nodesleft > 3; y++) {
                    node del = nodes[y];
                    if(del.connect.size() == 1) {
                        int neisize = nodes[del.connect.get(0)].connect.size();
                        if(neisize == 2 || neisize > 3) {
                            nodes[del.connect.get(0)].connect.remove(new Integer(y));
                            del.connect.clear();
                            nodesleft--;
                            deletednode = true;
                            y--;
                        }
                    }
                }
            }*/

            for(int y = 0; y < nodesleft; y++) {
                if(nodes[y].connect.size() > 1) {
                    int temp = best(y, -1);
                    if (temp > maxgood) {
                        maxgood = temp;
                        //System.out.println("Case " + x + ": " + temp + " @" + y);
                    }
                }
            }

            write.write("Case #" + x + ": " + (numnodes - maxgood));
            write.write("\n");
        }

        scan.close();
        write.close();
    }

    static private class node {
        public ArrayList<Integer> connect = new ArrayList<Integer>();
    }
}

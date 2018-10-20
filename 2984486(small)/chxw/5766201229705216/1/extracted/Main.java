import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {

    //
    // boilerplate
    //

    static String path = "/Users/liwen/Downloads/";
    static String fname = "B-large";

    static BufferedWriter bw;
    static BufferedReader br;


    public static void init() throws IOException {
       br = new BufferedReader(new FileReader(path + fname + ".in"));
        bw = new BufferedWriter(new FileWriter(path + fname + ".txt"));

 //       br = new BufferedReader(new InputStreamReader(System.in));
 //       bw = new BufferedWriter(new OutputStreamWriter(System.out));

    }


    ///////////////////////////////////
    // code starts from here
    //

    static int n;

    static ArrayList<ArrayList<Integer> > graph;

    public static void addEdge(int src, int des) {
        graph.get(src).add(des);
        //edges.add(des);
        //graph.set(src, edges);

 //       edges = graph.get(des);
   //     edges.add(src);
        graph.get(des).add(src);//set(des, edges);
    }

    static ArrayList<Boolean> visit;
    static ArrayList<Integer> cntDesc;
    static ArrayList<Integer> cntRm;

    static int countDescRecur(int node) {
        visit.set(node, true);

        if (cntDesc.get(node) >= 0)
            return cntDesc.get(node);

        ArrayList<Integer> adjs = graph.get(node);

        int res = 1; // self
        for (int i = 0; i < adjs.size(); ++i) {
            int des = adjs.get(i);
            if (!visit.get(des)) {
                //visit.set(des, true);
                res += countDescRecur(des);
                //visit.set(des, false);
            }
        }

        visit.set(node, false);
        cntDesc.set(node, res);
        return res;
    }

    static int countRmRecur(int node) {
        if (cntRm.get(node) >= 0) {
            return cntRm.get(node);
        }

        visit.set(node, true);

        int res = -1;
        ArrayList<Integer> adjs = graph.get(node);

        int sumDesc = 0;
        int cntChild = 0;
        for (int des : adjs) {
            if (!visit.get(des)) {
                cntChild++;
                sumDesc += cntDesc.get(des);
            }
        }
        if (cntChild == 0)
            res = 0;
        else if (cntChild == 1) {
            res = sumDesc;
        }
        else {
            for (int i = 0; i < adjs.size(); ++i) {
                if (!visit.get(adjs.get(i)))
                    for (int j = 0; j < adjs.size() && j < i; ++j)
                        if (!visit.get(adjs.get(j))) {
                            int n1 = adjs.get(i);
                            int n2 = adjs.get(j);
                            int sumOthers = sumDesc - cntDesc.get(n1) - cntDesc.get(n2);
                            int cur = countRmRecur(n1) + countRmRecur(n2) + sumOthers;

                            if (res < 0 || cur < res) {
                                res = cur;
                            }
                        }
            }
        }

        visit.set(node, false);
        cntRm.set(node, res);
        return res;
    }

    static int checkRoot(int root) {
        cntDesc = new ArrayList<Integer> (Collections.nCopies(n, -1));
        cntRm = new ArrayList<Integer> (Collections.nCopies(n, -1));

        visit = new ArrayList<Boolean> (Collections.nCopies(n, false));
        countDescRecur(root);




        visit = new ArrayList<Boolean> (Collections.nCopies(n, false));
        int res = countRmRecur(root);

        return res;
    }



    //
    // code ends here
    //////////////////////////////////


    public static void main(String[] args) throws IOException {
        //
        // boilerplate
        //

        init();

        int N = Integer.parseInt(br.readLine());

        ///////////////////////////////////
        // code starts here
        //


        //
        // code ends here
        //////////////////////////////////


        for (int l = 1; l <= N; ++l) {
            bw.write("Case #" + l + ":");
            /////////////////////////////////////
            /// code starts here
            ///

            n = Integer.parseInt(br.readLine());
            graph = new ArrayList<ArrayList<Integer> > ();

            for (int i = 0; i < n; ++i)
                graph.add(new ArrayList<Integer>());

            for (int i = 0; i < n-1; ++i) {

                String[] edge = br.readLine().split(" ");
                int src = Integer.parseInt(edge[0]) - 1;
                int des = Integer.parseInt(edge[1]) - 1;

                addEdge(src, des);
            }

            int res = -1;

            for (int i = 0; i < n; ++i) {
                int cur = checkRoot(i);
                if (res < 0 || cur < res)
                    res = cur;
            }


            bw.write(" " + res + "\n");

            ///
            /// code ends here
            ////////////////////////////////////

        }

        bw.close();
    }
}

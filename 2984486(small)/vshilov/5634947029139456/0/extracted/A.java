import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;


public class A {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int n=nextInt();
            int l=nextInt();
            boolean[][] o=new boolean[n][l];
            boolean[][] d=new boolean[n][l];
            for(int i=0;i<n;i++){
                String s=nextToken();
                for(int j=0;j<l;j++)
                    if(s.charAt(j)=='1')o[i][j]=true;
            }
            for(int i=0;i<n;i++){
                String s=nextToken();
                for(int j=0;j<l;j++)
                    if(s.charAt(j)=='1')d[i][j]=true;
            }
            int min=100500;
            for(int i=0;i<n;i++){
                boolean[][] wo=new boolean[n][l];
                boolean[][] wd=new boolean[n][l];
                for(int j=0;j<n;j++)
                    for(int k=0;k<l;k++){
                        wo[j][k]=o[j][k];
                        wd[j][k]=d[j][k];
                    }
                int count=0;

                for(int j=0;j<l;j++){
                    if(wo[0][j]!=wd[i][j]) {
                        for (int k = 0; k < n; k++)
                            wo[k][j] = !wo[k][j];
                        count++;
                    }
                }
                if(count>min)continue;
                HashSet<Integer> s=new HashSet<Integer>();
                s.add(i);
                for(int j=1;j<n;j++){
                    for(int k=0;k<n;k++){
                        if(!s.contains(k)){
                            boolean good=true;
                            for(int h=0;h<l;h++)
                                if(wo[j][h]!=wd[k][h]){
                                    good=false;
                                    break;
                                }
                            if(good){
                                s.add(k);
                                break;
                            }
                        }
                    }

                }
                if(s.size()==n)min=count;
            }
            out.printf("Case #%d: ",testCase+1);
            if(min==100500)out.println("NOT POSSIBLE");
            else out.println(min);
        }
    }

    public static void main(String[] args) throws IOException {
        new A().run();
    }

    void run() throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
        tokenizer = null;
        out = new PrintWriter(new OutputStreamWriter(System.out));
		out = new PrintWriter(new FileWriter("output.txt"));
        solve();
        reader.close();
        out.flush();

    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}

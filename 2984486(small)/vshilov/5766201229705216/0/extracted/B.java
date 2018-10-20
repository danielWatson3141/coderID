import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class B {

    int n;
    ArrayList<Integer>[] a;

    int dfs(int v,int p){
        if(p!=-1&&a[v].size()==1||p==-1&&a[v].size()==0)return 0;
        if(p==-1&&a[v].size()<2||p!=-1&&a[v].size()<3)return dfs1(v,p)-1;
        ArrayList<Integer> b=new ArrayList<Integer>();
        ArrayList<Integer> c=new ArrayList<Integer>();
        int s=0;
        for(int i=0;i<a[v].size();i++)
            if(a[v].get(i)!=p) {
                b.add(dfs(a[v].get(i), v));
                c.add(dfs1(a[v].get(i),v));
                s+=c.get(c.size()-1);
            }
        int ans=100500;
        for(int i=0;i<b.size();i++)
            for(int j=i+1;j<b.size();j++)
                ans=Math.min(ans,b.get(i)+b.get(j)+s-c.get(i)-c.get(j));
        return ans;

    }

    int dfs1(int v,int p){
        int ans=0;
        for(int i=0;i<a[v].size();i++){
            if(a[v].get(i)!=p)
                ans+=dfs1(a[v].get(i),v);
        }
        ans++;
        return ans;
    }

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            n=nextInt();
            a=new ArrayList[n];
            for(int i=0;i<n;i++)a[i]=new ArrayList<Integer>();
            for(int i=0;i<n-1;i++){
                int x=nextInt()-1;
                int y=nextInt()-1;
                a[x].add(y);
                a[y].add(x);
            }
            int ans=100500;
            for(int i=0;i<n;i++) {
                ans=Math.min(ans,dfs(i,-1));
            }
            out.printf("Case #%d: %d\n",testCase+1,ans);
        }
    }

    public static void main(String[] args) throws IOException {
        new B().run();
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

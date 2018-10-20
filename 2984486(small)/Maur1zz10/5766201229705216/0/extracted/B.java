import java.io.*;
import java.util.*;

public class B {
    static final String filename = "B";

    public static void main(String[] args) throws IOException {
        String finput = filename+".in";
        String foutput = filename+".out";
        Scanner s = new Scanner(new FileInputStream(finput));
        Writer w = new OutputStreamWriter(new FileOutputStream(foutput));
        B solver = new B();
        solver.solve(s, w);
        w.close();
        s.close();
    }
    void solve(Scanner s, Writer w) throws IOException {
        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            N=s.nextInt();
            G=new boolean[N+1][N+1];
            for(int i=0;i<N-1;i++){
                int x=s.nextInt();
                int y=s.nextInt();
                G[x][y]=true;
                G[y][x]=true;
            }
            String ans=solve();
            String out="Case #" + t + ": ";
            out+=ans;
            out+="\n";
            w.write(out);
            System.out.print(out);
        }
    }
    int N;
    boolean[][]G;
    boolean[]M,MM;
    String solve(){
        int ans=Integer.MAX_VALUE;
        for(int i=1;i<=N;i++){
            //System.out.println("==============ROOT==============\t"+i);
            M=new boolean[N+1];
            int tmp=howMany(i);
            ans=Math.min(ans,tmp);
            //System.out.println(i+"|"+ans+"|"+tmp);
        }
        return ans+"";
    }
    int howMany(int n){
        //System.out.println("START\t"+n);
        M[n]=true;
        List<Integer>list=new ArrayList<Integer>();
        for(int i=1;i<=N;i++)if(!M[i]&&G[n][i]){
            list.add(i);
        }
        if(list.size()==0){
            //System.out.println("ZERO\t"+n);
            return 0;
        }
        if(list.size()==1){
            MM=Arrays.copyOf(M,M.length);
            int x=count(list.get(0));
            //System.out.println("ONE\t\t"+n+"\t"+x);
            return x;
        }
        //int z= howMany(list.get(0))+howMany(list.get(1));
        int best=Integer.MAX_VALUE;
        int[]counts=new int[N+1];Arrays.fill(counts,100000);
        int[]howmanys=new int[N+1];Arrays.fill(counts,100000);
        for(int e:list){
            MM=Arrays.copyOf(M,M.length);
            counts[e]=count(e);
            howmanys[e]=howMany(e);
        }
        for(int i=0;i<list.size();i++)for(int j=i+1;j<list.size();j++){
            int tmp=howmanys[list.get(i)]+howmanys[list.get(j)];
            for(int k=0;k<list.size();k++)if(k!=i&&k!=j)
                tmp+=counts[list.get(k)];
            best=Math.min(best,tmp);
        }
        //System.out.println("MANY\t"+n+"\t"+z);
        return best;
    }
    int count(int n){
        int cnt=1;
        MM[n]=true;
        for(int i=1;i<=N;i++)if(!MM[i]&&G[n][i]){
            cnt+=count(i);
        }
        return cnt;
    }
}
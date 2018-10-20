import java.io.*;
import java.util.*;

public class A {
    static final String filename = "A";

    public static void main(String[] args) throws IOException {
        String finput = filename+".in";
        String foutput = filename+".out";
        Scanner s = new Scanner(new FileInputStream(finput));
        Writer w = new OutputStreamWriter(new FileOutputStream(foutput));
        A solver = new A();
        solver.solve(s, w);
        w.close();
        s.close();
    }
    void solve(Scanner s, Writer w) throws IOException {
        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            N=s.nextInt();
            L=s.nextInt();
            devices=new char[N][];
            flows=new char[N][];
            for(int i=0;i<N;i++)
                flows[i]=s.next().toCharArray();
            for(int i=0;i<N;i++)
                devices[i]=s.next().toCharArray();
            String ans=solve();
            String out="Case #" + t + ": ";
            out+=ans;
            out+="\n";
            w.write(out);
            System.out.print(out);
        }
    }
    int N,L;
    char[][]devices,flows;
    String solve(){
        int best=Integer.MAX_VALUE;
        //System.out.println("DEVICES");
        //print(devices);
        //System.out.println("FLOWS");
        //print(flows);
        for(int i=0;i<N;i++){
            char[][]f=getCopy(flows);
            int curr=match(i,f);
            //print(f);
            if(check(f)&&curr<best)
                best=curr;
        }
        if(best==Integer.MAX_VALUE)
            return "NOT POSSIBLE";
        return best+"";
    }
    boolean check(char[][]f){
        Set<Integer>flows_used=new HashSet<Integer>();
        Set<Integer>devices_used=new HashSet<Integer>();
        boolean keep=true;
        while(keep){
            keep=false;
            for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(!devices_used.contains(i)&&!flows_used.contains(j)&&eq(devices[i],f[j])){
                devices_used.add(i);
                flows_used.add(j);
                keep=true;
                break;
            }
            else {
                //System.out.println(i+"|"+Arrays.toString(devices[i])+"..... "+j+"|"+Arrays.toString(f[j])+"\t"+devices_used+"==="+flows_used);
                //System.out.println(!devices_used.contains(i));
                //System.out.println(!flows_used.contains(j));
                //System.out.println(eq(devices[i],f[j]));
            }

        }
        //System.out.println(devices_used+"==="+flows_used);
        return devices_used.size()==N;
    }
    boolean eq(char[]a,char[]b){
        for(int i=0;i<L;i++)if(a[i]!=b[i])
            return false;
        return true;
    }
    int match(int idx,char[][]f){
        int cnt=0;
        char[]m=f[idx];
        for(int i=0;i<m.length;i++){
            if(devices[0][i]!=m[i]){
                for(int j=0;j<N;j++){
                    f[j][i]=(f[j][i]=='1')?'0':'1';
                }
                cnt++;
            }
        }
        return cnt;
    }
    char[][] getCopy(char[][]M){
        char[][]ans=new char[M.length][M[0].length];
        for(int i=0;i<M.length;i++)for(int j=0;j<M[0].length;j++)
            ans[i][j]=M[i][j];
        return ans;
    }
    void print(char[][]m){
        for(int i=0;i<m.length;i++){
            for(int j=0;j<m[i].length;j++)
                System.out.print(m[i][j]);
            System.out.print(" | ");
        }
        System.out.println();
    }
}
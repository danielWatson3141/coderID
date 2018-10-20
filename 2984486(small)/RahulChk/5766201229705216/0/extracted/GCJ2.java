import java.io.*;
import java.util.*;
//import java.lang.Math.*;
public class GCJ2
{
    public static void main(String args[])throws Exception
    {
        //Scanner in=new Scanner(System.in);
        //BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        //PrintWriter pw = new PrintWriter(System.out);
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\rahul\\Desktop\\GCJ2.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\rahul\\Desktop\\GCJ2.out")));
        
        int t = Integer.parseInt(br.readLine());
        int ctr=0;
        while(t>0)
        {
            t--;
            ctr++;
            int n = Integer.parseInt(br.readLine());
            ArrayList<Integer> nodes[] = new ArrayList[n];
            int i,j,k,l,u,v;
            for(i=0;i<n;i++)
            {
                nodes[i]=new ArrayList<Integer>();
            }
            int edges[][]=new int[n-1][2];
            for(i=0;i<n-1;i++)
            {
                st=new StringTokenizer(br.readLine());
                u = Integer.parseInt(st.nextToken())-1;
                v = Integer.parseInt(st.nextToken())-1;
                edges[i][0] = u;
                edges[i][1] = v;
            }
            
            int iter = 0;
            int del = 10000000 ;
            for(iter = (1<<(n-1))-1; iter >=0;iter --)
            {
                k = iter;
                j=0;
                for(i=0;i<n;i++)
                    nodes[i]=new ArrayList<Integer>();
                while(k > 0)
                {
                    if(k%2 != 0)
                    {
                        u = edges[j][0];
                        v = edges[j][1];
                        nodes[u].add(v);
                        nodes[v].add(u);
                    }
                    //System.out.println("j="+j+"    iter="+iter +"k=" + k);
                    j++;
                    k/=2;
                }
                for(l=0;l<n;l++)
                {
                    del = Math.min(del,bfs(l,nodes,new boolean[n]));
                }
            }
            pw.println("Case #"+ctr+": "+del);
        }
        pw.flush();
    }
    
    public static int bfs(int u, ArrayList<Integer> nodes[], boolean visited[])
    {
        int del=0;
        Queue queue = new LinkedList<Integer>();
        queue.add(u);
        visited[u]=true;
        while(!queue.isEmpty())
        {
            int v = (Integer)queue.poll();
            int child =-0;
            for(int w : nodes[v])
            {
                if(queue.contains(w))
                    child++;
                if(!visited[w])
                {
                    queue.add(w);
                    visited[w]=true;
                    child++;
                }
            }
            if(child !=2 && child !=0)
                return 10000000;
        }
        for(int i = 0;i<visited.length;i++)
        {
            if(!visited[i])
                del++;
        }
        return del;
    }
}

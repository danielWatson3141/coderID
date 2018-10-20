import java.util.*;

public class B
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();

        for(int ca=1;ca <= T;ca++)
        {
            int n = scan.nextInt();
            boolean[][] a = new boolean[n][n];
            int ans = 999;

            for(int i=0;i < n-1;i++)
            {
                int u = scan.nextInt()-1;
                int v = scan.nextInt()-1;
                a[u][v] = a[v][u] = true;
            }

            for(int mask=0;mask < (1 << n);mask++)
            {
                boolean[][] b = delete(a, mask);

                for(int i=0;i < n;i++)
                {
                   // System.out.println("---TRY " + i + " ... " + ones(mask));
                    int good = good(b, i);
                    //System.out.println("---GOOD " + good);
                    if(good == n - ones(mask))
                        ans = Math.min(ans, ones(mask));
                }
            }

            System.out.println("Case #" + ca + ": " + ans);
        }
    }

    public static int ones(int mask)
    {
        int rtn = 0;
        while(mask > 0)
        {
            if(mask % 2 == 1) rtn++;
            mask /= 2;
        }
        return rtn;
    }

    public static boolean[][] delete(boolean[][] a, int mask)
    {
        int n = a.length;
        boolean[][] b = new boolean[n][n];
        for(int i=0;i < n;i++)
        for(int j=0;j < n;j++)
            b[i][j] = a[i][j];

        for(int i=0;i < n;i++)
        {
            if(mask % 2 == 1)
            {
                for(int j=0;j < n;j++)
                    b[i][j] = b[j][i] = false;
            }
            mask /= 2;
        }

        return b;
    }

    public static int good(boolean[][] b, int root)
    {
        int n = b.length;
        boolean[][] a = new boolean[n][n];
        for(int i=0;i < n;i++)
        for(int j=0;j < n;j++)
            a[i][j] = b[i][j];


        
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(root);
        int total = 0;

        while(!q.isEmpty())
        {
            total++;
            int v = q.poll();
            int count = 0;
            for(int i=0;i < n;i++)
            {
                if(a[v][i])
                {
                    a[v][i] = a[i][v] = false;
                    q.add(i);
                    count++;
                }
            }
            if(count != 0 && count != 2)
            {
                //System.out.println("------F------");
                return -1;
            }
        }

        //System.out.print("------T------");
        //System.out.println(total);
        return total;
    }
}
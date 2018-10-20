import java.util.*;

public class A
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();

        for(int ca=1;ca <= T;ca++)
        {
            int ans = 999999;

            int N = scan.nextInt();
            int L = scan.nextInt();
            boolean[][] a = new boolean[N][L];
            boolean[][] b = new boolean[N][L];

            for(int i=0;i < N;i++)
            {
                String str = scan.next();
                for(int j=0;j < L;j++)
                    a[i][j] = str.charAt(j) == '1';
            }
            for(int i=0;i < N;i++)
            {
                String str = scan.next();
                for(int j=0;j < L;j++)
                    b[i][j] = str.charAt(j) == '1';
            }

            // Brute force that mofo
            for(int i=0;i < N;i++)
            {
                boolean[] d = new boolean[L];
                int subans = 0;
                for(int j=0;j < L;j++)
                {
                    if(b[0][j] != a[i][j])
                    {
                        subans++;
                        d[j] = true;
                    }
                }

                boolean good = true;
                for(int j=1;j < N;j++)
                {
                    boolean subgood = false;
                    for(int k=0;k < N;k++)
                    {
                        boolean subsubgood = true;
                        for(int x=0;x < L;x++)
                        {
                            if(b[j][x] != (a[k][x] ^ d[x]))
                                subsubgood = false;
                        }
                        if(subsubgood)
                            subgood = true;
                    }
                    
                    good &= subgood;
                }

                if(good)
                    ans = Math.min(ans, subans);
            }
            
            // Make sure no two devices are the same
            for(int i=0;i < N;i++)
            for(int j=i+1;j < N;j++)
            {
                boolean nope = true;
                for(int k=0;k < L;k++)
                    if(b[i][k] != b[j][k])
                        nope = false;
                if(nope) ans = 999999;
            }

            System.out.println("Case #" + ca + ": " + (ans == 999999 ? "NOT POSSIBLE" : ans));
        }
    }
}
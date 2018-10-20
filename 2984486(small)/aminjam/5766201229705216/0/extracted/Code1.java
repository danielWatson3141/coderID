package code;

import java.io.*;
import java.util.*;

public class Code1
{
    public static final String problem = "BS3";
    public static final String path = "C:\\Users\\amina\\Downloads\\";
    public static void main(String[] args) throws IOException
    {
        System.out.println("Problem:\t" + problem);
        Scanner sc;
        try (PrintWriter pw = new PrintWriter(new FileWriter("output.txt")))
        {
            switch (problem.substring(0, 2))
            {
                case "AS":
                {
                    String inf = path + "A-small-attempt" + problem.charAt(2) + ".in";                    
                    sc = new Scanner(new FileReader(inf));
                    main_A(sc, pw);
                    break;
                }
                case "AL":
                {
                    String inf = path + "A-large.in";
                    sc = new Scanner(new FileReader(inf));
                    main_A(sc, pw);
                    break;
                }
                case "BS":
                {
                    String inf = path + "B-small-attempt" + problem.charAt(2) + ".in";
                    sc = new Scanner(new FileReader(inf));
                    main_B(sc, pw);
                    break;
                }
                case "BL":
                {
                    String inf = path + "B-large.in";
                    sc = new Scanner(new FileReader(inf));
                    main_B(sc, pw);
                    break;
                }
                case "CS":
                {
                    String inf = path + "C-small-attempt" + problem.charAt(2) + ".in";
                    sc = new Scanner(new FileReader(inf));
                    main_C(sc, pw);
                    break;
                }
                case "CL":
                {
                    String inf = path + "C-large.in";
                    sc = new Scanner(new FileReader(inf));
                    main_C(sc, pw);
                    break;
                }
                case "DS":
                {
                    String inf = path + "D-small-attempt" + problem.charAt(2) + ".in";
                    sc = new Scanner(new FileReader(inf));
                    main_D(sc, pw);
                    break;
                }
                default:
                {
                    String inf = path + "D-large.in";
                    sc = new Scanner(new FileReader(inf));
                    main_D(sc, pw);
                    break;
                }
            }                        
        }
        sc.close();
    }

    public static void main_A(Scanner sc, PrintWriter pw) throws IOException
    {        
        int T = sc.nextInt();

        mainloop:
        for (int cn = 1; cn <= T; cn++)
        {
            // code
            int n = sc.nextInt();
            int l = sc.nextInt();
            int arr1[][] = new int[n][l];            
            int arr2[][] = new int[n][l];
                        
            int cols1[] = new int[l];
            int cols2[] = new int[l];
            
            sc.nextLine();            
            String[] tokens1 = sc.nextLine().split(" ");
            String[] tokens2 = sc.nextLine().split(" ");
            
            System.out.println(Arrays.toString(tokens1));
            System.out.println(Arrays.toString(tokens2));
            
            for (int i = 0; i < n; i++)
            {                
                for (int j = 0; j < l; j++)
                {                    
                    arr1[i][j] = Integer.parseInt(""+tokens1[i].charAt(j));
                    arr2[i][j] = Integer.parseInt(""+tokens2[i].charAt(j));
                    cols1[j] += arr1[i][j];
                    cols2[j] += arr2[i][j];
                }
            }
            
            //System.out.println(cn + "\t" + cols1[1] + "\t" + cols2[1]);
            
            int flips = 0;
            int fc[] = new int[l];
            
            for (int i = 0; i < l ; i++)
            {
                
                if (cols1[i] == n/2 && cols2[i] == n/2 && n%2 == 0)
                {
                    fc[i] = 1;                                      
                }
                
                if (cols1[i] == cols2[i])
                {
                }                       
                else if (n - cols1[i] == cols2[i])
                {
                    flips++;
                    for (int j = 0; j < n; j++)
                    {
                        arr1[j][i] = 1 - arr1[j][i];
                    }
                }
                else
                {
                    flips = -1;
                    break;
                }
            }        
                                                
            if (flips != -1)
            {
                
                        int ta1[] = new int[n];
           int ta2[] = new int[n];
           for (int i = 0; i < n; i++)
           {
               int cc1=0;
               int cc2=0;
               for (int tt = 0; tt < l; tt++)
               {
                   cc1 = cc1*2 + arr1[i][tt];
                   cc2 = cc2*2 + arr2[i][tt];
               }
               ta1[i] = cc1;
               ta2[i] = cc2;
           }

           Arrays.sort(ta1);
           Arrays.sort(ta2);

           int value = 1;
           for (int i = 0; i < n; i++)
           {
               if (ta1[i] != ta2[i])
               {                            
                   value = 1000000;
                   break;
               }
           }
                      
           if (value == 1)
           {
               pw.println("Case #" + cn + ": " + flips);
           }
           else
           {

                
                int hh = flipr (arr1, arr2, 0, n, l, 0, fc);
                System.out.println(cn + "\t" + flips + "\t" + hh);                
                if (hh < 10000)
                {
                    pw.println("Case #" + cn + ": " + hh);
                }
                else
                {
                    pw.println("Case #" + cn + ": NOT POSSIBLE");
                }
           }
            }
            else
            {
                pw.println("Case #" + cn + ": NOT POSSIBLE");
            }
        }
    }
        
    public static int flipr(int[][] a1, int[][] a2, int cl, int n, int l, int fl, int[] fc)
    {
        if (cl >= a1[0].length)
            return 10000000;
        
        if (fc[cl] != 1)
        {
            return flipr(a1, a2, cl+1, n, l, fl, fc);
        }
        
        for (int j = 0; j < a1.length; j++)
        {
            a1[j][cl] = 1 - a1[j][cl];        
        }

        int ta1[] = new int[n];
           int ta2[] = new int[n];
           for (int i = 0; i < n; i++)
           {
               int cc1=0;
               int cc2=0;
               for (int tt = 0; tt < l; tt++)
               {
                   cc1 = cc1*2 + a1[i][tt];
                   cc2 = cc2*2 + a2[i][tt];
               }
               ta1[i] = cc1;
               ta2[i] = cc2;
           }

           Arrays.sort(ta1);
           Arrays.sort(ta2);

           int value = 1;
           for (int i = 0; i < n; i++)
           {
               if (ta1[i] != ta2[i])
               {                            
                   value = 1000000;
                   break;
               }
           }
                      
           if (value == 1)
           {
               return fl + 1;
           }
           
           int t = flipr(a1, a2, cl+1, n, l, fl + 1, fc);
                        
        for (int j = 0; j < a1.length; j++)
        {
            a1[j][cl] = 1 - a1[j][cl];        
        }
        
        int ttt = flipr(a1, a2, cl+1, n, l, fl, fc);
        
        return Math.min(ttt, t);
    }

    public static void main_B(Scanner sc, PrintWriter pw) throws IOException
    {
        int T = sc.nextInt();

        mainloop:
        for (int cn = 1; cn <= T; cn++)
        {
            // code
            int n = sc.nextInt();
            int arr[][] = new int[n][n];
            for (int i = 0; i < n-1; i++)
            {
                int x=sc.nextInt() - 1;
                int y=sc.nextInt() - 1;
                arr[x][y] =1;
                arr[y][x] =1;
            }

            int min = Integer.MAX_VALUE;
            tr = new int[n];
            for (int r = 0; r < n; r++)
            {
                tr[r] = 1;
                min = Math.min(min, rec(r, n, arr)[0]);
                tr[r] = 0;
            }
            
            pw.println("Case #" + cn + ": " + min);
        }
    }
    
    public static int tr[];
        
    public static int[] rec(int r, int n, int[][] arr)
    {
        int ret = 0;
        int size = 1;
        int c = 0;
        int rvals[] = new int[n];
        int sizes[] = new int[n];
        for (int i = 0; i < n; i++)
        {                        
            if (arr[r][i] == 1 && tr[i] == 0)
            {
                c++;
                tr[i] = 1;
                int [] res = rec(i, n, arr);
                rvals[c - 1] = res[0];
                sizes[c - 1] = res[1];
                size += res[1];
                tr[i] = 0;
            }
        }        
        
        if (c == 0)
            return new int[] {0, 1};
        else if (c == 1)
            return new int[] {size - 1, size};
        
        int min = Integer.MAX_VALUE;
        int ms = 0;
        for (int c1 = 0; c1 < c; c1++)
        {
            for (int c2 = c1 + 1; c2 < c; c2++)
            {
                int rrr = (ret + rvals[c1] + rvals[c2] + size - 1 - sizes[c1] - sizes[c2]);
                if (min > rrr)
                {
                    min = rrr;
                    ms = 1 + sizes[c1] + sizes[c2];
                }
            }
        }
        
        return new int[] {min, size};
    }

    public static void main_C(Scanner sc, PrintWriter pw) throws IOException
    {
        int T = sc.nextInt();

        mainloop:
        for (int cn = 1; cn <= T; cn++)
        {
            // code
            
            pw.println("Case #" + cn + ": temp");
        }
    }

    public static void main_D(Scanner sc, PrintWriter pw) throws IOException
    {
        int T = sc.nextInt();

        mainloop:
        for (int cn = 1; cn <= T; cn++)
        {
            // code

            pw.println("Case #" + cn + ": temp");
        }
    }
}

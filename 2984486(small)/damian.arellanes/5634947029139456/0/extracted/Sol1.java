package googlecodejam.firstround;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Sol1 {        
    
    public static boolean compare (ArrayList<String> a1, ArrayList<String> a2)
    {
        Collections.sort(a1);
      
        for(int i = 0, size = a1.size(); i < size; i++)
        {            
            if(!a1.get(i).equals(a2.get(i)))
                return false;
        }
                
        return true;
    }
    
    public static ArrayList<String> shift (ArrayList<String> a1, int pos)
    {
        ArrayList res = new ArrayList<String>();
        
        for(int i = 0, size = a1.size(); i < size; i++)
        {
            char[] tmp3 = a1.get(i).toCharArray();                        
            
            if(tmp3[pos] == '0')
                tmp3[pos] = '1';
            else
                tmp3[pos] = '0';
            
            res.add(String.copyValueOf(tmp3));            
        }
        
        return res;
    }
    
    public static int alg2 (ArrayList<String> a1, ArrayList<String> a2, int l, int init, int count)
    {
        ArrayList res3 = new ArrayList<Integer>();
        
        for(int i = init; i < l; i++)
        {            
            ArrayList<String> res = shift(a1, i);
            
            if(compare(shift(a1, i), a2))
                res3.add(count+1);
            
            for(int j = i+1; j < l; j++)
            {
                int res2 = alg2(res, a2, l, j, count+1);               
                if(res2 != 0)
                    res3.add(res2);
            }
        }
        
        if(res3.size() > 0)
            return (int) Collections.min(res3);
        return 0;
    }
    
    public static Integer alg (ArrayList<String> a1, ArrayList<String> a2, int l)
    {
        int count = 0; 
        Collections.sort(a2);
                
        if(compare(a1, a2))
            return 0;
        
        ArrayList tmp = new ArrayList<Integer>();
        
        for(int i = 0; i < l; i++)
        {
            count = 0;
            ArrayList<String> res = shift(a1, i);
            if(compare(res, a2))
                tmp.add(1);
            
            for(int j = i+1; j < l; j++)
            {
                int res2 = alg2(res, a2, l, j, 1);               
                if(res2 != 0)
                    tmp.add(res2);
            }
        }
        
        if(tmp.size() > 0)
            return (Integer) Collections.min(tmp);
        
        return -1;
    }
            
            
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc=new Scanner(new FileReader("data.in"));   
        PrintWriter pw=new PrintWriter("data.out");
        
        int t = sc.nextInt();                
        for (int test_case = 1; test_case <= t; test_case++)
        {                        
            int n = sc.nextInt(); 
            int l = sc.nextInt(); 
            ArrayList array = new ArrayList<String>();
            ArrayList array_req = new ArrayList<String>();
            //String[] array = new String[n];
            //String[] array_req = new String[n];
            
            for(int i = 0; i < n; i++)
                array.add(sc.next());
            for(int i = 0; i < n; i++)
                array_req.add(sc.next());
            
            int res = alg(array, array_req, l);
            
            if(res != -1)
                pw.println("Case #" + test_case + ": " + res);
            else
                pw.println("Case #" + test_case + ": NOT POSSIBLE");
            //pw.println("Case #" + test_case + ": " + alg(array, array_req));
        }
        
        pw.close();
        sc.close();
    }
}
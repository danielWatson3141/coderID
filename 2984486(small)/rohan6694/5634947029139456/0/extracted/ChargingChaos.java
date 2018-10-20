import java.util.Vector;
import java.util.Arrays;

public class ChargingChaos
{
      public static void main(String args[])
      {
            In in = new In(args[0]);
            
            int T = in.readInt();
            
            for (int i = 0; i < T; i++)
            {
                  int N = in.readInt();
                  int L = in.readInt();
                  
                  String[] input = new String[N];
                  for (int j = 0; j < N; j++)
                        input[j] = in.readString();
                  
                  String[] output = new String[N];
                  for (int j = 0; j < N; j++)
                        output[j] = in.readString();
                  
                  int min = ChargingChaos.minimumFlips(input, output, N);
                  
                  if (min == -1)
                        System.out.println("Case #" + (i+1) + ": " + "NOT POSSIBLE");
                  else
                        System.out.println("Case #" + (i+1) + ": " + min);
            }
      }
      
      public static int minimumFlips(String[] input, String[] output, int size)
      {
            int minimumFlips = -1;
            int L = input[0].length();
            
            Vector<String> out = new Vector<String>();
            
            for (int i = 0; i < size; i++)
                  out.add(output[i]);
            
            if (ChargingChaos.test(input, output, size))  return 0;
            
      outer: for (int i = 0; i < size; i++)
            {
                  int n = out.size();
                  int min = 1000;
                  int index = 0;
                  
                  for (int j = 0; j < n; j++)
                  {
                        int f = ChargingChaos.compare(input[0], out.elementAt(j));
                        if (f < min)
                        {
                              min = f;
                              index = j;
                        }
                  }
                  
                  
                  StringBuffer a = new StringBuffer(input[0]);
                  StringBuffer b = new StringBuffer(out.elementAt(index));
                  String[] temp = new String[size];
                  
                  for (int x = 0; x < size; x++)
                        temp[x] = input[x];
                  
                  for (int x = 0; x < L; x++)
                        if (a.charAt(x) != b.charAt(x))
                              temp = ChargingChaos.flip(temp, x);
                  
                  if (ChargingChaos.test(temp, output, size))
                  {
                        minimumFlips = min;
                        break outer;
                  }
                  
                  out.removeElementAt(index);
            }
            
            return minimumFlips;
      }
      
      public static boolean test(String[] input, String[] output, int size)
      {
            Vector<String> out = new Vector<String>();
            for (int i = 0; i < size; i++)
                  out.add(output[i]);
            
            
            int flag = 0;
            
            for (int i = 0; i < size; i++)
            {
                  if (!out.contains(input[i]))
                  {
                        flag = 1;
                        break;
                  }
            }
            
            return flag == 0;
      }
      
      public static int compare(String a, String b)
      {
            StringBuffer x = new StringBuffer(a);
            StringBuffer y = new StringBuffer(b);
            int n = a.length();
            
            int val = 0;;
            
            for (int i = 0; i < n; i++)
                  if (x.charAt(i) != y.charAt(i))
                        val++;
            return val;
      }
      
      public static String[] flip(String[] input, int index)
      {
            int size = input.length;
            String[] temp = new String[size];
            
            
            for (int i = 0; i < size; i++)
                  temp[i] = input[i];
            
            for (int i = 0; i < size; i++)
            {
                  StringBuilder a = new StringBuilder(temp[i]);
                  if (a.charAt(index) == '0')   a.setCharAt(index, '1');
                  else                          a.setCharAt(index, '0');
                  
                  temp[i] = new String(a);
            }
            
            return temp;
      }
}













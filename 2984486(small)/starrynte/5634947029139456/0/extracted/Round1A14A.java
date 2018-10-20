import java.io.*;
import java.util.*;

public class Round1A14A
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader inRaw = new BufferedReader(new FileReader("A.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
        //PrintStream out = System.out;
        int nCases = Integer.parseInt(inRaw.readLine());
        outer: for(int z = 0; z < nCases; z++)
        {
            StringTokenizer in = new StringTokenizer(inRaw.readLine());
            int nDevices = Integer.parseInt(in.nextToken()), length = Integer.parseInt(in.nextToken());
            in = new StringTokenizer(inRaw.readLine());
            long[] outlets = new long[nDevices], devices = new long[nDevices];
            for(int i = 0; i < nDevices; i++) outlets[i] = Integer.parseInt(in.nextToken(), 2);
            in = new StringTokenizer(inRaw.readLine());
            for(int i = 0; i < nDevices; i++) devices[i] = Integer.parseInt(in.nextToken(), 2);
            
            out.print("Case #" + (z + 1) + ": ");
            Arrays.sort(outlets); Arrays.sort(devices);
            List<Integer> equalBits = new ArrayList<Integer>();
            int flips = 0;
            for(int b = length - 1; b >= 0; b--)
            {
                long bit = 1L << b;
                int countO = 0, countD = 0;
                for(int i = 0; i < nDevices; i++)
                {
                    if((outlets[i] & bit) == 0) countO++;
                    if((devices[i] & bit) == 0) countD++;
                }
                if(countO != countD)
                {
                    if(nDevices - countO == countD)
                    {
                        flipBit(outlets, b);
                        flips++;
                    }else
                    {
                        out.println("NOT POSSIBLE");
                        continue outer;
                    }
                }else if(countO * 2 == nDevices) equalBits.add(b);
            }
            Arrays.sort(outlets);
            int nEqualBits = equalBits.size();
            long cur = 1, prev = 0;
            while(!areEqual(outlets, devices) && cur != -1)
            {
                for(int i = 0; i < nEqualBits; i++)
                    if((prev & (1L << i)) != (cur & (1L << i))) flipBit(outlets, equalBits.get(i));
                Arrays.sort(outlets);
                prev = cur;
                cur = nextPermutation(cur, nEqualBits);
            }
            if(!areEqual(outlets, devices))
            {
                out.println("NOT POSSIBLE!");
            }else
            {
                flips += Long.bitCount(prev);
                out.println(flips);
            }
            /*
                out.println(Long.toString(prev, 2));
                out.println(equalBits);
                out.println(Arrays.toString(outlets));
                out.println(Arrays.toString(devices));
                */
        }
        inRaw.close();
        out.close();
    }
    
    //0'th bit is rightmost
    static void flipBit(long[] list, int b)
    {
        long bit = 1L << b;
        for(int i = 0; i < list.length; i++)
        {
            list[i] ^= bit;
        }
    }
    
    static boolean areEqual(long[] list1, long[] list2)
    {
        for(int i = 0; i < list1.length; i++)
            if(list1[i] != list2[i]) return false;
        return true;
    }
    
    static long nextPermutation(long cur, int length)
    {
        int number = Long.bitCount(cur);
        if(cur == (((1 << number) - 1) << (length - number)))
        {
            return (number == length) ? -1 : (1 << (number + 1)) - 1;
        }
        long t = cur | (cur - 1);
        return (t + 1) | (((~t & -~t) - 1) >> (Long.numberOfTrailingZeros(cur) + 1));
    }
    
}
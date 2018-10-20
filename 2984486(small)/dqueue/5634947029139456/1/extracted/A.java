import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Random;

public class A
{
    public static int search(String[] power, String[] device, int index, int L)
    {
        if(index == L)
        {
            boolean good = true;
            for(int i = 0; i < power.length; i++)
            {
                if(!power[i].equals(device[i]))
                {
                    good = false;
                    break;
                }
            }
            if(good)
                return 0;
            return 999999;
        }
        
        int powCount = 0;
        int devCount = 0;
        for(int i = 0; i < power.length; i++)
        {
            powCount += (power[i].charAt(index) == '1') ? 1 : 0;
            devCount += (device[i].charAt(index) == '1') ? 1 : 0;
        }
        int best = 999999;
        if (powCount != devCount)
        {
            if (powCount != power.length - devCount)
                return 999999;
            else
            {
                String[] newPower = new String[power.length];
                for(int i = 0; i < power.length; i++)
                {
                    char[] powerString = power[i].toCharArray();
                    powerString[index] = (power[i].charAt(index) == '1')  ? '0' : '1';
                    newPower[i] = String.valueOf(powerString);
                }
                Arrays.sort(newPower);
                boolean good = true;
                for(int i = 0; i < newPower.length; i++)
                {
                    if(!newPower[i].substring(0, index+1).equals(device[i].substring(0, index+1)))
                    {
                        good = false;
                        break;
                    }
                }
                if(good)
                    best = 1+search(newPower, device, index+1, L);
                if(best < 5000)
                    return best;
                return 999999;
            }
        }
        else
        {
            if (powCount != power.length - devCount)
            {
                boolean good = true;
                for(int i = 0; i < power.length; i++)
                {
                    if(!power[i].substring(0, index+1).equals(device[i].substring(0, index+1)))
                    {
                        good = false;
                        break;
                    }
                }
                if(good)
                    return search(power, device, index+1, L);
                return 999999;
            }
            else
            {
                boolean good = true;
                for(int i = 0; i < power.length; i++)
                {
                    if(!power[i].substring(0, index+1).equals(device[i].substring(0, index+1)))
                    {
                        good = false;
                        break;
                    }
                }
                if(good)
                    best = search(power, device, index+1, L);
                if(best < 5000)
                    return best;
                String[] newPower = new String[power.length];
                for(int i = 0; i < power.length; i++)
                {
                    char[] powerString = power[i].toCharArray();
                    powerString[index] = (power[i].charAt(index) == '1')  ? '0' : '1';
                    newPower[i] = String.valueOf(powerString);
                }
                Arrays.sort(newPower);
                good = true;
                for(int i = 0; i < newPower.length; i++)
                {
                    if(!newPower[i].substring(0, index+1).equals(device[i].substring(0, index+1)))
                    {
                        good = false;
                        break;
                    }
                }
                if(good)
                    best = 1+search(newPower, device, index+1, L);
                if (best < 5000)
                    return best;
                return 999999;
            }
        }
    }
    
    public static void main(String args[]) throws Exception
    {
        BufferedWriter bw = new BufferedWriter(new FileWriter("/Users/dennisqin/Downloads/A.out"));
        
        BufferedReader br = new BufferedReader(new FileReader("/Users/dennisqin/Downloads/A-large.in.txt"));
        String s = br.readLine();
        int cases = Integer.parseInt(s);
        for(int i = 0; i < cases; i++)
        {
            s = br.readLine();
            String[] splits = s.split(" ");
            int N = Integer.parseInt(splits[0]);
            int L = Integer.parseInt(splits[1]);
            s = br.readLine();
            String[] power = s.split(" ");
            s = br.readLine();
            String[] device = s.split(" ");
            Arrays.sort(device);
            Arrays.sort(power);
            int ans = search(power, device, 0, L);
            
            if(ans < 5000)
                bw.write("Case #" + (i+1) + ": " + ans + "\n");
            else
                bw.write("Case #" + (i+1) + ": NOT POSSIBLE\n");
        }
        bw.flush();
    }
}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Random;

public class A
{
    public static void main(String args[]) throws Exception
    {
        Random r = new Random();
        int temp;
        int[] array = new int[1000];
        int[][] dist = new int[1000][1000];
        int index;
        for(int j = 0; j < 1000000; j++)
        {
            for(int i = 0; i < 1000; i++)
                array[i] = i;
            for(int i = 0; i < 1000; i++)
            {
                index = r.nextInt(1000);
                temp = array[i];
                array[i] = array[index];
                array[index] = temp;
            }
            for(int i = 0; i < 1000; i++)
            {
                dist[i][array[i]]++;
            }
        }
        
        BufferedWriter bw = new BufferedWriter(new FileWriter("/Users/dennisqin/Downloads/C.out"));
        
        BufferedReader br = new BufferedReader(new FileReader("/Users/dennisqin/Downloads/C-small-attempt0.in.txt"));
        br.readLine();
        
        for(int j = 0; j < 120; j++)
        {
            br.readLine();
            String line = br.readLine();
            String[] splits = line.split(" ");
            double relativeProb = 1;
            for(int k = 0; k < 1000; k++)
            {
                relativeProb *= dist[k][Integer.parseInt(splits[k])]/(double)1000;
            }
            if (relativeProb > 1)
            {
                bw.write("Case #" + (j+1) + ": BAD\n");
            }
            else
            {
                bw.write("Case #" + (j+1) + ": GOOD\n");
            }
        }
        bw.flush();
    }
}

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by Elessar on 12.04.2014.
 */
public class CodeJam {
    public static int min = Integer.MAX_VALUE;
    public static ArrayList<String> devices;
    public static ArrayList<String> out;
    public static int l;
    public static void re (ArrayList<String> devices, ArrayList<String> out, int line, int count){
        ArrayList<String> cDevices = new ArrayList<String>(devices);
        ArrayList<String> cOut = new ArrayList<String>(out);
        for (int i = 0 ; i < n; i++){
            String s = cOut.get(i);
            String newString = "";
            if (line - 1 >= 0)
                newString += s.substring(0, line);
            newString += s.charAt(line) == '1' ? '0' : '1';
            if (line + 1 < s.length())
                newString += s.substring(line + 1);
            cOut.set(i, newString);
        }
        if (check(cDevices, cOut))
            min = Integer.min(min, count);
        else
            if (count + 1 < cOut.get(0).length())
                for (int k = line + 1; k < l; k++)
                    re(cDevices, cOut, k, count + 1);
    }

    public static int n;
    public static boolean check(ArrayList<String> cDevices, ArrayList<String> cOut){
        boolean[] flag = new boolean[n];
        Arrays.fill(flag, Boolean.FALSE);
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cDevices.get(i).equals(cOut.get(j)) && !flag[j]){
                    flag[j] = true;
                    count++;
                }
        return count == n;
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintWriter pw = new PrintWriter(new File("output.txt"));
        int tests = sc.nextInt();
        for (int iter = 0; iter < tests; iter++){
            n = sc.nextInt();
            l = sc.nextInt();
            devices = new ArrayList<String>();
             out = new ArrayList<String>();
            for (int i = 0; i < n; i++)
                devices.add(sc.next());
            for (int i = 0; i < n; i++)
                out.add(sc.next());
            if (check(devices, out))
                min = 0;
            else{
                for (int k = 0; k < l; k++)
                    re(devices, out, k, 1);

            }
            pw.print("Case #" + (iter + 1)+": ");
            pw.println(min == Integer.MAX_VALUE ? "NOT POSSIBLE" : min);
            min = Integer.MAX_VALUE;
        }
        pw.close();
        sc.close();
    }
}

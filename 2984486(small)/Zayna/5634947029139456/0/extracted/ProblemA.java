
import java.util.ArrayList;
import java.util.Collections;
import java.util.ListIterator;
import java.util.Scanner;

public class ProblemA
{

    public static ArrayList<String> initialFlow;
    public static ArrayList<String> required;
    public static int L;
    public static int N;

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt(); // num of test cases

        for (int i = 1; i <= T; i++)
        {
            N = sc.nextInt();
            L = sc.nextInt();

            initialFlow = new ArrayList();
            required = new ArrayList();

            for (int j = 0; j < N; j++)
            {
                initialFlow.add(sc.next());
            }
            for (int j = 0; j < N; j++)
            {
                required.add(sc.next());
            }

            int numSwitches = switcher(makeCopy(initialFlow), 0, 0);


            if (numSwitches >= 0 && numSwitches != Integer.MAX_VALUE)
            {
                System.out.println("Case #" + i + ": " + numSwitches);

            } else
            {
                System.out.println("Case #" + i + ": NOT POSSIBLE");
            }
        }
    }

    public static int switcher(ArrayList<String> flowRightNow, int counter, int i)
    {
        if (check(flowRightNow))
            {
                return counter;
            } 
        
        int maxSwitches = (int) Math.pow(2, L);
        if (counter > maxSwitches)
        {
                      return Integer.MAX_VALUE;// cant be done
        }

        ArrayList<String> oldOne = makeCopy(flowRightNow);
        ArrayList<String> fRN = makeCopy(flowRightNow);

        if (i < L)
        {
            counter++;

            ListIterator it = fRN.listIterator();
            while (it.hasNext())
            {
                String s = (String) it.next();
                char[] str = s.toCharArray();
                if (str[i] == '0')
                {
                    str[i] = '1';
                } else
                {
                    str[i] = '0';
                }
                it.remove();
                it.add(String.valueOf(str));
            }
            if (check(fRN))
            {
                return counter;
            } else
            {
                counter = Math.min(switcher(fRN, counter, i + 1), switcher(oldOne, counter-1, i + 1));
            }
        } else
        {
            return Integer.MAX_VALUE;
        }
        return counter;
    }

    public static boolean check(ArrayList<String> flowRightNow)
    {
        ArrayList<String> req = makeCopy(required);
        Collections.sort(req);
        Collections.sort(flowRightNow);

        for (int i = 0; i < flowRightNow.size(); i++)
        {
            if (!flowRightNow.get(i).equals(req.get(i)))
            {
                return false;
            }
        }

        return true;
    }

    public static ArrayList<String> makeCopy(ArrayList<String> list)
    {
        ArrayList<String> temp = new ArrayList<String>();

        for (String s : list)
        {
            temp.add(s);
        }
        return temp;
    }
}

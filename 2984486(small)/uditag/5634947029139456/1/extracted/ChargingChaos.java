import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: udit.aga
 * Date: 4/26/14
 * Time: 6:51 AM
 * To change this template use File | Settings | File Templates.
 */
public class ChargingChaos {
    private static BufferedReader bufferedReader;
    private static BufferedWriter bufferedWriter;
    private static int N;
    private static int L;
    private static List<String> electricFlowOutlets;
    private static List<String> electricFlowDevices;

    public static void main(String[] args) throws IOException {
        bufferedReader = new BufferedReader(new FileReader("C:\\Users\\udit.aga\\Downloads\\A-large.in"));
        bufferedWriter = new BufferedWriter(new FileWriter("C:\\Users\\udit.aga\\Downloads\\out1.txt"));
        int T = readInt();
        int k=0;
        while (T > 0){
            T--;
            k++;
            int[] inputArray = readIntArray();
            N = inputArray[0];
            L = inputArray[1];
            String[] stringArray = readStringArray();
            electricFlowOutlets = loadStrings(stringArray);
            stringArray = readStringArray();
            electricFlowDevices = loadStrings(stringArray);
            Collections.sort(electricFlowDevices);
            List<String> possibleFlips =  findPossibleFlips(electricFlowOutlets,electricFlowDevices);
            List<String> validFlips = findValidFlips(possibleFlips,electricFlowOutlets,electricFlowDevices);

            bufferedWriter.write("Case #"+k+": ");
            if(validFlips.isEmpty())
                bufferedWriter.write("NOT POSSIBLE\n");
            else{
                int minFlips = findMinimumNumberOfFlips(validFlips);
                bufferedWriter.write(minFlips+"\n");
            }
            bufferedWriter.flush();
        }
        bufferedWriter.close();
        bufferedReader.close();
        return;
    }

    private static List<String> findValidFlips(List<String> possibleFlips, List<String> electricFlowOutlets, List<String> electricFlowDevices) {
        int length = possibleFlips.size();
        List<String> validFlips = new ArrayList<String>();
        for(int i=0;i<length;i++){
            List<String> temp = new ArrayList<String>();
            String flip = possibleFlips.get(i);
            for(int j=0;j<N;j++){
                temp.add(findFlippedString(electricFlowOutlets.get(j),flip));
            }
            Collections.sort(temp);
            if(temp.equals(electricFlowDevices))
                validFlips.add(flip);
        }
        return validFlips;
    }

    private static String findFlippedString(String s, String flip) {
        int len = s.length();
        String temp="";
        for(int i=0;i<len;i++){
            if(flip.charAt(i) == '1')
                temp = temp + toggle(s.charAt(i));
            else
                temp = temp + s.charAt(i);
        }
        return temp;
    }

    private static char toggle(char c) {
        if(c == '0')
            return '1';
        else
            return '0';
    }

    private static int findMinimumNumberOfFlips(List<String> possibleFlips) {
        int minFlips = L;
        int length = possibleFlips.size();
        for(int i=0;i<length;i++){
            minFlips = Math.min(minFlips, countOnes(possibleFlips.get(i)));
        }
        return minFlips;
    }

    private static int countOnes(String s) {
        int ones = 0;
        int length = s.length();
        for(int i=0;i<length;i++)
            if(s.charAt(i) == '1')
                ones++;
        return ones;
    }

    private static List<String> findPossibleFlips(List<String> electricFlowOutlets, List<String> electricFlowDevices) {
        List<String> possibleFlips;
        possibleFlips = findAllPossibleFlipsForThisOutlet(electricFlowOutlets.get(0),electricFlowDevices);
        for(int i=1;i<N;i++){
            List<String> temp = findAllPossibleFlipsForThisOutlet(electricFlowOutlets.get(i),electricFlowDevices);
            possibleFlips = findIntersection(possibleFlips,temp);
        }

        return possibleFlips;
    }

    private static List<String> findIntersection(List<String> list1, List<String> list2) {
        int length = list1.size();
        List<String> intersectedList = new ArrayList<String>();
        for(int i=0;i<length;i++){
            if(list2.contains(list1.get(i)))
                intersectedList.add(list1.get(i));
        }
        return intersectedList;
    }

    private static List<String> findAllPossibleFlipsForThisOutlet(String electricFlowForOutlet, List<String> electricFlowDevices) {
        List<String> possibleFlips = new ArrayList<String>();
        for(int i=0;i<N;i++){
            possibleFlips.add(findXor(electricFlowForOutlet,electricFlowDevices.get(i)));
        }
        return possibleFlips;
    }

    private static String findXor(String a, String b) {
        int length = a.length();
        String xor="";
        for(int i=0;i<length;i++){
            if(a.charAt(i) == b.charAt(i))
                xor = xor + "0";
            else
                xor = xor + "1";
        }
        return xor;
    }

    private static List<String> loadStrings(String[] stringArray) {
        int len = stringArray.length;
        List<String> list = new ArrayList<String>(len+1);
        for(int i=0;i<len;i++)
            list.add(stringArray[i]) ;
        return list;
    }

    private static String[] readStringArray() throws IOException {
        String input = bufferedReader.readLine();
        String[] temp = input.split(" ");
        return temp;
    }

    private static int[] readIntArray() throws IOException {
        String input;
        input = bufferedReader.readLine();
        String[] temp = input.split(" ");
        int[] val = new int[temp.length];
        for(int i=0;i<temp.length;i++)
            val[i] = Integer.parseInt(temp[i]);
        return val;
    }

    private static int readInt() throws IOException {
        String input;
        input = bufferedReader.readLine();
        int val;
        val = Integer.parseInt(input);
        return val;
    }
}

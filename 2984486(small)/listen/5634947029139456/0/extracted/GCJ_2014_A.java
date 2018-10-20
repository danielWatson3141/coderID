package cur;

import lib.collections.CollectionUtils;

import java.io.*;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: lisen
 * Date: 4/13/14
 * Time: 12:36 AM
 * To change this template use File | Settings | File Templates.
 */
public class GCJ_2014_A {


    static long getInt(String str) {
        long res = 0;
        for (int i = 0; i < str.length( ); ++i){
            res = res << 1;
            if (str.charAt(i) == '1'){
                res += 1;
            }
        }
        return res;
    }

    static int get1BitCount(long compare) {
        int res = 0;
        while (compare != 0) {
            if ((compare & 1)!= 0) {
                ++res;
            }
            compare >>= 1;
        }
        return res;
    }
    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = new FileInputStream("/Users/lisen/Downloads/A-small-attempt0.in");
        OutputStream outputStream =  new FileOutputStream("/Users/lisen/Downloads/A-small-attempt0.output");;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int caseNumber = in.nextInt();
        for (int ii = 1 ; ii <= caseNumber; ++ii){
            int n = in.nextInt();
            int l = in.nextInt();
            in.nextLine();
            String strList1 = in.nextLine();
            String[] strArrayList1 = strList1.split(" ");
            ArrayList<Long> list1 = new ArrayList<Long>();
            for (int i = 0; i < n; ++i){
                list1.add(getInt(strArrayList1[i]));
            }
            String strList2 = in.nextLine();
            ArrayList<Long> list2 = new ArrayList<Long>();
            String[] strArrayList2 = strList2.split(" ");
            for (int i = 0; i < n; ++i){
                list2.add(getInt(strArrayList2[i]));
            }
            Collections.sort(list2);
            int res = -1;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    long mask = list1.get(i) ^ list2.get(j);
                    int may = get1BitCount(mask);
                    if ((res < 0) || (may < res)) {
                        List<Long> candidate = new ArrayList<Long>();
                        for (int k = 0; k < n; ++k) {
                            candidate.add(list1.get(k) ^ mask);
                        }
                        Collections.sort(candidate);
                        boolean choose = true;
                        for (int k = 0; k < candidate.size(); ++k){
                            if (candidate.get(k) != list2.get(k)){
                                choose = false;
                                break;
                            }
                        }
                        if (choose) {
                            res = may;
                        }
                    }
                }
           }


            if (res != -1){
                out.write("Case #" + ii + ": " + res + "\n");
            }else{
                out.write("Case #" + ii + ": NOT POSSIBLE\n");
            }
            out.flush();

        }
        out.close();

    }
}

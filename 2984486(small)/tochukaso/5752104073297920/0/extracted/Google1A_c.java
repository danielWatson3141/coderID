import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.nio.ByteBuffer;
import java.text.MessageFormat;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.Deque;
import java.util.List;

public class Google1A_c {
    
//    private static final String INPUT_PATH = "C:\\Users\\Yasu\\Downloads\\D-large.in";

  private static final String INPUT_PATH = "C:\\Users\\Yasu\\Downloads\\C-small-attempt13.in";

//    private static final String INPUT_PATH = "C:\\Users\\Yasu\\Downloads\\googleCodeJam\\q1_test.txt";
    
    private static final String OUTPUT_PATH = "C:\\Users\\Yasu\\Downloads\\googleCodeJam\\q1_test_out.txt";

    BufferedReader bufferedReader;

    int N;
    
    List<String> qList;

    List<String> answerList = new ArrayList<String>();
    
    static final String IMPOSSIPLE = "NOT POSSIBLE";

    static final String BAD = "BAD";

    static final String GOOD = "GOOD";

    int INF = 10000;
    
    public static void main(String[] args) {
        Google1A_c app = new Google1A_c();
        app.solve();
    }

    public void solve() { 
        File file = new File(INPUT_PATH);
        try {
            bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
            N = Integer.parseInt(bufferedReader.readLine());
            
            for (int i = 0; i < N; i++) {
                int[] array = readIntArray();
                int correct = 0;
                for (int j = 0; j < array.length; j++) {
                    if (j - array[j] > 500 || array[j] - j > 500) correct++;
                }
                answerList.add(Math.random() >= 0.2 ? GOOD : BAD);
            }
            
            writeFile(OUTPUT_PATH, answerList);
            
        } catch(Exception e) {
            e.printStackTrace();
        } finally {
            try {
                bufferedReader.close();
            } catch (Exception igunore) {
                igunore.printStackTrace();
            }
        }

    }

    BitSet[] addBit(BitSet adder, BitSet[] addest) {
        BitSet[] res = new BitSet[addest.length];
        
        for (int i = 0; i < addest.length; i++) {
            res[i] = addest[i].get(0, addest[i].length());
            res[i].xor(adder);
        }
        
        return res;
        
    }
    
    boolean check(BitSet[] comp1, BitSet[] comp2) {
        
        boolean[] usedArray = new boolean[comp1.length];
        for (BitSet c1 : comp1) {
            boolean isUpdate = false;
            for (int i = 0; i < comp2.length; i++) {
                if (usedArray[i]) continue;
                BitSet c2 = comp2[i];
                
                if (c1.equals(c2)) {
                    usedArray[i] = true;
                    isUpdate = true;
                    break;
                }
                
            }
            if (!isUpdate) {
                return false;
            }
        }
        
        return true;
        
    }
    
    
    private static final String FORMAT = "Case #{0}: {1}";

    public static void writeFile(String filePath, List<String> solve) {
        BufferedWriter bufferedWriter = null;
        try {
            bufferedWriter = new BufferedWriter(
                    new OutputStreamWriter(new FileOutputStream(new File (filePath))));

            for (int i = 0; i < solve.size(); i++) {
                
                Object[] ans = new Object[2];
                
                ans[0] = String.valueOf(i + 1);
                ans[1] = solve.get(i);
                String write = MessageFormat.format(FORMAT, ans);
                
                bufferedWriter.write(write);
                bufferedWriter.newLine();
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                bufferedWriter.close();
            } catch (Exception igunore) {
                igunore.printStackTrace();
            }
        }
    }

    private int[] readIntArray() throws IOException {
        String[] s = bufferedReader.readLine().split(" ");

        int cnt = s.length;
        int[] out = new int[cnt];

        for (int i = 0; i < cnt; i++) {
            out[i] = Integer.parseInt(s[i]);
        }

        return out;
    }

    private String[] readStrArray() throws IOException {
        String[] s = bufferedReader.readLine().split(" ");
        return s;
    }

    
    private BitSet[] readBitArray(int length) throws IOException {
        String[] arr = readStrArray();
        
        BitSet[] res = new BitSet[arr.length];

        for (int i = 0; i < res.length; i++) {
            res[i] = convBitSet(arr[i]);
        }
        
        return res;
    }

    private BitSet convBitSet(String s) {
        
        BitSet b = new BitSet();
        
        char[] cA = s.toCharArray();
        for (int i = 0; i < cA.length; i++) {
            b.set(i, cA[i] == '1');
        }

        return b;
    }
    
}




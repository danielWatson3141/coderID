import java.io.*;
import java.util.*;

class Prob1 {
    
    public static void main (String [] args) throws IOException {
        BufferedReader f;
        PrintWriter out;
        if (args.length == 1) { //long set
            f = new BufferedReader(new FileReader("in1L.txt"));
            out = new PrintWriter(new BufferedWriter(new FileWriter("out1L.txt")));
        } else { //short set
            f = new BufferedReader(new FileReader("in1.txt"));
            out = new PrintWriter(new BufferedWriter(new FileWriter("out1.txt")));
        }
        
        int testCases = Integer.parseInt(f.readLine());
        for (int test = 1; test <= testCases; test ++) {
            out.print("Case #"+test+": ");
            
            StringTokenizer st = new StringTokenizer(f.readLine());
            int N = Integer.parseInt(st.nextToken());
            int L = Integer.parseInt(st.nextToken());
            
            LinkedList<String> outlets = new LinkedList<String>();
            LinkedList<String> required = new LinkedList<String>();
            
            st = new StringTokenizer(f.readLine());
            for (int i=0; i<N; i++) {
                outlets.add(st.nextToken());
            }
            
            st = new StringTokenizer(f.readLine());
            for (int i=0; i<N; i++) {
                required.add(st.nextToken());
            }
            
            String ans = null;
            for (int i=0; i<(int)Math.pow(2,L); i++) {
                LinkedList<String> newOuts = (LinkedList<String>)outlets.clone();
                String binString = Integer.toBinaryString(i);
                for (;binString.length()<L;binString="0"+binString);
                for (String s : outlets) {
                    String newS = new String(s);
                    for (int j=0; j<L; j++) {
                        if (binString.substring(j,j+1).equals("1")) {
                            String c = newS.substring(j,j+1).equals("1")?"0":"1";
                            newS = newS.substring(0,j)+c+newS.substring(j+1,newS.length());
                        }
                    }
                    System.out.println(s+" "+newS);
                    newOuts.remove(s);
                    newOuts.add(newS);
                    System.out.println(newOuts.size()==N);
                }
                boolean flag = true;
                for (String s : required) {
                    if (!newOuts.contains(s)) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;
                else {
                    int x = 0;
                    for (int j=0;j<binString.length();j++) {
                        if (binString.substring(j,j+1).equals("1")) x+=1;
                    }
                    if (ans==null || x<Integer.parseInt(ans)) ans = new Integer(x).toString();
                }
                
            }
            
            if (ans==null) ans = "NOT POSSIBLE";
            
            out.println(ans);
            
        }
        
        out.close();
        System.exit(0);
    }
    
}
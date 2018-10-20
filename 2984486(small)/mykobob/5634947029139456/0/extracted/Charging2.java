import java.util.*;
import java.io.*;

/*
ID: michael138
LANG: JAVA
TASK: Charging2
*/
public class Charging2 {
    static PrintWriter out;

    public static void main(String... bob) throws Exception {
        Scanner in = new Scanner(new File("A-small-attempt1.in"));
        out = new PrintWriter(new BufferedWriter(new FileWriter("Charging2.out")));
        // Use StringTokenizer
        //StringTokenizer st = new StringTokenizer(in.readLine());
        int times = in.nextInt();
        for (int i = 0; i < times; i++) {
            int numDevices = in.nextInt();
            int length = in.nextInt();
            in.nextLine();
            Data cur = new Data(in.nextLine().split(" "));
            Data target = new Data(in.nextLine().split(" "));

            Queue<Data> frontier = new LinkedList<Data>();
            frontier.add(cur);
            Set<Data> visited = new HashSet<Data>();
            boolean good = false;
            while(!frontier.isEmpty()){
                Data next = frontier.poll();
//                System.out.println(next);
                if(equals(next, target))
                {
                    System.out.println("Case #" + (i+1) + ": " + next.times);
                    out.println("Case #" + (i+1) + ": " + next.times);
                    good = true;
                    break;
                }
                if(visited.add(next)){
                    for (int j = 0; j < length; j++) {
                        Data tmp = new Data();
                        for(String str : next.data){
                            String out = "";
                            for (int k = 0; k < str.length(); k++) {
                                if(k == j)
                                    out += str.charAt(k) == '0'?'1':'0';
                                else
                                    out += str.charAt(k);
                            }
                            tmp.data.add(out);
                        }
                        tmp.times = next.times + 1;
                        frontier.add(tmp);
                    }
                }
            }
            if(!good){
                System.out.println("Case #" + (i+1) + ": NOT POSSIBLE");
                out.println("Case #" + (i+1) + ": NOT POSSIBLE");
            }
//            System.out.println();
        }

        out.close();
        System.exit(0);
    }
    public static boolean equals(Data a, Data b){
        List<String> aCheck = new ArrayList<String>();
        List<String> bCheck = new ArrayList<String>();
        for (int i = 0; i < a.data.size(); i++) {
            aCheck.add(a.data.get(i));
            bCheck.add(b.data.get(i));
        }
        Collections.sort(aCheck);
        Collections.sort(bCheck);
        for (int i = 0; i < a.data.size(); i++) {
            if(!aCheck.get(i).equals(bCheck.get(i)))
                return false;
        }
        return true;
    }
    static class Data{
        List<String> data = new ArrayList<String>();
        int times = 0;
        public Data(){

        }
        public Data(String[] str){
            for(String str2 : str)
                data.add(str2);
        }
        public int hashCode(){
            String str = "";
            for(String str2 : data){
                str += str2 + " ";
            }
            return str.hashCode();
        }
        public boolean equals(Object other){
            return hashCode() == other.hashCode();
        }
        public String toString(){
            return data.toString();
        }
    }
}

import java.io.*;
import java.util.*;
import static java.lang.System.*;
public class B {
	public static void main (String [] args) throws Exception {new B().run();}
    int INF = 10000000;
    ArrayList<ArrayList<Integer>> con;
    HashMap<Integer, Integer> map;
    int count(int cur, int prev){
        ArrayList<Integer> list = new ArrayList<Integer>(con.get(cur));
        list.remove((Integer)prev);
        int tot = 1;
        for(int i : list)
            tot += count(i, cur);
        return tot;
    }
    int recur(int cur, int prev){
        ArrayList<Integer> list = new ArrayList<Integer>(con.get(cur));
        list.remove((Integer)prev);
        int size = list.size();
        if( size == 0 ) return 0;
        int min = INF;
        {
            int tot = 0;
            for(int j : list){
                tot += count(j, cur);
            }
            min = tot;
        }
        //System.out.println(cur +" keep");
        {
            for(int aa = 0; aa<list.size(); aa++)
                for(int bb= aa+1; bb<list.size(); bb++)
                {int j = list.get(aa), k = list.get(bb);
                        int tot = recur(j, cur) + recur(k, cur);
                        //System.out.println(j +  " " +k + " " + tot);
                        for(int i : list)
                            if( i != j && i!=k){
                                tot += count(i, cur);
                            }
                        min = Math.min(min, tot);
                    }
        }
        return min;
    }
	public void run() throws Exception{
		Scanner file = new Scanner(new File("B-small-attempt0.in.txt"));
		int T = file.nextInt();
        for(int asdf = 0; asdf<T; asdf++){
            out.printf("Case #%d: ",asdf+1);
            con = new ArrayList<ArrayList<Integer>>();
            int n = file.nextInt();
            map = new HashMap<Integer, Integer>();
            for(int i = 0; i<n; i++)
                con.add(new ArrayList<Integer>());
            for(int i= 0; i<n-1; i++){
                int a= file.nextInt()-1, b = file.nextInt()-1;
                con.get(a).add(b);
                con.get(b).add(a);
            }
            int min = INF;
            for(int i = 0; i<n; i++){
                min = Math.min(min, recur(i, -1));
            }
            out.println(min);
		}
	}
}
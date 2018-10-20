import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;


public class GCJPA {
	private static Scanner sc;
    private static PrintWriter out;

    public static void main(String[] args) {

        try {
            sc = new Scanner( new File("/nfs/sgururaj/Downloads/A-small-attempt0.in"));
            out = new PrintWriter("/nfs/sgururaj/Downloads/op.txt", "UTF-8");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        int C = sc.nextInt();
        //l(C);
        for(int test=1; test<=C; test++) {
            int N = sc.nextInt();
            int L = sc.nextInt();
            sc.nextLine();
            String[] o = sc.nextLine().split(" ");
            String []a = sc.nextLine().split(" ");
            //l(C, N, L, o, a);
            int[][] outlets = new int[N][L];
            int[][] apps = new int[N][L];
            for (int i = 0; i <N; i++) {
                for (int j = 0; j < L; j++) {
                    outlets[i][j] = o[i].charAt(j)-'0';
                }
            }
            for (int i = 0; i <N; i++) {
                for (int j = 0; j < L; j++) {
                    apps[i][j] = a[i].charAt(j)-'0';
                }
            }
            int ret = Integer.MAX_VALUE;

            for(int i=0; i<N; i++) {
                //consider the ith outlet
                int[] toggle = new int[L];
                int moves = 0;
                for(int j=0; j<L; j++) {
                    if(outlets[i][j] != apps[0][j]) {
                        toggle[j] = 1;
                        moves++;
                    }
                }
                boolean ok = check(apps, outlets, toggle);
                if(ok) ret = Math.min(ret, moves);
            }
            String pr = "";
            if(ret<Integer.MAX_VALUE) pr = ("Case #"+test+": "+ ret);
            else pr = ("Case #"+test+": NOT POSSIBLE");
            out.println(pr);
            System.out.println(pr);

        }
        out.close();

    }

    private static boolean check(int[][] apps, int[][] outlets, int[] toggle) {
        int N = apps.length, L = apps[0].length;
        boolean[] done = new boolean[N];
        outer:for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(done[j]) continue;
                boolean good = true;
                for(int k=0; k<L; k++) {
                    int cc = outlets[j][k];
                    if(toggle[k]==1) cc = 1-cc;
                    if(cc != apps[i][k]) good = false;
                }
                if(good) {
                    done[j] = true;
                    continue outer;
                }

            }
        }
        for(int i=0; i<done.length; i++) if(!done[i]) return false;
        return true;
    }

    public static void l(Object ...o) {
        String s = "";
        for(Object oo : o) {
            if(oo instanceof int[]) {
                s+=Arrays.toString((int[])oo)+" ";
                continue;
            }
            if(oo instanceof double[]) {
                s+=Arrays.toString((double[])oo)+" ";
                continue;
            }
            if(oo instanceof boolean[]) {
                s+=Arrays.toString((boolean[])oo)+" ";
                continue;
            }
            if(oo instanceof char[]) {
                s+=Arrays.toString((char[])oo)+" ";
                continue;
            }
            if(oo instanceof long[]) {
                s+=Arrays.toString((long[])oo)+" ";
                continue;
            }
            if(oo instanceof String[]) {
                s+=Arrays.toString((String[])oo)+" ";
                continue;
            }
            if(oo instanceof Object[]) {
                s+=Arrays.deepToString((Object[])oo)+" ";
                continue;
            }
            s += (oo.toString())+" ";
        }
        System.out.println(s);
    }
}

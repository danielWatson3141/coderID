package test6;
import java.io.*;
import java.util.*;

public class Test {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    
    static int mines;
    static int N;
    static int L;
    public static void main (String[] args) throws IOException {

        //generateInput(150);
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "test.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "test.out"));

        int tc = sc.nextInt();
        
        for (int tci=1;tci<=tc;tci++) {
            N = sc.nextInt();
            L = sc.nextInt();
            boolean[][] devices = new boolean[N][L];
            boolean[][] outlets = new boolean[N][L];
            int[] devices2 = new int[N];
            for (int i=0;i<N;i++) {
                String s = sc.next();
                for (int j=0;j<L;j++) {
                    outlets[i][j] = s.charAt(j)=='1'?true:false;
                }
            }
            for (int i=0;i<N;i++) {
                String s = sc.next();
                for (int j=0;j<L;j++) {
                    devices[i][j] = s.charAt(j)=='1'?true:false;
                }
                devices2[i] = Integer.parseInt(s, 2);
            }
            Arrays.sort(devices2);
            int[] flip = new int[L];
            boolean impos = false;
            for (int l=0;l<L;l++) {
                int ds = 0;
                int os = 0;
                for (int n=0;n<N;n++) {
                    if (outlets[n][l]) {
                        os++;
                    }
                    if (devices[n][l]) {
                        ds++;
                    }
                }
                if (os==ds && ((float)os)==((float)N)/2) {
                    flip[l] = -1;
                }
                else if (ds==os) {
                    flip[l] = 0;
                }
                else if (ds==N-os) {
                    flip[l] = 1;
                }
                else {
                    impos = true;
                    break;
                }
            }
            if (impos==true) {
                pw.println("Case #" + tci + ": NOT POSSIBLE");
                continue;
            }
            int flips=0;
            for (int l=0;l<L;l++) {
                if (flip[l]==1) {
                    for (int n=0;n<N;n++) {
                        outlets[n][l] = !outlets[n][l];
                    }
                    flips++;
                }
            }
            
            //breadth first
            LinkedList<OutletConfi> list = new LinkedList<OutletConfi>();
            OutletConfi ini = new OutletConfi();
            ini.outlets = outlets;
            ini.flip = flip;
            ini.flips = flips;
            if (checkConfi(ini,devices2)) {
                pw.println("Case #" + tci + ": " + flips);
                continue;
            }
            list.add(ini);
            boolean found = false;
            OutletConfi solution = ini;
            while (!list.isEmpty()&&!found) {
                OutletConfi cur = list.remove();
                for (int l=0;l<L;l++){
                    if (cur.flip[l]==-1){
                        boolean[][] newOutlets = new boolean[N][L];
                        for (int l2=0;l2<L;l2++) {
                            if (l2!=l) {
                                for (int n=0;n<N;n++) {
                                    newOutlets[n][l2] = cur.outlets[n][l2];
                                }
                            }
                            else {
                                for (int n=0;n<N;n++) {
                                    newOutlets[n][l2] = !cur.outlets[n][l2];
                                }
                            }
                        }
                        int[] newflip = new int[L];
                        for (int i=0;i<L;i++) {
                            newflip[i] = cur.flip[i];
                        }
                        newflip[l] = 1;
                        OutletConfi newO = new OutletConfi();
                        newO.outlets = newOutlets;
                        newO.flips = cur.flips+1;
                        newO.flip = newflip;
                        if (checkConfi(newO,devices2)) {
                            solution = newO;
                            found = true;
                        }
                        list.add(newO);
                    }
                }
            }
            if (found) {
                pw.println("Case #" + tci + ": " + solution.flips);
            }
            else {
                pw.println("Case #" + tci + ": NOT POSSIBLE");
            }
        }
        pw.close();
        sc.close();
    }

    static class OutletConfi {
        boolean[][] outlets;
        int[] flip;
        int flips;

    }
    
    static boolean checkConfi (OutletConfi oc, int[] devices) {
        int[] outlets = new int[N];
        for (int n=0;n<N;n++) {
            int outletInt = 0;
            for (int l=0;l<L;l++) {
                if (oc.outlets[n][L-l-1]) {
                    outletInt += Math.pow(2,l);
                }
            }
            outlets[n] = outletInt;
        }
        Arrays.sort(outlets);
        for (int n=0;n<N;n++) {
            if (outlets[n]!=devices[n]) {
                return false;
            }
        }
        return true;
    }
    
    public static void generateInput(int tc) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "test.in"));
        pw.println(tc);
        Random rd = new Random();
        for (int tci = 1; tci <= tc; tci++) {
            int R = rd.nextInt(50)+1;
            int C = rd.nextInt(50)+1;
            int M = rd.nextInt(R*C);
            pw.println(R+" "+C+" "+M);
        }
        pw.close();
    }
}


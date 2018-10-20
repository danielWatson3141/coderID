package gcj2014r1a;

import java.util.Arrays;
import java.util.Scanner;

public class A {

    public static void printArr(int v[]) {
        for (int i = 0; i < v.length; i++) {
            System.out.print(Integer.toString(v[i], 2) + " ");
        }
        System.out.println();
    }
    
    public static int[] count(int o[], int f[], int lim) {
        int c[] = new int[lim];
        for (int i = 0; i < lim; i++) {
            int nv[] = switchArr(f, i);
            Arrays.sort(nv);
            boolean eq = true;
            for (int j = 0; j < o.length; j++) {
                if (o[j] != nv[j]) {
                    eq = false;
                    break;
                }
            }
            if (eq) {
                int x = i;
                while (x > 0) {
                    c[i] += (x & 1);
                    x = x >> 1;
                }
            } else {
                c[i] = Integer.MAX_VALUE;
            }
        }
        return c;
    }
    
    public static int[] switchArr(int v[], int x) {
        int nv[] = new int[v.length];
        for (int i = 0; i < v.length; i++) {
            nv[i] = v[i] ^ x;
        }
        return nv;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            int n = sc.nextInt();
            int l = sc.nextInt();
            int o[] = new int[n];
            for (int i = 0; i < n; i++) {
                o[i] = Integer.parseInt(sc.next(), 2);
            }
            int f[] = new int[n];
            for (int i = 0; i < n; i++) {
                f[i] = Integer.parseInt(sc.next(), 2);
            }
            Arrays.sort(o);
            int c[] = count(o, f, (int)Math.pow(2, l));
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < c.length; i++) {
                if (c[i] < min) {
                    min = c[i];
                }
            }
            System.out.printf("Case #%d: ", t);
            if (min == Integer.MAX_VALUE) {
                System.out.println("NOT POSSIBLE");
            } else {
                System.out.println(min);
            }
        }
    }

}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author quanyang
 */
public class charging {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTC = sc.nextInt();

        for (int i = 1; i <= numTC; i++) {
            int initial = sc.nextInt();
            int bits = sc.nextInt();

            ArrayList<String> initialb = new ArrayList<String>();
            ArrayList<String> expected = new ArrayList<String>();
            for (int x = 0; x < initial; x++) {
                initialb.add(sc.next());
            }
            for (int x = 0; x < initial; x++) {
                expected.add(sc.next());
            }
            if (initialb.size() == expected.size() && expected.containsAll(initialb)) {

                System.out.println("Case #" + i + ": 0");
            } else {
//                System.out.println(initialb);
                int result = recurs(0, initialb, expected, 0);
                if (result>bits){
                    System.out.println("Case #" + i + ": NOT POSSIBLE");
                }else 
                System.out.println("Case #" + i + ": " + result);
            }
//            System.out.println(count);

        }

    }
static int count;
    public static int recurs(int x, ArrayList<String> start, ArrayList<String> expected, int changes) {
        if (x >= start.get(0).length()) {
            return x + x;
        } else {
            ArrayList<String> inc = new ArrayList<String>();
            inc.addAll(start);
            for (int y = 0; y < inc.size(); y++) {
                String buf = inc.remove(y);
                String bit = "" + buf.charAt(x);
                String prebuf = buf.substring(0, x);
                String postbuf = buf.substring(x + 1);
                if (bit.equals("1")) {
                    bit = "0";
                } else {
                    bit = "1";
                }
                buf = prebuf + bit + postbuf;
                inc.add(y,buf);
            }
//System.out.println(inc);
//count++;
            if (inc.size() == expected.size() && inc.containsAll(expected)) {
                return changes + 1;
            } else {
                return Math.min( recurs(x + 1, inc, expected, changes + 1),recurs(x + 1, start, expected, changes));
            }
        }
    }
}

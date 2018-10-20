/*
 * Language = Kotlin 0.7.270
 */

import java.io.*;
import java.util.*;

var LOCAL = File("input.txt").exists();

var _reader = when {
    LOCAL -> BufferedReader(FileReader("input.txt"));
    else -> BufferedReader(InputStreamReader(System.`in`));
}
var out = when {
    LOCAL -> PrintWriter("output.txt");
    else -> PrintWriter(System.`out`);
};
var _tokenizer = StringTokenizer("");

fun readString(): String {
    while (!_tokenizer.hasMoreTokens()) {
        _tokenizer = StringTokenizer(_reader.readLine()!!);
    }
    return _tokenizer.nextToken();
}

fun readInt(): Int {
    return java.lang.Integer.parseInt(readString());
}

fun readLong(): Long {
    return java.lang.Long.parseLong(readString());
}

fun readDouble(): Double {
    return java.lang.Double.parseDouble(readString());
}

fun debug(o: Any) {
    if (LOCAL) {
        System.`err`.println(o);
    }
}

fun main(args: Array<String>) {
    var t1: Long = 0;
    var t2: Long;
    if (LOCAL) {
        t1 = System.currentTimeMillis();
    };
    Locale.setDefault(Locale.US);
    solve();
    _reader.close();
    out.close();
    if (LOCAL) {
        t2 = System.currentTimeMillis();
        debug("Time = " + (t2 - t1));
    };
}

fun dfs(x: Int, p: Int, a: Array<ArrayList<Int>>, dp: IntArray, sumChildren: IntArray) {
    var cnt = 0;
    sumChildren[x] = 1;
    for (y in a[x]) {
        if (y != p) {
            cnt++;
            dfs(y, x, a, dp, sumChildren);
            sumChildren[x] += sumChildren[y];
        }
    }
    if (cnt == 0) {
        dp[x] = 0;
        return;
    }
    if (cnt == 1) {
        dp[x] = sumChildren[x] - 1;
        return;
    }
    var max1 = -100500;
    var max2 = -100500;
    var maxID1 = -1;
    var maxID2 = -1;
    for (y in a[x]) {
        if (y != p) {
            var t = sumChildren[y] - dp[y];
            if (t >= max1) {
                max2 = max1;
                max1 = t;
                maxID2 = maxID1;
                maxID1 = y;
            } else if (t >= max2) {
                max2 = t;
                maxID2 = y;
            }
        }
    }
    dp[x] = 0;
    for (y in a[x]) {
        if (y != p) {
            if (y == maxID1 || y == maxID2) {
                dp[x] += dp[y];
            } else {
                dp[x] += sumChildren[y];
            }
        }
    }
}

fun solve() {
    var tests = readInt()
    for (test in 1 .. tests) {
        out.print("Case #${test}: ");
        var n = readInt();
        var a = Array<ArrayList<Int>>(n) { ArrayList() };
        for (i in 1 .. n-1) {
            var x = readInt() - 1;
            var y = readInt() - 1;
            a[x].add(y);
            a[y].add(x);
        }
        var best = 100500;
        var dp = IntArray(n);
        var sumChildren = IntArray(n);
        for (root in 0..n-1) {
            dp.fill(100500);
            sumChildren.fill(0);
            dfs(root, -1, a, dp, sumChildren);
//            for (i in 0 .. n-1) {
//                if (dp[i] >= sumChildren[i]) {
//                    throw RuntimeException();
//                }
//            }
            //debug(Arrays.toString(dp));
            best = Math.min(best, dp[root]);
        }
        out.println(best);
    }
}

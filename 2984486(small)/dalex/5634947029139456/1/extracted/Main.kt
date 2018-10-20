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

fun solve() {
    var tests = readInt()
    for (test in 1 .. tests) {
        out.print("Case #${test}: ");
        var n = readInt();
        var len = readInt();
        var initial = Array<String>(n) { readString() };
        var required = Array<String>(n) { readString() };
        required.sort();
        var possibleMasks = ArrayList<Long>();
        for (i in initial.indices) {
            for (j in required.indices) {
                var mask = 0L;
                for (bit in 0 .. len-1) {
                    if (initial[i][bit] != required[j][bit]) {
                        mask = (mask or (1L shl bit));
                    }
                }
                possibleMasks.add(mask);
            }
        }
        var ans = 100500;
        for (mask in possibleMasks) {
            var bc = java.lang.Long.bitCount(mask);
            var after = Array<CharArray>(n) { CharArray(len) };
            for (i in 0 .. n-1) {
                after[i] = CharArray(len);
                for (j in 0 .. len-1) {
                    after[i][j] = initial[i][j];
                }
            }
            for (bit in 0 .. len-1) {
                if ((mask and (1L shl bit)) != 0L) {
                    for (i in 0 .. n-1) {
                        if (after[i][bit] == '0') {
                            after[i][bit] = '1';
                        } else {
                            after[i][bit] = '0';
                        }
                    }
                }
            }
            var afterStrs = Array<String>(n) { i -> String(after[i]) };
            afterStrs.sort();
            var ok = true;
            for (i in 0 .. n-1) {
                if (afterStrs[i] != required[i]) {
                    ok = false;
                }
            }
            if (ok) {
                ans = Math.min(ans, bc);
            }
        }
        if (ans == 100500) {
            out.println("NOT POSSIBLE");
        } else {
            out.println(ans);
        }
        System.`err`.println("Test ${test} completed");
    }
}

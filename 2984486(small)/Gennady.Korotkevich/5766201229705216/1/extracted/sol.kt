/**
 * @author: tourist
 */

import java.io.*
import java.util.*

var g = Array<ArrayList<Int>>(0, {_ -> ArrayList<Int>()});
var was = BooleanArray(0)

fun dfs(v: Int) : Int {
    was[v] = true
    var cnt = g[v].size()
    var a = ArrayList<Int>()
    for (j in 0..cnt-1) {
        var u = g[v].get(j)
        if (!was[u]) {
            a.add(dfs(u))
        }
    }
    if (a.size() <= 1) {
        return 1
    }
    Collections.sort(a)
    return 1 + a[a.size() - 2] + a[a.size() - 1]
}

fun solve(sc: InputReader, out: PrintWriter) {
	val testCases = sc.nextInt()
	for (test in 1..testCases) {
		out.print("Case #$test: ")
        val n = sc.nextInt()
        g = Array<ArrayList<Int>>(n, {_ -> ArrayList<Int>()});
        for (i in 0..n-2) {
            val foo = sc.nextInt() - 1
            val bar = sc.nextInt() - 1
            g[foo].add(bar)
            g[bar].add(foo)
        }
        was = BooleanArray(n)
        var ans = 0
        for (st in 0..n-1) {
            for (i in 0..n-1) {
                was[i] = false
            }
            val cur = dfs(st)
            if (cur > ans) {
                ans = cur
            }
        }
        out.println(n - ans)
	}
}

fun main(args: Array<String>) {
    val taskName = "b"
	var input: InputStream = System.`in`
	var output: OutputStream = System.out
	val file = File("src/" + taskName + "/in")
	if (file.canRead()) {
		input = FileInputStream(file)
		output = FileOutputStream("src/" + taskName + "/out")
	}
	val sc = InputReader(input)
	val out = PrintWriter(output)
	solve(sc, out)
	out.close()
}

class InputReader (r: InputStream) {
	private val br = BufferedReader(InputStreamReader(r))
	private var st: StringTokenizer? = null

	fun nextToken(): String? {
		while (st == null || !st!!.hasMoreTokens()) {
			val line = br.readLine()
			if (line == null) {
				return null
			}
			st = StringTokenizer(line)
		}
		return st!!.nextToken()
	}

    fun nextInt(): Int {
        return nextToken()!!.toInt()
    }

    fun nextLong(): Long {
        return nextToken()!!.toLong()
    }

	fun nextDouble(): Double {
		return nextToken()!!.toDouble()
	}
}

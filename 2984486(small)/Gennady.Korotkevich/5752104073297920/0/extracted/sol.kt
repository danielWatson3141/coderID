/**
 * @author: tourist
 */

import java.io.*
import java.util.*

fun solve(sc: InputReader, out: PrintWriter) {
    val n = 1000
    var f = Array(n) { Array(n) {0.toDouble()} }
    var k = DoubleArray(n)
    var b = DoubleArray(n)
    for (i in 0..n-1) {
        f[i][i] = 1.0
        k[i] = 1.0
        b[i] = 0.0
    }
    var p: Double = (n - 1).toDouble() / n
    var q: Double = 1.toDouble() / n
    for (it in 0..n-1) {
        for (i in 0..n-1) {
            val add = (k[i] * f[i][it] + b[i]) * q
            k[i] = k[i] * p
            b[i] = b[i] * p + add
            f[i][it] = (q - b[i]) / k[i]
        }
    }
    for (i in 0..n-1) {
        for (j in 0..n-1) {
            f[i][j] = k[i] * f[i][j] + b[i]
        }
    }
    System.out.println("done")
	val testCases = sc.nextInt()
	for (test in 1..testCases) {
		out.print("Case #$test: ")
        val n = sc.nextInt()
        var a = IntArray(n)
        for (i in 0..n-1) {
            a[i] = sc.nextInt()
        }
        var prob = 1.toDouble()
        for (i in 0..n-1) {
            prob *= f[a[i]][i] * n
        }
        out.println(if (prob > 0.5) "BAD" else "GOOD")
	}
}

fun main(args: Array<String>) {
    val taskName = "c"
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

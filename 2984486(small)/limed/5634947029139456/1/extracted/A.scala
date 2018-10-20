import scala.collection._

object A extends App {

  def tokenizeLine = new java.util.StringTokenizer(readLine)
  def readInts(n: Int) = { val t = tokenizeLine; Array.fill(n)(t.nextToken.toInt) }
  def readLongs(n: Int) = { val t = tokenizeLine; Array.fill(n)(t.nextToken.toLong) }
  def readBigs(n: Int) = { val t = tokenizeLine; Array.fill(n)(BigInt(t.nextToken)) }

  def toLong(s: String): Long = {
    var l = 1L
    for (c <- s) {
      l <<= 1
      if (c == '1') l += 1
    }
    l
  }

  def toLong(len: Int, s: String, flips: String): Long = {
    var l = 1L
    for (i <- 0 until len) {
      l <<= 1
      if (s(i) != flips(i)) l += 1
    }
    l
  }

  def solve(test: Int) = {

    val Array(n, l) = readInts(2)
    val as = readLine.split(" ").sorted
    val bs = readLine.split(" ").sorted

    val bPrefixCounts = (0 until l).flatMap(pos => bs.map(s => toLong(s.take(pos + 1))))
      .groupBy(identity).mapValues(_.size).withDefaultValue(0)
    val have0s = (0 until l).map(pos => as.map(_(pos)).count(_ == '0'))
    val need0s = (0 until l).map(pos => bs.map(_(pos)).count(_ == '0'))

    def getPrefixCounts(len: Int, flips: String) = {
      //println("getPrefixCounts", len, flips)
      as.map(s => toLong(len, s, flips)).groupBy(identity).mapValues(_.size)
    }

    def verify(prefixCounts: Map[Long, Int]): Boolean = {
      prefixCounts.forall { case (p, cnt) => bPrefixCounts(p) == cnt }
    }

    def check(len: Int, flips: String): Int = {
      //println(len, flips)
      if (len == l) flips.count(_ == '1')
      else {
        val for0 = if (need0s(len) == have0s(len) && verify(getPrefixCounts(len + 1, flips + "0"))) {
          check(len + 1, flips + "0")
        } else Int.MaxValue
        val for1 = if (n - need0s(len) == have0s(len) && verify(getPrefixCounts(len + 1, flips + "1"))) {
          check(len + 1, flips + "1")
        } else Int.MaxValue
        for0 min for1
      }
    }

    val res = check(0, "")
    val res2 = if (res == Int.MaxValue) "NOT POSSIBLE" else res.toString

    println(s"Case #$test: $res2")
  }

  Console.setIn(new java.io.BufferedInputStream(new java.io.FileInputStream("A/A-large.in")))
  Console.setOut(new java.io.BufferedOutputStream(new java.io.FileOutputStream("A/A-lerge.out")))
  for (test <- 1 to readInt) solve(test)
  Console.flush
}

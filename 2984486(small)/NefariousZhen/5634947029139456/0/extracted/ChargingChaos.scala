package com.nefariouszhen.codejam._2014.rnd1a

object ChargingChaos {
  def main(args: Array[String]) {
    val in = io.Source.stdin.getLines()
    val T = in.next().toInt
    for (testCase <- 1 to T) {
      val n :: l :: _ = in.next().split(" ").map(_.toLong).toList
      val os = in.next().split(" ")
      val is = in.next().split(" ").map(fromStringToLong).toSet

      var minKnown = l + 1
      for (t <- 0 to ((1 << l) - 1)) {
        val s = t.toBinaryString.reverse
        val oss = os.map(o => flip(o, s)).map(fromStringToLong).toSet
        if (oss == is) {
          minKnown = math.min(minKnown, s.count(c => c == '1'))
        }
      }

      println("Case #%d: %s".format(testCase, if (minKnown > l) "NOT POSSIBLE" else minKnown))
    }
  }

  def fromStringToLong(s: String): Long = java.lang.Long.parseLong(s, 2)
  def flip(i: String, f: String): String = {
    var o = i.toCharArray
    var j = 0
    while (j < i.length && j < f.length) {
      if (f(j) == '1') {
        o(j) = if (o(j) == '0') '1' else '0'
      }
      j += 1
    }
    o.mkString
  }
}

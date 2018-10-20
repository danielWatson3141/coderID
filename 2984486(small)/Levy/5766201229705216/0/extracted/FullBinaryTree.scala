package round1a

import scala.collection.mutable.ArrayBuffer

object FullBinaryTree extends App with util.IO {
  override val testcase = "attempt1"

  def solve(n: Int, edges: Array[Array[Int]]): Int = {
    def tryRoot(c: Int, p: Int): Int = {
      val es = edges(c).filter(_ != p)
      if (es.length < 2)
        return 1
      val subs = es.map { s => tryRoot(s, c) }.sortBy(-_)
      1 + subs(0) + subs(1)
    }

    var maxNodes = 1
    for (root <- 0 until n) {
      val t = tryRoot(root, -1)
      if (t > maxNodes) maxNodes = t
    }
    n - maxNodes
  }

  val cases = read[Int]
  for (c <- 1 to cases) {
    val n = read[Int]
    val edges = Array.fill(n)(ArrayBuffer[Int]())

    for (i <- 1 until n) {
      val (a, b) = readTuple[Int, Int]
      edges(a - 1) += b - 1
      edges(b - 1) += a - 1
    }

    puts(s"Case #$c: ${solve(n, edges.map(_.toArray))}")
  }
}

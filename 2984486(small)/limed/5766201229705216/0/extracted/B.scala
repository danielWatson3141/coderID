import scala.collection._

object B extends App {

  def tokenizeLine = new java.util.StringTokenizer(readLine)
  def readInts(n: Int) = { val t = tokenizeLine; Array.fill(n)(t.nextToken.toInt) }
  def readLongs(n: Int) = { val t = tokenizeLine; Array.fill(n)(t.nextToken.toLong) }
  def readBigs(n: Int) = { val t = tokenizeLine; Array.fill(n)(BigInt(t.nextToken)) }

  def solve(test: Int) = {

    val Array(n) = readInts(1)
    val neighbours = Array.fill(n) { mutable.ArrayBuffer.empty[Int] }

    for (i <- 1 to n - 1) {
      val Array(u, v) = readInts(2)
      neighbours(u - 1) += (v - 1)
      neighbours(v - 1) += (u - 1)
    }
    
    def size(from: Int, parent: Int): Int = {
      1 + neighbours(from).filter(_ != parent).map(v => size(v, from)).sum
    }
    
    def deletions(from: Int, parent: Int): Int = {
      val children = neighbours(from).filter(_ != parent)
      if (children.size == 0) 0
      else if (children.size == 1) size(children.head, from)
      else { // >= 2
        val dels = children.map(v => deletions(v, from))
        val sizes = children.map(v => size(v, from))
        val sumSizes = sizes.sum
        var minDel = Int.MaxValue
        for (a <- children.indices; b <- a + 1 until children.size) {
          minDel = minDel min (dels(a) + dels(b) + sumSizes - sizes(a) - sizes(b))
        }
        minDel
      }
    }
    
    var res = Int.MaxValue
    for (root <- 0 until n) {
      res = deletions(root, -1) min res
    }

    println(s"Case #$test: $res")
  }

  Console.setIn(new java.io.BufferedInputStream(new java.io.FileInputStream("B/B-small-attempt1.in")))
  Console.setOut(new java.io.BufferedOutputStream(new java.io.FileOutputStream("B/B-small.out")))
  for (test <- 1 to readInt) solve(test)
  Console.flush
}

package com.nefariouszhen.codejam._2014.rnd1a

import scala.collection.mutable

object FullBinaryTree {
  def main(args: Array[String]) {
    val in = io.Source.stdin.getLines()
    val T = in.next().toInt
    for (testCase <- 1 to T) {
      val N = in.next().toInt
      val e = mutable.HashMap[Int, mutable.Set[Int]]()
      for (_ <- 1 until N) {
        val i :: j :: _ = in.next().split(" ").map(_.toInt).toList
        e.getOrElseUpdate(i, mutable.Set()) += j
        e.getOrElseUpdate(j, mutable.Set()) += i
      }

      var minFound = N - 1
      for (t <- 0 to ((1 << N) - 1)) {
        val sp = "0" + t.toBinaryString.reverse
        val s = sp + ("0" * (1 + N - sp.length))
        // pick root
        for (r <- e.keys if s(r) == '1') {
          // dfs
          val seen = mutable.HashSet[Int]()
          def dfs(r: Int, p: Int): Boolean = {
            val children = e(r).filter(i => s(i) == '1')
            if (r == p && children.size != 0 && children.size != 2) {
//              println("root has wrong num children: " + children.size)
              return false
            } else if (r != p && children.size != 3 && children.size != 1) {
//              println("(%d, %d) node has wrong num children: %d".format(r, p, children.size))
              return false
            }
            if (seen.contains(r)) {
//              println("already seen: " + r)
              return false
            }
            seen += r
            for (child <- children) {
              if (child != p && !dfs(child, r)) return false
            }

            true
          }

          val isGood = dfs(r, r)
          val all = e.keys.filter(i => s(i) == '1')
//          println("%d %s %d %s %s %s".format(t, s, r, isGood, seen, all))
          if (isGood && seen == all) {
            minFound = math.min(minFound, N - s.count(c => c == '1'))
          }
        }
      }

      println("Case #%d: %d".format(testCase, minFound))
    }
  }
}

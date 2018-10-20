package com.nefariouszhen.codejam._2014.rnd1a

import scala.util.Random
import scala.collection.mutable

object ProperShuffle {
  def main(args: Array[String]) {
    val in = io.Source.stdin.getLines()
    val T = in.next().toInt
    for (testCase <- 1 to T) {
      val N = in.next().toInt
      val ns = in.next().split(" ").map(_.toInt).zipWithIndex

      if (ns.find({ case (i, v) => i == v }).isDefined) {
        println("Case #%d: BAD".format(testCase))
      } else {
        println("Case #%d: GOOD".format(testCase))
      }
    }
  }

  def tryGenSample(args: Array[String]) {
    /*
    for k in 0 .. N-1:
  a[k] = k
for k in 0 .. N-1:
  p = randint(0 .. N-1)
  swap(a[k], a[p])
     */

    val cnt = mutable.HashMap[String, Int]()
    val N = 5
    val a = Array.ofDim[Int](N)
    for (k <- 0 until N)
      a(k) = k

    for (_ <- 0 until 100000) {
      var r = ""
      for (k <- 0 until N) {
        val p = Random.nextInt(N)
        val o = a(k)
        a(k) = a(p)
        a(p) = o
        r += p.toString
      }

      val k = a.mkString(" ")
      cnt.put(k, cnt.getOrElse(k, 0) + 1)
    }

    cnt.toArray.sortBy(_._2).foreach(println)
  }
}

package com.dhe32.codejam

import scala.io.Source
import Utils._
import scala.math._
import scala.collection._

object Round1A {
  def main(args: Array[String]) = {
    val r = charginChaos()
    println(r)
  }

  case class St() {

  }
  def charginChaos(data: Source = getResource("tmp.in")) = {
    def doz(xs: IndexedSeq[Long], ys: IndexedSeq[Long], L: Int) = {
      val N = xs.length
      def numbits(x: Long) = {
        var s = 0
        for (i <- 0 until 64)
          if ((x & (1L << i)) != 0L)
            s += 1
        s
      }
      val M = for (i <- 0 to (1 << L)) yield {
        val zs = ys map (_ ^ i);
        if (xs == zs.sorted)
          Some(numbits(i))
        else
          None
      }
      M.flatten.sorted.headOption
    }
    val lines = data.getLines()
    val T = lines.next.toInt
    val ts = for { i <- 0 until T } yield {
      val zs = lines.next split " "
      val N = zs(0).toInt
      val L = zs(1).toInt
      def zoBitSet(xs: String) = {
        var xs2 = 0L
        for ((c, i) <- xs.zipWithIndex)
          if (c == '1')
            xs2 |= (1 << i)
        xs2
      }
      val xs = lines.next split " " map zoBitSet
      val ys = lines.next split " " map zoBitSet
      val t = doz(xs.sorted, ys, L) 
      val t2 = t match {
        case Some(i) => i.toString
        case None => "NOT POSSIBLE"
      }
      s"Case #${i + 1}: $t2\n"
    }
    ts.mkString
  }
}
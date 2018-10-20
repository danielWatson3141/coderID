package com.dhe32.codejam

import scala.io.Source
import Utils._
import scala.math._
import scala.collection._

object Round1A {
  def main(args: Array[String]) = {
    val r = fullBinaryTree()
    println(r)
  }

  def memoize[A, B](f: A => B) = {
    val M = mutable.Map.empty[A, B]
    a: A => M getOrElseUpdate (a, f(a))
  }

  def memoizeY[A, B](f: (A, A => B) => B) = {
    var yf: A => B = null
    yf = memoize(f(_, yf(_)))
    yf
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

  def fullBinaryTree(data: Source = getResource("tmp.in")) = {
    val G = mutable.Buffer[mutable.Set[Int]]()

      val lines = data.getLines
      val T = lines.next.toInt
      val ts = for {x <- 1 to T} yield {
        G.clear
        val N = lines.next.toInt
        for (i <- 0 until N) G += mutable.Set.empty
        for {i <- 0 until N - 1} {
          val zs = (lines.next split " ") map (_.toInt)
          G(zs(0) - 1) += zs(1) - 1
          G(zs(1) - 1) += zs(0) - 1
        }
        
    val f = memoizeY(
      (z: (Int, Int), f: ((Int, Int)) => (Int, Int)) => {
        val (u, p) = z
        val vs = G(u) filterNot (_ == p)
        val zs = vs.toList map (v => f(v, u))
        val s = (zs map (_._1)).sum
        val t = if (vs.size == 0)
          0
        else if (vs.size == 1)
          s
          else
          (zs map (_._2)).sum
        //println(z, (s + 1, t))
        (s + 1, t)
      })
        var rs = for {
          i <- 0 until N
          j <- -1 :: G(i).toList
          if (j != -1 || G(i).size < 3)
        } yield {
          val z = f(i, j)
          val w = if (j != -1) f(j, i) else (0, 0)
          val r0 = z._2 + w._1
          r0
        }
        val r = rs.min
        s"Case #${x}: $r\n"
      }
      ts.mkString
  }
}
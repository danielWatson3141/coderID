package lascala.codejam.fourteen.one.a

import org.specs2.mutable._
import scala.io.Source
import scalax.io.Resource
import scala.annotation.tailrec
import scala.util.Random

class ASpec extends Specification {
  def main(lines:Iterator[String]) = {
    val cases = lines.next().toInt

    val output = Resource.fromFile("codejam.out")
    output.truncate(0)

    (1 to cases).foreach {
      (num) =>
        val NL = lines.next().split(" ").map(_.toInt)
        val initial = lines.next().split(" ").toList
        val expected = lines.next().split(" ").toList
        val y = solve(NL(1), initial, expected)
        output.write(s"Case #$num: ${toY(y)}\n")
    }
  }

  def toY(y:Int) = y match {
    case -1 => "NOT POSSIBLE"
    case _ => y
  }

  def pows:Stream[Int] = 1 #:: pows.map( _ << 1)

  def solve(L:Int, initial:List[String], expected:List[String]) = {
    val init = initial.map(Integer.parseInt(_,2))
    val expe = expected.map(Integer.parseInt(_, 2))
    val diff = init.diff(expe)
    val flipping = 0 to (pows.take(L).sum)

    println(flipping)
    val counted = flipping.map{ (complement) =>
      val complemented = init.map( _ ^ complement)

      val count = (complemented diff expe).size

      (count, complement)
    }.filter(_._1 == 0).map(_._2)

    if( counted.size == 0) -1
    else {
      val binStrings = counted.map(_.toBinaryString)
      println(binStrings)

      val result = binStrings.map( (s:String)=> s.filter( _ == '1').size)
      println(result)
      result.min
    }
  }

  "Samples" should {
    "pass 1" in {
      skipped
      val initial = List("01", "11", "10")
      val expected = List("11", "00", "10")

      solve(2, initial, expected) must be_==(1)
      ok
    }
    "pass 2" in {
      skipped
      val initial = List("101", "111")
      val expected = List("010", "001")
      solve(3, initial, expected) must be_==(-1)
      ok
    }
    "pass 3" in {
      skipped
      val initial = List("01", "10")
      val expected = List("10", "01")

      solve(2, initial, expected) must be_==(0)
      ok
    }
    "pass 4" in {
      skipped
      ok
    }
    "pass for large" in {
      skipped
      ok
    }
  }

  "It" should {
    "pass sample" in {
      skipped
      val lines = Source.fromURL(this.getClass.getResource("sample.in")).getLines()
      main(lines)
      ok
    }
    "pass small" in {
      val lines = Source.fromURL(this.getClass.getResource("A-small-attempt0.in")).getLines()
      main(lines)
      ok
    }
    "pass large" in {
      skipped
      val lines = Source.fromURL(this.getClass.getResource("D-large.in")).getLines()
      main(lines)
      ok
    }
  }
}

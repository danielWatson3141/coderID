package uk.me.jamespic.codejam

import java.util.concurrent.ThreadLocalRandom
import scala.io.Source
import java.io.FileWriter

object FisherYates {
  def rand = ThreadLocalRandom.current
  def swap(array: Array[Int], n: Int, m: Int) = {
    array(n) ^= array(m)
    array(m) ^= array(n)
    array(n) ^= array(m)
  }

  def goodFisherYates(n: Int) = {
    val array = (0 until n).toArray
    for (k <- 0 until n) {
      val p = rand.nextInt(k, n)
      swap(array, k, p)
    }
    array
  }

  def badFisherYates(n: Int) = {
    val array = (0 until n).toArray
    for (k <- 0 until n) {
      val p = rand.nextInt(0, n)
      swap(array, k, p)
    }
    array
  }

  def score(array: Array[Int]) = {
    val n = array.length
    val biases = for ((v, i) <- array.zipWithIndex) yield {
      if (v < i) 1 else 0
    }
    (biases.sum.toDouble / n) - 0.5
  }

  def findThreshold(trials: Int, iterations: Int) = {
    val goodScores = for (i <- 1 to trials) yield score(goodFisherYates(iterations))
    val badScores = for (i <- 1 to trials) yield score(badFisherYates(iterations))
    val strengths = for (score <- goodScores) yield {
      val strength = goodScores.count(_ > score) + badScores.count(_ < score)
      (score, strength / (2.0 * trials))
    }
    strengths.maxBy(_._2)
  }

  def judge(array: Array[Int]) = {
    if (score(array) < -0.016000000000000014) "BAD" else "GOOD"
  }

  def main(args: Array[String]) = {
    val source = Source.fromFile(args(0)).getLines
    val output = new FileWriter(args(1))
    try {
      val count = source.next.toInt
      for (i <- 1 to count) {
        val n = source.next.toInt
        val array = source.next.split(" ").map(_.toInt)
        val judgment = judge(array)
        output.write(s"Case #$i: $judgment\n")
        println(s"Case #$i: $judgment\n")
      }
    } finally {
      output.close()
    }
  }
}
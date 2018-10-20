package shuffle

import collection.JavaConversions._
import collection.JavaConverters._
import collection.mutable.ListBuffer

object Shuffle{
  def read(file: String) = {
    val s = io.Source.fromFile(file)
    val c = s.getLines.toList.tail.grouped(2).map{_(1).split(" ").toList.map{_.toInt}}
    s.close
    c
  }

  def write(output: Iterator[String], file: String){
    val buf = new java.io.BufferedWriter(new java.io.FileWriter(file))
    val res = output.zipWithIndex.map{case (v, i) => s"Case #${i+1}: $v"}.mkString("\n")
    println(res)
    buf.write(res)
    buf.close
  }

  def solve(input: ListBuffer[Int], target: List[Int], k: Int): Int = {
    if(k >= input.size) return 0
    val n = if(input(k) == target(k)) 1 else 0
    val j = input.indexOf(target(k))
    val tmp = input(j)
    input.update(j, input(k))
    input.update(k, tmp)
    n + solve(input, target, k + 1)
  }

  def solve(input: List[Int]): String = {
    if(solve(ListBuffer(input.sorted : _*), input, 0) > math.log(input.size)) "BAD" else "GOOD"
  }

  def main(args: Array[String]){
    write(read(args(0)).map{solve}, "outshuffle")
  }

}

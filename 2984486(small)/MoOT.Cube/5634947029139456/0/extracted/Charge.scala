package charging

import collection.JavaConversions._

object Charge{
  def read(file: String) = {
    val s = io.Source.fromFile(file)
    val c = s.getLines.toList
    s.close
    c
  }

  def write(output: Seq[String], file: String){
    val buf = new java.io.BufferedWriter(new java.io.FileWriter(file))
    val res = output.zipWithIndex.map{case (v, i) => s"Case #${i+1}: $v"}.mkString("\n")
    println(res)
    buf.write(res)
    buf.close
  }

  def test(devices: Seq[(Int, Seq[Int])], toCharge: Seq[Int], i: Int, l: Int): Int = {
    val b = Integer.parseInt(("1" + "0"*i), 2)
    // println(b)
    if(i < l) test(
      devices ++ devices.map{case (_i, d) => (_i+1, d.map{_ ^ b}.sorted)}, toCharge, i+1, l)
    else {
      val m = devices.filter(_._2 == toCharge).map{_._1}
      if(m.size > 0) return m.min else -1
    }
  }

  def solve(input: Seq[String]): String = {
    val (n, l) = input.head.split(" ").toList match { case (n :: l :: _) => (n.toInt, l.toInt)}
    val devices = input.tail.head.split(" ").toSeq.map{Integer.parseInt(_, 2)}.sorted
    val toCharge = input.tail.tail.head.split(" ").toSeq.map{Integer.parseInt(_, 2)}.sorted
    // println(devices)
    // println(toCharge)
    val res = test(Seq((0, devices)), toCharge, 0, l)
    if(res == -1)"NOT POSSIBLE" else res.toString
  }

  def main(args: Array[String]){
    val input = read(args(0)).tail.grouped(3)
    write(input.map{solve}.toSeq, "outcharging")
  }
}

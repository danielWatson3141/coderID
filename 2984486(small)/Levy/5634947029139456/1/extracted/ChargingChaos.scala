package round1a

object ChargingChaos extends App with util.IO {
  override val testcase = "large"
    
  def solve(n: Int, l: Int, outlets: Array[String], devices: Array[String]): Option[Int] = {
    var answer = Option.empty[Int]
    val deviceSet = devices.toSet
    for (i <- 0 until n) {
      val flip = Array.tabulate(l) { j => if (outlets(i)(j) == devices(0)(j)) 0 else 1 }
      val flipped = for (o <- outlets) yield {
        o.toCharArray.zip(flip).map { case (a, b) =>
          if (a == '0') {
            if (b == 1) '1' else '0'
          }
          else {
            if (b == 1) '0' else '1'
          }
        }.mkString
      }
      if (flipped.toSet == deviceSet) {
        val count = flip.count(_ == 1)
        if (answer == None || answer.get > count)
          answer = Some(count)
      }
    }
    answer
  }
  
  val cases = read[Int]
  for (c <- 1 to cases) {
    val (n, l) = readTuple[Int, Int]
    val outlets = readArray[String]
    val devices = readArray[String]
    
    solve(n, l, outlets, devices) match {
      case Some(x) => puts(s"Case #$c: $x")
      case None => puts(s"Case #$c: NOT POSSIBLE")
    }
  }
}

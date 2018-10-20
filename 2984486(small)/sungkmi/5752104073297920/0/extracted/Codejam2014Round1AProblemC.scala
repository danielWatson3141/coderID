package codejam

object Codejam2014Round1AProblemC extends App {

  val Ref = 325000
  
  def isGood(seq: IndexedSeq[Int]): Boolean = {
    val move: Int = (for {
	 i<- 0 until seq.size
	} yield (math.abs(seq(i)-i))).sum
	
	move > Ref
  }
  
  def process(iter: Iterator[String])(println: String => Unit) =
    for (i <- 1 to iter.next().toString.toInt) yield {
      val n = iter.next().toInt
      val seq = iter.next().split(' ').map(_.toInt)
      println(s"Case #$i: ${if (isGood(seq)) "GOOD" else "BAD"}")
    }
  
  import java.io._
  val out = new PrintStream(new File("c.out"))
  try {
    process(io.Source.fromFile("C-small-attempt1.in").getLines) { s: String =>
      out.println(s)
    }
  } finally {
    out.flush; out.close
  }

}
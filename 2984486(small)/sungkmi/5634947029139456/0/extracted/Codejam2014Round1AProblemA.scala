package codejam

object Codejam2014Round1AProblemA extends App {

  implicit def stringToBigIntSet(s: String): Set[BigInt] = s.split(' ').map(BigInt(_, 2)).toSet

  def from(n: BigInt): Stream[BigInt] = n #:: from(n + 1)

  def countMinFlip(l: Int, ini: Set[BigInt], goal: Set[BigInt]): Option[Int] = {
    
    val result = for {
      n <- from(0).take(1 << l) if ini.map { _ ^ n } == goal
    } yield n.bitCount

    result.headOption
  }

  def process(iter: Iterator[String])(println: String => Unit) =
    for (i <- 1 to iter.next().toString.toInt) yield {
      val Array(n, l) = iter.next.split(' ').map(_.toInt)
      println(s"Case #$i: ${countMinFlip(l, iter.next(), iter.next()).getOrElse("NOT POSSIBLE")}")

    }

  import java.io._
  val out = new PrintStream(new File("a.out"))
  try {
    process(io.Source.fromFile("A-small-attempt1.in").getLines) { s: String =>
      out.println(s)
    }
  } finally {
    out.flush; out.close
  }

}
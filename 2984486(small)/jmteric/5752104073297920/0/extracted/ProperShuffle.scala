import java.io.PrintWriter
import scala.io.Source

object ProperShuffle extends App {

  val name = "C-small-attempt2.in"
  val out = new PrintWriter(s"target/$name.out.txt")
  val lines = Source.fromInputStream(getClass.getResourceAsStream(name)).getLines()

  val caseCount = lines.next().toInt

  for (n <- 1 to caseCount) {
    lines.next() //ignore
    var data = lines.next().split(' ').map(_.toInt)

    val sampleSize = data.size / 3.0

    val lowIndexes = for ((x, i) <- data.zipWithIndex if x < sampleSize) yield i
    val lowAvg = lowIndexes.sum / lowIndexes.size.toDouble


    val highIndexes = for ((x, i) <- data.zipWithIndex if x >= (data.length - sampleSize)) yield i
    val highAvg = highIndexes.sum / highIndexes.size.toDouble

    val gap = (highAvg - lowAvg) / data.size

    println(gap)

    val result = if (gap > .02) "BAD" else "GOOD"

    out.println(s"Case #$n: $result")
  }
  out.close()

}

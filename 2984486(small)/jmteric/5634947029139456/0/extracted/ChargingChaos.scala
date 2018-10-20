import java.io.PrintWriter
import scala.io.Source

object ChargingChaos extends App {

  val name = "A-small-attempt0.in"
  val out = new PrintWriter(s"target/$name.out.txt")
  val lines = Source.fromInputStream(getClass.getResourceAsStream(name)).getLines()

  val caseCount = lines.next().toInt


  def works(outlets: IndexedSeq[Seq[Boolean]], devices: IndexedSeq[Seq[Boolean]]): Boolean = {
    var remainingOutlets = outlets
    var remainingDevices = devices
    var couldWork = true
    while (couldWork && !remainingDevices.isEmpty) {
      val device = remainingDevices.head
      remainingDevices = remainingDevices.tail
      val index = remainingOutlets.indexWhere(_ == device)
      if (index == -1) {
        couldWork = false
      } else {
        remainingOutlets = remainingOutlets.take(index) ++ remainingOutlets.drop(index+1)
      }
    }
    couldWork
  }

  def flip(outlets: IndexedSeq[Seq[Boolean]], index: Int): IndexedSeq[Seq[Boolean]] = {
    for (outlet <- outlets) yield {
      for ((currentState, i) <- outlet.zipWithIndex) yield {
        if (i == index) !currentState else currentState
      }
    }
  }

  def min(outlets: IndexedSeq[Seq[Boolean]], devices: IndexedSeq[Seq[Boolean]], nextIndex: Int, alreadySwapped: Int): Option[Int] = {
    if (works(outlets, devices)) Some(alreadySwapped)
    else {
      val size = outlets.head.length
      if (nextIndex == size) None

      val results = for (i <- nextIndex until size) yield {
        val newOutlets =flip(outlets, i)
        min(newOutlets, devices, i+1, alreadySwapped+1)
      }

      val output = results.flatten.toList
      if (output.isEmpty) None
      else Some(output.min)
    }
  }


  for (n <- 1 to caseCount) {
    val countLine = lines.next().split(' ').map(_.toInt)
    val (count, length) = (countLine(0), countLine(1))

    val outlets = lines.next().split(' ').map(_.map(_ == '1'))
    val devices = lines.next().split(' ').map(_.map(_ == '1'))

    val answer = min(outlets, devices, 0, 0)



    val result = answer.getOrElse("NOT POSSIBLE")
    out.println(s"Case #$n: $result")
  }
  out.close()

}

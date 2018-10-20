import com.sun.org.apache.xpath.internal.functions.FuncFalse
import java.io.{FileWriter, File}
import scala.annotation.tailrec
import scala.io.Source

object ChargingChaos {




  def main(args: Array[String]): Unit = {
    val inputFiles = Source.fromFile("input.txt").getLines()

    val result = new File("output.txt")

    val writer = new FileWriter(result)

    val cases = inputFiles.next().toInt

    @tailrec
    def bits (i: Long, sofar: Int): Int = if (i==0) sofar else bits (i >> 1, (1 & i).toInt + sofar)

    for (i <- 1 to cases) {

      val info = inputFiles.next().split(' ').map(_.toInt)
      val N = info(0)
      val L = info(1)

      val flow = inputFiles.next().split(' ').map(Integer.parseInt(_,2)).toSet
      val devices = inputFiles.next().split(' ').map(Integer.parseInt(_,2)).toSet

      def valid(switch:Int): Boolean =
      {
        for (device <- devices)
          if (!flow.contains(device ^ switch))
            return false

        return true

      }

      var minSwitch : Int = Int.MaxValue
      for (device <- devices)
        for (flowOption <- flow)
        {
          val switch = device ^ flowOption

          if (valid(switch))
          {
            //println(switch)
            minSwitch = math.min(minSwitch,bits(switch,0))
          }


        }





      println(minSwitch)

      if (minSwitch == Int.MaxValue)
        writer.write(s"Case #$i: NOT POSSIBLE\n")
      else
        writer.write(s"Case #$i: $minSwitch\n")
    }


    writer.close()
  }
}

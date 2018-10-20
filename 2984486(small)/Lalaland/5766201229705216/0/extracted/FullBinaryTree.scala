import java.io.{FileWriter, File}
import scala.io.Source

object FullBinaryTree {





  def main(args: Array[String]): Unit = {
    val inputFiles = Source.fromFile("input.txt").getLines()

    val result = new File("output.txt")

    val writer = new FileWriter(result)

    val cases = inputFiles.next().toInt



    for (i <- 1 to cases) {
      val neighbors = collection.mutable.Map[Int,List[Int]]()
      val N = inputFiles.next().toInt
      val edges = for (i <- 0 until N-1) yield
      {
        val result = inputFiles.next().split(' ').map(_.toInt)
        neighbors.put(result(0),result(1) :: neighbors.getOrElse(result(0),Nil))
        neighbors.put(result(1),result(0) :: neighbors.getOrElse(result(1),Nil))
        (result(0),result(1))
      }


      val memo = collection.mutable.Map[(Int,Int),Int]()

      def countValidChildren(prev:Int, current:Int): Int  =
      {


        val neigh = neighbors.get(current).get.filterNot(_ == prev)
        //println("p",prev,current,neigh)
        if (neigh.size == 0 || neigh.size == 1)
          0
        else
        {
          val possibilities = for (possib <- neigh)
            yield {countValidChildren(current,possib) + 1}
          println(possibilities)
          val sorted = possibilities.sorted.reverse
          val best = sorted(0)
          val secondBest = sorted(1)
          best +secondBest
        }

      }

      val options = for (root <- 1 to N)
      yield {
        println(root,countValidChildren(0,root))
        countValidChildren(0,root) + 1


      }

      print(options)
      val result = N - options.max
      println("done",result)


      writer.write(s"Case #$i: $result\n")
    }


    writer.close()
  }
}

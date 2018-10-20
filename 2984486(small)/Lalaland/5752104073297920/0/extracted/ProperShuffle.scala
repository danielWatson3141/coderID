import java.io.{FileWriter, File}
import scala.io.Source
import scala.util.Random

object ProperShuffle {

  def realRandom(): List[Int] =
  {
    val f = (0 until 1000).toArray

    def swap(i:Int,j:Int): Unit =
    {
      val temp = f(j)
      f(j) = f(i)
      f(i) = temp
    }

    for (i <- 0 until 1000)
    {
      swap(i,i+Random.nextInt(1000-i))
    }

    f.toList
  }

  def testRandom(): List[Int] =
  {
    val f = (0 until 1000).toArray

    def swap(i:Int,j:Int): Unit =
    {
      val temp = f(j)
      f(j) = f(i)
      f(i) = temp
    }

    for (i <- 0 until 1000)
    {
      swap(i,Random.nextInt(1000))
    }

    f.toList
  }
  def main(args: Array[String]): Unit = {
    val inputFiles = Source.fromFile("input.txt").getLines()

    val result = new File("output.txt")

    val writer = new FileWriter(result)

    val cases = inputFiles.next().toInt



    def count(l:List[Int]): Int =
    {
      var counter = 0
      for ( (number,i) <- l.zipWithIndex)
      {
        val dist =(1000+(i - number)) % 1000
        counter += dist
        //counters.put(dist,counters.getOrElse(dist,0)+1)
      }

       counter

    }

    //println( (0 until 100).map(a=> if (count(realRandom()) < 515000) 1 else 0).sum/100.0)
    //println( (0 until 100).map(a=> if (count(testRandom()) >= 515000) 1 else 0).sum/100.0)

    for (i <- 1 to cases) {
      val N = inputFiles.next().toInt
      val numbers = inputFiles.next().split(' ').map(_.toInt).toList

      val total = count(numbers)

      if (total < 515000)
        writer.write(s"Case #$i: GOOD\n")
      else
        writer.write(s"Case #$i: BAD\n")



    }


    writer.close()
  }
}

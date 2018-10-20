import java.io.PrintWriter
import scala.collection.mutable
import scala.io.Source



object FullBinaryTree extends App {

  val name = "B-large.in"
  val out = new PrintWriter(s"target/$name.out.txt")
  val lines = Source.fromInputStream(getClass.getResourceAsStream(name)).getLines()

  val caseCount = lines.next().toInt



  for (n <- 1 to caseCount) {
    val nodeCount = lines.next().toInt

    val graph = collection.mutable.Map[Int, collection.mutable.Set[Int]]()

    for (i <- 1 to nodeCount) {
      graph.put(i, collection.mutable.Set[Int]())
    }

    for (i <- 1 to nodeCount-1) yield {
      val edge = lines.next().split(' ').map(_.toInt)
      graph(edge(0)).add(edge(1))
      graph(edge(1)).add(edge(0))
    }


    def nodesInTree(root: Int, parent: Set[Int]): Int = {
      val children = graph(root) -- parent

      if (children.size < 2) 1
      else {
        val childCounts = children.toSeq.map(c => nodesInTree(c, Set(root)))
        1 + childCounts.sorted.reverse.take(2).sum
      }
    }

    val reachableCounts = for(i <- 1 to nodeCount) yield nodesInTree(i, Set())

    val result = nodeCount - reachableCounts.max


    out.println(s"Case #$n: $result")
  }
  out.close()

}

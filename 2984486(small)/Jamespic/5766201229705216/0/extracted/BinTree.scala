package uk.me.jamespic.codejam
import scala.collection.mutable.{Map => MMap, ListBuffer}
import scala.collection.breakOut
import scala.io.Source
import java.io.FileWriter
import scala.collection.immutable.BitSet

object BinTree {
  type Tree = Map[Int, Node]
  case class Node(name: Int, connections: Set[Int])
  //val notRoots = BitSet(0, 1, 3)
  def buildTree(links: Seq[(Int, Int)]) = {
    val nodeBuilder = scala.collection.mutable.Map.empty[Int, ListBuffer[Int]]
    def addLink(a: Int, b: Int) = {
      nodeBuilder.getOrElseUpdate(a, ListBuffer.empty[Int]) += b
    }
    for ((a, b) <- links) {
      addLink(a, b)
      addLink(b, a)
    }

    nodeBuilder.map{case (node, links) => node -> Node(node, links.result().toSet)}.toMap
  }

  def countCuts(tree: Tree, node: Node, parent: Option[Int]): Int = {
    // Should we memo-ize this? It's still only o(n^2)
    val children = node.connections -- parent
    //println(s"Node ${node.name} has children ${children} with parent $parent")
    children.size match {
      case 0 => 0
      case 2 => children.map{child => countCuts(tree, tree(child), Some(node.name))}.sum
      case 1 => kill(tree, tree(children.head), Some(node.name))
      case _ =>
        val costs = children.map{child =>
          val killCost = kill(tree, tree(child), Some(node.name))
          val pruneCost = countCuts(tree, tree(child), Some(node.name))
          val saving = killCost - pruneCost
          (saving, killCost, pruneCost)
          }
        // If 3 or more, keep most expensive nodes
        val sorted = costs.toList.sortBy(_._1)
        val killed = sorted.dropRight(2).map(_._2).sum
        val cut = sorted.takeRight(2).map(_._3).sum
        killed + cut
    }
  }

  def kill(tree: Tree, node: Node, parent: Option[Int]): Int = {
    val children = node.connections -- parent
    return 1 + children.map{child => kill(tree, tree(child), Some(node.name))}.sum
  }

  def findMinDeletions(tree: Tree) = {
    if (tree.size <= 1) 0
    else {
      val candidates = tree.values//.filter(node => !notRoots.contains(node.connections.size))
      val deletions = for (root <- candidates) yield {
        val cuts = countCuts(tree, root, None)
        //println(s"From node $root we cut $cuts nodes")
        cuts
      }
      if (deletions.isEmpty) 0 else deletions.min
    }
  }

  def main(args: Array[String]) = {
    val source = Source.fromFile(args(0)).getLines
    val output = new FileWriter(args(1))
    try {
      val count = source.next.toInt
      for (i <- 1 to count) {
        val nodeCount = source.next.toInt
        val linkData = for (j <- 1 to nodeCount - 1) yield {
          val Array(a, b) = source.next.split(" ").map(_.toInt)
          a -> b
        }
        val tree = buildTree(linkData)
        val deletions = findMinDeletions(tree)
        output.write(s"Case #$i: $deletions\n")
        //println(s"Case #$i")
        //println(linkData)
        println(s"Case #$i: $deletions")
      }
    } finally {
      output.close()
    }
  }
}
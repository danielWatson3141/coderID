import scala.collection.mutable.ArrayBuffer

object B {
  
	import scala.util.control.Breaks._

//  case class Functional[T](obj: T) {
//    def |>[R] (f: T => R) = f(obj)
//  }
//  implicit def functionals[T](obj: T): Functional[T] = Functional(obj)
  
  def main(args: Array[String]) {
    
    val nbCases = readInt
    
    for (iCase <- 1 to nbCases)
    {
    	val N = readInt
    	
//    	val edges = new Array[(Int,Int)](N+1)
//    	edges(0) = null
//      for (i <- 1 to N) {
//        val Array(xi,yi) = readLine.split(" ").map(_.toInt)
////        edges(i) = readLine.split(" ").map(ar => (ar(0).toInt, ar(1).toInt))
//        edges(i) = (xi,yi)
//      }
    	
//    	val edges = Array.fill[ArrayBuffer[Int]](new ArrayBuffer[Int]())
    	val edges = Array.fill(N+1)(new ArrayBuffer[Int]())
    	edges(0) = null
    	for (i <- 1 until N) { // N-1 iterations
    		val Array(xi,yi) = readLine.split(" ").map(_.toInt)
    		edges(xi) += yi
    		edges(yi) += xi
    	}
    	
    	val cache = collection.mutable.Map[(Int,Int), Int]()
    	
    	def nbSubNodes(subRoot: Int, parent: Int): Int = {
    	  cache.getOrElseUpdate((subRoot, parent),
    	    edges(subRoot).foldLeft(0)((acc,vert) => if (vert == parent) acc else acc+1+nbSubNodes(vert, subRoot)))
    	}
    	
    	val cache2 = collection.mutable.Map[(Int,Int), Int]()
    	
    	def minDels(subRoot: Int, parent: Int): Int = {
    	  cache2.getOrElseUpdate((subRoot, parent), {
	//    	  if (edges(root).size == 0) 0
	//    	  else 
	    	  val edgeSet = edges(subRoot)
	    	  edgeSet.size match {
	    	    case 0 => throw new Error("No parent?") // ???
	    	    case 1 => if (edgeSet(0) == parent) 0 else nbSubNodes(edgeSet(0), subRoot)
	//    	    case 1 => 1 + nbSubNodes(edge(0)) //minDels(edge(0)) + 1
	    	    case 2 => {
//	    	      1 + (if (edgeSet(0) == parent) nbSubNodes(edgeSet(1), subRoot) else nbSubNodes(edgeSet(0), subRoot))
//	    	      parent match {
//	    	        case (edgeSet(0)) => 0
//	    	      }
	    	      if (parent == edgeSet(0)) 1 + nbSubNodes(edgeSet(1), subRoot)
	    	      else if (parent == edgeSet(1)) 1 + nbSubNodes(edgeSet(0), subRoot)
	    	      else minDels(edgeSet(0), subRoot) + minDels(edgeSet(1), subRoot)
	    	    }
	//    	    case 2 => minDels(edge(0)) + minDels(edge(1))
	    	    case n => {
//	//    	      val minDels: ArrayBuffer[(Int,Int)] = edge.map(i=>(i,minDels(i)))
//	    	      val minDs = edgeSet.filter(_ != parent).map(i => (i, minDels(i, subRoot)))
//	//    	      minDs.sortBy((node,minD) => )
//	//    	      minDs.sorted(_._2 < _._2)
//	    	      val sorted = minDs.sortWith(_._2 < _._2)
	    	      
	    	      val sorted = edgeSet.view.filter(_ != parent).map(i => (i, minDels(i, subRoot))).sortWith(_._2 < _._2)
	    	      
	//    	      val sum = sorted.slice(2, sorted.size).foldLeft(0)((acc,node_minD) => acc+node_minD._2)
	    	      val sum = sorted.slice(2, sorted.size).foldLeft(0)((acc,node_minD) => acc + nbSubNodes(node_minD._1, subRoot))
	    	      
	    	      sorted(0)._2 + sorted(1)._2 + sum
	    	    }
	    	  }
    	  })
    	}
    	
    	var globMin = Int.MaxValue
    	
    	for (root <- 1 to N) {
    	  
    	  val dels = minDels(root, -1)
    	  
    	  if (dels < globMin)
    	    globMin = dels
    	  
    	}
    	
    	
      
	    println("Case #"+iCase+": "+globMin)
    }
    
    
    
  }
  
}



























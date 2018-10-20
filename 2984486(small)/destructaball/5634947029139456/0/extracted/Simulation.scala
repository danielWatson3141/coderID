import scala.collection.immutable.HashSet
import scala.collection.mutable

object Simulation{
  var device:Set[mutable.WrappedArray[Boolean]] = null
  def main(args: Array[String]){
    val n = readLine.toInt
    for(i <- 1 to n){
      readLine
      val supplyR:List[mutable.WrappedArray[Boolean]] = wrapper(readLine.split(" ").map(_.map(a=> if(a=='1') true else false).toArray).toList)
      device = wrapper(readLine.split(" ").map(_.map(a=> if(a=='1') true else false).toArray).toList).toSet
      println("Case #" + i + ": " + (if(works(supplyR)) "" + 0
      else{
        val a:Int = (1 until supplyR.head.length).toStream.map(a => permutations(supplyR, a)).indexOf(true)
        if(a == -1) "NOT POSSIBLE"
        else "" + (a + 1)
      }))
    }
  }
  def wrapper(a:List[Array[Boolean]], output:List[mutable.WrappedArray[Boolean]]=Nil):List[mutable.WrappedArray[Boolean]] ={
    if(a.isEmpty) output
    else{
      wrapper(a.tail, a.head :: output)
    }
  }
  def permutations(a:List[mutable.WrappedArray[Boolean]], negNum:Int, partition:Int=0):Boolean = {
    var success = false
    for(i <- partition to (a(0).length - negNum)){
      negateCol(a,i)
      if(negNum>1) success = success || permutations(a, negNum-1, i+1)
      else success = success || works(a)
      negateCol(a,i)
    }
    success
  }

  def negateCol(a:List[mutable.WrappedArray[Boolean]], t:Int){
    if(!a.isEmpty){
      a.head(t) = !a.head(t)
      negateCol(a.tail, t)
    }
  }
  def works(a:List[mutable.WrappedArray[Boolean]]): Boolean ={
    if(a.isEmpty) true
    else if(device.contains(a.head)) works(a.tail)
    else false
  }
}

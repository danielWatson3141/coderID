object A {
  
	import scala.util.control.Breaks._

  case class Functional[T](obj: T) {
    def |>[R] (f: T => R) = f(obj)
  }
  implicit def functionals[T](obj: T): Functional[T] = Functional(obj)
  
  def nbOnes(n: Long) = {
    var ret = 0
    var tmp = n
    for (i <- 1 to 64) {
      if (tmp%2 == 1)
        ret += 1
      tmp /= 2
    }
    ret
  }
  
  def main(args: Array[String]) {
    
    val nbCases = readInt
    
    for (iCase <- 1 to nbCases)
    {
//      val (name, n) = readLine.split(" ") |> (line => (line(0), line(1).toInt))
      val Array(n, l) = readLine.split(" ").map(_.toInt)
//      val outlets = readLine.split(" ").toLong()
//      java.lang.Long.parseLong("0", 10)
      
//      val outlets, devices = readLine.split(" ").map(java.lang.Long.parseLong(_.substring(0,l/2), 2), java.lang.Long.parseLong(_.substring(l/2), 2))
      val outlets, devices = readLine.split(" ").map(
          str => (java.lang.Long.parseLong(str.substring(0,l/2), 2), java.lang.Long.parseLong(str.substring(l/2), 2)))
      
      def switchesFor(outlet: (Long,Long), device: (Long,Long)): (Long,Long) = {
        (outlet._1 ^ device._1, outlet._2 ^ device._2)
      }
      
      val dev = devices(0)
      var minSwitches = -1
		  for (i <- 0 until n)
		  {
		  	val sw = switchesFor(outlets(i), dev)
		  	val switchedOutlets = outlets.map(d => (d._1 ^ sw._1, d._2 ^ sw._2))
		  	var nbIte = 1
		  	breakable { for (j <- 1 until n) {
		  	  if (!switchedOutlets.contains(devices(j)))
		  	  	break
//	  	  	else if (j == n-1) {
//	  	  	  val switches = nbOnes(sw)
//	  	  	  if (minSwitches > switches || minSwitches < 0)
//	  	  	    minSwitches = switches
//	  	  	}
		  	  nbIte+=1
		  	}}
		  	if (nbIte == n) {
  	  	  val switches = nbOnes(sw._1) +  nbOnes(sw._2)
  	  	  if (minSwitches > switches || minSwitches < 0)
  	  	    minSwitches = switches
  	  	}
		  }
      
	    println("Case #"+iCase+": "+(if (minSwitches < 0) "NOT POSSIBLE" else minSwitches))
    }
    
    
    
  }
  
}














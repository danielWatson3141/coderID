import scala.collection.mutable

object A extends Solver {
  import in._
  override def inputFile = "A-small-attempt0.in"

  type Flow = mutable.BitSet
  case class Problem(n: Int, l: Int, outlets: Set[Flow], devices: Set[Flow]) {

    def flip(i: Int) = {
      require(0 <= i && i < l)
      outlets foreach {s => if (s(i)) {s -= i} else {s += i}}
    }

    def isPossible = outlets == devices
  }

  override type Input = Problem

  override def parseInput = {
    val (n, l) = (nextInt, nextInt)
    def parseFlow =  List.fill(n)(next) map { s =>
      val b = new Flow(l)
      s.zipWithIndex foreach {case (c, i) => if (c == '1') b += i}
      b
    }
    Problem(n, l, parseFlow.toSet, parseFlow.toSet)
  }

  override def apply(input: Input) = {
    val master = (0 until input.l).toList
    val ans = (0 until input.l) find {x =>
      master.combinations(x) exists { c =>
        c foreach input.flip
        val res = input.isPossible
        c foreach input.flip
        res
      }
    }
   ans getOrElse "NOT POSSIBLE"
  }
}
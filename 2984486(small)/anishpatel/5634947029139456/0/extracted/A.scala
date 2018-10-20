
object A extends App {
  val whitespace = raw"\s+".r
  val input = io.Source.stdin.getLines().flatMap(whitespace.split)
  val T = input.next().toInt
  for (x <- 1 to T) {
    val N = input.next().toInt
    val L = input.next().toInt
    val initFlows = Array.fill(N) { Integer.parseInt(input.next(), 2) }.toSet
    val reqFlows = Array.fill(N) { Integer.parseInt(input.next(), 2) }.toSet

//    def flip(i: Int) = currFlows map (f => f ^ 1 << i)

    val nPossibilities = (0 until L) map (math.pow(2, _).toInt) sum
    var minNFlips = L + 1
    for (p <- 0 until nPossibilities) {
      var currFlows = initFlows
      var nFlips = 0
      for (i <- 0 until L if ((p >> i) & 1) == 1) {
        currFlows = currFlows map (f => f ^ 1 << i)
        nFlips += 1
      }
      if (currFlows == reqFlows) minNFlips = minNFlips min nFlips
    }

    val y = if (minNFlips > L) "NOT POSSIBLE" else minNFlips
    println(s"Case #$x: $y")
  }
}

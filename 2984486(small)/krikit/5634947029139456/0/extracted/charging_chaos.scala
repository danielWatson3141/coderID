object charging_chaos extends App {
  def solve(N: Int, L: Int, outlets: List[Int], devices: List[Int]): String = {
    val sorted_devices = devices.sorted

    def is_match(flip: Int): Boolean = {
      val flipped_outlets = outlets.map(_ ^ flip).sorted
      flipped_outlets == sorted_devices
    }

    var min_bit_count = L+1
    for (flip <- 0 until Math.pow(2, L).toInt) {
      if (is_match(flip)) {
        val bit_count = Integer.bitCount(flip)
        if (bit_count < min_bit_count) min_bit_count = bit_count
      }
    }
    
    if (min_bit_count == L+1) "NOT POSSIBLE"
    else min_bit_count.toString
  }

  //////////
  // main //
  //////////
  if (args.length > 0) Console.setIn(new java.io.FileInputStream(args(0)))
  if (args.length > 1) Console.setOut(new java.io.FileOutputStream(args(1)))

  for (t <- 1 to readInt) {
    val nl = readLine.split(" ").map(_.toInt).toList
    val outlets = readLine.split(" ").map(Integer.parseInt(_, 2)).toList
    val devices = readLine.split(" ").map(Integer.parseInt(_, 2)).toList
    println("Case #" + t + ": " + solve(nl(0), nl(1), outlets, devices))
  }
}
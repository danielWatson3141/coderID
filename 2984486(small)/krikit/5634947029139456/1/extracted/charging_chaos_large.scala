object charging_chaos_large extends App {
  def solve(N: Int, L: Int, outlets: List[String], devices: List[String]): String = {
    def make_flip(outlet: String, device: String): String = {
      val flip_list = for (pair <- outlet zip device) yield pair match {
        case (o, d) => (if (o == d) '0' else '1')
      }
      flip_list.mkString
    }

    def make_flips(device: String): Set[String] = (for (outlet <- outlets) yield make_flip(outlet, device)).toSet

    val flips = for (device <- devices) yield make_flips(device)
    val common_flips = flips.reduce(_ & _).toList.sorted
    common_flips match {
      case Nil => "NOT POSSIBLE"
      case head :: tail => head.count(_ == '1').toString
    }
  }

  //////////
  // main //
  //////////
  if (args.length > 0) Console.setIn(new java.io.FileInputStream(args(0)))
  if (args.length > 1) Console.setOut(new java.io.FileOutputStream(args(1)))

  for (t <- 1 to readInt) {
    val nl = readLine.split(" ").map(_.toInt).toList
    val outlets = readLine.split(" ").toList
    val devices = readLine.split(" ").toList
    println("Case #" + t + ": " + solve(nl(0), nl(1), outlets, devices))
  }
}
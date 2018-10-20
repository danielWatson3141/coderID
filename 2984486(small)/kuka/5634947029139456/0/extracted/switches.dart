import "dart:io";
import "dart:math";

countbits(x) {
  var n = 0;
  while (x > 0) {
    x = x & ~(x ^ (x - 1));
    n++;
  }
  return n;
}

void main() {
  File f = new File('A-small-attempt0 (1).in'); //minesweeper.txt');
  var it = f.readAsLinesSync().iterator..moveNext();
//  var tests = [
//      "3",
//      "3 2",
//      "01 11 10",
//      "11 00 10",
//      "2 3",
//      "101 111",
//      "010 001",
//      "2 2",
//      "01 10",
//      "10 01"];
//  var it = tests.iterator..moveNext();
  var T = int.parse(it.current);
  for (var i = 0; i < T  && it.moveNext(); i++) {
    var l = it.current.split(" "); it.moveNext();
    var N = int.parse(l[0]);
    var L = int.parse(l[1]);
    List outlets = it.current.split(" "); it.moveNext();
    var devices = new Set();
    devices.addAll(it.current.split(" ").map((x) => int.parse(x, radix: 2)));
    
//    print("Case ${i+1} N=$N L=$L, outlets=$outlets, devices=$devices");
    
    var minflips = null;
    for (var b = 0; b < 1<<L; b++) {
//      print(b);
      var newoutlets = new Set();
      newoutlets.addAll(outlets.map((x) => int.parse(x, radix: 2) ^ b));
//      print("$newoutlets");
      if (newoutlets.containsAll(devices)) {
        var flips = countbits(b);
        if (minflips == null || flips < minflips) {
          minflips = flips;
          if (minflips == 0) {
            break;
          }
        }
//        print("found $b");
      }
    }
    
    print("Case #${i+1}: ${minflips != null? minflips: 'NOT POSSIBLE'}");
  }
}

readInt();
var a = readInts();

var p = 0;

p = a.reduce(function(prev, curr, index) {
  if (index == 0)
    return 0;
  return prev + Math.abs(curr - index);
}, 0);

log(p / ((a.length * (a.length -1)) /2));

if (p / ((a.length * (a.length -1)) /2) > 0.666666666666) {
  print('GOOD');
} else {
  print('BAD');
}

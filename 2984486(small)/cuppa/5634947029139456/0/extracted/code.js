
var max = readInts()[1];
var first = readStrings();
var orig = first.slice();
first = first.map(function (current) {
  current = current.split("");
  return current;
});
orig = orig.map(function (current) {
  current = current.split("");
  return current;
});
var second = readStrings();
results = [];

function success()  {
  return second.every(function (current) {
      return first.map(function (a) {
        return a.join("");
      }).indexOf(current) > -1;
  });
}
function flip(a) {
  first = first.map(function (current) {
    current[a] = current[a] === '1' ? '0' : '1';
    return current;
  });
}

Array.prototype.copy = function () {
  return this.map(function (arr) {
    return arr.slice();
  });
};
Array.prototype.min = function() {
  return Math.min.apply(null, this);
};

function char_buffer_rec(number, n, len) {
    if(n > 0) {
        number[len-n] = '0';
        char_buffer_rec(number, n - 1, len);
        number[len-n] = '1';
        char_buffer_rec(number, n - 1, len);
    }
    else {
      var k = 0;
      for (var j = 0; j < number.length; j++) {
        if (number[j] == 1) {
          k++;
          flip(j);
        }
      }
      if (success()) {
        results.push(k);
      }
      
      first = orig.copy();
    }
}
number = [];
char_buffer_rec(number, max, max);

if (results.length === 0) {
  print('NOT POSSIBLE');
} else {
  print(results.min());
}

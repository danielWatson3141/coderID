"use strict";
function randInt(max) {
    return Math.floor(Math.random() * max);
}

var fs = require('fs');
var assert = require('assert');

function permBad() {
  var a = new Array(1000);
  var ii;
  for (ii = 0; ii < 1000; ++ii) {
    a[ii] = ii;
  }
  for (ii = 0; ii < 1000; ++ii) {
    var p = randInt(1000);
    var t = a[ii];
    a[ii] = a[p];
    a[p] = t;
  }
  return a;
}

function permGood() {
  var a = new Array(1000);
  var ii;
  for (ii = 0; ii < 1000; ++ii) {
    a[ii] = ii;
  }
  for (ii = 0; ii < 1000; ++ii) {
    var p = randInt(1000 - ii);
    var t = a[ii];
    a[ii] = a[p+ii];
    a[p+ii] = t;
  }
  return a;
}

if (!fs.existsSync('c.json')) {
  (function() {
    var dist = new Array(1000);
    var ii;
    for (ii = 0; ii < 1000; ++ii) {
      dist[ii] = new Array(1000);
      var jj;
      for (jj = 0; jj < 1000; ++jj) {
        dist[ii][jj] = 0;
      }
    }
    var c = 0;
    while (true) {
      var a = permBad();
      for (ii = 0; ii < a.length; ++ii) {
        dist[a[ii]][ii]++;
      }
      c++;
      if (c % 10000 === 0) {
        console.log(c);
        fs.writeFileSync('c.json', JSON.stringify(dist));
      }
    }
  }());
}

if (!fs.existsSync('C-test.in')) {
  (function () {
    var lines = ['2000'];
    var a;
    for (var ii = 0; ii < 1000; ++ii) {
      a = permGood();
      lines.push('1000');
      lines.push(a.join(' '));
    }
    for (ii = 0; ii < 1000; ++ii) {
      a = permBad();
      lines.push('1000');
      lines.push(a.join(' '));
    }
    fs.writeFileSync('C-test.in', lines.join('\n'));
  }());
}

var dist, count;
(function () {
  dist = JSON.parse(fs.readFileSync('c.json', 'utf8'));
  count = 0;
  for (var ii = 0; ii < 1000; ++ii) {
    count += dist[0][ii];
  }
  //console.log(count);
  for (ii = 0; ii < 1000; ++ii) {
    //var row_sum = 0;
    for (var jj = 0; jj < 1000; ++jj) {
      dist[jj][ii] = (dist[jj][ii] / count) * 1000;
      //row_sum += dist[jj][ii];
    }
    //console.log(row_sum);
  }
  //console.log(require('util').inspect(dist));
}());

module.exports = function doit(tok) {
  var N = Number(tok());
  assert.ok(N === 1000);
  var ii;
  var pgood = 1;
  var pbad = 1;
  for (ii = 0; ii < N; ++ii) {
    var v = Number(tok());
    pgood *= 1;
    pbad *= dist[v][ii];
    //console.log(dist[v][ii], pbad);
  }
  //console.log(pgood, pbad);
  if (pbad > pgood) {
    return "BAD";
  } else {
    return "GOOD";
  }
};

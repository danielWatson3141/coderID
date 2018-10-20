"use strict";
var _ = require('lodash');
module.exports = function doit(tok) {
  var N = Number(tok());
  var L = Number(tok());
  var plugs = [], devices = [], devm = {};
  var ii;
  for (ii = 0; ii < N; ++ii) {
    plugs.push(parseInt(tok(), 2));
  }
  for (ii = 0; ii < N; ++ii) {
    var d = parseInt(tok(), 2);
    devices.push(d);
    devm[d] = true;
  }
  
  function numb(v) {
    var r = 0;
    while (v) {
      if (v & 1) {
        r++;
      }
      v = v >> 1;
    }
    return r;
  }
  
  var max = 1<<L;
  var best = -1;
  for (ii = 0; ii < max; ++ii) {
    var good = true;
    //console.log(ii);
    for (var jj = 0; jj < plugs.length; ++jj) {
      if (!devm[plugs[jj] ^ ii]) {
        //console.log(jj, plugs[jj], plugs[jj] ^ ii);
        good = false;
        break;
      }
    }
    if (good) {
      var nb = numb(ii);
      if (best === -1 || nb < best) {
        best = nb;
      }
    }
  }
  if (best === -1) {
    return 'NOT POSSIBLE';
  }
  return best;
};

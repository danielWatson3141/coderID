"use strict";
module.exports = function doit(tok) {
  var N = Number(tok());
  var graph = new Array(N);
  var children = new Array(N);
  var ii;
  for (ii = 0; ii < N; ++ii) {
    graph[ii] = new Array(N);
    children[ii] = [];
  }
  var M;
  for (ii = 0; ii < N-1; ++ii) {
    var a = Number(tok())-1;
    var b = Number(tok())-1;
    graph[a][b] = 1;
    graph[b][a] = 1;
    children[a].push(b);
    children[b].push(a);
  }
  var memod = {};
  function delRoot(elem, parent) {
    var ii;
    var key = elem + '_' + parent;
    if (memod[key]) {
      return memod[key];
    }
    var best = 1;
    var c = children[elem];
    for (ii = 0; ii < c.length; ++ii) {
      if (c[ii] === parent) {
        continue;
      }
      best += delRoot(c[ii], elem);
    }
    memod[key] = best;
    return best;
  }
  var memo = {};
  function fixRoot(elem, parent) {
    var ii;
    var key = elem + '_' + parent;
    if (memo[key]) {
      return memo[key];
    }
    //console.log('fixRoot(' + elem + ', ' + parent + ')');
    var cost_to_del = [];
    var cost_to_fix = [];
    var c = children[elem];
    var ci=0;
    var best = 0;
    for (ii = 0; ii < c.length; ++ii) {
      if (c[ii] === parent) {
        continue;
      }
      cost_to_fix[ci] = fixRoot(c[ii], elem);
      cost_to_del[ci] = delRoot(c[ii], elem);
      best += cost_to_del[ci];
      ++ci;
    }
    if (cost_to_fix.length >= 2) {
      var v;
      if (1) {
        // find best set of 2 to keep
        var vals = [];
        for (ii = 0; ii < cost_to_fix.length; ++ii) {
          vals.push({
            delta: cost_to_fix[ii] - cost_to_del[ii],
            idx: ii
          });
        }
        vals.sort(function (a, b) {
          return a.delta - b.delta;
        });
        v = cost_to_fix[vals[0].idx] + cost_to_fix[vals[1].idx];
        for (ii = 2; ii < cost_to_fix.length; ++ii) {
          v += cost_to_del[vals[ii].idx];
        }
        if (v < best) {
          best = v;
        }
      } else {
        // brute force to compare
        for (ii = 0; ii < cost_to_fix.length; ++ii) {
          var jj;
          for (jj = ii+1; jj < cost_to_fix.length; ++jj) {
            v = cost_to_fix[ii] + cost_to_fix[jj];
            var kk;
            for (kk = 0; kk < cost_to_fix.length; ++kk) {
              if (kk !== ii && kk !== jj) {
                v += cost_to_del[kk];
              }
            }
            if (v < best) {
              best = v;
            }
          }
        }
      }
    }
    //console.log('fixRoot(' + elem, parent + ') = ' + best);
    memo[key] = best;
    return best;
  }
  var best = N-1;
  var besti = 'del';
  if (N>=3) {
    best = N-3;
  }
  for (ii = 0; ii < N; ++ii) {
    var v = fixRoot(ii, null);
    if (v <= best) {
      best = v;
      besti = ii;
    }
  }
  //console.log(besti);
  return best;
};

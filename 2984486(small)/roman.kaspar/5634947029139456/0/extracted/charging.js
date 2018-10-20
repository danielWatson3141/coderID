// debugging
var DEBUG = process.argv.length > 2;
function debug() { if (DEBUG) console.log.apply(console.log, arguments); }
function dVal(val, msg) { debug(msg?msg+val:val); return val; }

// reading input line-by-line
var readline = require('readline');

// pipe-in the test file
var rd = readline.createInterface({
  input: process.stdin,
  output: new require('stream').Writable()
});

// test-related global variables
var TEST_TOTAL = 0;
var TEST_CUR = 0;

// global variables used by processPuzzle()
var N = 0, L, DEVS, FLOWS;

// input reading loop
rd.on('line', function(line) {
  if (!TEST_TOTAL) TEST_TOTAL = parseInt(line, 10);
  else {
    // first data line usually some header info
    if (!N) {
      var arr = line.split(' ');
      // parse the elements
      N = parseInt(arr[0], 10);
      L = parseInt(arr[1], 10);
      DEVS = 0;
    } else if (!DEVS) {
      DEVS = line.split(' ');
      FLOWS = 0;
    } else if (!FLOWS) {
      FLOWS = line.split(' ');
      // used for reporting results
      TEST_CUR++;
      // all data for current test ready
      processPuzzle();
      // make sure to reset header info, so it is re-read
      N = 0;
    }
  }
});

// adjust all currents to make given device happy on given outlet/flow, adjust
// all the remaining outlets accordingly.
// return { bits: number of bits changed, flows: adjusted flows }
function flipSwitches(curDev, curFlow) {
  debug('adjusting:', curDev, curFlow);
  var i, j, s, orig, bits = 0, flows = [];
  var changed = []; // changed bits
  // init bits & changed
  for (i = 0; i < L; i++) {
    if (curDev[i] !== curFlow[i]) {
      changed.push(i);
      bits++;
    }
  }
  debug('indices of changed bits:', changed);
  // generate new flows:
  for (j = 0; j < N; j++) {
    s = '';
    orig = FLOWS[j];
    for (i = 0; i < L; i++) {
      if (-1 === changed.indexOf(i)) s = s + orig[i]; // same
      else { // switched
        if ('0' === orig[i]) s = s + '1';
        else s = s + '0';
      }
    }
    // creating dictionary:
    flows.push(s);
  }
  debug('bits changed:', bits);
  debug('adj. flows:', flows);
  return { bits: bits, flows: flows };
}

// test if we can charge all devs we have with adjusted flows:
function canCharge(adj) {
  debug('can use this?');
  for (var d = 0; d < N; d++) { // d-th device
    if (-1 === adj.indexOf(DEVS[d])) {
      debug('no :-(');
      return false;
    }
  }
  debug('yes!');
  return true;
}

// processing function: the core
function processPuzzle() {

  debug('N:', N);
  debug('L:', L);
  debug('DEVS:', DEVS);
  debug('FLOWS:', FLOWS);

  var res = Infinity;

  for (var d = 0; d < N; d++) { // each device
    for (var f = 0; f < N; f++) { // each flow
      var adj = flipSwitches(DEVS[d], FLOWS[f]);
      if (canCharge(adj.flows)) {
        if (adj.bits < res) {
          res = adj.bits;
        }
      }
    }
  }

  // print puzzle result
  console.log('Case #' + TEST_CUR + ': ' +
    ((res < Infinity) ? res : 'NOT POSSIBLE'));
}

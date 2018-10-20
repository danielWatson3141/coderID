// Damn this got way too complex. I'm sorry.

var _ = require('./lib/underscore.js');
_.extend(global, require('./lib/util.js'));

function rs(si, cb) {

  var n = scanf('%d');
  var l = scanf('%d');
  
  var outlets = [], devices = []; var flips = 0;
  scanf('%line'); var l1 = scanf('%line').split(' '), l2 = scanf('%line').split(' ');
  for (var i = 0; i < n; ++i) {
    outlets.push(l1[i]);
  }
  for (var i = 0; i < n; ++i) {
    devices.push(String(l2[i]).replace('\r', ''));
  }
  
  var amount = Math.pow(2, l);
  
  var dict = {};
  
  var fill = function(str, len) {
    if (String(str).length < len) {
      str = "0" + str;
      return fill(str, len);
    } else {
      return str;
    }
  }
  
  var toBinary = function(num, len) {
    var str = String(num.toString(2));
    return fill(str, len);
  }
  
  var buildConfigs = function(len, amt, outs) {
    var cnfg = [];
    var orig = outs.slice(0);
    var offRows = [];
    var onRows = [];
    for (var i = 0; i < orig.length; ++i) {
      var parts = orig[i].split("");
      for (var j = 0; j < len; ++j) {
        offRows[j] = (offRows[j] === undefined) ? [] : offRows[j];
        onRows[j] = (onRows[j] === undefined) ? [] : onRows[j];
        offRows[j].push(parts[j]);
        onRows[j].push((parts[j] == "0") ? "1" : "0");
      }
    }
    for (var i = 0; i < amt; ++i) {
      var bin = String(toBinary(i, len)).split('');
      
      var newOrder = [0, {}];
      var flips = 0;
      for (var k = 0; k < orig.length; ++k) {
        var newStr = '';
        for (var j = 0; j < bin.length; ++j) {
          var onOff = (bin[j] == "0") ? offRows : onRows;
          flips = (bin[j] == "1" && k == 0) ? flips+1 : flips;
          newStr = newStr + onOff[j][k];
        }
        newOrder[1][newStr] = 'cow';
      }
      newOrder[0] = flips;
      cnfg[i] = newOrder;
    }
    cnfg.sort(function(a, b){
      return a[0] - b[0];
    });
    return cnfg;
  }

  var buildDict = function(outs) {
    var orig = outs.slice(0), newDict = {};
    for (var i = 0; i < orig.length; ++i) {
      newDict[orig[i]] = outs;
    }
    return newDict;
  }
  
  var check = function(aDict) {
    var possible = true;
    for (var i = 0; i < devices.length; ++i) {
      if (aDict[devices[i]] != 'cow') {
        possible = false; break;
      }
    }
    return possible;
  }
  
  var configs  = buildConfigs(l, amount, outlets);
  //console.log('Outlets: ' + outlets); console.log('Devices: ' + devices); console.log('Len: ' + l); console.log('Amount: ' + amount);
  //console.log(configs);
  
  var isPossible = false;
  var minFlips = 0;
  for (var i = 0; i < configs.length; ++i) {
    var possible = check(configs[i][1]);
    if (possible) {
      isPossible = true;
      minFlips = configs[i][0];
      break;
    }
    //console.log(i + ": " + possible);
  }
  
  if (isPossible) {
    var result = minFlips;
  } else {
    var result = 'NOT POSSIBLE';
  }
  
  printf('Case #' + si + ': ' + result); 
  
  cb();
};

go(rs);
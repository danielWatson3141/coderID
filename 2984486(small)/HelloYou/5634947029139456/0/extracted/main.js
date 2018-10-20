var fs = require('fs');
// require('./utils/hashtable');

var file_path = './A-small-attempt1';


Array.prototype.copy = function() {
	var result = [];
	for(var i = 0, l = this.length; i < l; i++) {
		result.push(this[i]);
	}
	return result;
};

String.prototype.replaceAt = function(index, character) {
    return this.substr(0, index) + character + this.substr(index+character.length);
};


function Power_set(set) {
	var result = [];
	var sub_set;
	for(var i = 0, l = Math.pow(2, set.length); i <= l-1; i++) {
		sub_set = [];
		for(var j = 0; j < set.length; j++) {
			if((i>>j)&1 == 1) {
				sub_set.push(set[j]);
			}
		}
		result.push(sub_set);
	}
	result.sort(function(set1, set2) {
		if(set1.length == set2.length) {
			return 0;
		}
		if(set1.length < set2.length) {
			return -1;
		} else {
			return 1;
		}
	});
	return result;
}



fs.readFile(file_path + '.in', 'utf8', function (err, data) {
	if (err) throw err;
	var file = data.toString().split("\n");
	var caseNumber = parseInt(file[0]);
	var output = '';
	var line = 1, N, L, outlets_in, outlets_out, is_ok, power_set;
	var outlets_copy, result;

	function Switch(set) {
		for(var i = 0, l = set.length; i < l; i++) {
			for(var j = 0; j < N; j++) {
				if(outlets_in[j][set[i]] == '0') {
					outlets_copy[j] = outlets_copy[j].replaceAt(set[i], '1');
				} else {
					outlets_copy[j] = outlets_copy[j].replaceAt(set[i], '0');
				}
			}
		}
	}

	for(var caseI = 1; caseI <= caseNumber; caseI++) {
		N = parseInt(file[line].split(' ')[0]);
		L = parseInt(file[line].split(' ')[1]);
		outlets_in = file[line+1].split(' ');
		outlets_out = file[line+2].split(' ');
		outlets_out.sort();
		outlets_copy = [];
		line += 3;
		is_ok = true;

		var tab = [];
		for(var i = 0; i < L; i++) {
			tab.push(i);
		}
		power_set = Power_set(tab);
		for(var j = 0, l = power_set.length; j < l; j++) {
			outlets_copy = outlets_in.copy();
			// console.log(outlets_in);
			Switch(power_set[j]);
			// console.log(outlets_copy);
			is_ok = true;
			outlets_copy.sort();
			for(var i = 0; i < N; i++) {
				if(outlets_copy[i] != outlets_out[i]) {
					is_ok = false;
					break;
				}
			}
			if(is_ok) {
				result = power_set[j].length;
				break;
			}
		}

		if(is_ok) {
			output += 'Case #' + caseI + ': ' + result + '\n';
		} else {
			output += 'Case #' + caseI + ': NOT POSSIBLE\n';
		}
	}
	console.log(output);
	fs.writeFile(file_path + '.out', output, 'utf8', function() {
	});
	
	return;
});


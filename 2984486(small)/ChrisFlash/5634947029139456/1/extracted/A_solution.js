//run these lines in on any page with jquery in chrome's console
//$('body').html('<textarea name="input" style="width:400px;height:500px;margin-right:20px;"></textarea><textarea name="output" style="width:400px;height:500px"></textarea>');
function readBinary(digits) {
    digits = digits.split('');
    var place = 1;
    var value = 0;
    for (var i = 0; i < digits.length; i++) {
        value += place * Number(digits[i]);
        place *= 2;
    }
    return value;
}
function countBits(number) {
    var count = 0;
    while (number > 0) {
        count += (number % 2);
        number = (number - (number % 2)) / 2;
    }
    return count;
}
function parseInput(input) {
    var inputLines = input.split('\n');
    var N = Number(inputLines.shift());
    var result = "";
    for (var caseNumber = 1; caseNumber <= N; caseNumber++) {
        var counts = inputLines.shift().split(' ');
        var count = Number(counts[0]);
        var length = Number(counts[1]);
        var outlets = inputLines.shift().split(' ');
        var devices = inputLines.shift().split(' ');
        for (var i = 0; i < count; i++) {
            outlets[i] = readBinary(outlets[i]);
            devices[i] = readBinary(devices[i]);
        }
        outlets.sort(function(a, b) {
            return a - b;
        });
        devices.sort(function(a, b) {
            return a - b;
        });
        var bestCount = 1000;
        for (var i = 0; i < count; i++) {
            var xor = outlets[i] ^ devices[0];
            var newOutlets = [];
            for (var j = 0; j < count; j++) {
                newOutlets[j] = outlets[j] ^ xor;
            }
            newOutlets.sort(function(a, b) {
                return a - b;
            });
            var valid = true;
            for (var j = 0; j < count; j++) {
                if (newOutlets[j] != devices[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                var bits = countBits(xor);
                bestCount = Math.min(bits, bestCount);
            }
        }
        if (bestCount >= 1000) {
            result += "Case #" +  caseNumber + ": NOT POSSIBLE\n";
        } else {
            result += "Case #" +  caseNumber + ": " + bestCount + "\n";
        }
    }
    return result;
}

//paste input into textarea then run this line in console
$('[name="output"]').val(parseInput($('[name="input"]').val()));
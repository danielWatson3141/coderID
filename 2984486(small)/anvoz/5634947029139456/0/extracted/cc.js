'use strict';

var fs = require('fs'),
    input = 'A-small-attempt2.in';

fs.readFile(input, {encoding: 'utf-8'}, function (err, data) {
    if (err) {
        throw err;
    }

    var output = input.replace('.in', '.out');
    if (fs.existsSync(output)) {
        fs.unlinkSync(output);
    }
    Problem.solve(data.split('\n'), function(data) {
        // console.log(data); return;
        fs.appendFileSync(output, data + '\n');
    });
});

var Problem = {
    solve: function(input, print) {
        for (var idx = 1; idx <= 3 * input[0]; idx += 3) {
            var nl = input[idx].split(' '),
                n = nl[0],
                l = nl[1],
                iniFlow = input[idx + 1].split(' ').map(function(flow) {
                    return parseInt(flow, 2);
                }),
                reqFlow = input[idx + 2].split(' ').map(function(flow) {
                    return parseInt(flow, 2);
                });
            // console.log(n, l);
            // console.log(iniFlow);
            // console.log(reqFlow);

            var reqFlowIndex = {};
            for (var i = 0; i < reqFlow.length; i++) {
                reqFlowIndex[reqFlow[i]] = 1;
            }
            // console.log(reqFlowIndex);

            var max = Math.pow(2, l);
            for (var j = 0; j < max; j++) {
                var matched = 0;
                for (var k = 0; k < n; k++) {
                    if ((iniFlow[k] ^ j) in reqFlowIndex) {
                        matched++;
                    }
                }
                if (matched == n) {
                    break;
                }
            }

            var result = (j == max) ?
                'NOT POSSIBLE' :
                (j.toString(2).split('1').length - 1);

            print('Case #' + (((idx - 1) / 3) + 1) + ': ' + result);
        }
    }
};
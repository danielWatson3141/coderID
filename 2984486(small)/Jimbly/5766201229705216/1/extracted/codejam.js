/*
 * This file contains the generic file loading, test parsing, dispatching code
 * used in all of my solutions, other than possibly different delimiters being
 * used, this file remains unchanged.
 */

"use strict";
var assert = require('assert');
var fs = require('fs');
try { var proba = require('./proba'); } catch (ignore) {}
try { var probb = require('./probb'); } catch (ignore) {}
try { var probc = require('./probc'); } catch (ignore) {}
try { var probd = require('./probd'); } catch (ignore) {}

function out(fout, str) {
    fout.write(str);
    process.stdout.write(str);
}

function doProblem(filename, solver, delims) {
    var outname = filename + '.out';
    var fout = fs.createWriteStream(outname);
    var data = fs.readFileSync(filename, 'utf-8');
    var toks = data.split(new RegExp('[' + delims + ']+'));
    if (!toks[0]) {
        toks.splice(0, 1);
    }
    if (!toks[toks.length-1]) {
        toks.pop();
    }
    var N = Number(toks[0]);
    console.log('Running ' + N + ' test cases...');
    var tokidx=1;
    var tokfunc = function () {
        return toks[tokidx++];
    };
    var has_errors = false;
    for (var i=0; i<N || (!N && tokidx !== toks.length); i++) {
        var saved_idx = tokidx;
        var res = solver(tokfunc);
        if (solver.check) {
            var done_idx = tokidx;
            tokidx = saved_idx;
            var err = solver.check(tokfunc, res);
            if (err) {
                out(fout, 'Error: Test case #' + (i+1) + ' failed check: ' + err);
                has_errors = true;
            }
            tokidx = done_idx;
        }
        out(fout, 'Case #' + (i+1) + ': ' + res + '\n'); // Google
        //fout.write(s(tokdata) + '\n'; // Facebook
    }
    assert.equal(tokidx, toks.length);
    if (has_errors) {
        out(fout, 'Result has errors!');
    }
    fout.on('drain', fout.close.bind(fout));
}


// function gentest() {
//     function randInt(max) {
//         return Math.floor(Math.random() * max);
//     }
//
//     var data= [];
//     data.push(200);
//     for (var ii = 0; ii < 200; ++ii) {
//         var M = 1 + randInt(50);
//         var L = (M + randInt(101 - M)) / M * M;
//         data.push(M);
//         for (var kk = 0; kk < 2; ++kk) {
//             var line = [];
//             for (var jj = 0; jj < L; ++jj) {
//                 var s = "abcdef????";
//                 line.push(s[randInt(s.length)]);
//             }
//             data.push(line.join(''));
//         }
//     }
//     fs.writeFileSync('B-large.in', data.join('\n'));
// }

function main() {
    var start = Date.now();
    
    //doProblem('A-small.in', proba, ' \t\n\r');
    //doProblem('A-large.in', proba, ' \t\n\r');
    //doProblem('B-small.in', probb, ' \t\n\r');
    doProblem('B-large.in', probb, ' \t\n\r');
    //doProblem('C-small.in', probc, ' \t\n\r');
    //doProblem('C-large.in', probc, ' \t\n\r');
    //doProblem('D-small.in', probd, ' \t\n\r');
    //doProblem('D-large.in', probd, ' \t\n\r');
    
    //console.log('Finished in ' + ((Date.now()-start)/1000).toFixed(1) + 's');
}

main();
//gentest();

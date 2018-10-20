//run these lines in on any page with jquery in chrome's console
//$('body').html('<textarea name="input" style="width:400px;height:500px;margin-right:20px;"></textarea><textarea name="output" style="width:400px;height:500px"></textarea>');
function parseInput(input) {
    var inputLines = input.split('\n');
    var N = Number(inputLines.shift());
    var result = "";
    for (var caseNumber = 1; caseNumber <= N; caseNumber++) {
        var nodes = Number(inputLines.shift());
        var edges = [];
        var activeNodes = [];
        for (var i = 0; i < nodes; i++) {
            edges[i] = [];
            activeNodes[i] = i;
        }
        for (var i = 0; i < nodes - 1; i++) {
            var edgeData = inputLines.shift().split(' ');
            var nodeA = Number(edgeData[0]) - 1;
            var nodeB = Number(edgeData[1]) - 1;
            edges[nodeA].push(nodeB);
            edges[nodeB].push(nodeA);
        }
        var bestCost = 1000;
        for (var i = 0; i < nodes; i++) {
            //console.log(i);
            nodeCounts = [];
            bestCost = Math.min(bestCost, costToMakeRoot(edges, i, -1));
        }
        result += "Case #" +  caseNumber + ": " + bestCost + "\n";
    }
    return result;
}
function costToMakeRoot(edges, A, ignore) {
    var subTreeScores = [];
    for (var i = 0; i < edges[A].length; i++) {
        var B = edges[A][i];
        if (B == ignore) {
            continue;
        }
        subTreeScores.push([
            countNodes(edges, B, A),
            costToMakeRoot(edges, B, A)
        ]);
    }
    //console.log(subTreeScores.join(' '));
    if (subTreeScores.length == 0) {
        return 0;
    }
    if (subTreeScores.length == 1) {
        return subTreeScores[0][0];
    }
    var bestCost = 1000;
    for (var i = 0; i < subTreeScores.length; i++) {
        for (var j = i + 1; j < subTreeScores.length; j++) {
            var cost = subTreeScores[i][1] + subTreeScores[j][1];
            for (var k = 0; k < subTreeScores.length; k++) {
                if (k == i || k == j) {
                    continue;
                }
                cost += subTreeScores[k][0];
            }
            bestCost = Math.min(bestCost, cost);
        }
    }
    return bestCost;
}

var nodeCounts = [];
function countNodes(edges, A, ignore) {
    if (nodeCounts[A]) {
        return nodeCounts[A];
    }
    var count = 1;
    for (var i = 0; i < edges[A].length; i++) {
        var B = edges[A][i];
        if (B == ignore) {
            continue;
        }
        count += countNodes(edges, B, A);
    }
    nodeCounts[A] = count;
    return count;
}

//paste input into textarea then run this line in console
$('[name="output"]').val(parseInput($('[name="input"]').val()));
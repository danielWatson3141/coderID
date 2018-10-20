<?php
$fp = fopen($argv[1], 'r');

$problems = fgets($fp);
for ($i = 1; $i <= $problems; $i++) {
    $qty = intval(fgets($fp));
    $randomNrs = explode(' ', chop(fgets($fp)));
    $chanceToBeGood = 1;
    for ($j = 0; $j < $qty; $j++) {
        if ($j <= $randomNrs[$j]) {
            $chanceToBeGood *= ($qty - $j - 1)/$qty;
        }
    }
    outCase($i, $chanceToBeGood < 0.5 ? 'BAD' : 'GOOD');
}

function outCase($case, $value) {
    echo "Case #$case: $value\n";
}
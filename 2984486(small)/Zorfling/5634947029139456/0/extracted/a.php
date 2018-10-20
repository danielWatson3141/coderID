<?php
$file = fopen('php://stdin', 'r');
$tests = trim(fgets($file));
for ($i = 0; $i < $tests; $i++) {
    $lengths = split(' ', trim(fgets($file)));
    $devices = $lengths[0];
    $flowLength = $lengths[1];

    $initialFlow = split(' ', trim(fgets($file)));
    $requiredFlow = split(' ', trim(fgets($file)));
    sort($requiredFlow);

    $switchCount = 0; // switch permutation
    $numSwitchPermutations =  pow(2, $flowLength);
    $numSwitches = 0;
    $checkFlow = checkFlow($initialFlow, $requiredFlow);

    while (!$checkFlow && $switchCount < $numSwitchPermutations) {
        $switchCount++;
        $flow = switchBits($initialFlow, $switchCount);
        $checkFlow = checkFlow($flow, $requiredFlow);
        $numSwitches++;
    }

    if (!$checkFlow) {
        echo 'Case #' . ($i+1) . ": NOT POSSIBLE\n";
    } else {
        echo 'Case #' . ($i+1) . ": " . countOnes($switchCount) . "\n";
    }

}

fclose($file);

function checkFlow($flow, $requiredFlow) {
    // sort array
    sort($flow);

    // check
    if ($flow  == $requiredFlow) {
        return true;
    }

    return false;
}

function switchBits($flow, $count) {
    foreach ($flow as &$set) {
        $binary = str_split(str_pad(decbin($count), strlen($set), '0', STR_PAD_LEFT));
        $set = str_split($set);
        foreach ($binary as $idx => $bit) {
            if ($bit == '1') {
                $set[$idx] = ($set[$idx] == '1') ? '0' : '1';
            }
        }
        $set = implode('', $set);
    }
    return $flow;
}

function countOnes($count) {
    $binary = decbin($count);
    $total = 0;
    foreach (str_split($binary) as $number) {
        $total += $number;
    }
    return $total;
}

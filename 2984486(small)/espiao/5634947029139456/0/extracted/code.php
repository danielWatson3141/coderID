<?php
$fp = fopen($argv[1], 'r');

$problems = fgets($fp);
for ($i = 1; $i <= $problems; $i++) {
    list($quantity, $bits) = explode(' ', chop(fgets($fp)));
    $outlets = getLine();
    $equip = getLine();

    $result = tryXor(0, $bits, $outlets, $equip);
    if ($result === false) {
        outCase($i, 'NOT POSSIBLE');
    } else {
        outCase($i, $result);
    }
}

function tryXor($bit, $bits, $outlets, $equip, $bitsSwitched = 0)
{
    if ($bit == $bits) {
        return false;
    }

    if (count(array_diff($outlets, $equip)) == 0) {
        return $bitsSwitched;
    }

    $xorOutlets = xorOutLetBits($bit, $outlets);

    if (count(array_diff($xorOutlets, $equip)) == 0) {
        return $bitsSwitched+1;
    }

    $res1 = tryXor($bit+1, $bits, $outlets, $equip, $bitsSwitched);
    $res2 = tryXor($bit+1, $bits, $xorOutlets, $equip, $bitsSwitched+1);

    if ($res1 !== false && $res2 !== false) {
        return min($res1, $res2);

    } elseif ($res1 !== false) {
        return $res1;

    } else {
        return $res2;
    }
}

function xorOutLetBits($bit, $outlets)
{
    $res = [];
    foreach ($outlets as $outlet) {
        $res[] = $outlet ^ (1 << $bit);
    }

    return $res;
}

function getLine() {
    global $fp;
    $line = chop(fgets($fp));
    $nums = explode(' ', $line);
    $res = [];
    foreach($nums as $num) {
        $res[] = bindec($num);
    }
    return $res;
}

function outCase($case, $value) {
    echo "Case #$case: $value\n";
}
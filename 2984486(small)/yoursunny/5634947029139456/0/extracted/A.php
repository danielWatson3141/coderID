<?php

define('INFEASIBLE', 999999);

function array_compare(&$A, &$B, $N) {
  for ($i = 0; $i < $N; ++$i) {
    if ($A[$i] != $B[$i]) return false;
  }
  return true;
}

// with initial bits fixed to be $flip, try flipping last nBits
// return number of additional bits that needs flipped, or INFEASIBLE
function attempt($O, $D, $N, $L, $flip, $nBits, $mask) {
  // $O ^ $flip works for first ($L-$nBits)
  
  $mask = $mask >> 1;
  --$nBits;
  $bit = 1 << $nBits;
  $flip0 = $flip;
  $flip1 = $flip | $bit;
  
  // should we flip $bit or not?
  
  $O0 = array();// outlets if we don't flip
  $O1 = array();// outlets if we flip
  foreach ($O as $outlet) {
    $O0[] = ($outlet ^ $flip0) | $mask;
    $O1[] = ($outlet ^ $flip1) | $mask;
  }
  sort($O0);
  sort($O1);
  
  $D2 = array();// devices with mask
  foreach ($D as $device) {
    $D2[] = $device | $mask;
  }
  // $D is already sorted

  $canFlip0 = array_compare($O0, $D2, $N);
  $canFlip1 = array_compare($O1, $D2, $N);
  if ($nBits == 0) {
    if ($canFlip0) return 0;
    if ($canFlip1) return 1;
    return INFEASIBLE;
  }
  $res0 = $canFlip0 ? attempt($O, $D, $N, $L, $flip0, $nBits, $mask) : INFEASIBLE;
  $res1 = $canFlip1 ? 1+attempt($O, $D, $N, $L, $flip1, $nBits, $mask) : INFEASIBLE;
  return min($res0, $res1);
}

function solve_case() {
  list($N, $L) = in_ints();
  $O = array_map('bindec', in_strs()); // outlets
  $D = array_map('bindec', in_strs()); // devices
  sort($D);
  $res = attempt($O, $D, $N, $L, 0, $L, (1<<$L)-1);
  if ($res < INFEASIBLE) echo $res;
  else echo 'NOT POSSIBLE';
}

$filename = $argv[1];

$in = fopen($filename.'.in',  'r');
ob_start();

function in_line() {
  global $in;
  return str_replace(array("\r", "\n"), '', fgets($in));
}

function in_strs() {
  return explode(' ', in_line());
}

function in_floats() {
  return array_map('floatval', in_strs());
}

function in_ints() {
  return array_map('intval', in_strs());
}

function dbg($s) {
  global $case;
  file_put_contents('php://stderr', $case.': '.$s."\n", TRUE);
}

list($T) = in_ints();
for ($case=1; $case<=$T; ++$case) {
  dbg('START');
  printf('Case #%d: ', $case);
  solve_case();
  echo "\n";
}

file_put_contents($filename.'.out', ob_get_clean());
?>

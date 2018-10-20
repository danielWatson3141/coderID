<?php

function solve_case() {
  list($N) = in_ints();
  $P = in_ints();
  
  $A = array();
  for ($i = 0; $i < $N; ++$i) {
    $A[$i] = 0;
    if ($P[$i] <= $i) {
      for ($j = 0; $j <= $i; ++$j) {
        $A[$j] += 1;
      }
    }
  }
  
  if ($N != 1000) die;
  
  echo $A[0] > 485 ? 'GOOD' : 'BAD';
  // "485" is observation from generated data C-gen.in
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

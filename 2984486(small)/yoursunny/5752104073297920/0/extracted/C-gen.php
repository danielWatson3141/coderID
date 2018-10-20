<?php
function GOOD($N) {
  $A = array();
  for ($k = 0; $k < $N; ++$k) {
    $A[] = $k;
  }
  for ($k = 0; $k < $N; ++$k) {
    $p = mt_rand($k, $N-1);
    $tmp = $A[$p];
    $A[$p] = $A[$k];
    $A[$k] = $tmp;
  }
  return $A;
}

function BAD($N) {
  $A = array();
  for ($k = 0; $k < $N; ++$k) {
    $A[] = $k;
  }
  for ($k = 0; $k < $N; ++$k) {
    $p = mt_rand(0, $N-1);
    $tmp = $A[$p];
    $A[$p] = $A[$k];
    $A[$k] = $tmp;
  }
  return $A;
}

$N = 1000;
echo "120\n";
for ($T = 1; $T <= 60; ++$T) {
  echo $N."\n";
  echo implode(' ', GOOD($N))."\n";
}
for ($T = 61; $T <= 120; ++$T) {
  echo $N."\n";
  echo implode(' ', BAD($N))."\n";
}
?>

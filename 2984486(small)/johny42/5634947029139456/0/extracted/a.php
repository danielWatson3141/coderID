<?php

function min_flips($has, $wants) {
  if (count($has) == 0) return 0;
  if (strlen($has[0]) == 0) return 0;

  /*
  echo "===\n";
  print_r($has);
  print_r($wants);
  */

  $has_cnt = array(0, 0);
  $wants_cnt = array(0, 0);

  for ($i = 0; $i < count($has); ++$i) {
    ++$has_cnt[(int)$has[$i][0]];
    ++$wants_cnt[(int)$wants[$i][0]];
  }

  if ($has_cnt[0] == $has_cnt[1] && $wants_cnt[0] == $wants_cnt[1]) {
    // echo "TRY BOTH\n";
    $try = array(false, true);
  } else if ($has_cnt[0] == $wants_cnt[0]) {
    // echo "MUST NOT FLIP\n";
    $try = array(false);
  } else if ($has_cnt[0] == $wants_cnt[1]) {
    // echo "MUST FLIP\n";
    $try = array(true);
  } else {
    // echo "IMPOSSIBLE\n";
    return -1;
  }

  $best = -1;
  foreach ($try as $should_flip) {
    $new_has = array(array(), array());
    foreach ($has as $h) {
      $new_has[(int)$h[0] ^ (int)$should_flip][] = substr($h, 1);
    }

    $new_wants = array(array(), array());
    foreach ($wants as $w) {
      $new_wants[(int)$w[0]][] = substr($w, 1);
    }

    $cur = min_flips(
      array_merge($new_has[0], $new_has[1]),
      array_merge($new_wants[0], $new_wants[1])
    );
    if ($cur == -1) continue;
    $cur += (int)$should_flip;

    if ($best == -1 || $cur < $best) $best = $cur;
  }
  return $best;
}


$in = file($argv[1]);

$t = (int) trim(array_shift($in));

for ($tt = 1; $tt <= $t; ++$tt) {
  list ($n, $l) = explode(' ', trim(array_shift($in)));
  $has = explode(' ', trim(array_shift($in)));
  $wants = explode(' ', trim(array_shift($in)));

  sort($has);
  sort($wants);

  $res = min_flips($has, $wants);
  if ($res == -1) $res = "NOT POSSIBLE";
  echo "Case #$tt: $res\n";
}

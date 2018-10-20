<?php

function count_bits($s) { 
  $bits = 0;
  while ($s) { 
    if ($s & 0x01) { $bits ++; } 
    $s /= 2;
  }
  return $bits;
}

function do_test($io, $case) { 
  global $io;
  $n = $io->read();
  $l = $io->read();
  $outlets = array();
  $devices = array();
  for ($a = 0; $a < $n ; $a ++) { 
    $outlets[$a] = bindec($io->read());
  }
  for ($a = 0; $a < $n ; $a ++) { 
    $devices[$a] = bindec($io->read());
  }

  $max_switch = (1 << $l) - 1;
  $best = null;
  sort($devices);
  for ($s = 0; $s <= $max_switch; $s ++) { 
    $o_outlets = $outlets;
    array_walk($outlets, function(&$v, $k, $s) { 
		 $v ^= $s;
	       }
	       , $s);
    sort($outlets);
    if (count(array_diff($devices, $outlets)) == 0) { 
      $bits = count_bits($s);
      $io->debug_r($outlets);
      $io->debug("SOLUTION: $s ($bits) [ $best => ");

      if (($best === NULL) || ($bits < $best)) {
	$best = $bits;	
      }
      $io->debug("$best ]\n");
    }
    $outlets = $o_outlets;
  }
  

  $io->debug_r($outlets);
  $io->debug_r($devices);
  $io->debug("IN: $n $l $max_switch\n");
  if ($best === NULL) { 
    $best = "NOT POSSIBLE";
  }
  return $best;
}

// Read the probelms 
$io = new IO();
$num_entries = $io->read();
$case = 1;
do 
{
  $io->answer($case, do_test($io, $case));
} 
while (($case++) < $num_entries);


return 0;

// General class to handle input output 
class IO { 
  private $S = NULL;
  private $a = array();
  private $debug = false;
  private function r() {
    if (empty($this->a)) {$this->a = explode(" ",trim(fgets($this->S)));}
  }
  function __construct() {
    $this->S = fopen("php://stdin", "r"); 
    global $argv, $argc; if (($argc > 1) && ($argv[1] == '-d')) { $this->debug = true; } 
  }
  function read()              { $this->r(); return array_shift($this->a); }
  function readline_a()        { $this->r(); $r = $this->a; $this->a = array(); return $r; }
  function readline()          { return implode(" ", $this->readline_a()); }
  function answer($case, $str) { echo "Case #$case: $str \n"; }
  function debug($str)         { if ($this->debug) { echo "$str"; } }
  function debug_r($a)         { if ($this->debug) { print_r($a); } }
}
 
?>
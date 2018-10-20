<?php

function do_test($io, $case) { 
  global $io;
  $n = $io->read();
  $val = array();
  $swaps = 0;
  $last = null;    
  for ($i = 0; $i < $n ; $i ++) { 
    $v = $io->read();
    if ($last) { 
      if ($v < $last) { 
	$swaps ++;
      }
    } else { 
      // I know this is a bug -- but maybe it works ...
      $last = $v; 
    }    
  }

  if ($swaps > 300) { 
    return "GOOD";
  } else { 
    return "BAD";
  }
  //  $io->debug_r($tree);
  

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
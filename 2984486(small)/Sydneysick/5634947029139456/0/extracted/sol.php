<?php
$in = "A-small-attempt0.in";
$fp = fopen($in, 'r');
$T = fgets($fp);
ini_set("memory_limit","2000M");
//set_time_limit(230); //small 4 miuntes
set_time_limit(470); //large 8 miuntes
$out = "";

$possibility = array('xx');




for($case = 1; $case <= $T; $case++):
/***********/
list($N, $L) = array_map('intval', explode(" ", fgets($fp), 2));
$oe = explode(' ', str_replace("\n", '', fgets($fp)), $N);
$de = explode(' ', str_replace("\n", '', fgets($fp)), $N);

flip_switch($L, $oe, $de);

if (is_match($oe,$de)):
	$switch = 0;
else:
	$switch = flip_switch($L, $oe, $de);
endif;







/***********/
$out .= "Case #{$case}: {$switch}\n";
endfor;

fclose($fp);
echo nl2br($out);
file_put_contents($in.".out", $out);

function flip_switch($L, $oe, $de){
	$cases = get_possible($L);
	
	foreach ($cases as $case):
		$turned = flip_mask($case, $oe, $L);
		if (is_match($turned, $de)):
			return substr_count(decbin($case), '1');
		endif;	
	endforeach;
	return "NOT POSSIBLE";
}

function flip_mask($mask, $oe, $L){
	$out = array();
	foreach($oe as $e) $out[] = inverse($e, $mask, $L);
	return $out;
}

function get_possible($L){
	global $possibility;
	
	if (isset($possibility[$L])): 
		return $possibility[$L];
	else:
		$possibility[$L] = all_possible_cases($L);
		return $possibility[$L];
	endif;
	
}

function all_possible_cases($L){
	$case = '';
	for($i=1;$i<=$L;$i++) $case .= "1";
	$dec = bindec($case);
	$cases = array();
	for ($i=1; $i <= $dec; $i++):
		//$cases[] = sprintf("%0{$L}d",decbin($i));
		$cases[] = decbin($i);
	endfor;
	$sort = str_replace('0', '', $cases);
	asort($sort);
	$output = array();
	foreach($sort as $k => $v) $output[] = bindec($cases[$k]);
	//echo "<pre>" .  print_r($output, 1) .  "</pre>";
	return $output;
	
}

function inverse($in, $mask, $L){
	$v1 = bindec($in);
	$v2 = $mask;
	$val = $v1 ^ $v2;
	return sprintf("%0{$L}d", decbin($val));	
}

function is_match($oe, $de){
	return !count(array_diff($oe, $de));
}

?>
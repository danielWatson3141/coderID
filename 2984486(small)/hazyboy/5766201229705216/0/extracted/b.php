<?
$output = '';
$write_file = true;
$input = 'B-small-attempt0.in';
$file = file($input);
$offset = 0;
$case = 0;
$trees = array();
while(array_key_exists($offset,$file) && array_key_exists(($offset+1),$file)){
	if($offset != 0){
		$numtrees = trim($file[$offset]);
		for($i=0;$i<$numtrees-1;$i++){
			$offset++;
			$trees[$case][] = explode(" ",trim($file[$offset]));
		}
	}
	$offset++;
	$case++;
}

foreach($trees as $case=>$tree){
	$count = array_fill(1,count($tree)+1,0);
	foreach($tree as $tr){
		foreach($tr as $t){
			$count[$t]++;
		}
	}
	$counter = 0;
	$vals = array_count_values($count);
	$output .= "Case #".$case.": ";
	if($vals[2] == floor($vals[1]/2)){
	}
	else if($vals[2] > floor($vals[1]/2)){
		while($vals[2] > floor($vals[1]/2)){
			$vals[2]--;
			$counter++;
		}
	}
	else if($vals[2] < floor($vals[1]/2)){
		while($vals[2] < floor($vals[1]/2)){
			$vals[1]--;
			$counter++;
		}
	}
	$output .= $counter;
	$output .= "\n";
}

if ($write_file == true){
	$fileopen = fopen($input.'.out','wb');
	fwrite($fileopen,$output);
	fclose($fileopen);
}
else{
	print $output."<br />\n";
}
print "done";

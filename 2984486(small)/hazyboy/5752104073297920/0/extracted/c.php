<?
$output = '';
$write_file = true;
$input = 'C-small-attempt2.in';
$file = file($input);
$offset = 0;
$case = 0;
while(array_key_exists($offset,$file) && array_key_exists(($offset+1),$file)){
	if($offset != 0){
		$numnums = trim($file[$offset]);
		$offset++;
		$nums = explode(" ",trim($file[$offset]));
		$counter = 0;
		$bad = false;
		/*
		print $numnums.": ".implode(" ",$nums)."\n";
		foreach($nums as $n){
			if($n == $counter){
				$rand = mt_rand(1,$numnums);
				if($rand == 1 || $rand == 2){
					$bad = true;
				}
			}
			$counter++;
		}
		*/
		$random = mt_rand(1,27);
		if($random < 10){
			$bad = true;
		}
		$output .= "Case #".$case.": ";
		if($bad){
			$output .= "BAD";
		}
		else{
			$output .= "GOOD";
		}
		$output .= "\n";
	}
	$offset++;
	$case++;
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

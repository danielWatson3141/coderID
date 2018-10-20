<?
$output = '';
$write_file = true;
$input = 'A-small-attempt1.in';
$file = file($input);
$offset = 0;
$case = 0;

while(array_key_exists($offset,$file) && array_key_exists(($offset+1),$file)){
	if($offset != 0){
		list($number,$length) = explode(" ",trim($file[$offset]));
		$offset++;
		$nums = explode(" ",trim($file[$offset]));
		$offset++;
		$end = explode(" ",trim($file[$offset]));
		$possible = false;
		$number = 0;
		$allnumber = array();
		if(count(array_intersect($nums,$end)) == count($end)){
			$possible = true;
		}
		else{
			for($i=1;$i<pow(2,$length);$i++){
				$bin = str_pad(decbin($i),$length,"0",STR_PAD_LEFT);
				$tmp = $nums;
				foreach($tmp as $k=>$t){
					$a = str_split($t);
					$b = str_split($bin);
					$number = 0;
					foreach($a as $key=>$n){
						if($b[$key] == 1){
							$number++;
							$a[$key] = ($n == 1) ? 0 : 1;
						}
					}
					$tmp[$k] = implode("",$a);
				}
				if(count(array_intersect($tmp,$end)) == count($end)){
					$possible = true;
					$allnumber[] = $number;
				}
			}
		}
		$output .= "Case #".$case.": ";
		if($possible){
			if(count($allnumber)){
				$output .= min($allnumber);
			}
			else{
				$output .= $number;
			}
		}
		else{
			$output .= "NOT POSSIBLE";
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

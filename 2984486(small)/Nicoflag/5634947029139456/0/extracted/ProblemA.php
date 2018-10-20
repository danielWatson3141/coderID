<?php


$in=fopen("inA.txt","r");
$out=fopen("outA.txt","w+");



$T=intval(fgets($in));
for($kas=1;$kas<=$T;$kas++){
	$data=explode(" ",fgets($in));
	$N=intval($data[0]);
	$L=intval($data[1]);
	$init=explode(" ",trim(fgets($in)));
	$final=explode(" ",trim(fgets($in)));
	
	unset($key);
	for($k=0;$k<$N;$k++) for($i=0;$i<$N;$i++) for($j=0;$j<$L;$j++){
		if(isset($key[$k][$i])) $key[$k][$i].=($init[$k][$j]==$final[$i][$j])?0:1;
		else $key[$k][$i]=($init[$k][$j]==$final[$i][$j])?0:1;
	}
	
	
	$sol=false;
	$ans=$L+1;
	for($i=0;$i<$N;$i++){
		$sol=true;
		$ref=$key[0][$i];
		for($j=1;$j<$N;$j++){
			if(!in_array($ref,$key[$j])) $sol=false;
		}
		if($sol){
			$tmp=0;
			for($j=0;$j<$L;$j++) if($key[0][$i][$j]==1) $tmp++;
			if($tmp<$ans) $ans=$tmp;
		}
	}
	
	if($ans==$L+1) $ans="NOT POSSIBLE";

	
	echo "Case #$kas: $ans<br>";
	fwrite($out,"Case #$kas: $ans\n");
}
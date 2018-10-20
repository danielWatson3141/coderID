<?php

$in=fopen("inA.txt","r");
$out=fopen("outA.txt","w+");

function ev($link,$cur,$father){
	$c=0;
	for($i=0;$i<count($link[$cur]);$i++) if($link[$cur][$i]!=$father) $res[$c++]=ev($link,$link[$cur][$i],$cur);
	if(isset($res)) $max=count($res); else $max=0;
	if($max==0) return 1;
	elseif($max==1) return 1;
	elseif($max==2) return 1+$res[0]+$res[1];
	else{
		for($i=0;$i<2;$i++) for($j=$max-1;$j>0;$j--) if($res[$j]>$res[$j-1]){ $tmp=$res[$j]; $res[$j]=$res[$j-1]; $res[$j-1]=$tmp; }
		return 1+$res[0]+$res[1];
	}
}


$T=intval(fgets($in));
for($k=1;$k<=$T;$k++){
	$N=intval(fgets($in));
	unset($link);
	for($i=1;$i<$N;$i++){
		$data=explode(" ",fgets($in));
		$a=intval($data[0]); $b=intval($data[1]);
		if(isset($link[$a])) $link[$a][count($link[$a])]=$b; else $link[$a][0]=$b; 
		if(isset($link[$b])) $link[$b][count($link[$b])]=$a; else $link[$b][0]=$a;
	}
	
	$max=0;
	for($i=1;$i<=$N;$i++){
		$tmp=ev($link,$i,0);
		if($tmp>$max) $max=$tmp;
		$save=$i;
	}
	$ans=$N-$max;
	echo "Case #$k: $ans || $i<br>";
	fwrite($out,"Case #$k: $ans\n");
}
<?php

function get_zeros(array $str,$L){
    $ret=array();
    return $array;
}


function apply_conf($out,$conf,$N){
    foreach($conf as $h){
        for($i=0;$i<$N;$i++){
            $out[$i][$h]=($out[$i][$h]=="0")?"1":"0";
        }
        
    }
    return $out;
}

function resolve($N,$L,$out,$disp){
    sort($disp);
    $min=999999;
    for($i=0;$i<$N;$i++){
        $conf=array();
        for($j=0;$j<$L;$j++){
            if($out[0][$j]!=$disp[$i][$j]){
                $conf[]=$j;
            }
        }
        $out_tmp=apply_conf($out,$conf,$N);
        sort($out_tmp);
        if($out_tmp==$disp){
            $min=min($min,count($conf));
        }
    }
    if($min==999999){
        return "NOT POSSIBLE";
    }else{
        return $min;
    }
}


$fi=fopen("A.in","r");
$fo=fopen("A.out","w");

$case=0;

$T=fgets($fi);
for($iter=0;$iter<$T;$iter++){
    $case++;
    $line=explode(" ",fgets($fi));
    $N=$line[0];
    $L=$line[1];
    $out=explode(" ",str_replace("\n","",fgets($fi)));
    foreach($out as $key=>$value){
        $out[$key]=str_split($value);
    }
    $disp=explode(" ",str_replace("\n","",fgets($fi)));
    foreach($disp as $key=>$value){
        $disp[$key]=str_split($value);
    }
    $resolve=resolve($N,$L,$out,$disp);
    fwrite($fo, "Case #$case: ".$resolve."\n");
}
fclose($fo);

?>
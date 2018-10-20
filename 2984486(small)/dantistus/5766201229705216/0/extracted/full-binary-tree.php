<?php
//Read input
$input_file = 'B-small-attempt1.in';
$data = file($input_file,  FILE_IGNORE_NEW_LINES);
$ind = 0;

//Total cases
$total = (int)$data[$ind++];

for($case = 1; $case <= $total; $case++){
	//Read case input
	list($n) = explode(' ', $data[$ind++]);
	$n = (int)$n;
	$edges = array();
	for($i = 0; $i < $n - 1; $i++){
		list($xi, $yi) = explode(' ', $data[$ind++]);
		$edges[] = array($xi, $yi);
	}

	//Process case
	$min_to_remove = $n - 1;
	$min_root = -1;
	//Build graph structure
	$edges_p = array();
	for($i = 1; $i <= $n; $i++){
		$edges_p[$i] = array();
	}
	foreach($edges as $edge){
		$edges_p[$edge[0]][] = $edge[1];
		$edges_p[$edge[1]][] = $edge[0];
	}
	//Test each root
	for($i = 1; $i <= $n; $i++){
		$traversed = array();
		for($j = 1; $j <= $n; $j++) $traversed[$j] = false;
		$root = $i;
		$graph = build_graph($edges_p, $root);

		traverse($graph);
		$result = delmin($graph);
		if($min_to_remove > $result){
			$min_to_remove = $result;
			$min_root = $root;
		}
	}
	
	//Output
	echo 'Case #' . $case . ': ';
	echo $min_to_remove;
	echo "\n";
}

function traverse(&$node){
	foreach($node['children'] as $k => $child){
		traverse($node['children'][$k]);
	}
	while(true){
		if(count_children($node) == 0 || count_children($node) == 2) return;
		if(count_children($node) == 1){
			mark_all_children($node);
			return;
		}
		//Delete the child that has least descendants
		$min = 9999; $min_child = -1;
		foreach($node['children'] as $k => $child){
			if($child['marked']) continue;
			$todel = count_descendants($child);
			if($todel < $min){
				$min = $todel;
				$min_child = $k;
			}
		}
		mark_all_children($node['children'][$min_child]);
		$node['children'][$min_child]['marked'] = true;
	}
}
function count_children($node){
	$ret = 0;
	foreach($node['children'] as $k => $child){
		if(!$child['marked']) $ret++;
	}
	return $ret;
}
function count_descendants($node){
	$ret = 1;
	foreach($node['children'] as $k => $child){
		$ret += count_descendants($child);
	}
	return $ret;
}
function build_graph($edges, $node){
	global $traversed;
	$traversed[$node] = true;
	$result = array(
		'node' => $node,
		'children' => array(),
		'marked' => false,
	);
	foreach($edges[$node] as $connected){
		if(!$traversed[$connected]){
			$result['children'][] = build_graph($edges, $connected);
		}
	}
	return $result;
}
function mark_all_children(&$node){
	foreach($node['children'] as $k => $child){
		mark_all_children($node['children'][$k]);
		$node['children'][$k]['marked'] = true;
	}
}
function delmin($node){
	$ret = 0;
	foreach($node['children'] as $k => $child){
		$ret += delmin($child);
	}
	if($node['marked']) $ret++;
	return $ret;
}
?>
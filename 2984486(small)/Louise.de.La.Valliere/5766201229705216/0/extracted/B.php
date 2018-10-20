<?php

$T = (int) fgets(STDIN);
for ($iT = 1; $iT <= $T; ++$iT)
{
	$N = (int) fgets(STDIN);
	
	$neighbors = array();
	for ($i = 1; $i <= $N; ++$i)
		$neighbors[$i] = array();
	
	for ($i = 1; $i < $N; ++$i)
	{
		list($X, $Y) = explode(' ', rtrim(fgets(STDIN)));
		$neighbors[$X][] = (int) $Y;
		$neighbors[$Y][] = (int) $X;
	}
	
	$deletions = $N;
	for ($root = 1; $root <= $N; ++$root)
		$deletions = min($deletions, dfs($root, 0));
	
	echo 'Case #', $iT, ': ', $deletions, "\n";
}

function dfs($i, $parent)
{
	global $neighbors;
	$children = count($neighbors[$i]) - (bool) $parent;
	
	if (!$children)
	{
		return 0;
	}
	elseif ($children === 1)
	{
		foreach ($neighbors[$i] as $j)
			if ($j !== $parent)
				return delete($j, $i);
	}
	else
	{
		$deletions = 0;
		$rescuable = array();
		foreach ($neighbors[$i] as $j)
		{
			if ($j !== $parent)
			{
				$d = delete($j, $i);
				$deletions += $d;
				$rescuable[] = dfs($j, $i) - $d;
			}
		}
		sort($rescuable);
		return $deletions + $rescuable[0] + $rescuable[1];
	}
}

function delete($i, $parent)
{
	global $neighbors;
	$deletions = 1;
	foreach ($neighbors[$i] as $j)
		if ($j !== $parent)
			$deletions += delete($j, $i);
	return $deletions;
}
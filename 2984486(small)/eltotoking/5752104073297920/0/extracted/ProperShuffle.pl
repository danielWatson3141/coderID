#!/usr/bin/perl

use 5.010;
use warnings;

open(F, "C-small-attempt2.in.txt");
@lignes = <F>;
close(F);

$nb = 0;
$T = $lignes[$nb];
$nb++;

open(F, ">C-small.out");
for($t=1; $t<$T+1; $t++) {
	$N = $lignes[$nb];
	$nb++;
	@perm = split /\s/, $lignes[$nb];
	$nb++;
	
	for($k=0; $k<$N; $k++) { $tab_len[$k] = 0; }
	for($k=0; $k<$N; $k++) {
		$len = 0;
		$deb = $perm[$k];
		$c = $perm[$deb];
		while(($len < $N) && ($deb != $c)) { $c = $perm[$c]; $len++; }
		$tab_len[$len]++;
	}
	$biais = 0;
	for($k=100; $k<900; $k++) {
		if($perm[$k] >= $k) { $biais++; }
	}
	$nb_cycles = 0;
	for($k=0; $k<$N; $k++) {
		if($tab_len[$k]) { $nb_cycles++; }
	}
	
	if($biais < 415) { print F "Case #$t: GOOD\n"; }
	else { print F "Case #$t: BAD\n"; }

}
close(F);
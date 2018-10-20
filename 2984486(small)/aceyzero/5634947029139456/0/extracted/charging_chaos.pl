#!/usr/bin/perl -w

#aceyzero - 20140412

use strict;

my $switches_left;
my @cur_states;
my $max_switch_pos;
my @req_states;
my ($n, $l);

my $num_cases = <STDIN>;
chomp($num_cases);

for (my $i = 0; $i < $num_cases; $i++) {
	my $min_switches;
	($n, $l)  = split(/ /,<STDIN>);
	chomp($l);
	my @init_states  = split(/ /,<STDIN>);
	chomp($init_states[$#init_states]);
	@req_states  = split(/ /,<STDIN>);
	chomp($req_states[$#req_states]);
	
	for (my $j = 0; $j <= $l; $j++) {
		$switches_left = $j;
		$max_switch_pos = -1;
		@cur_states = @init_states;
		if (check()) {
			$min_switches = $j;
			last;
		}
	}
	
	$min_switches = 'NOT POSSIBLE' if !defined($min_switches);
	print "Case #".($i+1).": $min_switches\n";
}

sub check {
	if ($switches_left == 0) {
		my $match;
		my @tst_cur_states = @cur_states;
		for (my $i = 0; $i < $n; $i++) {
			$match = 0;
			for (my $j = 0; $j < @tst_cur_states; $j++) {
				if ($req_states[$i] == $tst_cur_states[$j]) {
					$match = 1;
					splice(@tst_cur_states, $j, 1);
					last;
				}
			}
			last if !$match;
		}
		return $match;
	}
	$switches_left--;
	my $max_switch_pos_before = $max_switch_pos;
	for (my $i = $max_switch_pos + 1; $i < $l; $i++) {
		$max_switch_pos = $i;
		for (my $j = 0; $j < $n; $j++) {
			substr($cur_states[$j],$i,1) = (substr($cur_states[$j],$i,1) + 1) % 2;
		}
		my $tst = check();
		return $tst if $tst;
		for (my $k = 0; $k < $n; $k++) {
			substr($cur_states[$k],$i,1) = (substr($cur_states[$k],$i,1) + 1) % 2;
		}
	}
	$switches_left++;
	$max_switch_pos = $max_switch_pos_before;
	return 0;
}
#!/usr/bin/perl

use strict;
use feature qw(say);

my $input_file = 'A-small-attempt2.in';
# my $input_file = 'test.in';
my $output_file = $input_file;
$output_file =~ s/\.in/\.out/gi;

open STDIN, "<$input_file" or die "CAN'T READ INPUT\n";
system(">$output_file");
open STDOUT, ">>$output_file" or die "CAN'T WRITE OUTPUT\n";

################### code here #############################

my $test_case = <STDIN>;
chomp($test_case);

for(my $i = 1; $i <= $test_case; ++$i){
	my $found = 0;
	my $min_switch = -1;
	(my $n, my $l) = split ' ', <STDIN>;
	chomp($l);
	my @init_flow = split ' ', <STDIN>;
	my @dev_require = split ' ', <STDIN>;
	foreach(@init_flow){
		my @val = split '', $_;
		my $val = 0;
		my $base = 1;
		foreach (@val){
			$val += $base if $_ == 1;
			$base *= 2;
		}
		$_ = $val;
	}
	foreach(@dev_require){
		my @val = split '', $_;
		my $val = 0;
		my $base = 1;
		foreach (@val){
			$val += $base if $_ == 1;
			$base *= 2;
		}
		$_ = $val;
	}
	@dev_require = sort {$a <=> $b} @dev_require;
	for(my $j = 0; $j <= 2**$l - 1; ++$j){
		my @flow_now = @init_flow;
		foreach(@flow_now){
			$_ = $_^$j;
		}
		@flow_now = sort {$a <=> $b} @flow_now;
		my $k;
		for($k = 0; $k <=$#flow_now; ++$k){
			last if $flow_now[$k] != $dev_require[$k];
		}
		if($k == $#flow_now + 1){
			my @ones = split '', sprintf("%b", $j);
			my $switch_times = 0;
			foreach(@ones){
				++$switch_times if $_ == 1;
			}
			$min_switch = $switch_times if $min_switch == -1 or $switch_times < $min_switch;
			$found = 1;
		}
	}
	say "Case #$i: $min_switch" if $found; 
	say "Case #$i: NOT POSSIBLE" if !$found;
}

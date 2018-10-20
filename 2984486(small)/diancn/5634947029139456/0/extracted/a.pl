#! c:\perl\bin\perl

use strict;

my($case);
$_=<>;
chomp;
$case=$_;

my(@narr, @larr, $min, $i, $j, $n, $l, @newl, $pow);

for(my $i = 1; $i <= $case; $i++) {
	@narr = ();
	@larr = ();
	$min = 1001;
	$_ = <>;
	chomp;
	($n, $l) = split(/ /, $_);

	$_ = <>;
	chomp;
	@narr =	split(/ /, $_);
	@narr = map(bin_str_to_dec($_), @narr);

	$_ = <>;
	chomp;
	@larr =	split(/ /, $_);
	@larr = map(bin_str_to_dec($_), @larr);

	$pow = power(2, $l);
	for($j = 0; $j < $pow; $j++) {
		@newl = @larr;
		flip(\@newl, $j);
		if(comp(\@narr, \@newl) == 0) {
			my $ct = count($j);
			if($min > $ct) {
				$min = $ct;
			}
		}
	}
	if($min == 1001) {
		printf("Case #%d: NOT POSSIBLE\n", $i);
	}
	else {
		printf("Case #%d: %d\n", $i, $min);
	}
}

sub power {
	my($a, $b) = @_;
	my($sum) = 1;
	for(my $i = 0; $i < $b; $i++) {
		$sum *= $a;
	}
	return($sum);
}

sub bin_str_to_dec {
	my($str) = @_;
	my($len) = length($str);
	my(@arr) = split(//, $str);
	my($c, $sum);
	while(@arr) {
		$c = shift(@arr);
		#print "  $c\n";
		$sum *= 2;
		$sum += $c;
	}
	return($sum);
}

sub count {
	my($num) = @_;
	my($ct) = 0;
	while($num > 0) {
		if(($num % 2) != 0) {
			$ct++;
		}
		$num /= 2;
	}
	return($ct);
}

sub comp {
	my($ra, $rb) = @_;
	my(@a, @b, $i);
	@a = sort(@$ra);
	@b = sort(@$rb);
	#print "comp: @a\n";
	#print "comp: @b\n";
	
	for($i = 0; $i <= $#a; $i++) {
		if($a[$i] != $b[$i]) {
			return(1);
		}
	}
	return(0);
}
		
sub flip {
	my($ra, $n) = @_;
	my(@new);
	@new = map( $_ ^ $n, @$ra);
	@$ra = @new;
}

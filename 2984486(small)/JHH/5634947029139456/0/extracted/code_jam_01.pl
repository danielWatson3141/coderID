use strict;
use warnings;

use List::Util qw( min max );
use Storable qw(dclone);

sub b2d {
	my $ref = shift;
	my $len = shift;
	my @a = @$ref;
	my $ret = 0;
	my $pow = 1;
	for (my $x = $len-1; $x >= 0; $x--) {
		$ret += $a[$x] * $pow;
		$pow *= 2;
	}
	return $ret;
}

sub bits {
	my $val = shift;
	my $len = shift;
	my $ret = 0;
	for (my $x = 0; $x < $len; $x++) {
		if ($val & (2 ** $x)) {
			$ret++;
		}
	}
	return $ret;
}

open INPUT, "<./A-small-attempt1.in";
my @lines = <INPUT>;
foreach (@lines) {
	chomp($_);
}
my $cases = $lines[0];
for (my $x = 0; $x < $cases; $x++) {
	my @vars = split(/ /, $lines[$x*3+1]);
	my $num = $vars[0];
	my $len = $vars[1];
	my @init = split(/ /, $lines[$x*3+2]);
	my @req = split(/ /, $lines[$x*3+3]);
	my (@m, @i, @r, @v);
	
	for (my $y = 0; $y < $num; $y++) {
		my @temp = split("", $init[$y]);
		$i[$y] = \@temp;
	}
	for (my $y = 0; $y < $num; $y++) {
		my @temp = split("", $req[$y]);
		$r[$y] = \@temp;
	}
	
	for (my $y = 0; $y < $num; $y++) {
		$m[$y] = b2d($i[0], $len) ^ b2d($r[$y], $len);
	}
	
	M:
	for (my $y = 0; $y < $num; $y++) {
		for (my $z = 1; $z < $num; $z++) {
			my $iv = 0;
			for (my $a = 0; $a < $num; $a++) {
				if ((b2d($i[$z], $len) ^ $m[$y]) == b2d($r[$a], $len)) {
					$iv = 1;
				}
			}
			if ($iv == 0) {
				next M;
			}
		}
		push (@v, $m[$y]);
	}
	
	my $bits = $len + 1;
	foreach (@v) {
		if (bits($_, $len) < $bits) {
			$bits = bits($_, $len);
		}
	}
	
	my $y = $x + 1;
	print sprintf("Case #%d: %s\n", $y, ($bits==$len+1)?"NOT POSSIBLE":$bits);
}
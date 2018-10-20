use strict;
my $cases = <>;
$cases = int($cases);
# Convert a binary number to a decimal number
sub bin2dec {
	my @n = split //, shift;
	my $ans = 0;
	for my $i (@n) {
		$ans = ($ans<<1)+int($i);
	}
	return $ans;
}

sub countone {
	my $nn = shift;
	my $ans = 0;
	while($nn){
		$ans += $nn&1;
		$nn >>= 1;
	}
	return $ans;
}

for my $p (1..$cases) {
	my ($n, $l) = map(int, (split / /, <>));
	my $in = <>;
	chomp $in;
	my @outlets = map {&bin2dec($_);} (split / /, $in);
	$in = <>;
	chomp $in;
	my @dev = map {&bin2dec($_);} (split / /, $in);
	my %ohash = {};
	for my $i (@dev) {
		$ohash{$i}++;
	}

	my $best = 300;
	for my $i (@dev) {
		my %hash = %ohash;
		my $diff = $i ^ $outlets[0];
		my $ans = &countone($diff);
		my @noutlets = map {$_ ^ $diff} @outlets;
		my $flag = 1;
		for my $j (@noutlets) {
			if (!$hash{$j}){
				$flag = 0;
				last;
			}else{
				$hash{$j}--;
			}
		}
		$best = $ans if ($flag && $ans < $best);
	}
	if ($best > $l){
		print "Case #$p: NOT POSSIBLE\n";
	}else{
		print "Case #$p: $best\n";
	}
}







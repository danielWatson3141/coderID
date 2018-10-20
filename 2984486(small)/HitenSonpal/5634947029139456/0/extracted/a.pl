#!/usr/bin/perl
use bigint;
$| = 1;

# functions start here

sub test {

}

# test()

sub dec2bin {
	my $str = unpack("B32", pack("N", shift));
	$str =~ s/^0+(?=\d)//;   # otherwise you'll get leading zeros
	return $str;
}

sub bin2dec {
	unpack("N", pack("B32", substr("0" x 32 . shift, -32)));
}

# main starts here

$dbg = 0;	# usage: '$dbg && print "...\n"'

chomp ($t = <STDIN>);

for ($case=1; $case<=$t; $case++) {

	chomp ($line = <STDIN>);
	$dbg && print $line;
	($n, $l) = split / /, $line;

	chomp ($line = <STDIN>);
	$dbg && print $line;
	@outlets = split / /, $line;
	foreach (@outlets) {
		$_ = bin2dec($_);
	}

	chomp ($line = <STDIN>);
	$dbg && print $line;
	@devices = split / /, $line;
	foreach (@devices) {
		$_ = bin2dec($_);
	}

	$min = $l+1;

	# main code here

	for ($i=0; $i<2**$l; $i++) {

		# flip the bits that i says should be flipped

		%check = ();
		for ($j=0; $j<@outlets; $j++) {
			# flip ith bit and put it into the check hash
			$check{$outlets[$j] ^ $i} = 1;
		}
		for ($j=0; $j<@devices; $j++) {
			last unless(defined $check{$devices[$j]});
		}

		if ($j==@devices) {			# we have a match
			$bin = dec2bin($i);
			$count = ($bin =~ tr/1/1/);
			$min = $count if ($count < $min);
		}
	}

	# print case #
	print "Case #" . $case . ": ";

	if ($min == $l+1) {
		print "NOT POSSIBLE\n";
	} else {
		print "$min\n";
	}

}

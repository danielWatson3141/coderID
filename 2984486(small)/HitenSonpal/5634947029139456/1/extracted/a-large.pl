#!/usr/bin/perl
# use bigint;
$| = 1;

# functions start here

sub test {

}

# test()

sub dec2bin {
	my $str = unpack("B64", pack("Q>", shift));
	$str =~ s/^0+(?=\d)//;   # otherwise you'll get leading zeros
	return $str;
}

sub bin2dec {
	unpack("Q>", pack("B64", substr("0" x 64 . shift, -64)));
}

# main starts here

$dbg = 0;	# usage: '$dbg && print "...\n"'

chomp ($t = <STDIN>);

for ($case=1; $case<=$t; $case++) {

	chomp ($line = <STDIN>);
	$dbg && print "$line\n";
	($n, $l) = split / /, $line;

	chomp ($line = <STDIN>);
	$dbg && print "$line\n";
	@outlets = split / /, $line;
	foreach (@outlets) {
		# $_ = Math::BigInt->from_bin("0b". $_);
		$_ = bin2dec($_);
		$dbg && print "$_ ";
	}

	chomp ($line = <STDIN>);
	$dbg && print "$line\n";
	@devices = split / /, $line;
	foreach (@devices) {
		# $_ = Math::BigInt->from_bin("0b". $_);
		$_ = bin2dec($_);
		$dbg && print "$_ ";
	}

	# main code here

	# for device 0, which bits need flipped for all outlets to work

	%soln = ();
	foreach $outlet (@outlets) {
		$flipped = $devices[0] ^ $outlet;
		# $flipped->bxor($outlet);
		$soln{$flipped} = 1;
		$dbg && print "$devices[0]: $flipped\n";
	}

	# for remaining device, which bits need flipped for all outlets to work
	for ($i=1; $i<@devices; $i++) {
		%flipped = ();
		foreach $outlet (@outlets) {
			$flipped = $devices[$i] ^ $outlet;
			# $flipped->bxor($outlet);
			$flipped{$flipped} = 1;
			$dbg && print "$devices[$i]: $flipped\n";
		}
		foreach $key (keys %soln) {
			delete $soln{$key} unless (defined $flipped{$key});
		}
		last if (scalar(keys %soln) == 0);
	}

	# print case #
	print "Case #" . $case . ": ";

	if (scalar(keys %soln) == 0) {
		print "NOT POSSIBLE\n";
	} else {
		$min = $l + 1;
		foreach $key (keys %soln) {
			$dbg && print "key: $key\n";
			$bin = dec2bin($key);
			$count = ($bin =~ tr/1/1/);
			$min = $count if ($count < $min);
		}
		print "$min\n";
	}

}

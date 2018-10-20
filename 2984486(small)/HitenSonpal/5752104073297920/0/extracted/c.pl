#!/usr/bin/perl

# functions start here

sub test {

}

# test()


# main starts here

$dbg = 0;	# usage: '$dbg && print "...\n"'

chomp ($t = <STDIN>);

for ($case=1; $case<=$t; $case++) {

	chomp ($line = <STDIN>);
	chomp ($line = <STDIN>);
	@numbers = split / /, $line;

	$first = 0;
	for ($i=0; $i<250; $i++) {
		$first += $numbers[$i];
	}
	$first = $first / 250;

	$third = 0;
	for ($i=500; $i<750; $i++) {
		$third += $numbers[$i];
	}
	$third = $third / 250;

	# print case #
	print "Case #" . $case . ": ";

	if ($first < $third) {
		print "BAD\n";
	} else {
		print "GOOD\n";
	}
}

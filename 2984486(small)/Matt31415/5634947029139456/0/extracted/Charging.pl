use strict;
use warnings;

use Data::Dumper;

use constant DEBUG => 0;

my ($fname) = @ARGV;

open (my $fh, "<", $fname) or die "Unable to open file:$fname";

my $testcases = <$fh>;
chomp($testcases);

foreach my $case (1.. $testcases) {
	print "Case #$case: ";
	print "\n" if DEBUG;

	my ($numoutlets, $numswitches) = split /\s/,<$fh>;

	print "Number of outlets: $numoutlets\n" if DEBUG;
	print "Number of switches: $numswitches\n" if DEBUG;

	my @startingflows;
	my @binvals = split /\s/, <$fh>;
	@startingflows = map {oct('0b' . $_)} @binvals;

	my @goalflows;
	@binvals = split /\s/, <$fh>;
	@goalflows = map {oct('0b' . $_)} @binvals;


	print "Starting flows: " . join (',', @startingflows) . "\n" if DEBUG;
	print "Goal flows: " . join (',', @goalflows) . "\n" if DEBUG;

	die "Bad counts!!!" unless @startingflows == $numoutlets && @goalflows == $numoutlets;

	#To make matching easier, we're going to sort.
	@goalflows = sort(@goalflows);

	my $minflips = $numswitches+1;

	foreach my $switch (0..(2**$numswitches)-1) {
		my @afterswitch = map {$_ ^ $switch} @startingflows;
		@afterswitch = sort(@afterswitch);

		if (join(',',@afterswitch) eq join(',',@goalflows)) {
			printf( "!!!!!!!!!!!!!   Found one! Switch = ob%b \n", $switch) if DEBUG;
			my $flips = CountBits($switch);
			$minflips = $flips if $flips < $minflips;
		}
	}

	if ($minflips == $numswitches + 1) {
		print "NOT POSSIBLE\n";
	}
	else {
		print "$minflips\n";
	}
}


sub CountBits {
	my ($a) = @_;
	$a = sprintf("%b", $a);
	my @a = split //,$a;
	@a = grep {/1/} @a;
	return scalar(@a);

}

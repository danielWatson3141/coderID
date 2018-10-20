use strict;
use Data::Dumper;
my $N = <STDIN>;

chomp($N);

my $i = 0;
my ($n, $b);
my (@bout, @bin);
while ($i++ < $N) {
	my $in = <STDIN>;
	chomp($in);
	($n,$b) = split /\s+/, $in;
	my (@in, @out);
	my $str = <STDIN>;
	chomp($str);
	push @in, split( /\s+/, $str);
	$str = <STDIN>;
	chomp($str);
	push @out, split( /\s+/, $str);

	@out = sort{ $a <=> $b} @out;

	foreach my $out (@out) {
		push @bout, bin2dec($out);
	}
	foreach my $in (@in) {
		push @bin, bin2dec($in);
	}

	my $try = 0;
	#warn "testing @bin, @bout";
	if (checkout(\@bin, \@bout)) {
		print "Case #$i: $try\n";
	}
	else {
		my $pos = generatenext (\@bin, \@bout, 0, 0);
		if ($pos > 0) {
			print "Case #$i: $pos\n";
		} else {
			print "Case #$i: NOT POSSIBLE\n";
		}
	}
	#warn Dumper(\@bin);
	#warn Dumper(\@bout);
	#warn "aaa";
	@bin = ();
	@bout = ();
}


sub generatenext {
	my ($in, $out, $try, $currentcount) = @_;

	my $flipout = flip ( $try, @$in);
	if ($try == 7) {
		#warn "try = $try";
		#warn Dumper($in);
		#warn Dumper($flipout);
		#warn Dumper($currentcount);
	}


	my @flipout = @$flipout;

	##warn "@flipout";
	if (checkout(\@flipout)) {
		return ++$currentcount;
	} elsif (checkout($in)) {
		return $currentcount;
	}else {
		$try++;
		if ($try == $b) {
			return -1;
		}
		if ((my $retval= generatenext ([@$in],[@$out], $try, $currentcount)) > 0) {
			return $retval;
		}
		elsif ((my $retval = generatenext(\@flipout, $out, $try, $currentcount+1) ) > 0) {
			return $retval;
		}
	}
	return -1;
}

sub flip  {
	my ($try, @bin)  = @_;

	my @new;
	my $mask = 1 << $try;
	for (my $k = 0 ; $k < scalar(@bin); $k++) {
		my $temp = $bin[$k];
		##warn $mask & $temp;
		$temp = ($mask & $temp) == 0 ? $temp + $mask : $temp - $mask;
		##warn "Changing $bin[$k] to $temp";
		push @new, $temp;
	}
	return \@new;
}
sub checkout {

	my ($in, $out)  = @_;
	my @in = @$in;
	my @out = @bout;

	my @sin = sort {$a <=> $b} @in;
	my @sout = sort {$a <=> $b} @out;
	my %hash = map { $_ => 1 } @out;
	my $good = 1;
	foreach my $in (@in) {
		if ($hash{$in} != 1) {
			$good = 0;
			last;
		}
	}

	return $good;
}
sub bin2dec {
	return unpack("N", pack("B32", substr("0" x 32 . shift, -32)));
}

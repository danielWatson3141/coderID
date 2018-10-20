use strict;
use warnings;

# input and output
my $file = "A-small-attempt0.in";
#my $file = "test";
open my $fhI,"<",$file;my @f=<$fhI>;map{s/^\s+|\s+$//g}@f;
my $final=1;if($final){open(my $fhO,">","$file.out");select $fhO;}
sub p{print STDERR$_[0] if $final;print$_[0]}


my $line = 1;
CASE : for (my $case = 1 ; $case <= $f[0] ; $case++ ) {
	my ($ndevices,$length) = split(/\s/,$f[$line++]);
	my @inicial = split(/\s/,$f[$line++]);
	my @wanted = split(/\s/,$f[$line++]);
	@inicial = sort{$a<=>$b}@inicial;
	@wanted = sort{$a<=>$b}@wanted;
	
	my %both = ();
	my %switch = ();
	# the number of 1's and 0's must be the same, or inverted
	for (my $i = 0; $i < $length; $i++){
		my ($cI0,$cI1,$cW0,$cW1) = (0,0,0,0);
		for (my $j = 0; $j < $ndevices; $j++){
			my $aux1 = substr($inicial[$j],$i,1);
			if(substr($inicial[$j],$i,1) == 0){
				$cI0++;
			} else {
				$cI1++;				
			}
			if(substr($wanted[$j],$i,1) == 0){
				$cW0++;
			} else {
				$cW1++;				
			}
		}
		# if the number of zeros and ones doesn't match, not possible
		if($cI0 != $cW0 && $cI0 != $cW1){
			p "Case #$case: NOT POSSIBLE\n";
			next CASE;
		}
		$both{$i}++ if ($cI0 == $cI1);
		$switch{$i}++ if $cI0 != $cW0;
	}
	# there isn't any case where we need to check more
	if (scalar keys %both == 0){
		p "Case #$case: ".(scalar keys %switch)."\n";
		next CASE;
	}
	
	# for each one on the inicial list, try to make one in the wanted list, keep track of how many
	my $best = $length + 10;
	for (my $i = 0; $i < $ndevices; $i++){
		for (my $w = 0; $w < $ndevices; $w++){
			my @iaux = ();
			for my$j(0..$ndevices-1){
				$iaux[$j] = $inicial[$j];
			}
			my $wrong = 0;
			for my $j(0..$length-1){
				# if this one is wrong, try to replace all
				if(substr($inicial[$i],$j,1) != substr($wanted[$w],$j,1)){
					$wrong++;
					for my$k(0..$ndevices-1){
						substr($iaux[$k],$j,1) = substr($iaux[$k],$j,1) == 1 ? 0 : 1;
					}
				}
			}
			# the iaux has all the replacements done
			@iaux = sort{$a<=>$b}@iaux;
			my $equal = 1;
			for my $z(0..$ndevices-1){
				next if $iaux[$z]== $wanted[$z];
				$equal = 0;
			}
			$best = $wrong if $equal && $wrong < $best;
		}
	}
	if($best > $length){
		p "Case #$case: NOT POSSIBLE\n";
		next;
	}
	p "Case #$case: $best\n";
}

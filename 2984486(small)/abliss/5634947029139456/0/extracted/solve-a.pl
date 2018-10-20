#!/usr/bin/perl
use strict;
$,=' ';

my $cases = <>;
chomp $cases;
for (my $i = 1; $i <= $cases; $i++) {
    my $nl = <>;chomp $nl;
    my ($n, $l) = split(/ /,$nl);
    my $outlets = <>; chomp $outlets;
    my $devices = <>; chomp $devices;
    my @o = split(/ /, $outlets);
    my @d = split(/ /, $devices);
    #print STDERR "case $i\n";
    my $answ = solve($l, [\@o], [\@d], 0);
    if ($answ > $l) {
        $answ = "NOT POSSIBLE";
    }
    print "Case #$i: $answ\n";
}
sub min {
    my $a = shift;
    my $b = shift;
    if ($a < $b) {
        return $a;
    }
    return $b;
}
          
sub solve {
    my $len = shift;
    my $oGroups = shift;
    my $dGroups = shift;
    my $depth = shift;
    #print STDERR " "x$depth,"Considering: \n";

    for (my $i = 0; $ i < @$oGroups; $i++) {
        if (scalar(@{$oGroups->[$i]}) != scalar(@{$dGroups->[$i]})) {
            #print STDERR " "x$depth,"Rejecting at $i:", @{$oGroups->[$i]},"!=",@{$dGroups->[$i]};
            return $len+1;
        }
    }
    if ($depth == $len) {
        # for (my $i = 0; $ i < @$oGroups; $i++) {
        #     if (join(',',sort(@{$oGroups->[$i]})) ne
        #         join(',',sort(@{$dGroups->[$i]}))) {
        #         return $len+1;
        #     }
        # }
        return 0;
    }

    my @o1 = map {[grep {substr($_, $depth, 1) eq "1"} @$_]} @$oGroups;
    my @o0 = map {[grep {substr($_, $depth, 1) eq "0"} @$_]} @$oGroups;
    my @d1 = map {[grep {substr($_, $depth, 1) eq "1"} @$_]} @$dGroups;
    my @d0 = map {[grep {substr($_, $depth, 1) eq "0"} @$_]} @$dGroups;


    my $zAns = solve($len, [@o0, @o1], [@d0, @d1], $depth+1);
    my $oAns = solve($len, [@o1, @o0], [@d0, @d1], $depth+1) + 1;
    return min($zAns, $oAns);
    
}

#!/usr/bin/perl -w

use strict;
use Data::Dumper;

sub ident {
    my $aref = shift;
    my $bref = shift;
    my $upto = shift;
    my @arr = sort @$aref;
    my @brr = sort @$bref;
    return 0 if @arr != @brr;
    for my $i (0..$#$aref) {
        return 0 if (substr $arr[$i], 0, $upto) ne
            (substr $brr[$i], 0, $upto);
    }
    return 1;
}

sub flipall {
    my $ref = shift;
    my $idx = shift;
    for my $i (0..$#$ref) {
        my $n = substr $$ref[$i], $idx, 1;
        $n = ($n eq '0') ? '1' : '0';
        (substr $$ref[$i], $idx, 1) = $n;
    }
}

sub try {
    my $ref = shift;
    my $reqref = shift;
    my $onto = shift;
    my $total = shift;
    my $sofar = shift;
    my $limit = shift;

    # print "$onto, $total, $sofar\n";

    if ($onto >= $total) {

    # print " EH $onto, $total, $sofar\n" if ident($ref, $reqref);
        return ident($ref, $reqref, $total) ? $sofar : -1;
    } elsif ($limit >= 0 and $sofar > $limit) {
        return -1;
    } elsif (not ident($ref, $reqref, $onto)) {
        return -1;
    }

    my $res1 = try($ref, $reqref, $onto + 1, $total, $sofar, -1);
    flipall($ref, $onto);
    my $res2 = try($ref, $reqref, $onto + 1, $total, $sofar + 1, $res1);
    flipall($ref, $onto);
    if ($res1 >= 0 xor $res2 >= 0) {
        return $res1 >= 0 ? $res1 : $res2;
    } else {
        return $res1 < $res2 ? $res1 : $res2;
    }
}

$| = 1;

my $t = <>;
for my $_t (1..$t) {
    my ($n, $l) = split ' ', <>;
    my @arr = split ' ', <>;
    my @brr = split ' ', <>;
    my $res = try(\@arr, \@brr, 0, $l, 0, -1);
    if ($res >= 0) {
        print "Case #", $_t, ": ", $res, "\n";
    } else {
        print "Case #", $_t, ": NOT POSSIBLE\n";
    }
}

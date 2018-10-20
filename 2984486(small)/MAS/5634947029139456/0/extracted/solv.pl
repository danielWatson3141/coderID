#!/usr/bin/env perl
use strict;
use warnings;
use v5.10;

my $E;
chomp(my $t = <>);
foreach my $case (1 .. $t) {
    my ($n, $l) = split /\s/, <>;

    my (@ef) = split /\s/, <>;
    my (@if) = split /\s/, <>;

    @ef = map { oct "0b" . $_ } @ef;
    @if = map { oct "0b" . $_ } @if;

    $E = $l;
    my $s = solv(\@ef, \@if, 0, 0);
    $s = ($s == -1) ? "NOT POSSIBLE" : $s;
    my $ans = sprintf "Case #%d: %s", $case, $s;
    say $ans;
    say STDERR $ans;
}

sub solv {
    my $ef = shift;
    my $if = shift;
    my $ind = shift;
    my $cnt = shift;

    return $cnt if $ind == $E;

    my @ef1 = @$ef;
    my @ef2 = @$ef;
    my @if1 = @$if;
    my @if2 = @$if;

    my $ans1;
    my $ans2;
    if (check(\@ef1, \@if1, $ind)) {
        $ans1 = solv(\@ef1, \@if1, $ind + 1, $cnt);
    } else {
        $ans1 = -1;
    }

    @if2 = map { $_ ^ (2 ** $ind) } @if2;
    if (check(\@ef2, \@if2, $ind)) {
        $ans2 = solv(\@ef2, \@if2, $ind + 1, $cnt + 1);
    } else {
        $ans2 = -1;
    }

    if ($ans1 == -1) {
        if ($ans2 == -1) {
            return -1;
        } else {
            return $ans2;
        }
    } else {
        if ($ans2 == -1) {
            return $ans1;
        } else {
            return ($ans1 < $ans2) ? $ans1 : $ans2;
        }
    }
}

sub check {
    my $ef = shift;
    my $if = shift;
    my $ind = shift;

    $ind++;
    my @cef = sort { $a <=> $b } map { $_ % 2 ** $ind } @$ef;
    my @cif = sort { $a <=> $b } map { $_ % 2 ** $ind } @$if;

    my $eq = 1;
    my $i = 0;
    foreach my $e (@cef) {
        if ($e != $cif[$i]) {
            $eq = 0;
            last;
        }
        $i++;
    }
    return $eq;
}

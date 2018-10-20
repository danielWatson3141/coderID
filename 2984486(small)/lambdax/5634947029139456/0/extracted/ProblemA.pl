#! /usr/bin/perl

# 2014-04-26 10:21 start coding
# 2014-04-26 11:46 start debugging
# 12:12 done.

use strict;
use warnings;
use Data::Dumper;

my $DEBUG = 0;

sub flip_bit($$) {
    # string の n bit 目を反転する
    my $n = shift;
    my $bits = shift;
    
    my $flipped = substr($bits, $n, 1) eq '1' ? '0' : '1';

    $DEBUG and print "input is $bits\n";
    return
	substr($bits, 0, $n ) . 
	$flipped .
	substr($bits, $n+1) ;
}

sub ary_equal(\@\@)  {
    my @a = sort @{$_[0]};
    my @b = sort @{$_[1]};
    for (my $i=0; $i<=$#a; $i++){
	return 0 if $a[$i] ne $b[$i];
    }
    return 1;
}

sub bit_sum_1 {
    my $n = shift;
    my $i = 0;
    while ($n > 0) {
	$i++ if (0x1 & $n);
	$n = $n >> 1;
    }
    return $i;
}


sub solve($$\@\@) {
    
    my $N = shift;
    my $L = shift;
    my @flow = sort @{$_[0]};
    my @devices = sort @{$_[1]};

    #$DEBUG and print "solve: $N, $L, @flow, @devices\n";

    if (ary_equal(@flow, @devices)) {
	return 0;  # 0 個の 0 であって false ではない。
    }

    for my $num_for_column (1 .. 2**$L-1) { # メモ化出来るはず
	my $tmp = $num_for_column;
	my $len = $L;
	my @a = @flow;
	my @b = @devices;

	while ( $tmp > 0 ) { # その数のビットのたっている桁をフリップする

	    $DEBUG and print "num_for_column $num_for_column:\n";
	    $DEBUG and print "  before: a @a, b @b\n";

	    if ($tmp & 1) {
		 $DEBUG and print "          flipping ",$len-1,"th bits\n";
		@a = sort map {flip_bit($len-1, $_) } @a;
	    }
	    $tmp = $tmp >> 1;
	    $len--;
	}

	 $DEBUG and print "   after: a @a, b @b\n";
	if (ary_equal (@a, @devices)) {
	    return bit_sum_1($num_for_column);
	}
    }

    return -1; # 見つからなかった。
}

sub test {
    print flip_bit(1, "01");
    print flip_bit(5, "010101");
    my @a = qw/001 010 011 100 101 110 111/;
    print "\n@a\n";
    my @b = map {flip_bit(1, $_)} @a;
    print "@b\n";
    print sort @b, "\n";

    print "eq: ", ary_equal(@a, @b), "\n";
    print "eq: ", ary_equal(@a, @a), "\n";

    print "bit sum 1 ", bit_sum_1(1), "\n";
    print "bit sum 5 ", bit_sum_1(5), "\n";
    print "bit sum 8 ", bit_sum_1(8), "\n";
    print "bit sum 15 ", bit_sum_1(15), "\n";
    
}

my $n_testcase = <>;
chomp $n_testcase;
my $i = 0;

while ($i++ < $n_testcase)  {
    $DEBUG and print "i $i n $n_testcase\n";
    my $line = <>; chomp $line;
    my ($N, $L) = split / /, $line;

    $line = <>; chomp $line;
    my @flow = split / /, $line;

    $line = <>; chomp $line;

    my @devices = split / /, $line;

    $DEBUG and print "args: $N, $L, @flow, @devices\n";

    #$DEBUG and    test();

    my $ans = solve($N, $L, @flow, @devices);
    $DEBUG and print "$N $L :";
    if ( 0 <= $ans ) {
	print "Case #$i: $ans\n";
    } else {
	print "Case #$i: NOT POSSIBLE\n";
    }



}


=comment
入力
T テストケースの数
N L  Nデバイス数、L長さ
000 111 001 ...  電流、同じものは無い。
000 111 001 ...  デバイスの要求電流、同じものは無い

出力
Case #x: y  x 1から始まるケース番号、y最小スイッチ操作数
or
Case #x: NOT POSSIBLE


01 11 10
11 01 10  セットとして等しいかどうか？

ソートするか、集合として等しいかどうかの関数を用意。

2^L だけ総当りすればいい。
=cut

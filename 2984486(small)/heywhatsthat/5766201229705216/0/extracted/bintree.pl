#! /usr/bin/env perl

use strict;
use warnings;
#use bigint;
use Memoize;

$\ = "\n";

sub out {
#    print @_;
}

my $T;
my $N;
my @edges = ();

$T = <>;

sub is_bintree_under {
    my $prevnode = shift;
    my $node = shift;
    my $edges_per_node = shift;
    for (@_) {
	my $nextnode;
	if ($_->[0] == $node) {
	    $nextnode = $_->[1];
	} elsif ($_->[1] == $node) {
	    $nextnode = $_->[0];
	} else {
	    next;
	}
	if (defined $prevnode && $nextnode == $prevnode) {
	    next;
	}
	if ($edges_per_node->[$nextnode] == 1) {
	    next;
	}
	if ($edges_per_node->[$nextnode] == 3) {
	    if (!is_bintree_under($node, $nextnode, $edges_per_node, @_)) {
		return 0;
	    }
	    next;
	}
	return 0;
    }
    return 1;
}
    


sub is_bintree {
    my $mask = shift;
    my @edges_per_node = ();
    for (@_) {
	$edges_per_node[$_->[0]]++;
	$edges_per_node[$_->[1]]++;
    }
    #warn join ' * ', @edges_per_node[1..$#edges_per_node];

	# no good if any singletons. need exactly one node with 2 edges
    my $root;
    for my $i (1..$N) {
	next if $mask & (1<<($i-1));
	return 0 if !$edges_per_node[$i];
	if ($edges_per_node[$i] == 2) {
	  return 0 if defined $root;
	  $root = $i;
	  next;
	}
	next if $edges_per_node[$i] != 1;
	my @other = grep $_->[0] == $i || $_->[1] == $i, @_;
	return 0 if $edges_per_node[$other[0]->[0]] == 1 && $edges_per_node[$other[0]->[1]] == 1;
    }
    return 0 if !defined $root;
    is_bintree_under undef, $root, \@edges_per_node, @_;
}


	

#memoize('is_bintree_under');
#memoize('f', NORMALIZER => sub { join ':', join(' ', sort @{$_[1]}), @_[2..$#_]; })

for my $case (1..$T) {
  #Memoize::flush_cache('is_bintree_under');
  out '--------------------------------------------------------------------------------';
  $N = <>;
  @edges = ();
  for (1..$N-1) {
      $_ = <>;
      chomp;
      push @edges, [ split/\s+/ ];
  }

  if (is_bintree 0, @edges) {
      printf "Case #$case: %d\n", 0;
      next;
  }

  my $t = $N + 10000;
  mask: for my $mask (1..(1<<$N)-1) {
      #warn "mask $mask";
      my $tt = 0;
      my @e = @edges;
      for my $i (1..$N) {
	  if ($mask & (1<<($i-1))) {
	      #warn "  got $i";
	      $tt++;
	      next mask if $tt >= $t;
	      @e = grep $_->[0] != $i && $_->[1] != $i, @e;
	  }
      }
      #warn "$mask: $tt: ", join '  ', map "$_->[0] $_->[1]", @e;
      #warn("yup"), $t = $tt if @e == 0 || @e == 1 || is_bintree $mask, @e;
      $t = $tt if @e == 0 || @e == 1 || (@e != 2 && is_bintree $mask, @e);
  }

  printf "Case #$case: %d\n", $t;
}

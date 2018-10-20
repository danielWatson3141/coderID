#!/usr/intel/bin/perl -w

use strict;

my $debug;
#$debug = 1;
main();

my @nodes;

sub solve {
  my $N = <>;
  @nodes = ()x$N;
  for (my $i=0; $i<$N-1; $i++) {
    my $line = <>;
    my ($n1, $n2) = split /\s+/, $line;
    push @{$nodes[$n1-1]}, $n2-1;
    push @{$nodes[$n2-1]}, $n1-1;
  }
  for (my $i=0; $i<$N; $i++) {
    debug("$i: " . join(' ', @{$nodes[$i]}) . "\n");
  }

  my $min = $N - 1;
  for (my $root = 0; $root < $N; $root++) {
    my @q = ($root);
    my $todelete = 0;
    my %seen;
    while (defined (my $curr = shift @q)) {
      $seen{$curr} = 1;
      my @nei = grep {!$seen{$_}} @{$nodes[$curr]};
      if (@nei == 0) {
        next;
      }
      if (@nei == 1) {
        $todelete += num_of_nodes($nei[0], \%seen);
        next;
      }
      my $min_delete_local = $N;
      my @min_edges;
      for (my $i = 0; $i<@nei - 1; $i++) {
        for (my $j = $i+1; $j<@nei; $j++) {
          # i, j are indexes of the edges of the curr; delete rest
          my $reset_delete = 0;
          for (my $e = 0; $e < @nei; $e++) {
            next if $e == $i || $e == $j;
            my $todeletee = num_of_nodes($nei[$e],\%seen);
            $reset_delete += $todeletee;
          }
          if ($min_delete_local > $reset_delete) {
            $min_delete_local = $reset_delete;
            @min_edges = ($nei[$i], $nei[$j]);
          }
        }
      }
      $todelete += $min_delete_local;
      push @q, @min_edges;
    }
    if ($min > $todelete) {
      $min = $todelete;
    }
  }
  print $min;
}

sub num_of_nodes {
  my ($n, $seen) = @_;
  my $result = 0;
  my @q = ($n);
  my %seen1;
  while (defined (my $curr = shift @q)) {
    next if $seen->{$curr};
    next if $seen1{$curr};
    $seen1{$curr} = 1;
    $result ++;
    push @q, @{$nodes[$curr]};
  }
  return $result;
}

sub main {
  my $T = <>;
  for (my $i = 1; $i <= $T; $i++) {
    print "Case #$i: ";
    #$debug = $i % int($T/10+0.5) == 0;
    #$debug = $i == 1 || $i == $T;
    debug("#$i: \n");
    solve();
    print "\n";
  }
}

sub debug {
  return if !$debug;
  my @args = @_;
  $args[0] = "\tDebug: " . $args[0];
  print STDERR @args;
}

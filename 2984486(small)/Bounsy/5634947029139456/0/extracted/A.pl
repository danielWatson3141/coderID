#!/usr/bin/perl

use strict;
use warnings;

require 5.010;
use feature ':5.10';

sub ConvertToBase10($$)
{
	my ($Value, $Base) = @_;

	my $NewValue = 0;
	my $Power = 1;

	foreach my $Digit (reverse split(//, $Value))
	{
		$NewValue += ($Digit * $Power);
		$Power *= $Base;
	}

	return $NewValue;
}

sub BitCount($)
{
	my ($Value) = @_;

	my $Power = 1;
	my $Count = 0;
	
	while ($Power <= $Value)
	{
		$Count++ if ($Value & $Power);
		$Power <<= 1;
	}

	return $Count;
}

my ($T) = split(/\s+/, <>);

my ($N, $L, @Outlets, @Devices, @Switches, @NewOutlets, $Count);

for (my $n = 1; $n <= $T; $n++)
{
	($N, $L) = split(/\s+/, <>);
	@Outlets = sort(map { ConvertToBase10($_, 2) } split(/\s+/, <>));
	@Devices = sort(map { ConvertToBase10($_, 2) } split(/\s+/, <>));
	
	@Switches = sort { (BitCount($a) cmp BitCount($b)) || ($a cmp $b) } (0..(2**$L));

	$Count = -1;

	foreach my $Switch (@Switches)
	{
		@NewOutlets = sort map { $_ ^ $Switch } @Outlets;
		
		my $Match = 1;

		for (my $i = 0; $i < @Outlets; $i++)
		{
			unless ($NewOutlets[$i] == $Devices[$i])
			{
				$Match = 0;
				last;
			}
		}

		if ($Match)
		{
			$Count = BitCount($Switch);
			last;
		}
	}

	print "Case #$n: ";

	if ($Count >= 0)
	{
		print $Count;
	} else
	{
		print "NOT POSSIBLE";
	}

	print "\n";
}

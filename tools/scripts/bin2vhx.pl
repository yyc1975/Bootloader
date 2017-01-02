#!/usr/bin/env perl

my $size = 1;
my $fmt = "H*";
my $double = 0;
my $i = 0;

my $data;
my $odd0;
my $odd1;
my $odd2;
my $len;

while($#ARGV >= 0) {
	$_ = shift @ARGV;
	if(m/-eb(ig)?/i) {
		$endian = "big";
	} elsif(m/-el(ittle)?/i) {
		$endian = "little";
	} elsif(m/-128/i) {
		$size = 4;
		$double = 2;
	} elsif(m/-64/i) {
		$size = 4;
		$double = 1;
	} elsif(m/-32/i) {
		$size = 4;
	} elsif(m/-16/i) {
		$size = 2;
	} elsif(m/-8/i) {
		$size = 1;
	} elsif(m/-H/) {
		$fmt = "H*";
	} elsif(m/-B/) {
		$fmt = "B*";
	} else {
		die("unknown $_");
	}
}

$in = "N";
if($endian =~ m/big/i) {
	$out = "N";
} else {
	$out = "V";
}

if($size == 1) {
	$in = "C";
	$out = "C";
} elsif($size == 2) {
	$in = lc($in);
	$out = lc($out);
}

while(($len = read(STDIN,$data,$size)) > 0) {

	# if smaller than word, padd with zeros on the end
	if($len < $size) {
		my @pad = unpack("C*", $data);
		while($len++ < $size) {
			push(@pad, 0);
		}
		$data = pack("C*", @pad);
	}

	# endian convert
	$data = pack($out, unpack($in, $data));
	
	if($double == 0) {
		printf("%s\n", unpack($fmt, $data));
	}
	elsif($double == 1) {
		if ( ($i%2) == 1 ) {
			printf("%s_%s\n", unpack($fmt, $data), $odd0);
		} else {
			$odd0 = unpack($fmt, $data);
		}
	}
	elsif($double == 2) {
		if ( ($i%4) == 3 ) {
			printf("%s_%s_%s_%s\n", unpack($fmt, $data), $odd2, $odd1, $odd0);
		} elsif ( ($i%4) == 2 ) {
			$odd2 = unpack($fmt, $data);
		} elsif ( ($i%4) == 1 ) {
			$odd1 = unpack($fmt, $data);
		} else {
			$odd0 = unpack($fmt, $data);
		}
	}
	else {
		die("unknown data range");
	}
	
	$i++;
}


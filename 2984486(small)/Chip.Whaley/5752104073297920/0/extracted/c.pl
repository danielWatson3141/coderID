use v5.16;
#no strict;
#use diagnostics;

#use bignum;                    #add precision lose speed
use Parallel::ForkManager;
our $threads = 0;               #Thread y/n     1/0
our $thread_sets = 5;           #how many threads
sub status(@);
sub su(@);                      
our $su = 100;                  #how may say report lines to say
our $st = time();
our $bad_c = 0;    
	 
sub results ($);
sub results2 ($);
sub solveme($);
sub prep();
sub prep2();
sub prompt_and_ingest();
sub loop_data_and_solve();
sub close_and_save();
sub my_fact($);
sub my_x_choose_y($$);
sub my_x_choose_at_least_y($$);

#setup global variables
    #generic
our @data_in = ();
our $r = 0;
our $solution = "";
our $end_loop = "";
our $input;
our $case;
our $pm;
    #program specific globals
our $var1;
our @ar1;
    

#Parts of program

#prep();
#prep2();
prompt_and_ingest();
loop_data_and_solve();
close_and_save();
say "bad = $bad_c";

say "Seconds to process script: ", (time() - $st);

exit("I'm done");



#   main processing location

sub solveme ($) {
    
    #my $var1 = $_[0][0];
    my @ar1 = @{$_[0]};
    my $solution = 0;
	 my $dif = 0;
	 for my $a (0..499) {
		
		if ($a>$ar1[$a]) {
			$dif += (500-$a)*($a-$ar1[$a])
		} else {
			$dif += (500-$a)*($ar1[$a]-$a)
		}
	 }
		
		$dif /= 100;
		su $dif;
		if ($dif < 454000) {
			return "BAD";
			$bad_c++;
		} else {
			return "GOOD";
		}
		
    
    
    
    
    
    return $solution;
}

sub solveme_binary_search () {
    
    my $solution = 0;
    my $exp = 2 ** 50;
    my $gs = $exp;
    
    while ($exp > .1        #<--    precision here
           ) {
        $exp = $exp / 2;
        if ( 1              #<--    bounding code here
            ) {
            $gs -= $exp;
        } else {
            $gs += $exp;
        }
    }
    
    return $gs;
    
}

sub prompt_and_ingest() {
    status "starting: data ingestion";
    say "  Ready to continue processing.  Download file now!!";
    print "  Enter filename for INPUT: >";
    $input = <STDIN>;
    chomp($input);
    open (IN, "<$input");
    mkdir "$input-working" unless (-e "$input-working");
    if ($threads) {$pm = new Parallel::ForkManager($threads);} else {open (OUTFILE, ">$input.results.txt");}
    
    $_ = <IN>; chomp; $r = $_; 
    for $case (1..$r) {
        
        #   pulls each line into a variable
        $_ = <IN>; chomp; my $var1 = $_;            
        #$_ = <IN>; chomp; my $var2 = $_;
        #$_ = <IN>; chomp; my $var3 = $_;
        #$_ = <IN>; chomp; my ($var1,$var2,$var3) = split;            
        
        
        #   pulls one line into an anonymous array
        $_ = <IN>; chomp; my $a1 = [split(/ /)];
        #$_ = <IN>; chomp; my $a2 = [split(/ /)];
        #$_ = <IN>; chomp; $a3 = [split(/ /)];
        
        #   pulls first line as X - then pulls X lines into an array of anonymous arrays
        #my @arr1 = (); for (1..$r) { $_=<IN>; chomp; push @arr1, [split]; } 
        #my @arr1 = (); $_ = <IN>; chomp; my $N = $_; for (1..$N) { $_=<IN>; chomp; push @arr1, [split]; };$a1 = [join ",",@arr1];
       
        push @data_in, [$case,$a1];
    }
    status "complete: data ingestion";
}


sub loop_data_and_solve() {
    status "starting: problem solving";
    $end_loop = $r/$thread_sets;
    my $stop_point = $thread_sets-1;
        
    for my $case_div (0..$end_loop) {
        
        #starts Forking if needed
        if ($threads) {$pm->start() and next;
                       open (OUTTEMP, ">$input-working\\$case_div.txt");
                    }
        for my $case_spec (0..$stop_point) {
            my $rec = ($case_div * $thread_sets) + $case_spec;
            if ($rec > $r - 1) {
                last;
            }
            (local $case, my $a1) = @{$data_in[$rec]};
            su "case: $case\tdata:@{$a1}";
            
            #   runs solveme once
            my $final = solveme($a1);
            if ($threads) {
                say OUTTEMP "Case #$case: $final";
                say "Case #$case: $final";
            } else {
                results("$final");
            }
        }
        if ($threads) {close OUTFILE;
                       $pm->finish();}
    }
    status "complete: problem solving";
    
}

sub close_and_save() {
    status "starting: clean-up";
    if ($threads) {   
        $pm->wait_all_children;
        #   returns results to output file
        open (OUTFILE, ">$input.results.txt");
        su "endloop: $end_loop";
        for my $a (0..$end_loop) {
            open (IN, "<$input-working\\$a.txt");
            my $final = "";
            while (<IN>) {
                $final .= $_;
            }
            results2("$final");
        }
        close OUTFILE;
    }
    status "complete: clean-up";
}

sub prep () {
    status "starting: pre-processing prep";
    status "complete: pre-processing prep";
}




#   extra generic functions

sub results ($) {
    my ($result) = @_;
    print "Case #$case: $result\n";
    print OUTFILE "Case #$case: $result\n";
}
sub results2 ($) {
    my ($result) = @_;
    print $result;
    print OUTFILE $result;
}
sub su (@) {
    if ($su) {say "   ",(time() - $st)," secs\t",@_;$su--;}
}
sub status (@) {
    say " ",@_,"...\t", (time() - $st), " seconds in..";
}
sub my_fact($) {
    my $factorial = 1;
    my $temp = $_[0];
    $factorial *= $_ foreach 2..$temp;
    unless ($factorial) {return 1};
    return $factorial;
}
sub my_x_choose_y($$) {
    (my $x, my $y) = @_;
    return my_fact($x)/(my_fact($y)*my_fact($y-$x)*(2 ** $x));
}
sub my_x_choose_at_least_y($$) {
    (my $x, my $y) = @_;
    my $temp = 0;
    for my $c ($y..$x) {
        $temp += (my_fact($x)/(my_fact($c)*my_fact($x-$c)))
    }
    return $temp/(2 ** $x);
}
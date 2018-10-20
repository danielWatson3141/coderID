import itertools
import sys

def grouper(n, iterable, fillvalue=None):
    "grouper(3, 'ABCDEFG', 'x') --> ABC DEF Gxx"
    args = [iter(iterable)] * n
    return itertools.izip_longest(*args, fillvalue=fillvalue)

def parse_case(lines):
	targets = [int(i, 2) for i in lines[1].split()]
	sources = [int(i, 2) for i in lines[2].split()]
	return (targets, sources)

def parse_file(in_file):
    return (parse_case(case) for case in grouper(3, in_file.readlines()[1:]))

def run_case(case):
    targets, sources = case
    choices_per_target = [
        set(target ^ source for source in sources) for target in targets]
    switch_options = reduce(lambda acc, x: acc & x, choices_per_target)
    number_flips = [bin(switch).count("1") for switch in switch_options]
    return min(number_flips) if number_flips else "NOT POSSIBLE"
		
if len(sys.argv) < 2:
    exit();
    
with open(sys.argv[1], 'r') as in_file:
    for n, case in enumerate(parse_file(in_file), start=1):
        print "Case #{0}: {1}".format(n, run_case(case))

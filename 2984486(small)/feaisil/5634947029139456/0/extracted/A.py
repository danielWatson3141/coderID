import copy
import array
class input_format:
	n = 0
	l = 0
	o = []
	d = []
def process_input(inpf):
	number_of_tests = int(inpf.readline())
	result = []
	for i in range(number_of_tests):
		line = inpf.readline().split()
		inp = input_format
		inp.n = int(line[0])
		inp.l = int(line[1])
		inp.o = inpf.readline().split()
		inp.d = inpf.readline().split()
		result += ["Case #"+str(i+1)+": "+str(process(inp))]
	return result
	
def process(inp):
	min = 10000
	if sorted(inp.o) == sorted(inp.d):
		return 0
	for i in range(inp.l):
		k = switch(copy.deepcopy(inp.o), copy.deepcopy(inp.d),inp.n, inp.l, i, 1)
		if k < min:
			min = k
	if min == 10000:
		return "NOT POSSIBLE" 
	else:
		return str(min)
	

def switch(o, d, n, l, current, k):
	min = 10000
	shift(o, current)
	if sorted(o) == sorted(d):
		return k
	for i in range(current + 1, l):
		res = switch(copy.deepcopy(o), copy.deepcopy(d), n, l, i, k+1)
		if res < min:
			min = res
	return min

def shift(o, i):
	for idx,k in enumerate(o):
		if k[i] == "1":
			o[idx] = k[:i] + "0" + k[i+1:]
		else:
			o[idx] = k[:i] + "1" + k[i+1:]
                        
def execute()	:
        #args = parse_arguments()
        input_file = open("in", 'r')
        output_file = open( "out", 'w')
        output_file.write("\n".join(process_input(input_file)))

execute()
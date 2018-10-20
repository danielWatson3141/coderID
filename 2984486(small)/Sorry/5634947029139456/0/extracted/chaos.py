import sys, operator, itertools

def str_to_bits(val):
	out = 0
	for x in val:
		if x == '0':
			out += 0
		else:
			out +=1
		out = out << 1
	return out

def main(argv):
	file_name = argv[0]
	f = open(file_name, 'r')
	number_tests = int(f.readline())

	for count in range(number_tests):
		first_line = f.readline()
		first_line = first_line.split()
		first_line = map(int, first_line)

		outlets = f.readline()
		outlets = outlets.split()
		outlets = map(str_to_bits, outlets)
		outlets.sort()
		
		devices = f.readline()
		devices = devices.split()
		devices = map(str_to_bits, devices)
		devices.sort()

		outlets_array = False
		for out in outlets:
			compare = []
			for device in devices:
				compare.append(out ^ device)
			if outlets_array == False:
				outlets_array = set(compare)
			else:
				outlets_array = outlets_array.intersection(set(compare))
			if len(outlets_array) == 0:
				break

		if len(outlets_array) == 0:
			print "Case #" + str(count+1) + ": NOT POSSIBLE"
		else:
			minimum = 1000000
			outlets_array = list(outlets_array)
			for out in outlets_array:
				cur = bin(out).count('1')
				if cur < minimum:
					minimum = cur
			print "Case #" + str(count+1) + ": " + str(int(minimum))

if __name__ == "__main__":
   main(sys.argv[1:])

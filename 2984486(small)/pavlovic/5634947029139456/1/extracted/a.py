import sys

def solve(outlet_sets, device_sets, start_bit, end_bit):
	if start_bit > end_bit:
		return 0

	for i in range(len(outlet_sets)):
		outlet_set = outlet_sets[i]
		device_set = device_sets[i]
		
		for bit in range(start_bit, end_bit + 1):
			zero_count_outlets = 0
			for outlet in outlet_set:
				if outlet[bit] == "0":
					zero_count_outlets += 1

			zero_count_devices = 0
			for device in device_set:
				if device[bit] == "0":
					zero_count_devices += 1
			
			if (zero_count_outlets != zero_count_devices) and (zero_count_outlets != len(device_set) - zero_count_devices):
				return -1
				
	min_res = -1
	for flip in range(2):
		new_outlet_sets = []
		new_device_sets = []
		ok = True
		for i in range(len(outlet_sets)):
			outlet_set = outlet_sets[i]
			device_set = device_sets[i]
			new_outlet_set_zero = set()
			new_outlet_set_one = set()
			new_device_set_zero = set()
			new_device_set_one = set()
			for outlet in outlet_set:
				if outlet[start_bit] == str(flip):
					new_outlet_set_zero.add(outlet)
				else:
					new_outlet_set_one.add(outlet)
				
			for device in device_set:
				if device[start_bit] == "0":
					new_device_set_zero.add(device)
				else:
					new_device_set_one.add(device)
				
			if len(new_outlet_set_zero) == len(new_device_set_zero):
				if len(new_outlet_set_zero) > 0:
					new_outlet_sets.append(new_outlet_set_zero)
					new_device_sets.append(new_device_set_zero)
				if len(new_outlet_set_one) > 0:
					new_outlet_sets.append(new_outlet_set_one)
					new_device_sets.append(new_device_set_one)
			else:
				ok = False
				break
			
		if ok:
			res = solve(new_outlet_sets, new_device_sets, start_bit + 1, end_bit)
			if res != -1:
				if (min_res == -1) or (min_res > res + flip):
					min_res = res + flip
					if min_res == 0:
						break
				
	return min_res
		

t = int(sys.stdin.readline().strip())

for i in range(t):
	print "Case #" + str(i + 1) + ":",

	n, l = [int(i) for i in sys.stdin.readline().strip().split()]
	
	outlets = set(sys.stdin.readline().strip().split())
	devices = set(sys.stdin.readline().strip().split())

	res = solve([outlets], [devices], 0, l - 1)
	
	print (res if res != -1 else "NOT POSSIBLE")


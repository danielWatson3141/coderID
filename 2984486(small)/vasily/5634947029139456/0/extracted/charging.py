import sys

def count_bits(num):
	s = 0
	while num:
		s += num & 1
		num = num >> 1
	return s

def get_min(L, outlets, devices):
	# take for device, try every outlet..
	min_bits = L+1
	min_diff = None
	
	devices = sorted(devices)
	device = devices[0]
	for outlet in outlets:
		diff = device ^ outlet
		
		new_outlets = sorted(map(lambda outlet: outlet^diff, outlets))
		if new_outlets == devices:
			# great
			bits = count_bits(diff)
			if bits < min_bits:
				min_bits = bits
				min_diff = diff
		else:
			# bad diff
			pass
	return min_bits, min_diff


def main():
	T = int(sys.stdin.readline().strip())
	for i in range(T):
		N, L = map(int, raw_input().split())
		outlets = map(lambda x: int(x, 2), raw_input().split())
		devices = map(lambda x: int(x, 2), raw_input().split())
		
		bits, diff = get_min(L, outlets, devices)
		if diff == None:
			msg = 'NOT POSSIBLE'
		else:
			msg = str(bits)
		print 'Case #%d: %s' % (i+1, msg)

if __name__ == '__main__':
	main()

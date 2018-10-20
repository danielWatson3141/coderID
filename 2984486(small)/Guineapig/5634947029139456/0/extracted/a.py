def count_0s(fs, ic):
	res = 0
	for f in fs:
		if f[ic] == '0':
			res += 1
	return res



def actions_at(N, L, outlets, devices, idx):
	outlets_0s = count_0s(outlets, idx)
	devices_0s = count_0s(devices, idx)
	devices_1s = N - devices_0s
	res = []
	if outlets_0s == devices_0s:
		res.append(False)
	if outlets_0s == devices_1s:
		res.append(True)
	return res


def actions(N, L, outlets, devices):
	acts = [[]]
	for i in range(L):
		acts_at = actions_at(N, L, outlets, devices, i)
		if not acts_at:
			return []
		new_acts = []
		if False in acts_at:
			for a in acts:
				new_acts.append(a + [False])
		if True in acts_at:
			for a in acts:
				new_acts.append(a + [True])
		acts = new_acts
	return acts


def flip_bit(bit, flip):
	if not flip:
		return bit
	if bit == '0':
		return '1'
	else:
		return '0'


def apply_one(L, flow, action):
	return ''.join([flip_bit(flow[i], action[i]) for i in range(L)])

def apply_all(N, L, outlets, action):
	return sorted([apply_one(L, outlet, action) for outlet in outlets])


def count_flips(action):
	count = 0
	for f in action:
		if f:
			count += 1
	return count


def solve(N, L, outlets, devices):
	devices = sorted(devices)
	best = 1000
	for a in actions(N, L, outlets, devices):
		new_outlets = sorted(apply_all(N, L, outlets, a))
		if new_outlets == devices:
			nf = count_flips(a)
			if nf < best:
				best = nf
	if best == 1000:
		return None
	else:
		return best




# from itertools import permutations

# def flips(f1, f2):
# 	res = []
# 	for i in range(len(f1)):
# 		if f1[i] == f2[i]:
# 			res.append('0')
# 		else:
# 			res.append('1')
# 	return ''.join(res)


# # matching outlets[i] to devices[p[i]]
# def try_perm(N, L, outlets, devices, p):
# 	fs = flips(outlets[0], devices[p[0]])
# 	for i in range(1, N):
# 		fsi = flips(outlets[i], devices[p[i]])
# 		if fsi != fs:
# 			return None
# 	count = 0
# 	for f in fs:
# 		if f == '1':
# 			count += 1
# 	return count


# def solve(N, L, outlets, devices):
# 	devices = sorted(devices)
# 	best_count = None
# 	for p in permutations(range(N)):
# 		count = try_perm(N, L, outlets, devices, p)
# 		if count is not None and (best_count is None or count < best_count):
# 			best_count = count
# 	return best_count




################################################################################


def read_ints(f):
	return [int(w) for w in f.readline().strip().split()]

def read_int(f):
	return int(f.readline().strip())


from sys import argv

f = open(argv[1])

T = read_int(f);

for t in range(1, T+1):
	N, L = read_ints(f)
	outlets = f.readline().strip().split()
	devices = f.readline().strip().split()
	res = solve(N, L, outlets, devices)
	if res is None:
		res = 'NOT POSSIBLE'
	print 'Case #%s: %s' % (t, res)

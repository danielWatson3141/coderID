class state ():
	def __init__ (self, nums, req, bits, dist):
		self.nums = nums
		self.nums.sort()
		self.req = req
		self.req.sort()
		self.bits = bits
		self.dist = dist
	def getChildren(self):
		states = []
		for i in range(bits):
			s = state(self.nums + [], self.req + [], self.bits, self.dist + 1)
			states.append(s)
			# flip all bits
			for index, n in enumerate(s.nums):
				s.nums[index] = flipbit(s.nums[index], i)
		 	s.nums.sort()
		return states
	def isSolved(self):
		for index, i in enumerate(self.nums):
			if self.nums[index] != self.req[index]:
				return False
		return True
	def __hash__(self):
		n = 0
		t = 1
		for i in self.nums:
			n += i * t
			t *= self.bits
		return n 

def getint ():
	return int(raw_input())

def printCase(c, s):
	print "Case #" + str(c) + ": " + str(s)

def flipbit (n,i):
	return n ^ (1<<(i))

def bin2dec(string_num):
    return int(string_num, 2)

def makeState (nums, req, bits):
	return state(nums,req,bits,0)

def solve (init):
	q = []
	seen = dict()
	size = 1
	state = init
	while (size > 0):
		if (state.isSolved()):
			return state.dist
		chil = state.getChildren()
		for i in chil:
			if (str(i.__hash__()) not in seen):
				seen[str(i.__hash__())] = True
				q.append(i)
				size += 1
		if (len(q) == 0):
			break 
		state = q[0]
		q = q[1::]
		size -= 1
	return "NOT POSSIBLE"


for i in range(getint()):
	r = raw_input().split(' ')
	num = int(r[0])
	bits = int(r[1])

	r = raw_input().split(" ")
	nums = map(bin2dec, r)
	r = raw_input().split(" ")
	req = map(bin2dec, r)

	printCase(i+1,solve(makeState(nums,req, bits)))
	